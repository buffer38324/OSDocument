#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>



struct Root_file //��Ŀ¼
{
	int ID;
	//������Ϣ
	string File_name;//�ļ�����
	string Type; //�ļ�����
	int Length; //�ļ���С
	int Limit[7]; //Ȩ��
	int File_User; //�����û�

	Files* Address = NULL; //�ܱ�λ�ã��ļ��������
	int File_address[100]; //�ļ�ռ�ÿ���
};





struct Files
{
	map<string, int> Doc; //�ļ���
	int Self; //��ǰ�ڵ�
	int Father; //���ڵ�Ŀ¼
};


struct Block
{
	int n;	//��ſ��п�ĸ���
	int free[50];	//��ſ��п�ĵ�ַ
	int a;	//�ÿ��Ƿ�ռ��
	char content[100];	//ÿ���ֽڴ�ŵ��ַ�
}Memory[500];

struct Block_super
{
	int n; //���п����
	int free[50]; //���п��ַ
}Super_block;

struct User
{
	string Name; //�û���
	string Pwd; //����
}Users[8];


extern int BOOT_i = 0;

queue<int> Reuse_file;