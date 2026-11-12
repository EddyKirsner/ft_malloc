#ifndef MALLOC_INTERNAL_H
# define MALLOC_INTERNAL_H

#include "../libft/libft.h"
#include <sys/mman.h>
#include <pthread.h>
#include <stdint.h>
#include <sys/resource.h>

extern pthread_mutex_t	g_mutex;

#define TINY 128 // 12800 octets 
#define SMALL 1024 // 102400 octets

typedef struct s_block
{
	int		is_free; // 0 == used, 1 == free
	int		size; // real size asked
	struct	s_block *next;
}	t_block;

//type 0 = tiny, 1 = small, 2 = large
typedef struct s_area // pouvoir retrouver directement les zones a partir des adresses
{
	t_block *first_block;
	size_t type; //number of bytes required by block (== TINY or SMALL or higher)
	size_t length; // full length of the area
	struct s_area *next;
}	t_area;

extern t_area *first_area;

void	*malloc_internal(size_t size);
void	free_internal(void *ptr);
void	*realloc_internal(void *ptr, size_t size);
void	show_alloc_mem_internal(void);
void	show_alloc_mem();
void	memalloc_viewer();

#endif
