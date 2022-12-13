#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

void  Longest_Prefix_Suffix(char *keyword,int keyword_length,int *pi);
void Pattern_Search_Kmp(char *text,char *keyword);
int main()
{
 char text[10001],keyword[10001];
 printf("Enter Text:");
 scanf("%[^\n]s",text);
 getchar();
 printf("Enter a keyword you want to search in Text:");
 scanf("%[^\n]s",keyword);
 Pattern_Search_Kmp(text,keyword);
 return 0;
}
void Pattern_Search_Kmp(char *text,char *keyword)
{
 HANDLE colors=GetStdHandle(STD_OUTPUT_HANDLE);	
 int text_length=0,keyword_length=0,counter=0,i=0,j=0;
 text_length=strlen(text);
 keyword_length=strlen(keyword);
 int pi[keyword_length];
 int index_position[text_length+1];
 Longest_Prefix_Suffix(keyword,keyword_length,pi);
  for(i=0;i<text_length+1;i++)
  {
     index_position[i]=0;
  }
  i=0;j=0;
  while(i<text_length)
  {
  	if(i<text_length && text[i]!=keyword[j])
  	{
  		if(j==0)
  		{
  			i+=1;
		}
		else if(j!=0)
		{
			j=pi[j-1];
		}
	}
	 if(text[i]==keyword[j])
	{
		i++;j++;
	}
	 if(j==keyword_length)
	{
		index_position[i-j]++;
		printf("%d) keyword is Found at Index Position %d\n",++counter,(i-j));
		j=pi[j-1];
	}
  }
  if(counter==0)
  {
  	printf("%s Keyword is Not Found in below text\n",keyword);
  }
  else
  {
  	printf("Keyword is Found at %d positions\n",counter);
  }
  	int length=0,flag=0;   // Visualization
    for(i=0;i<text_length;i++)
    {
        if(index_position[i]>0)
        {
        	SetConsoleTextAttribute(colors,6);
            printf("%c",text[i]);
            flag=1;
        }
        else
        {
            if(flag==1)
            {
              SetConsoleTextAttribute(colors,6);
              printf("%c",text[i]);
            }
            else
            {
              SetConsoleTextAttribute(colors,7);
              printf("%c",text[i]);  
            }
        }
        
        if(flag==1)
        {
            length++;
        }
        
        if(length==keyword_length)
        {
            flag=0;
            length=0;
        }
    }
    SetConsoleTextAttribute(colors,7);
}

void  Longest_Prefix_Suffix(char *keyword,int keyword_length,int *pi)
{
	int length=0,i=1;
	pi[0]=0;
	while(i<keyword_length)
	{
		if(keyword[i]!=keyword[length])
		{
			if(length==0)
			{
				pi[i]=0;
				i++;
			}
			else 
			{
				length=pi[length-1];
			}
		}
		else if(keyword[i]==keyword[length])
		{
			length++;
			keyword[i]=length;
			i++;			
		}
	}
}
