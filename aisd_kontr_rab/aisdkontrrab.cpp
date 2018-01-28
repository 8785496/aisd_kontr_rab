// aisdkontrrab.cpp : Defines the entry point for the console application.

#include <iostream>
#include <string>
#include "btree.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "ru-RU");
	cout << "Меню: " << endl;
	cout << "  0 - выход" << endl;
	cout << "  1 - количество узлов" << endl;
	cout << "  2 - очистка дерева" << endl;
	cout << "  3 - пустое ли дерево" << endl;
	cout << "  4 - поиск по ключу" << endl;
	cout << "  5 - добавить элемент" << endl;
	cout << "  6 - удалить по ключу" << endl;
	cout << "  7 - обход дерева" << endl;
	cout << "  8 - поиск по проядковому номеру" << endl;
	cout << "  9 - вывести структуру дерева" << endl;
	cout << "  10 - заполнить дерево тестовыми данными" << endl << endl;

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
			cout << "Количество узлов: " << tree.getSize() << endl;
			break;
		case 2:
			tree.clear();
			break;
		case 3:
			cout << (tree.isEmpty() ? "Дерево пустое" : "Дерево не пустое") << endl;
			break;
		case 4:
			cout << "Поиск по ключу. Введите ключ: ";
			cin >> key;
			cout << (!tree.find(key, value) ? "Узел не найден" : to_string(value)) << endl;
			break;
		case 5:
			cout << "Добавление. Введите ключ: ";
			cin >> key;
			cout << "Введите значение: ";
			cin >> value;
			tree.insert(key, value);
			break;
		case 6:
			cout << "Удаление. Введите ключ: ";
			cin >> key;
			cout << (tree.remove(key) ? "Элемент удален" : "Элемент не удален") << endl;
			break;
		case 7:
			cout << "Восходящий обход дерва по схеме L -> R -> t" << endl;
			tree.print();
			cout << endl;
			break;
		case 8:
			cout << "Поиск по индексу. Введите индекс: ";
			cin >> index;
			cout << (tree.findByIndex(index, value) ? to_string(value) : "Элемент не найден") << endl;
			break;
		case 9:
			tree.printStructure();
			break;
		case 10:
			tree.insert(10, 10);
			tree.insert(11, 11);
			tree.insert(7, 7);
			tree.insert(5, 5);
			tree.insert(6, 6);
			tree.insert(8, 8);
			tree.insert(9, 9);
			tree.printStructure();
			break;
		default:
			cout << "Команда не найдена" << endl;
		}
	}

	return 0;
}
