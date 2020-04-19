#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
int input_check()
{
	int v,init;
	while(1)
	{
		printf("输入有效值：");
		v = scanf("%d",&init);
		if(v==1)
		{
			return init;
			break;			
		}
		else
		{
			printf("给出数字！\n"); 
			while(1)
			{
				char c = getchar();
				if(c == '\n')
					break;
			}			
		}
	}
}

char check()
{
    char c, flag;
    int i;
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i)
            ;
        if(i == 1){
            if('0'<=flag && flag<='9'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        printf("请输入有效数字：");
    }
    return '\0';
}

void print_arry(int *arr,int n)
{
	int i;
	for(i = 0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void pri()
{
	printf("\n***********************WELCOME TO USE***************************");
	printf("\n                ||-----------1 : insertSort------------||\n");      
	printf("                ||-----------2 : MergeSort()-----------||\n");
	printf("                ||-----------3 : QuickSort_Recursion---||\n");
	printf("                ||-----------5 : CountSort-------------||\n");
	printf("                ||-----------6 : RadixCountSort--------||\n");
	printf("                ||-----------7 : ColorSort-------------||\n");
	printf("                ||-----------0 : exit------------------||\n");
	printf("会打印最后一次测试结果,多次测试时会从数据库里多次获得数据，数据量大的时候请耐心等待\n"); 
	printf("假数据库在D:\\a.txt\n");
}

int creat_data(int *a,int size){
	FILE *fp;
	srand((unsigned)time(NULL));
	int i;
	fp=fopen("D:\\a.txt","w");
	for(i = 0; i < size; ++i){
		a[i] = rand() % 30000;
	}
	for (i = 0; i < size; i++) {
	fprintf(fp,"%d\n",a[i]);
	}
	fclose(fp);
}

int creat_data_012(int *a,int size){
	FILE *fp;
	srand((unsigned)time(NULL));
	int i;
	fp=fopen("D:\\a012.txt","w");
	for(i = 0; i < size; ++i){
		a[i] = rand() % 3+0;
	}
	for (i = 0; i < size; i++) {
		fprintf(fp,"%d\n",a[i]);
	}
	fclose(fp);
}

int visit_data_012(int *a,int size){
	int i;
	FILE *fp;
	fp=fopen("D:\\a012.txt","r");
	for (i = 0; i < size; i++) {
	fscanf(fp,"%d",&a[i]);
	}
	fclose(fp);
}

int visit_data(int *a,int size){
	int i;
	FILE *fp;
	fp=fopen("D:\\a.txt","r");
	for (i = 0; i < size; i++) {
	fscanf(fp,"%d",&a[i]);
	}
	fclose(fp);
}

int main() {
	int size,i,n;
	printf ("待排序数组的大小 size=\n");
	size = input_check();
	int *sorted_data = (int *)malloc(sizeof(int) * size);
	int *data = (int *)malloc(sizeof(int) * size);
	creat_data(data,size);
	pri();
	while(1)
	{
		printf("Please give the number to continue:\n");
		switch(n = check())
		{	
			case '1':
					system("cls");
					pri();
					printf("你想测试几次？\n");
					n = input_check();
					start = clock();
					for(i=0;i<n;i++){
						visit_data(data,size);
						insertSort(data,size);
						printf("%d-----------------%d",i+1);
					}
				    stop = clock();
    				diff = (double)(stop - start)/1;
					printf("用时:%f(μs)\n",diff);
					print_arry(data,size);
					break;	
			case '2':
					system("cls");
					pri();
					visit_data(data,size);
					n = input_check();
					start = clock();
					for(i=0;i<n;i++){
						visit_data(data,size);
						MergeSort(data,0,size-1,sorted_data);
						printf("%d-----------------%d",i+1);
					}
				    stop = clock();
    				diff = (double)(stop - start)/1;
					printf("用时:%f(μs)\n",diff);
					print_arry(sorted_data,size);
					break;
			case '3':
					system("cls");
					pri();
					visit_data(data,size);
					n = input_check();
					start = clock();
					for(i=0;i<n;i++){
						visit_data(data,size);
						QuickSort_Recursion(data,0,size-1);
						printf("%d-----------------%d",i+1);
					}
				    stop = clock();
    				diff = (double)(stop - start)/1;
					printf("用时:%f(μs)\n",diff);
					print_arry(data,size);
					break;
			case '4':
					system("cls");
					pri();
					break;
			case '5':
					system("cls");
					pri();
					n = input_check();
					start = clock();
					for(i=0;i<n;i++){
						visit_data(data,size);
						CountSort(data,size,sorted_data);
					}
				    stop = clock();
    				diff = (double)(stop - start)/1;
					printf("用时:%f(μs)\n",diff);
					print_arry(sorted_data,size);
					break;
			case '6':
					system("cls");
					pri();
					visit_data(data,size);
					n = input_check();
					start = clock();
					for(i=0;i<n;i++){
						visit_data(data,size);
						RadixCountSort(data,size);
					}
				    stop = clock();
    				diff = (double)(stop - start)/1;
					printf("用时:%f(μs)\n",diff);
					print_arry(data,size);
					break;
			case '7':
					system("cls");
					pri();
					visit_data_012(data,size);
					n = input_check();
					start = clock();
					for(i=0;i<n;i++){
						visit_data(data,size);
						ColorSort(data,size);
					}
				    stop = clock();
    				diff = (double)(stop - start)/1;
					printf("用时:%f(μs)\n",diff);
					print_arry(data,size);
					break;
			case '8':
					system("cls");
					pri();
					break;
			case '9':
					system("cls");
					pri();
					break;					
			case '0':
					printf("\n*******************谢谢使用！*******************\n");
					Sleep(2000);
					return 0;
		}
	}
	return 0;
}
