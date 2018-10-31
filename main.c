#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  struct stat meta;
  stat("main.c", &meta);
  printf("File Size: %ld\n", meta.st_size);
  printf("Modes (Permissions): %d\n", meta.st_mode);
  printf("Time of Last Access: %s\n", ctime(&(meta.st_atime)));

  char size[50];
  if(meta.st_size < 1024){
      sprintf(size, "The file is %ld bytes.", meta.st_size);
      printf("%s\n", size);
  }
  else if(meta.st_size < 1048576){
      sprintf(size, "The file is %f kilobytes.", meta.st_size / 1024.0);
      printf("%s\n", size);
  }
  else if(meta.st_size < 1073741824){
      sprintf(size, "The file is %f gigabytes.", meta.st_size / 1048576.0);
      printf("%s\n", size);
}




  return 0;
}
