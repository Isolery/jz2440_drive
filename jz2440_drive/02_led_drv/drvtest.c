#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    char* filename;
    int fd;
    int val;

    if(argc != 3)
    {
        printf("Usage error:\n");
        return 0;
    }

    filename = argv[1];
    fd = open(filename, O_RDWR);
    if(fd < 0)
    {
        printf("error, cant't open %s\n", filename);
        return 0;
    }

    if(strcmp(argv[2], "on") == 0)
    {
        val = 1;
        write(fd, &val, 4);
    }
    else if(strcmp(argv[2], "off") == 0)
    {
        val = 0;
        write(fd, &val, 4);
    }

    return 0;
}
