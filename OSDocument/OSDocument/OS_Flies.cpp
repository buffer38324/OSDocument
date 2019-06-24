using namespace std;
#include"Head.h"

extern queue<int> Reuse_file;
extern Block Memory[500];
extern vector<Root_file> Base_table;

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

void File_delete(int id) {//删除文件
	int s[100];
	for (int i = 0; i < 100; i++) {
		s[i] = Base_table[id].File_address[i];
		Base_table[id].File_address[i] = 0;
	}
	Reuse_file.push(id);
	empty_root_file(id);
	//回收磁盘块
	for (int i = 0; i < 100; i++)
	{
		if (s[i] == 0)
			break;
		//callback(s[i]);
		s[i] = 0;
	}
}

void Doc_delete(int id) {//删除文件夹
	empty_root_file(id);
	for (map<string, int>::iterator it = Base_table[id].Address->Doc.begin(); it != Base_table[id].Address->Doc.end(); it++)
	{
		if (Base_table[it->second].Address == NULL)
		{
			File_delete(it->second);	//问题：函数递归和参数s[100]的冲突，解决在file_delete中嵌入成组连接法的回收
		}
		else
		{
			Doc_delete(it->second);
		}
	}
	delete Base_table[id].Address;
	Base_table[id].Address = NULL;
	Reuse_file.push(id);
}

//过
Files* creat_files(string name, int self, int father, int File_id) {//文件夹建立
	Files* address = new Files;
	address->Doc[name] = File_id;
	address->Self = self;
	address->Father = father;
	return address;
}

//没测
void add_files(string Name, int file_id, int id)//添加文件目录
{
	if (Base_table[id].Address->Doc[Name] != 0)
	{
		cout << "当前目录文件名重复";
	}
	else
		Base_table[id].Address->Doc[Name] = file_id;
}

void empty_root_file(int id)
{
	//其他信息
	Base_table[id].File_name = "已回收";//文件名称
	Base_table[id].Type = ""; //文件类型
	Base_table[id].Length = 0; //文件大小
	Base_table[id].Limit[7] = { 0 }; //权限
	Base_table[id].File_User = 0; //创建用户
}

