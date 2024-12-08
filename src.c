#include <page_alloc.h>
#include <sys/mman.h>
#include <unistd.h>

unsigned long PAGE_ALLOC_UNIT = 0;
char PAGE_ALLOC_INIT = 0;

void page_alloc_init() {
  PAGE_ALLOC_UNIT = getpagesize();
  PAGE_ALLOC_INIT = 1;
}

void *page_alloc(void *addr, unsigned size) {
  void *data = mmap(NULL, ALLOC_PAGE_SIZE * size, PROT_READ | PROT_WRITE,
                    MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  if (data != MAP_FAILED) {
    return data;
  }

#ifdef DEBUG
  const char format[] = "alloc_page {addr: %p, size: %u}";
  char buffer[sizeof(format) + sizeof(void *) * 2];
  sprintf(buffer, format, addr, size);
  perror(buffer);
#endif

  return NULL;
}

int page_free(void *addr, unsigned size) {
  if (munmap(addr, ALLOC_PAGE_SIZE * size) != -1) {
    return 0;
  }

#ifdef DEBUG
  const char format[] = "unalloc_page {addr: %p, size: %u}";
  char buffer[sizeof(format) + sizeof(void *) * 2];
  sprintf(buffer, format, addr, size);
  perror(buffer);
#endif

  return -1;
}
