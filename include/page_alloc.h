extern unsigned long PAGE_ALLOC_UNIT;
extern char PAGE_ALLOC_INIT;

void *page_alloc(void *addr, unsigned size);
int page_free(void *addr, unsigned size);
