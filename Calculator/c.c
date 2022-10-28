#include <stdio.h>
#include <math.h>
int main()
{
   char opr;
   double num1,num2;

   printf("Type formula: (num (operator) num )\n");
   scanf(" %lf %c %lf",&num1 ,&opr ,&num2 );

   if ( num1 > 0 && num1 < 1 && num2 > 0 && num2 < 1){
   switch(opr)
   {
   	case '+':
   		printf("%lf\n",(num1+num2));
   		break;
   	case '-':
   		printf("%lf\n",(num1-num2));
   		break;
   	case '*':
   		printf("%lf\n",(num1*num2));
   		break;
   	case '/':
   		printf("%lf\n",(num1/num2));
   		break;
   	default:
   		printf("Invalid input.");
   }
   }
   else

   switch(opr)
   {
   	case '+':
   		printf("%lg\n",num1+num2);
   		break;
   	case '-':
   		printf("%lg\n",num1-num2);
   		break;
   	case '*':
   		printf("%lg\n",num1*num2);
   		break;
   	case '/':
   		printf("%.1lg\n",num1/num2);
   		break;
   	default:
   		printf("Invalid input.");
   }


   return 0;
}
