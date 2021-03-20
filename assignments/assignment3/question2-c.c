#include <stdio.h>

short read_chunk(FILE * fil, char * to)
{
  short len;
  fread(&len, 2, 1, fil); /* read length of binary data */
//  if (len > sizeof(to)) return -1;

  len = len > sizeof(to) / 2 ? sizeof(to) / 2 : len;

  fread(to, 1, len, fil); /* read len bytes of binary data */
  return len;
}

int main(int argc, char * argv[])
{
  FILE *fp;
  fp = fopen("test.txt", "r");

  char testOverflow[4];
  short readLen = read_chunk(fp, testOverflow);

  printf("Buffer contents: %s\nLength read (bytes): %d\n", testOverflow, readLen);

  return 0;
}
