#include "../src/malloc.h"


/* int main()
{
	printf("%d\n%d\n", 10/6, 10%6);
} */
int main()
{
	size_t				nb = 10;
	char 			*zone = NULL;
	long 			page_size = sysconf(_SC_PAGESIZE);
	size_t	required_pages; //the number of pages we need
	size_t	required_bytes;
	size_t 	TINY = 128; // 12800 octets 
	size_t 	SMALL = 1024; // 102400 octets
	size_t	header_zone_size = 50;
	size_t	header_block_size = 50;

	if (page_size < 1)
	{
		write(1, "Error: invalid sys page size.\n",30);
		return (1);
	}
	//printf("%d\n", (int)page_size);
	if (nb < 1)
		return (1);
	else if (nb <= TINY)
	{
		required_bytes = (TINY + header_block_size) * 100 + header_zone_size;
		if (required_bytes % page_size != 0)
			required_pages = required_bytes / page_size + 1;
		else
			required_pages = required_bytes / page_size;
	}
	else if (nb <= SMALL)
	{
		required_bytes = (SMALL + header_block_size) * 100 + header_zone_size;
		if (required_bytes % page_size != 0)
			required_pages = required_bytes / page_size + 1;
		else
			required_pages = required_bytes / page_size;
	}
	zone = mmap(
		NULL,
		(size_t)page_size,
        PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANONYMOUS,
		-1, 0);
	if (zone = MAP_FAILED)
		return (1);
}