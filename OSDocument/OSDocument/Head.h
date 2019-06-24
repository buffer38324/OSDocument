#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>

struct Files
{
	map<string, int> Doc; //�ļ���
	int Self; //��ǰ�ڵ�
	int Father; //���ڵ�Ŀ¼
};

struct Root_file //��Ŀ¼
{
	int ID;
	//������Ϣ
	string File_name;//�ļ�����
	string Type; //�ļ�����
	int Length; //�ļ���С
	int Limit[7]; //Ȩ��
	int File_User; //�����û�

	Files *Address = NULL; //�ܱ�λ�ã��ļ��������
	int File_address[100]; //�ļ�ռ�ÿ���
};





struct Block
{
	int n;	//��ſ��п�ĸ���
	int free[50];	//��ſ��п�ĵ�ַ
	int a;	//�ÿ��Ƿ�ռ��
	char content[100];	//ÿ���ֽڴ�ŵ��ַ�
};


struct Block_super
{
	int n=0; //���п����
	int free[50] = {0}; //���п��ַ
};



struct User
{
	string Name; //�û���
	string Pwd; //����
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