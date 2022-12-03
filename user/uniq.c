#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

char buf[512];
char buf1[512];
char buf2[512];

void unniq(int fd)
{
  int n;
int result;

  while((n = read(fd, buf, sizeof(buf))) > 0) {

for (int i=0; i<n; i++)
{
if(buf[i] != '\n')
{
 buf1[i] = buf[i];
}
else
{
for(int j=i+1 ; j<n; j++)
{
if (buf[j] != '\n')
{
buf2[j] = buf[j];
}
else
{
 result = strcmp(buf1,buf2);
printf("%d",result);
}
}
}
}
}
}
int main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 1){
    unniq(0);
    exit(0);
  }

  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      fprintf(2, "File %s  does not exist \n", argv[i]);
      exit(1);
    }
    unniq(fd);
    close(fd);
  }
  exit(0);

return 0;
}
