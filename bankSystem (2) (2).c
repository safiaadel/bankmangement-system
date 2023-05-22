#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void menu(void);
void newaccount(int n);
void Search(void);
void transact(void);
unsigned int i=0;
int j=0;
char name[1000][100];
char birthday[1000][15];
long long int citizenship [1000];
char address[1000][100];
long long int phone [1000];
long long int deposit [1000];
long long int transaction[1000][100];
char date[1000][100];
int count[1000]= {0};
char type[1000][20];
void ViewList(void);
int ID[1000];
void see(void);
void edit(void);
void Erase(void);
int main_exit;

int main()
{
    puts("\n \n \n");
    puts("\t\t\t\t\t WELCOME IN BANK MANAGEMENT SYSTEM \n");

    menu();

    printf("\n \t\t\t\t Enter 1 to return to menu and 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");

    if (main_exit == 1)

        main();

    else if (main_exit == 0)

        system("cls");

    return 0;
}
void newaccount(int i)
{

    printf("\n\n\t\t\t Enter your name : \t\t");
    scanf(" %s[^\n]",&name[i]);
    puts("");

    printf ("\t\t\t Enter the  number of account : \t\t");
    scanf("%lld",&ID[i]);
    puts("");

    printf ("\t\t\t Enter the address : \t\t");
    scanf(" %s[^\n]",&address[i]);
    puts("");

    printf ("\t\t\t Enter the birthday : \t\t");
    scanf("%s",&birthday[i]);
    puts("");

    printf ("\t\t\t Enter the citizenship : \t\t");
    scanf("%s",&citizenship[i]);
    puts("");

    printf ("\t\t\t Enter the  phone number : \t\t");
    scanf("%lld",&phone[i]);
    puts("");

    printf ("\t\t\t Enter the  deposit : \t\t");
    scanf("%lld",&deposit[i]);
    transaction[i][0]=deposit[i];
    count[i]++;
    puts("");

    printf("\t\t\t choose 1.saving  2.investment  3.current : \t\t");
    scanf("%s",&type[i]);
    puts("");
    printf("\t\t\t\t\t your Account created successfully \n\n\n");


}

void Search(void)
{
    int z=1;
    char search[100];
    printf("\n\n\t\t\t Enter the name you want to search on : \t\t");
    scanf(" %[^\n]",search);
    puts("\n");
    for(j=0; j<1000; j++)
    {
        if(strcmp(search, name[j])==0)
        {
            printf("\t\t\t name : %s\n \t\t\t Birthday : %s \n \t\t\t citizenship : %lld \n",name[j],birthday[j],citizenship[j]);
            printf("\t\t\t Address : %s \n \t\t\t phone number : %lld \n \t\t\t Deposit : %lld \n \t\t\t Type of deposit : %s \n",address[j],phone[j],deposit[j],type[j]);
            z=0;
            break;
        }
    }
    if (z==1)
        printf("\t\t\t\t this Account not exict \n");


}



void see(void)
{
    int s;
    printf("\n\n\t\t\t Enter the Account number : \t\t");
    scanf("%d",&s);
    puts("\n");
    s=s-1;
    printf("\t\t\t name : %s \n \t\t\t Birthday : %s \n \t\t\t citizenship : %lld \n",name[s],birthday[s],citizenship[s]);
    printf("\t\t\t Address : %s \n \t\t\t phone number : %lld \n \t\t\t Deposit : %lld \n \t\t\t Type of deposit : %s \n",address[s],phone[s],deposit[s],type[s]);



}
void ViewList(void)
{
    int j=0;
    for(j=0; j<i; j++)
    {
        printf("\n\n\t\t\t Customer name : %s\n \t\t\t Birthday : %s \n \t\t\t citizenship : %lld \n",name[j],birthday[j],citizenship[j]);
        printf("\t\t\t Address : %s \n \t\t\t phone number : %lld \n \t\t\t deposit : %lld \n \t\t\t Type of deposit : %s \n",address[j],phone[j],deposit[j],type[j]);
        printf("\t\t\t--------------------------------------------------\n");
    }
}
/*
void Erase(void){
       int position;
       printf("\t\t\t Enter the number of Account you want to delete : \t\t ");
       scanf("%d",position);

        // if(position < 0 || position > i)
    //{
      //  printf("Invalid Account Please enter position between 1 to %d", size);
    //}
    //else
    //{
        for(j=position; j<=i; j++)
        {
           strcpy( name[j] , name[j+1]);

           strcpy(birthday[j], birthday[j+1]);
            citizenship [j]= citizenship [j+1];
            strcpy(address[j], address[j+1]);
            phone [j] =phone [j+1];
            deposit [j] =deposit [j+1];
        strcpy (type[j],type[j+1]);
        }
           i--;






}
*/


