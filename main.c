#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <fcntl.h>
#include <pthread.h>

int copyfile(const char *iname, const char *oname) {
  int idesc = open(iname, O_RDONLY);
  int odesc = open(oname, O_WRONLY | O_CREAT | O_EXCL, 0666);
  while(1) {
    char buffer [4096];
    int rcnt = read (idesc, buffer, sizeof(buffer));
    if (rcnt == 0)
    break;
    int pos = 0;
    while (rcnt != 0) {
      int wcnt = write(odesc, buffer + pos, rcnt);
      rcnt -= wcnt;
      pos += wcnt;
    }
  }
  close(idesc);
  close(odesc);
  return 0;
}
