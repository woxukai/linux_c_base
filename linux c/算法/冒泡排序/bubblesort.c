void swap(int *a, int *b); //����������  
  
int main()  
{  
    int     str[10];  
    int     i, j;  
    //��ʼ������Ϊ10 9 8 7 6 5 4 3 2 1  
    for (i = 0; i < 10; i++)  
    {  
        str[i] = 10 - i;  
    }  
    //���򣬴�a[0]��ʼ�ţ���С����  
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
        //��ʮ�������  
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
