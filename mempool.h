#pragma once
#include"memblocklist.h"

class MemPool{
private:
	void *pbuf;
	int isize;
private:
	int iusedsize;
	int itotalsize;
private:
	int iunitcount;
	MemUnit *punit;
	void *pmem;
	int imemcount;
	MemBlockList blockpool;
	MemBlockList freeblock;
public:
	MemPool(void *mem,int size);
	void *getMem(size_t size);
	void freeMem(void *mem);
public:
	void test()
	{
		printf("...........................\n");
		printf("itotalsize:%d,iunitcount:%d,imemcount:%d\n",this->itotalsize,this->iunitcount,this->imemcount);
		this->blockpool.test();
		this->freeblock.test();
		printf("...........................\n");
	}
};