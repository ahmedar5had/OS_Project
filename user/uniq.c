#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void)
{
printf("return val is %d\n",uniq());
printf("Uniq system call executed successfully");

exit(0);
}
