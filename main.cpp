#include"memblocklist.h"
#include"memunit.h"
#include"mempool.h"
#include<stdio.h>

char *get(MemPool *object,int size)
{
	char *a = (char*)object->getMem(size);
	int i;
	for(i = 0;i < 64;++ i)
	{
		printf("%c,",a[i]);
	}
	printf("\n");
	object->test();
	return a;
}

int main()
{
	MemPool *m = MemPool::getInstance();
	m->test();
	char *a = get(m,64);
	char *b = get(m,64);
	m->freeMem(b);
	m->test();
	m->freeMem(a);
	m->test();
	get(m,120);
	getchar();
	return 0;
}
