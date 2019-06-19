#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>

struct Root_file //根目录
{
	int ID;
	//其他信息
	string Name; //文件名字
	string Type; //文件类型
	int Length; //文件大小
	int Limit[7]; //权限
	int File_User; //创建用户

	Files* Address = NULL; //总表位置（文件夹情况）
	int File_address[100]; //文件占用块数
};

extern vector<Root_file> Base_table;

struct Files
{
	map<string, int> Doc; //文件夹
	int Self; //当前节点
	int Father; //父节点目录
};

struct Block
{
	int n;	//存放空闲块的个数
	int free[50];	//存放空闲块的地址
	int a;	//该块是否被占用
	char content[100];	//每个字节存放的字符
};
extern Block Memory[500];

struct Block_super
{
	int n; //空闲快个数
	int free[50]; //空闲块地址
};
extern Block_super Super_block;

struct User
{
	string Name; //用户名
	string Pwd; //密码
};
extern User Users[8];

void callback(int num);
void init_super_block(int Free_size, int Memory_size);
int allocate();
