# Page Alloc
![Build Status](https://github.com/tasinfarhanmc/page-alloc/actions/workflows/ci.yml/badge.svg)
A Page Allocator Written in C **([POSIX](https://wikipedia.org/wiki/POSIX#POSIX-oriented_operating_systems) Required])**
## API Reference

#### Initialize

```c
  void page_alloc_init(); 
```

#### Allocate Memory

```c
  void *page_alloc(void *addr, size_t size); 
```

| Parameter | Type     | Description                      |
| :-------- | :------- | :------------------------------- |
| `addr`    | `void *` | **Optional**. Allocation Address [NULL for Random] |
| `size`    | `size_t` | Allocation Size [In Bytes] |

#### Deallocate / Free Memory

```c
  int page_free(void *addr, size_t size)
```
| Parameter | Type     | Description                      |
| :-------- | :------- | :------------------------------- |
| `addr`    | `void *` | Address |
| `size`    | `size_t` | Allocation Size [In Bytes] |


#### Constants (Set via [`page_alloc_init()`](#initialize) at runtime)
- **`PAGE_ALLOC_INIT`**: Indicates if the library has been initialized using [`page_alloc_init()`](#initialize).
- **`PAGE_ALLOC_SIZE`**: Defines the size of each page in the allocator (typically **4096** bytes).
