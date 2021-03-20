#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void next_tag(char * str)
{
  char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u','v', 'w', 'x', 'y', 'z' };
  for (int i = 0; i < sizeof(str); i++)
  {
    str[i] = alphabet[rand() % 26];
  }
}

int main(int argc, char * argv[]) {
  int valid = 0;
  char str1[8];
  char str2[8];
  next_tag(str1);
  fgets(str2, 8, stdin);
  if (strncmp(str1, str2, 8) == 0) valid = 1;
  printf("buffer1: str1(%s), str2(%s), valid(%d)\n", str1, str2, valid);
}
