#include <stdio.h>

int copy_buf(char * to, int pos, char * from, int len) {
  int i;

  for (i = 0; i < len; i++) {
    if (i >= sizeof(*from)) return pos;
    if (pos >= sizeof(*to)) return pos;

    to[pos] = from[i];
    pos++;
  }
  return pos;
}

int main(int argc, char * argv[])
{
  char buff[5] = { 'h', 'e', 'l', 'l', 'o' };
  char from[5] = { 'a', 'b', 'c', 'd', 'e' };

  copy_buf(buff, 0, from, 4);

  printf("Clean copy_buf test: %s\n\n", buff);

  char dirtybuff[5] = { 'h', 'e', 'l', 'l', 'o' };
  char dirtyfrom[2] = { 'a', 'b' };

  // This causes a segfault, with the non-fixed function
  int copyAmt = copy_buf(dirtybuff, 0, dirtyfrom, 9999);

  printf("Dirty buffer: %s\nAmount copied: %d\n\n", dirtybuff, copyAmt);


  char dirtybuff2[5] = { 'h', 'e', 'l', 'l', 'o' };
  char dirtyfrom2[10] = { 't', 'e', 's', 't', 's', 't', 'r', 'i', 'n', 'g' };

  int copyAmt2 = copy_buf(dirtybuff2, 1000, dirtyfrom2, 99999) - 1000;

  printf("Dirty buffer 2: %s\nAmount copied: %d\n", dirtybuff2, copyAmt2);

  return 0;
}
