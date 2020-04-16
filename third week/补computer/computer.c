#include"computer.h"

void InitStack(SqStack *S)
{
	S->base=(Elemtype*)malloc(sizeof(Elemtype)*INITSIZE);
	assert(S->base !=NULL);
	S->top=S->base;
	S->size=INITSIZE;
}

void PushStack(SqStack *S,Elemtype c)
{
	if(S->top - S->base >= S->size)
	{
		S->base=(Elemtype*)realloc(S->base,sizeof(Elemtype)*(S->size+INCREMENT));
		assert(S->base !=NULL);
		S->top =S->base+S->size;
		S->size+=INCREMENT;
	}
	*S->top++ = c;
}

int StackLength(SqStack *S)
{
	return (S->top - S->base);
}
int PopStack(SqStack *S,Elemtype *c)
{
	if(!StackLength(S))
	{
		return 0;
	}
	*c=*--S->top;
	return 1;
}

void Change(SqStack *S,Elemtype str[],Elemtype cpy[],int data[])
{
	int i=0,j=0;
	char e;
	char change[15] = {'\0'}; 
	char a[2] = {'0','\0'};
	InitStack(S);
	while(str[i]!='\0')
	{
		while(isdigit(str[i]))	//数字直接输出
		{
			a[0] = str[i++];
			strcat(cpy,a);
			strcat(change,a);
		//	printf("%c",str[i++]);
			if(!isdigit(str[i]))
			{
				data[j] = atoi(change);
				change[0] = '\0';
				j++;
				break;
				//printf(" ");
			}
		}
		if(str[i]=='+'||str[i]=='-')
		{
			if(!StackLength(S))
			{
				PushStack(S,str[i]);
			}
			else
			{
				do
				{
					PopStack(S,&e);
					if(e=='(')		//	直接入栈 
					{
						PushStack(S,e);
					}
					else
					{
						a[0] = e;
						strcat(cpy,a);	
				//		printf("%c ",e);
					}
				}while( StackLength(S) && e != '(' );
				
				PushStack(S,str[i]);
			}
		}
		
		else if(str[i]==')')
		{
			PopStack(S,&e);
			while(e!='(')	//一直出栈知道遇到左括号 
			{ 
				a[0] = e;
				strcat(cpy,a);
			//	printf("%c ",e);
				PopStack(S,&e);
			}
		}
		
		else if(str[i]=='*'||str[i]=='/'||str[i]=='(')
		{
			PushStack(S,str[i]);
		}
		
		else if(str[i]=='\0')
		{
			break;
		}
		
		else
		{
			printf("\n请用英文输入，只支持+-*/整数运算！\n");
			return ;
		}
		i++;
	}
	
	while(StackLength(S))
	{
		PopStack(S,&e);
	//	printf("%c ",e);
		a[0] = e;
		strcat(cpy,a);		
	}
}

int calculate(Elemtype cpy[],int data[]){
	int i=0,res,k;
	while(cpy[i] != '\0'){
		if(cpy[i]=='+'){
			res = data[0] + data[1];
			data[0] = res;
			for(k=1;k<8;k++){
				data[k]	= data[k+1];
			}
		}
		else if(cpy[i]=='-'){
			res = data[0] - data[1];
			data[0] = res;
			for(k=1;k<8;k++){
				data[0]	= data[1];
			}
		}
		else if(cpy[i]=='*'){
			res = data[0] * data[1];
			data[0] = res;
			for(k=1;k<8;k++){
				data[k]	= data[k+1];
			}
		}
		else if(cpy[i]=='/'){
			res = data[0] / data[1];
			data[0] = res;
			for(k=1;k<8;k++){
				data[k]	= data[k+1];
			}
		}
		i++;
	}
	printf("结果是：%d",data[0]);
} 
