#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

void main() 
{
int q=0,a=0;
here:do
     {  
	printf("\n");
	int t;
	char *ptr = "/dev/i2c-2";
	if ((t = open(ptr, O_RDWR)) < 0) 
	{
		printf("unable to access the pin (19,20). \n");
		exit(1);
	}
	
	ioctl(t, I2C_SLAVE, 0x53);

	char config[2]={0};
	config[0] = 0x31;
	config[1] = 0x08;
	write(t, config, 2);
	sleep(1);

	char rgstr[1] = {0x32};
	write(t, rgstr, 1);
	char data[6] ={0};
	if(read(t, data, 6) != 6)
	{
		printf("Error 404: Something went wrong\n");
		exit(1);
	}
	else
	{
		int x = ((data[1] & 0x03) * 256 + (data[0] & 0xFF));
		if(x > 511)
		{
			x -= 1024;
		}

		int y = ((data[3] & 0x03) * 256 + (data[2] & 0xFF));
		if(y > 511)
		{
			y -= 1024;
		}

		int z = ((data[5] & 0x03) * 256 + (data[4] & 0xFF));
		if(z > 511)
		{
			z -= 1024;
		}

		printf("X , Y , Z : %d , %d , %d \n", x,y,z);
		++q;	
	}
     }while(q<=a);
printf("enter the number of iterations: ");
scanf("%d",&a);

if(a==0)
     exit(0);
else
    {
     q=1;
     goto here;
    }
}










