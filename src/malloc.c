#include "malloc_internal.h"

t_area *first_area = NULL;
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

void create_large_block(char *area, size_t size, size_t h_area_size)
{
	t_block *b = (t_block *)&area[h_area_size];
	b->next = NULL;
	b->is_free = 1;
	b->size = size;
}

void create_blocks(char *area, size_t block_size, size_t h_area_size, size_t h_block_size)
{
	for (int i = 0; i < 100; i++)
	{
		t_block *b = (t_block *)&area[h_area_size + (h_block_size * i) + (block_size * i)];
		if (i < 99)
			b->next = (t_block *)&area[h_area_size + (h_block_size * (i + 1)) + (block_size * (i + 1))];
		else
			b->next = NULL;
		b->is_free = 1;
		b->size = 0;
	}
	/* t_block *b = (t_block *)&area[h_area_size];
	while (b->next != NULL)
	{
		printf("block = %d\n", b->is_free);
		b = b->next;
	} */
}

void	*take_free_block(size_t block_size, size_t size, size_t header_block_size) // return addr of the first bytes of a available block, else. return NULL. he also set the block as used
{
	t_area *cursor = first_area;
	while (cursor)
	{
		if (cursor->type == block_size)
		{
			t_block *block_cursor = cursor->first_block;
			while (block_cursor)
			{
				if (block_cursor->is_free)
				{
					block_cursor->is_free = 0;
					block_cursor->size = size;
					return ((char *)block_cursor + header_block_size);
				}
				block_cursor = block_cursor->next;
			}
		}
		cursor = cursor->next;
	}
	return NULL;
}

void	insert_area(t_area *z)
{
	t_area	*prev;
	t_area	*cursor;

	prev = NULL;
	cursor = first_area;
	while (cursor && cursor < z)
	{
		prev = cursor;
		cursor = cursor->next;
	}
	z->next = cursor;
	if (!prev)
		first_area = z;
	else
		prev->next = z;
}

static int	is_valid_size(size_t size, size_t page_size)
{
	struct rlimit	limit;
	size_t			overhead;
	size_t	header_area_size = (sizeof(t_area) + 15) / 16 * 16; // 16 multiple guaranted
	size_t	header_block_size = (sizeof(t_block) + 15) / 16 * 16;

	overhead = header_area_size + header_block_size + 15 + page_size;
	if (size > SIZE_MAX - overhead)
		return (0);
	if (getrlimit(RLIMIT_AS, &limit) == 0
		&& limit.rlim_cur != RLIM_INFINITY
		&& size > limit.rlim_cur)
		return (0);
	return (1);
}

void	*malloc_internal(size_t size)
{
	char	*addr; // addr to return
	char	*area = NULL;
	long	page_size = sysconf(_SC_PAGESIZE);
	size_t	block_size; // real value of tiny, small or long
	size_t	required_pages; //the number of pages we need
	size_t	required_bytes;
	size_t	header_area_size = (sizeof(t_area) + 15) / 16 * 16; // 16 multiple guaranted
	size_t	header_block_size = (sizeof(t_block) + 15) / 16 * 16;

	//printf("area = %d, block = %d\n", header_area_size, header_block_size);
	if (page_size < 1)
	{
		write(1, "Error: invalid sys page size.\n",30);
		return (NULL);
	}
	if (size == 0) // like the true malloc, size 0 allocate a minimal zone
		size = 1;
	if (size <= SMALL)
	{
		block_size = SMALL;
		if (size <= TINY)
			block_size = TINY;

		addr = take_free_block(block_size, size, header_block_size);
		if (addr)
			return (addr);
		// if the program must create new area
		required_bytes = (block_size + header_block_size) * 100 + header_area_size;
		if (required_bytes % page_size != 0)
			required_pages = required_bytes / page_size + 1;
		else
			required_pages = required_bytes / page_size;

	}
	else // create a large zone
	{
		if (!is_valid_size(size, page_size))
			return (NULL);
		block_size = ((size + 15) / 16 * 16);
		required_bytes = block_size + header_block_size + header_area_size;
		if (required_bytes % page_size != 0)
			required_pages = required_bytes / page_size + 1;
		else
			required_pages = required_bytes / page_size;
	}
	area = mmap(
		NULL,
		(size_t)page_size * required_pages,
		PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANONYMOUS,
		-1, 0);

	if (area == MAP_FAILED)
		return (NULL);

	t_area *z = (t_area *)area;
	// init the area
		z->first_block = (t_block *)&area[header_area_size];
	z->type = block_size;
	z->next = NULL;
	z->length = required_pages * page_size;
	if (block_size <= SMALL)
		create_blocks(area, block_size, header_area_size, header_block_size);
	else
		create_large_block(area, size, header_area_size);
	insert_area(z); // trie les zones par leurs adresses
	return (take_free_block(block_size, size, header_block_size));
	//t_block *b = z->first_block;
	//b = b->next;
	//printf("%d\n", b->is_free);
}

void	*malloc(size_t size)
{
	void	*ptr;

	pthread_mutex_lock(&g_mutex);
	ptr = malloc_internal(size);
	pthread_mutex_unlock(&g_mutex);
	return (ptr);
}

void *calloc(size_t nmemb, size_t size)// if wanted, call calloc from my libft
{
    return (ft_calloc(nmemb, size));
}
