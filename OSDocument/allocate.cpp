#include "head.h"

using namespace std;

/* 超级块结构
n:	5
free[50]:	
[0]	1
[1] 5
[2] 86
[3] 12
[4] 9
[5...49] -1
*/

void callback(int num)
{
	Memory[num].a = 0;	//占用块->空闲块
	if (Super_block.n != 50)	//50 = Free_size
	{
		Super_block.free[Super_block.n++] = num;
	}
	else
	{
		for (int i = 0; i < 50; i++)
		{
			Memory[num].free[i] = Super_block.free[i];
			Super_block.free[i] = -1;
		}
		Super_block.free[0] = num;
		Super_block.n = 1;
	}
}

void init_super_block(int Free_size, int Memory_size)
{
	Super_block.n = 0;
	for(int i = 0; i < Free_size; i++)
		Super_block.free[i] = -1;
	for (int i = 1; i <= Memory_size; i++)
		callback(i);
}

int allocate()
{
	if (Super_block.n == 0)
	{
		cout << "没有空闲块，分配失败";
		//exit(0);
	}
	else
	{
		int result = Super_block.free[Super_block.n - 1];
		Super_block.free[--Super_block.n] = -1;
		if (Super_block.n == 0)
		{
			Super_block.n = Memory[result].n;
			for (int i = 0; i < 50; i++)
			{
				Super_block.free[i] = Memory[result].free[i];
			}
		}
		Memory[result].a = 1;	//1表示占用
		return result;
	}
}