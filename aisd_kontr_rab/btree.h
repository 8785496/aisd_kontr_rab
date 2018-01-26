#pragma once

#include <string>

template <typename K, typename V> class BTree
{
private:
	class Node
	{
	public:
		K key;
		V value;
		int index;
		Node *right;
		Node *left;
		Node(K key, V value)
		{
			this->key = key;
			this->value = value;
			this->right = nullptr;
			this->left = nullptr;
		}
		~Node()
		{
			delete this->right;
			delete this->left;
		}
	};
	Node *root;
	void _printStructure(Node *node, int level)
	{
		if (node != nullptr)
		{
			_printStructure(node->right, level + 1);
			for (int i = 0; i < level; i++)
			{
				std::cout << "    ";
			}
			std::cout << node->key << std::endl;
			_printStructure(node->left, level + 1);
		}
	}
	void _insert(Node **node, K key, V value)
	{
		if (*node == nullptr) // место для вставки
		{
			*node = new Node(key, value);
			return;
		}

		if (key == (*node)->key) // элемент уже существует
		{
			(*node)->value = value;
			return;
		}

		if (key < (*node)->key)
		{
			_insert(&(*node)->left, key, value);
		}
		else
		{
			_insert(&(*node)->right, key, value);
		}
	}
	int _getSize(Node *node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		return (_getSize(node->left) + _getSize(node->right) + 1);
	}
	void _print(Node *node)
	{
		if (node != nullptr)
		{
			_print(node->left);
			_print(node->right);
			std::cout << node->key << ' ';
		}
	}
public:
	int getSize()
	{
		return _getSize(root);
	}
	void clear()
	{
		delete this->root;
		root = nullptr;
	}
	bool isEmpty()
	{
		return this->root == nullptr;
	}
	bool find(K key, V &value)
	{
		Node *node = root;
		while (true)
		{
			if (node == nullptr)
			{
				return false;
			}
			else if (key < node->key)
			{
				node = node->left;
			}
			else if (key > node->key)
			{
				node = node->right;
			}
			else
			{
				value = node->value;
				return true;
			}
		}
	}
	void insert(K key, V value)
	{
		_insert(&root, key, value);
	}
	void remove(K key)
	{
		// TODO
	}
	K findByIndex(int index)
	{
		return K(); // TODO
	}
	void print()
	{
		_print(root);
	};
	void printStructure()
	{
		_printStructure(root, 0);
	}
	BTree()
	{
		this->root = nullptr;
	}
	~BTree()
	{
		this->clear();
	}
};
