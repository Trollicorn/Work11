#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  struct stat meta;
  stat("main.c", &meta);
  printf("%ld\n", meta.st_size);
  printf("%d\n", meta.st_mode);
  printf("%s\n", ctime(&(meta.st_atime)));

  return 0;
}
