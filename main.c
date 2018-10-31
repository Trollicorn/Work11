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

  char perm[9] = "---------";
  int n = 0;
  for (int m = 2; m > -1; m--){
	for(int i = 2; i > -1; i--){
	  if ( meta.st_mode & (1 << ((3 * i)+m)) ){
//	  	printf("%d\n", m);
	  	if( m == 2){
	  		perm[n] = 'r';
	  	}
	  	else if (m == 1){
	  		perm[n] = 'w';
	  	}
	  	else {
	  		perm[n] = 'x';
	  	}
//	  	printf("%d:%c\n",n,perm[n] );
	  }
	  n+=3;
	}
	n = 3 - m;
  }
  n = 0;
  while (n < 9){
  	printf("%c",perm[n]);
  	n++;
  }
printf("\n");



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
