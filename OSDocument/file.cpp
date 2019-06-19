#include "head.h"

using namespace std;

Files* create_files(string Name, int self, int father, int file_id)
{
	Files* address = new Files;
	address->Doc[Name] = file_id;
	address->Self = self;
	address->Father = father;
	return address;
}

void add_files(string Name, int file_id, int id)
{
	if (Base_table[id].Address->Doc[Name] != 0)
	{
		cout << "当前目录文件名重复";
	}
	else
		Base_table[id].Address->Doc[Name] = file_id;
}