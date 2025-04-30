#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("fstat");
        return 1;
    }

    struct stat sb;

    if (fstat(fd, &sb) == -1)
    {
        perror("fstat");
        return 1;
    }

    size_t size = sb.st_size;

    void *ptr = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);

    if (ptr == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return 1;
    }

    write(STDOUT_FILENO, ptr, size);

    munmap(ptr, size);

    close(fd);

    return 0;
}
