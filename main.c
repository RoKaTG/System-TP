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


/**         Partie 2
  Obtient les permissions et droits sur les fichiers pendant la copie et les garde après copie
  @param char *src
  @param char *dest
  @return void
*/

void perm(char *src, char *dest) {
  struct stat state;
  stat(src, &state);
  chmod(dest, state.st_mode);
}


/**
  Copie le contenu d'un fichier source vers un fichier destination tout en gardant les permissions
  @param char *src
  @param char *dest
  @return void
*/

void copyPerm(char *src, char *dest) {
  perm(src, dest);
  copy(src, dest);
}


/**         Partie 3
  Copie le contenu d'un repertoir source dans un repertoir destination tout en gardant les permissions
  @param char *dirS
  @param char *fileS
  @param char *path
  @return NULL
*/

char pathFromSrc(char *dirS, char *fileS, char *path) {
  regex_t regex;
    regcomp (&regex, "/$", REG_EXTENDED);
    char *res = (char *)malloc(strlen(dirS) + strlen(fileS) + 1);
    strcpy(res, dirS);
    if(regexec(&regex, dirS, 0, NULL, 0)){
         return strcat(strcat(res, path),fileS);
    }
    else{
    	return strcat(res, fileS);
    }
	return NULL;
}

void copy(char *dirsrc,char *dirdest){
	  DIR *rep = opendir(dirsrc);
	  struct dirent *lecture;
	  while ((lecture = readdir (rep)))
	  {
	  	if(!strcmp(lecture -> d_name,".") && !strcmp(lecture -> d_name,"..")){
	  		char *src=constructPath(dirsrc,lecture -> d_name,"/");
		  	char *dest=constructPath(dirdest,lecture -> d_name,"/");
		  	printf("%s\n",src );
		  	printf("%s\n",dest );
		    cpiFiable(src,dest);
	  	}
    }
  }


  /**         Partie 4
    Copie le contenu d'un repertoir source dans un repertoir destination tout en gardant les permissions de manière recursive
    @param char *dirS
    @param char *fileS
    @param char *path
    @return NULL
  */





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
