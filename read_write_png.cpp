
//#include <png.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

//#define SIZE 20

void main()
{
	int k;
FILE *fp = fopen("input.png","rb");
FILE *tmpf = fopen("test4.png", "wb");
FILE *fpt = fopen("out.txt","w+");

fseek(fp, 0, SEEK_END);

long size = ftell(fp);

rewind(fp);

char *buffer = (char*)malloc(sizeof(char)*size);

size_t result = fread(buffer, 1, size, fp);

fwrite(buffer, 1, size, tmpf);

printf(" RESULT=%d",result);
printf(" size=%ld",size);
/* Decimal */
    for (size_t i = 1; i <=size; i++)
	{
		fprintf(fpt,"%d",buffer[i]);
        //printf("%d", buffer[i]);
     fprintf(fpt,"\n"); 
	}

	 /* Hexadecimal
    for (size_t i = 1; i <= SIZE; i++)
        printf("%02X ", buffer[i]);
    printf("\n"); */

fflush(tmpf);
fclose(tmpf);

}