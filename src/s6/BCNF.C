                                  /*3CF AND BCNF*/

#include<stdio.h>
#include<string.h>

int substring(char string[],char sbstr[]);
char att[30],key[30],fds[10][20],left[15],right[15],rattr[30],lattr[30];
int nattr,nfds,found=0;
char key2[15];
	int main()
		{
		int i,j,k;
		printf("3NF & BCNF Checking\n");
		printf("Enter the no of attributes: ");
		scanf("%d",&nattr);
		printf("\nThe attributes are: \n");
		for(i=0;i<nattr;i++)
			{
			att[i]='A'+i;
			printf("%c",att[i]);
			}
		printf("\nEnter the primary key: \n");
		fflush(stdin);
		scanf("%s",key);
		printf("\nEnter the candidate key: \n");
		scanf("%s",key2);
		fflush(stdin);
		printf("\nEnter the no of relations:");
		scanf("%d",&nfds);


		printf("\nEnter the relations: ");
		for(i=0;i<nfds;i++)
		{
		fflush(stdin);
		scanf("%s",fds[i]);
		}
		for(i=0;i<nfds;i++)
		{	
			for(j=0,k=0,found=0;j<strlen(fds[i]);j++)
			{
			if(fds[i][j]=='-')
				{
				left[k]='\0';
				k=0;
				j++;
				found=1;
				}
			else if(found==0)
			left[k++]=fds[i][j];
			else
			right[k++]=fds[i][j];
			}
			right[k]='\0';
			if((substring(left,key)==1))
			printf("%s in BCNF and in 3NF\n",fds[i]);
			else if((substring(key,right)==1)||(substring(key2,right)==1))
				{
				printf("%s in 3NF but not in BCNF\n",fds[i]);
				}
			else
			printf("%s violates 3nf & bcnf\n",fds[i]);
			}
		}
	
		int substring(char str[],char sbstr[])
		{
		int i,j,k;
			for(j=0;j<strlen(sbstr);j++)
			{
			for(k=0;k<strlen(str);k++)
				{
				if(sbstr[j]==str[k])
				break;
			}
	
		if(k==strlen(str))
		return 0;
		}
		return 1;
		}


		/* OUTPUT

3NF & BCNF Checking
Enter the no of attributes: 5

The attributes are: 
ABCDE
Enter the primary key: 
a

Enter the candidate key: 
b

Enter the no of relations:4

Enter the relations: a->b
b->c
c->a
d->c
a->b in BCNF and in 3NF
b->c violates 3nf & bcnf
c->a in 3NF but not in BCNF
d->c violates 3nf & bcnf

 */
