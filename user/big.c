#include "user.h"

int main() {
  char buf[512];
  int fd, i, blocks;

  fd = open("big.file", O_CREATE | O_WRONLY);
  if(fd < 0) {
    printf("big: cannot open big.file for writing\n");
    exit();
  }

  blocks = 0;
  while(1) {
    *(int*) buf = blocks;
    int cc = write(fd, buf, sizeof(buf));
    if(cc <= 0)
      break;
    blocks++;
  }

  close(fd);
  fd = open("big.file", O_RDONLY);
  if(fd < 0) {
    printf("big: cannot re-open big.file for reading\n");
    exit();
  }
  for(i = 0; i < blocks; i++) {
    int cc = read(fd, buf, sizeof(buf));
    if(cc <= 0) {
      printf("big: read error at block %d\n", i);
      exit();
    }
    if(*(int*) buf != i) {
      printf("big: read the wrong data (%d) for block %d\n", *(int*) buf, i);
      exit();
    }
  }

  printf("%d\n", blocks);

  exit();
}
