#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>

struct Files
{
	map<string, int> Doc; //文件夹
	int Self; //当前节点
	int Father; //父节点目录
};

struct Root_file //根目录
{
	int ID;
	//其他信息
	string File_name;//文件名称
	string Type; //文件类型
	int Length; //文件大小
	int Limit[7]; //权限
	int File_User; //创建用户

	Files *Address = NULL; //总表位置（文件夹情况）
	int File_address[100]; //文件占用块数
};





struct Block
{
	int n;	//存放空闲块的个数
	int free[50];	//存放空闲块的地址
	int a;	//该块是否被占用
	char content[100];	//每个字节存放的字符
};


struct Block_super
{
	int n=0; //空闲快个数
	int free[50] = {0}; //空闲块地址
};



struct User
{
	string Name; //用户名
	string Pwd; //密码
};
//static User Users[8];


void callback(int num);
void init_super_block(int Free_size, int Memory_size);
int allocate();

//extern int BOOT_i = 0;

void File_Creat(Root_file a);
void Doc_delete(int id);
void File_delete(int id);
Files* creat_files(string name, int self, int father, int File_id);
void add_files(string Name, int file_id, int id);
void empty_root_file(int id);