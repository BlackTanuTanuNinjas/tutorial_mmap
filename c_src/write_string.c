// Linux
#define _GNU_SOURCE

#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

int main()
{
    size_t size = getpagesize();

    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);

    if (ptr == MAP_FAILED)
    {
        perror("mmap");
        return 1;
    }

    const char *message = "Hello, World!";
    memcpy(ptr, message, strlen(message) + 1);

    printf("%s\n", (char *)ptr);

    munmap(ptr, size);

    return 0;
}
