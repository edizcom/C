#include <stdio.h>

int main()
{
      int x;
      int y;
      int z;
      char ch;

      printf("Type color in RGB format:\n");
      printf("Format: rgb ( r , g , b ) :");
      int ret = scanf(" rgb ( %d , %d , %d %c",&x , &y , &z, &ch);


      if
         (x < 0 || x > 255   ||
          y < 0 || y > 255   ||
          z < 0 || z > 255   ||
          ret != 4)
	{
      printf("Invalid input.\n");

  }
   else
 		{
      printf("#%02X%02X%02X\n", x, y, z);
  }

      return 0;
}

