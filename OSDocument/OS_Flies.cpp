#include"Head.h"
vector<Root_file> Base_table;
using namespace std;


void File_Creat(Root_file a) {//根目录创建
	
	if (Base_table.size() == 0) {//初始化根目录
		Root_file test;
		test.ID = 0;
		Base_table.push_back(test);
		if (Reuse_file.empty() == 1) {
			Base_table.push_back(a);
		}
		else {
			Base_table[Reuse_file.front()] = a;
			Reuse_file.pop();
		}
	}
	else{
		if (Reuse_file.empty() == 1) {
			Base_table.push_back(a);
		}
		else {
			Base_table[Reuse_file.front()] = a;
			Reuse_file.pop();
		}

	}
}

void File_delete(int id,int s[100]) {//删除文件
	for (int i = 0; i < 100; i++) {
		s[i] = Base_table[id].File_address[i];
		Base_table[id].File_address[i] = 0;
	}
	Reuse_file.push(id);
	//回收磁盘块
	for (int i = 0; i < 100; i++)
	{
		if (s[i] == 0)
			break;
		//callback(s[i]);
		s[i] = 0;
	}
}

void Doc_delete(int id, int s[100]) {//删除文件夹
	for (map<string, int>::iterator it = Base_table[id].Address->Doc.begin(); it < Base_table[id].Address->Doc.end(); it++)
	{
		if (Base_table[it->second].Address == NULL)
		{
			File_delete(id, s);	//问题：函数递归和参数s[100]的冲突，解决在file_delete中嵌入成组连接法的回收
		}
		else
		{
			Doc_delete(id, s);
		}
	}
	delete Base_table[id].Address;
	Base_table[id].Address = NULL;
	Reuse_file.push(id);
}


Files* creat_files(string name, int self, int father, int File_id) {//文件夹建立
	Files* address = new Files;
	address->Doc[name] = File_id;
	address->Self = self;
	address->Father = father;
	return address;
}

void add_files(string Name, int file_id, int id)//添加文件目录
{
	if (Base_table[id].Address->Doc[Name] != 0)
	{
		cout << "当前目录文件名重复";
	}
	else
		Base_table[id].Address->Doc[Name] = file_id;
}



