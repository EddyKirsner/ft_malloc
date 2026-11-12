#include "malloc_internal.h"

void *realloc_internal(void *ptr, size_t size)
{
	size_t	header_block_size = (sizeof(t_block) + 15) / 16 * 16;
	if (!ptr)
		return(malloc_internal(size));
	if (!first_area)
		return (NULL);
	t_area *cursor = first_area;
	t_block	*block = first_area->first_block;

	while (cursor)
	{
		block = cursor->first_block;
		while(block)
		{
			if ((char *)block + header_block_size == ptr)
			{
				if (block->is_free)
					return (NULL);
				if (size == 0)
				{
					free_internal(ptr);
					return (NULL);
				}
				else if ((size <= TINY && block->size <= TINY) || (size <= SMALL && size > TINY && block->size <= SMALL && block->size > TINY))
				{
					block->size = size;
					return (ptr);
				}
				else
				{
					void    *new_ptr;
					size_t  copy_size;

					new_ptr = malloc_internal(size);
					if (!new_ptr)
						return (NULL);
					copy_size = block->size;
					if (size < copy_size)
						copy_size = size;
					ft_memcpy(new_ptr, ptr, copy_size);
					free_internal(ptr);
					return (new_ptr);
				}
			}
			block = block->next;
		}
		cursor = cursor->next;
	}
	return (NULL);
}

void	*realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	pthread_mutex_lock(&g_mutex);
	new_ptr = realloc_internal(ptr, size);
	pthread_mutex_unlock(&g_mutex);
	return (new_ptr);
}
