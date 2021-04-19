#include <stdio.h>
#include <stdlib.h>
struct stu
{
    float a,b,c,d;
};
float change(float num)
{
    int f1=(int)(num*1000)%10;
    return (float)((int)(num*1000-(float)f1))/1000;
}
int main()
{
    int T,done=0;
    //scanf("%d",&T);
    while(~scanf("%d",&T))
    {

        if(T==0)
        {
            break;
        }
        else
        {
            if(done){
            puts("");
        }else{
        done++;
        }
            struct stu list[T];
            for(int t=0; t<T; t++)
            {
                float aa,bb,cc;
                scanf("%f%f%f",&aa,&bb,&cc);
                list[t].a=aa;
                list[t].b=bb;
                list[t].c=cc;
                list[t].d=0.1*aa+0.3*bb+0.6*cc;
            }
            printf("%s\n%s\n%s\n",
                   "==================================================",
                   "Index   Attendance   Practice   Exam   Final Score",
                   "==================================================");
            float max[4];
            for(int i=0; i<4; i++)
            {
                max[i]=0;
            }
            for(int t=0; t<T; t++)
            {
                printf("%05d%13.f%11.f%7.f%14.2f\n",t+1,list[t].a,list[t].b,list[t].c,list[t].d);
                max[0]+=list[t].a;
                max[1]+=list[t].b;
                max[2]+=list[t].c;
                max[3]+=list[t].d;
            }
            printf("%s\n%-5s%13.2f%11.2f%7.2f%14.2f\n%s\n",
                   "==================================================",
                   "Mean",change(max[0]/T),change(max[1]/T),change(max[2]/T),change(max[3]/T),
                   "=================================================="
                  );
        }
    }
    return 0;
}
