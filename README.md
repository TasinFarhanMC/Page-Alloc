# Page Alloc
A Page Allocator Written in C **[POSIX Required]**
## API Reference

#### Initialize

```c
  void *page_alloc_init(); 
```

#### Allocate Memory

```c
  void *page_alloc(void *addr, unsigned size); 
```

| Parameter | Type     | Description                      |
| :-------- | :------- | :------------------------------- |
| `addr`    | `void *` | **Optional**. Allocation Address [NULL for Random] |
| `size`    | `unsigned int` | Number of Pages |

#### Deallocate / Free Memory

```c
  int page_free(void *addr, unsigned size)
```
| Parameter | Type     | Description                      |
| :-------- | :------- | :------------------------------- |
| `addr`    | `void *` | Address |
| `size`    | `unsigned int` | Number of Pages |
