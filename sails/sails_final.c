#include <stdio.h>
#include <stdlib.h>
#include <math.h>

	double fbW,fbH,sW,sH,overlap,temporary;
	int result,i,finalResult;

	double Aux(double fabric, double sail,double overlap)
{
    if (sail <= fabric)
    {
        return 1;
    }
    
    if(((sail-overlap)/(fabric-overlap)) - 0.00001 < ceil(((sail-overlap)/(fabric-overlap))-1) )
    
    {
        return (int)((sail-overlap)/(fabric-overlap));
    }
    
    return ceil((sail-overlap)/(fabric-overlap));
}


static void Calc()
{
    result = (int)(Aux(fbH, sH, overlap)) * (int)(Aux(fbW, sW, overlap));
    if(finalResult == 0 || (result < finalResult))
    {
        finalResult = result;
    }
}

static int Maxoverlap()
{
    if((fbH<sH && fbW < sW) && (overlap >= fbW || overlap >= fbH))
    {
        return 1;
    }
    else if((fbH<sH && fbW >= sW && overlap >= fbH) ||
            (fbW<sW && fbH >= sH && overlap >= fbW))
    {
        return 1;
    }
    return 0;
}

int main()
{
    printf("Sheet dimensions:\n");
    if ( scanf ( " %lf %lf", &fbW, &fbH ) != 2 || fbW <= 0 || fbH <= 0)
    {
        printf("Invalid input.\n");
        return 0;
    }
    printf("Sail dimensions:\n");
    if ( scanf ( " %lf %lf", &sW, &sH ) != 2 || sW <= 0 || sH <= 0)
    {
        printf("Invalid input.\n");
        return 0;
    }

    if(!(fbW >= sW && fbH >= sH) && !(fbW >= sH && fbH >= sW))
    {
        printf("Overlap:\n");
        if ( scanf ( "%lf", &overlap ) != 1 || overlap < 0)
        {
            printf("Invalid input.\n");
            return 0;
        }
    }
    else{
        result = 1;
        printf("Sheets: %d\n",result);
        return 0;
    }

    
    if(Maxoverlap())
    {
        temporary = fbW;
        fbW = fbH;
        fbH = temporary;
        if(Maxoverlap())
        {
            printf("No solution.\n");
            return 0;
        }
        else
        {
            Calc();
        }
    }
    else
    {
       
        for(i=0;i<2;++i)
        {
            if(i==1 && Maxoverlap())
            {
                break;
            }
            Calc();
            temporary = fbW;
            fbW = fbH;
            fbH = temporary;
        }
    }
    printf("Sheets: %d\n",finalResult);
    return 0;

}
