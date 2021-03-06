/*1002 phone-number question*/

#include <stdio.h>
#include <string.h>

char a[15];
int time = 0;
struct phone{
	int value;
	char number[8];
};
struct phone library[100000];
struct phone use[2];

int get_n(char *a);
void deal_input(char *a);
void check_same(int Nu);
void check_order(int n);


int main(void){

	int n,i;
	int q=0;
	
	while(scanf("%s",a) != EOF)
	{
		if(strlen(a) <= 6)
			n=get_n(a);
		else{
			deal_input(a);
			for(i=0;i<strlen(a);i++)
				a[i]=0;
		}
	}

	for(i=0;i<n;i++)
	{
		check_same(i);
	}

	check_order(n);

	for(i=0;i<n;i++)
	{
		if((library[i].value == -1) || (library[i].value == 1))
			continue;
		else
		{
			printf("%s %d\n",library[i].number,library[i].value);
			q=1;
		}
	}

	if(q == 0)
		printf("No duplicates.\n");
return 0;
}

int get_n(char *a){
	int i,j,n=0;
	for(i=strlen(a)-1,j=0;i>=0;i--,j++)
		{
			int l,k=1;
			if(j == 0)
				k =1;
			else
				for(l=0;l<j;l++)
					k *=10;

			n += (a[i]-48)*k;		
		}
return n;
}

void deal_input(char *a){

	int n=0;
	int i,j;

	for(i=0,j=0;i<strlen(a);i++,j++)
	{
		if(a[i] == '-')
		{
			j = j-1;
			continue;
		}
		switch (a[i]){
			case 'A':case 'B':case 'C':a[i] = '2';break;
			case 'D':case 'E':case 'F':a[i] = '3';break;
			case 'G':case 'H':case 'I':a[i] = '4';break;
			case 'J':case 'K':case 'L':a[i] = '5';break;
			case 'M':case 'N':case 'O':a[i] = '6';break;
			case 'P':case 'R':case 'S':a[i] = '7';break;
			case 'T':case 'U':case 'V':a[i] = '8';break;
			case 'W':case 'X':case 'Y':a[i] = '9';break;
		}
		library[time].number[j] = a[i];			
	}
	library[time].value = 1;                            /*every used element's value equal 1*/
	time += 1;
return;
}

void check_same(int Nu){

	int i,j;
	for(i=0;i<Nu;i++)
	{
		 j=0;
		 while((library[Nu].number[j] == library[i].number[j])&&(j<7))
		 {
		 	j++;
		 }
		 	
		 if((j == 7) && (library[i].value != -1))
		 {
		 	library[Nu].value += library[i].value;
		 	library[i].value = -1;		 	
		 }
	}
return;	
}

void check_order(int n){
	int i,j;

	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			if(library[i].number[0]>library[i+1].number[0])
			{
				use[0]=library[i];
				library[i]=library[i+1];
				library[i+1]=use[0];
			}
		}
	}
return;	
}