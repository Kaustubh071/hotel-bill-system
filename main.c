#include <stdio.h>
#include <stdlib.h>

int gtot=0,sst=0,dst=0,tst=0,amount,l,v[9]={200,100,50,20,10,5,2,1},value,i;

void menu()
{
    printf("MENU\n");
    printf("1 Samosa 20\n");
    printf("2 Dosa 30\n");
    printf("3 Tea 10\n");
    printf("0 Exit\n");
}
void cash()
{
     value=amount-gtot;
     printf("Return = %d\n",value);
     for(i=0;i<8;i++)
     {
            if((value/v[i])==0)
            continue;
            if(v[i]>=10)
            printf("%d/- Note X %d= %d/-\n",v[i], value/v[i],(value/v[i])*v[i]);
            else
            printf("%d/- Coin X %d= %d/-\n",v[i], value/v[i],(value/v[i])*v[i]);
            value=value%v[i];
     }
}

void Enter()
{
    printf("Enter your cash: ");
	scanf("%d",&amount);
    if(amount>gtot)
    {
       cash();
    }
    else if(amount<gtot)
    {
        gtot=gtot-amount;
        printf("Please pay %d Rs more\n",gtot);
        Enter();
    }
}

void cupsPlats(int ch)
{
     printf("Enter Number of ");
     if(ch==3)
      printf("Cups\n");
     else
     printf("Plates\n");
}

void order(int rate,int ch)
{
    int qty=0;
    cupsPlats(ch);
    scanf("%d",&qty);
    switch(ch)
    {
    case 1:
         sst+=qty*rate;
        break;
    case 2:
         dst+=qty*rate;
        break;
    case 3:
         tst+=qty*rate;
        break;
    }
}

void bill()
{
printf("::Your Bill::\n");
      printf("\nSr.No.  /Item  /Qty  /Rate  /Sub Total\n");
      printf("-----------------------------------------\n");
      if(sst)
      printf("1       /Samosa/ %d /|20   /%d\n",sst/20,sst);
      if(dst)
      printf("2       /Dosa  / %d  /30    /%d\n",dst/30,dst);
      if(tst)
      printf("3       /Tea   / %d  /10    /%d\n",tst/10,tst);
      printf("-----------------------------------------\n");
      gtot=sst+dst+tst;
      printf("                     Grand Total: %d/-\n",gtot);
}

void userChoice()
{ int ch=0,l=1;
      while(l)
    {
    menu();
    printf("\nEnter your Choice: ");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        printf("Samosa!\n");
        order(20,ch);
        break;
    case 2:
        printf("Dosa!\n");
        order(30,ch);
        break;
    case 3:
        printf("Tea!\n");
         order(10,ch);
        break;
    case 0:
        l=0;
        bill();
        Enter();
        printf("\n\n Thank You Visit Again !\n");
        break;
    default:
        printf("Wrong Input!\n");
        break;
        }
    }
}
int main()
{
    printf("Welcome to Hotel Primz !\n");
    userChoice();
    return 0;
}


