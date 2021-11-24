#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <fcntl.h>
#define CHUNK 128

#define AND &&
#define OR ||
#define ISNOT !=
#define NOT !
#define then

/**         Partie 1
  Copie le contenue d'un fichier source dans un fichier destination
  @param char *src
  @param char *dest
  @return void
*/
void copy(char *src, char *dest) {
  int fileS = open(src, O_RDONLY);
  int fileD = open(dest, O_CREAT | O_WRONLY);
  char buffer[CHUNK];
  size_t n;
  if (fileS < 0 || fileD < 0) {
    exit(EXIT_FAILURE);
  }
  else {
    while ((n = read(fileS, buffer, CHUNK)) > 0) {
      write(fileD, buffer, n);
    }
  }
  close(fileS);
  close(fileD);
}

void perm(char *src, char *dest) {
  struct stat state;
  stat(src, &state);
  chmod(dest, state.st_mode);
}








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