void Erase(void)
{
    long int number;
    int j,y=0;
    printf("Enter the account number:\n");
    scanf("%ld", &number);
    for (j = 0; j < 100; j++)
    {
        if (number == ID[j])
        {
            system("cls");
            strncpy(name[j],"0",100),strncpy(birthday[j],"0",100),strncpy(address[j],"0",100),phone[j]=0,citizenship[j]=0,ID[j]=0,deposit[j]=0,strncpy(type[j],"0",20);
            printf("this Account has been deleted\n");
            y=1;
            break;
        }
    }
    if (y==0)
    {
        system("cls");
        printf("There is no account with this account number");

    }
}


void edit(void)
{
    char search[100];
    int x,z=1;
    printf("\n\n\t\t\t\t Enter the name of the account : \t");
    scanf("%s",search);

    for(j=0; j<1000; j++)
    {
        if(strcmp(search, name[j])==0)
        {
            z=0;
            printf("\n \t\t\t choose what you want to edit : \n\t\t\t(1)phone number \n \t\t\t(2) address \n \t\t\t(3) both ");
            scanf("%d",&x);
            if(x==1)
            {
                printf("\t\t\t The phone number you wanted to edit is %lld \n", phone[j]);
                printf("\t\t\t please enter the edieted phone number : \t");
                scanf("%lld",&phone[j]);
            }
            else if(x==2)
            {
                printf("\t\t\t The address you want to edit is %s \n",address[j]);
                printf("\t\t\t please enter the edited address : \t");
                scanf("%s",&address[j]);

            }
            else if(x==3)
            {
                printf("\t\t\t The phone number you wanted to edit is %lld\n", phone[j]);
                printf("\t\t\t please enter the edieted phone number : \t");
                scanf("%lld",& phone[j]);
                printf("\n \t\t\tThe address you want to edit is %s\n",address[j]);
                printf("\t\t\t please enter the edited address : \t");
                scanf("%s",&address[j]);

            }
        }
    }
    if (z==1)
        printf("\t\t\t\t this Account not exict \n");
}



