#include"Head.h"
vector<Root_file> Base_table;
using namespace std;


void File_Creat(Root_file a) {//��Ŀ¼����
	
	if (Base_table.size() == 0) {//��ʼ����Ŀ¼
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

void File_delete(int id,int s[100]) {//ɾ���ļ�
	for (int i = 0; i < 100; i++) {
		s[i] = Base_table[id].File_address[i];
		Base_table[id].File_address[i] = 0;
	}
	Reuse_file.push(id);
	//���մ��̿�
	for (int i = 0; i < 100; i++)
	{
		if (s[i] == 0)
			break;
		//callback(s[i]);
		s[i] = 0;
	}
}

void Doc_delete(int id, int s[100]) {//ɾ���ļ���
	for (map<string, int>::iterator it = Base_table[id].Address->Doc.begin(); it < Base_table[id].Address->Doc.end(); it++)
	{
		if (Base_table[it->second].Address == NULL)
		{
			File_delete(id, s);	//���⣺�����ݹ�Ͳ���s[100]�ĳ�ͻ�������file_delete��Ƕ��������ӷ��Ļ���
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


Files* creat_files(string name, int self, int father, int File_id) {//�ļ��н���
	Files* address = new Files;
	address->Doc[name] = File_id;
	address->Self = self;
	address->Father = father;
	return address;
}

void add_files(string Name, int file_id, int id)//����ļ�Ŀ¼
{
	if (Base_table[id].Address->Doc[Name] != 0)
	{
		cout << "��ǰĿ¼�ļ����ظ�";
	}
	else
		Base_table[id].Address->Doc[Name] = file_id;
}



