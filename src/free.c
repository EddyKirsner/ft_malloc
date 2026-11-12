#include "malloc_internal.h"

int is_cache_area(size_t type) // function return 1 if it need to keep an area tiny or small as a last area for cache
{
	if (type > SMALL)
		return (0);
	t_area *cursor = first_area;
	size_t type_counter = 0; //if we find more than 1 of this type area, we return 0 to delete
	while (cursor)
	{
		if (cursor->type == type)
			type_counter++;
		cursor = cursor->next;
	}
	return (type_counter == 1 ? 1 : 0);
}

int	is_empty_area(t_area *area)
{
	t_block	*block = area->first_block;
	while(block)
	{
		if (block->is_free != 1) // no security for double free as malloc
			return (0);
		block = block->next;
	}
	return (1);
}
void	destroy_area(t_area *area)
{
	t_area *cursor = first_area;

	if (area == first_area)
	{
		first_area = area->next;
		munmap(area, area->length);
	}
	else
	{
		while (cursor->next && cursor->next != area)
			cursor = cursor->next;
		if (cursor->next == area)
		{
			cursor->next = area->next;
			munmap(area, area->length);
		}
	}
}

void free_internal(void *ptr)
{
	size_t	header_block_size = (sizeof(t_block) + 15) / 16 * 16;
	if (!first_area)
		return;
	t_area *cursor = first_area;
	t_block	*block = first_area->first_block;

	while (cursor)
	{
		block = cursor->first_block;
		while(block)
		{
			if ((char *)block + header_block_size == ptr) // no security for double free as malloc
			{
				if (block->is_free)
					return;
				block->is_free = 1;
				block->size = 0;
				if (is_empty_area(cursor))
					if (!is_cache_area(cursor->type))
						destroy_area(cursor);
				return;
			}
			block = block->next;
		}
		cursor = cursor->next;
	}
}

void	free(void *ptr)
{
	pthread_mutex_lock(&g_mutex);
	free_internal(ptr);
	pthread_mutex_unlock(&g_mutex);
}
