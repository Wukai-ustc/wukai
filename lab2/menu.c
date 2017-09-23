#include<stdio.h>
#include<stdlib.h>

void help();
void quit();
void hello();
void bigger();
void add();
void sub();
void multi();
void divi();

int main()
{
    char* cmd[] = {"help", "quit", "hello", "bigger", "add", "sub", "multi", "divi"};
    
    
    while (1)
        {
	    int i;
	    char command[256];
            scanf ("%s", command);
	    for(i=0;i<8;i++)
            {
                if(strcmp(command,cmd[i]) == 0)
                {
                    break;
                }
            } 
	    switch(i)
      	    {
        	case 0:
                help();
                break;

        	case 1:
                quit();
                break;

        	case 2:
                hello();
                break;

        	case 3:
                bigger();
                break;

        	case 4:
                add();
                break;

        	case 5:
                sub();
                break;

        	case 6:
                multi();
                break;

        	case 7:
                divi();
                break;

                default:
                printf("Wrong Command\n");
                break;
            }
	    
        }

}



void help()
{
    printf("+--------+---------------------------------+\n");
    printf("+ name   + desciption                      +\n");
    printf("+--------+---------------------------------+\n");
    printf("+ help   + cmd tips                        +\n");
    printf("+ quit   + exit cmd                        +\n");
    printf("+ hello  + welcome                         +\n");
    printf("+ bigger + bigger of two numbers           +\n");
    printf("+ add    + addition of two numbers         +\n");
    printf("+ sub    + subtraction of two numbers      +\n");
    printf("+ multi  + multiplication of two numbers   +\n");
    printf("+ div    + division of two numbers         +\n");
    printf("+--------+---------------------------------+\n");
}

void quit()
{
    exit(0);
}

void hello()
{
    printf("+-------*--------*--------*--------*-------+\n");
    printf("Hello guy\n");
    
}

void bigger()
{
    double num1,num2,bigger;
    printf("+-------*--------*--------*--------*-------+\n");
    printf("Bigger!\nplease input two numbers:");
    scanf("%lf %lf",&num1,&num2);
    bigger = num1 > num2 ? num1 : num2;
    printf("%lf is bigger than the other\n",bigger);
}

void add()
{
    double num1,num2,add;
    printf("+-------*--------*--------*--------*-------+\n");
    printf("Addition!\nplease input two numbers:");
    scanf("%lf %lf",&num1, &num2);
    add = num1 + num2;
    printf("%lf + %lf = %lf \n",num1, num2, add);
}

void sub()
{
    double num1,num2,sub;
    printf("+-------*--------*--------*--------*-------+\n");
    printf("Subtraction!\n please input two numbers:");
    scanf("%lf %lf",&num1, &num2);
    sub = num1 - num2;
    printf("%lf - %lf = %lf\n",num1, num2, sub);
}

void multi()
{
    double num1,num2,multi;
    printf("+-------*--------*--------*--------*-------+\n");
    printf("Multiplcation!\n please input two numbers:");
    scanf("%lf %lf",&num1, &num2);
    multi = num1 * num2;
    printf("%lf * %lf = %lf\n",num1, num2, multi);
}

void divi()
{
    double num1,num2,div;
    printf("+-------*--------*--------*--------*-------+\n");
    printf("Division!\n please input two numbers:");
    scanf("%lf %lf",&num1, &num2);
    if (num2 == 0)
    {
        printf("Error:divisor can not be zero!\n");
    }
    else
    {
        div = num1 / num2;
        printf("%lf / %lf = %lf\n",num1, num2, div);
    }
}
