#define N 100
typedef int data_t;

typedef struct 
{
	data_t data[N];
	int last; //当前表尾指针
}sqlist_t,*sqlink_t;

