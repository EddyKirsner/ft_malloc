# malloc

My own dynamic memory allocator: `malloc`, `free` and `realloc` built on `mmap`/`munmap`, with TINY / SMALL / LARGE zones and a `show_alloc_mem` function to display allocated blocks.

## Build

```bash
make        # builds libft_malloc_$HOSTTYPE.so
```

## Usage

```bash
LD_PRELOAD=./libft_malloc.so ls
```

## Skills

Memory management, `mmap`/`munmap`, page alignment, zone allocation strategy (TINY / SMALL / LARGE), shared libraries (`.so`, `-fPIC`, `LD_PRELOAD`), debugging with `show_alloc_mem`.

---
*Project from the [42](https://42.fr) curriculum (42 Paris) by Eddy Kirsner.*
