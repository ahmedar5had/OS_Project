#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

char buf[2512];
char buf1[2512];
char buf2[2512];

int func1(char arr[],char arr2[], int n)
{
	for (int i=0;i<n ;i++)
	{
	
		if (arr[i] != arr2[i])
		{
			return 1;
		
		}
	}
	return 0;
}

void unniq(int fd)
{
	int n;
	int result;
  	while((n = read(fd, buf, sizeof(buf))) > 0)
	{
	int start1 = 0, start2 = 0, len1=0;
	int s1, s2;
	s1 = 0;
	for (int i=0; i<n; ++i)
	{
		if(buf[i] != '\n')
		{
 			buf1[s1++] = buf[i];
		}
		else
		{
			len1 = i - start1;
			start1 = i+1;
			s1 = 0;
			start2 = i+1;
			int  len3 = 0;
			s2 = 0;
			int flag = 1;
			for(int j=i+1 ; j<n; j++)
			{
				if (buf[j] != '\n')
				{
					buf2[s2++] = buf[j];
				}
				else
				{
					len3 = j - start2;
					start2 = j+1;
					s2 = 0;
					
					if(len1 == len3)
						result = func1(buf1,buf2,len3);
					else
						result = 1;
					
					memset(buf2, 0, 2512);
					if ( result == 0 )
					{
						flag = 0;
						break;
					}
				}
					

			
			}
			if(flag == 1){
				write(1,buf1,sizeof(buf1));
				printf("\n");
			}
			memset(buf1, 0, 2512);
		}
	}
	}
}



int main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 1)
  {
    unniq(0);
    exit(0);
  }

  for(i = 1; i < argc; i++)
	{
  	if((fd = open(argv[i], 0)) < 0)
	{
      		fprintf(2, "File %s  does not exist \n", argv[i]);
      		exit(1);
    	}
    	unniq(fd);
    	close(fd);
  	}
exit(0);

return 0;
}