/*
void edit(void){
  printf("enter the name of the account\n");
      char search[100];
    scanf("%s",search);
    for(i=0;i<1000;i++){
        if(strcmp(search, name[i])==0){
      int x;
      printf("please enter a number to edit...(1) to edit the phone number , (2) to edit the address and (3) to edit both ");
scanf("%d",&x);
if(x==1){
      printf("The phone number you wanted to edit is %lld\n", phone[i]);
      printf("please enter the edieted phone number \n");
      scanf("%lld",& phone[i]);
     printf("%lld\n", phone[i]);
}else if(x==2){
    printf("The address you want to edit is %s\n",address[i]);
    printf("please enter the edited address \n");
    scanf("%s",&address[i]);
  printf("%s\n",address[i]);
}else if(x==3){
    printf("The phone number you wanted to edit is %lld\n", phone[i]);
      printf("please enter the edieted phone number \n");
      scanf("%lld",& phone[i]);
     printf("%lld\n", phone[i]);

      printf("The address you want to edit is %s\n",address[i]);
    printf("please enter the edited address \n");
    scanf("%s",&address[i]);
  printf("%s\n",address[i]);

}
        }
        else printf("this Account not exict \n");
        break;
        }}


*/
void Sort (void)
{
    char name1[1000][100];
    char birthday1[1000][100];
    long long int citizenship1 [1000];
    char address1[1000][100];
    long long int phone1 [1000];
    long long int deposit1 [1000];
    char type1[1000][100];
    char temp1[100];
    char temp2[100];
    long long int temp3;
    char temp4[100];
    int temp5;
    int temp6;
    char temp7[100];
    char temp8[100];
    int z;
    for (z=0; z<100; z++)
    {
        strcpy(name1[z],name[z]);
        strcpy(birthday1[z],birthday[z]);
        strcpy(address1[z],address[z]);
        strcpy(type1[z],type[z]);
        citizenship1[z]=citizenship[z];
        phone1[z]=phone[z];
        deposit1[z]=deposit[z];

    }

    for (int x=0; x<i; x++)
    {
        for(int y=x+1; y<i; y++)
        {
            if(strcmp(name1[x],name1[y]) >0)
            {
                strcpy(temp1,name1[x]);
                strcpy(name1[x],name1[y]);
                strcpy(name1[y],temp1);
                //------------//
                strcpy(temp2,birthday1[x]);
                strcpy(birthday1[x],birthday1[y]);
                strcpy(birthday1[y],temp2);
                //----------------//
                temp3 = citizenship1[x];
                citizenship1[x]=citizenship1[y];
                citizenship1[y]=temp3;
                //-----------//
                strcpy(temp4,address1[x]);
                strcpy(address1[x],address1[y]);
                strcpy(address1[y],temp4);
                //-------------//
                temp5=phone1[x];
                phone1[x]=phone1[y];
                phone1[y]=temp5;
                //-----------//
                temp6=deposit1[x];
                deposit1[x]=deposit1[y];
                deposit1[y]=temp6;
                //-----------//
                strcpy(temp7,type1[x]);
                strcpy(type1[x],type1[y]);
                strcpy(type1[y],temp7);

            }
        }

    }

    for(z=0; z<i; z++)
    {
        printf("\n\n\t\t\t Customer name : %s\n \t\t\t Birthday : %s \n \t\t\t citizenship : %lld \n",name1[z],birthday1[z],citizenship1[z]);
        printf("\t\t\t Address : %s \n \t\t\t phone number : %lld \n \t\t\t deposit : %lld \n \t\t\t Type of deposit : %s \n",address1[z],phone1[z],deposit1[z],type1[z]);
        printf("\t\t\t--------------------------------------------------\n");

    }
}








void menu(void)
{
    int x;
    printf("\t\t\tchoose what you want to do ? \n\n");
    printf("\t\t\t 1.Add Account  \n \t\t\t 2.view list \n \t\t\t 3.Edit \n \t\t\t 4.transact \n");
    printf("\t\t\t 5.Erase \n \t\t\t 6.See \n \t\t\t 7.Search \n \t\t\t 8.Sort \n");
    scanf("%d",&x);
    system("cls");
    switch(x)
    {
    case 1 :
        newaccount(i);
        i++;
        break;
    case 2 :
        ViewList();
        break;
    case 3 :
        edit();
        break;
    case 4 :
        transact();
        break;
    case 5 :
        Erase();
        break;
    case 6 :
        see();
        break;
    case 7 :
        Search();
        break;
    case 8 :
Sort:
        break;

    }
}
void transact(void)
{
    int d;
    int x;
    int a;
    long long int f;
    //  printf("please enter the date:");
    //scanf("\n%s",date[i]);
    printf("which account do you want to deposite or withdraw on it please enter your ID:");
    scanf("%d",&d);
    //count[x]++;
    for(x=0; x<i; x++)
    {
        if(d==ID[x])
        {
            printf("do you wont to deposite enter '1'or you wont to withdarw enter '2':");
            scanf("%d",&a);
            printf("please enter the amount of money do you wont to deposite or withdraw:");
            scanf("%lld",&f);
            if(a==1)
            {
                transaction[x][count[x]]= (transaction[x][count[x]-1])+f;
                printf("%lld",transaction[x][count[x]]);
                count[x]++;

            }
            else if(a==2)
            {
                transaction[x][count[x]]= (transaction[x][count[x]-1])-f;
                printf("%lld",transaction[x][count[x]]);
                count[x]++;
            }

        }

    }


}

