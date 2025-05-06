// Linux
// #define _GNU_SOURCE

#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

int main()
{

    size_t size = getpagesize();
    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);

    if (ptr == MAP_FAILED)
    {
        perror("mmap");
        return 1;
    }

    ((char *)ptr)[0] = 'A';
    printf("%c\n", ((char *)ptr)[0]);

    munmap(ptr, size);

    return 0;
}