void swap(int *a, int *b); //交换两个数  
  
int main()  
{  
    int     str[10];  
    int     i, j;  
    //初始化数组为10 9 8 7 6 5 4 3 2 1  
    for (i = 0; i < 10; i++)  
    {  
        str[i] = 10 - i;  
    }  
    //排序，从a[0]开始排，从小到大  
    for (i = 0; i < 10; i++)  
    {  
        for (j = i + 1; j < 10; j++)  
        {  
            if (str[i] > str[j])  
            {  
                swap(&str[i], &str[j]);  
            }  
        }  
    }  
        //将十个数输出  
    for (i = 0; i < 10; i++)  
        printf("%d\n", str[i]);  
    return    0;  
}  
void swap(int *a, int *b)  
{  
    int     c;  
     c = *a;  
    *a = *b;  
    *b =  c;  
}  
