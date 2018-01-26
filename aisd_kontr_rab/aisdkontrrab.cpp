// aisdkontrrab.cpp : Defines the entry point for the console application.

#include <iostream>
#include <string>
#include "btree.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "ru-RU");
	cout << "����: " << endl;
	cout << "  0 - �����" << endl;
	cout << "  1 - ���������� �����" << endl;
	cout << "  2 - ������� ������" << endl;
	cout << "  3 - ������ �� ������" << endl;
	cout << "  4 - ����� �� �����" << endl;
	cout << "  5 - �������� �������" << endl;
	cout << "  6 - ������� �� �����" << endl;
	cout << "  7 - ����� ������" << endl;
	cout << "  8 - ����� �� ����������� ������" << endl;
	cout << "  9 - ������� ��������� ������" << endl << endl;

	BTree<int, int> tree;
	while (true)
	{
		cout << ">> ";
		int command;
		cin >> command;
		int key, value, index;
		switch (command)
		{
		case 0:
			return 0;
		case 1:
			cout << tree.getSize() << endl;
			break;
		case 2:
			tree.clear();
			break;
		case 3:
			cout << (tree.isEmpty() ? "������ ������" : "������ �� ������") << endl;
			break;
		case 4:
			cout << "����� �� �����. ������� ����:" << endl;
			cin >> key;
			cout << (!tree.find(key, value) ? "���� �� ������" : to_string(value)) << endl;
			break;
		case 5:
			cout << "����������. ������� ����:" << endl;
			cin >> key;
			cout << "������� ��������:" << endl;
			cin >> value;
			tree.insert(key, value);
			break;
		case 6:
			cout << "��������. ������� ����:" << endl;
			cin >> key;
			tree.remove(key);
			break;
		case 7:
			tree.print();
			cout << endl;
			break;
		case 8:
			cout << "����� �� �������. ������� ������:" << endl;
			cin >> index;
			cout << tree.findByIndex(index) << endl;
			break;
		case 9:
			tree.printStructure();
			break;
		default:
			cout << "������� �� �������" << endl;
		}
	}

	return 0;
}