using namespace std;
#include "Head.h"

Block_super Super_block;
queue<int> Reuse_file;
Block Memory[500];
vector<Root_file> Base_table;



void admin();
void test1_operate();
void test1_1(int n);
void test1_2(int n);

int allocate_memmery[500] = {0};
int temp = 0;

Root_file create_root(int id, string fileName, Files* file)
{
	Root_file a;
	a.ID = id;
	//������Ϣ
	a.File_name = fileName;//�ļ�����
	a.Type; //�ļ�����
	a.Length = 123; //�ļ���С
	a.Limit[7] = { 0 }; //Ȩ��
	a.File_User = 1; //�����û�

	a.Address = file;  //�ܱ�λ�ã��ļ��������
	a.File_address[100] = { 0 }; //�ļ�ռ�ÿ���
	return a;
}

int main()
{
	//��ʼ��
	Root_file test;
	test.ID = 0;
	Base_table.push_back(test);

	test1_operate();
	Root_file x = create_root(1, "", creat_files("������ѧ", 1, 0, 2));
	File_Creat(x);
	//cout << Base_table[1].Address << endl;
	Root_file a = create_root(2, "�����", NULL);
	int num = 0;
	a.File_address[num++] = allocate();
	File_Creat(a);

	for (int i = 0; i < Base_table.size(); i++)
	{
		cout << Base_table[i].ID << " " << Base_table[i].File_name << " " << Base_table[i].File_address[0] << endl;
	}

	File_delete(2);
	for (int i = 0; i < Base_table.size(); i++)
	{
		cout << Base_table[i].ID << " " << Base_table[i].File_name << endl;
	}
	
	Root_file aa = create_root(2, "�����", NULL);
	int num1 = 0;
	a.File_address[num1++] = allocate();
	File_Creat(aa);
	for (int i = 0; i < Base_table.size(); i++)
	{
		cout << Base_table[i].ID << " " << Base_table[i].File_name << endl;
	}

	Doc_delete(1);
	//cout << Base_table[1].Address->Doc["������ѧ"] << endl;
	for (int i = 0; i < Base_table.size(); i++)
	{
		cout << Base_table[i].ID << " " << Base_table[i].File_name << endl;
	}
	
	system("pause");
	return 0;
}


void admin()
{
	string username, password;
	cout << "��ӭ�����������û�����";
	cin >> username;
	cout << "���룺";
	cin >> password;

}


//����ͻ��տ��п�
void test1_operate()
{
	init_super_block(50, 150);
	int n=200;
	cout << endl;
	test1_1(151);
	test1_2(52);

	for (int i = 0; i < n; i++)
	{
		cout << allocate_memmery[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < 50; i++)
	{
		cout << Super_block.free[i] << " ";
	}

}


//allocate_test
void test1_1(int n)
{

	for (int i = 0; i < n; i++)
	{
		allocate_memmery[temp++] = allocate();
	}
	
}

//callback_test
void test1_2(int n)
{
	for (int i = 0; i < n; i++)
	{
		temp--;
		while (allocate_memmery[temp] < 0)
		{
			temp--;
		}
		callback(allocate_memmery[temp]);
		allocate_memmery[temp] = 0;
		
	}
}




