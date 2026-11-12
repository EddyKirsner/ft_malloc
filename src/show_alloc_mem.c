#include "malloc_internal.h"

static void	ft_putnbr_base(size_t n, const char *base, size_t base_len)
{
	char	buf[64];
	int		i;

	i = 64;
	if (n == 0)
		buf[--i] = base[0];
	while (n > 0)
	{
		buf[--i] = base[n % base_len];
		n /= base_len;
	}
	write(1, &buf[i], 64 - i);
}

void	ft_putaddr(void *ptr)
{
	write(1, "0x", 2);
	ft_putnbr_base((uintptr_t)ptr, "0123456789ABCDEF", 16);
}

void	show_alloc_mem_internal(void)
{
	if (!first_area)
	{
		write(1, "Total : 0 bytes\n", 16);
		return;
	}
	size_t	header_block_size = (sizeof(t_block) + 15) / 16 * 16;
	size_t	total_bytes = 0;
	t_area	*cursor = first_area;
	t_block	*block;

	while (cursor)
	{
		if (cursor->type == TINY)
			write(1, "TINY : ", 7);
		else if (cursor->type == SMALL)
			write(1, "SMALL : ", 8);
		else if (cursor->type > SMALL)
			write(1, "LARGE : ", 8);
		ft_putaddr(cursor);
		write(1, "\n", 1);
		block = cursor->first_block;
		while (block)
		{
			if (!block->is_free)
			{
				ft_putaddr((char *)block + header_block_size);
				write(1, " - ", 3);
				ft_putaddr((char *)block + header_block_size + block->size);
				write(1, " : ", 3);
				ft_putnbr_base(block->size, "0123456789", 10);
				total_bytes += block->size;
				write(1, " bytes\n", 7);
			}
			block = block->next;
		}
		cursor = cursor->next;
	}
	write(1, "Total : ", 8);
	ft_putnbr_base(total_bytes, "0123456789", 10);
	write(1, " bytes\n", 7);
}

void	show_alloc_mem()
{
	pthread_mutex_lock(&g_mutex);
	show_alloc_mem_internal();
	pthread_mutex_unlock(&g_mutex);
}