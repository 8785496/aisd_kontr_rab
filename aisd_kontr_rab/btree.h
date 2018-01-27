#pragma once

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
	bool insert(K key, V value)
	{
		if (root == nullptr)
		{
			root = new Node(key, value);
			return true;
		}
		Node *current = root;
		Node *previous = nullptr;
		while (current != nullptr)
		{
			previous = current;
			if (key == current->key)
			{
				return false;
			}
			if (key < current->key)
			{
				current = current->left;
			}
			else
			{
				current = current->right;
			}
		}
		if (key < previous->key)
		{
			previous->left = new Node(key, value);
		}
		else
		{
			previous->right = new Node(key, value);
		}
		return true;
	}
	bool remove(K key)
	{
		int f = 0; int s = 0; Node *P = nullptr, *Q, *Lp, *Rp, *T;
		T = root;
		if (T == nullptr)
		{
			return false; // Дерево пустое
		}
		while (T != nullptr && f == 0)
		{
			if (key < T->key)
			{
				s = 1; P = T; T = T->left;
			}
			else if (key > T->key)
			{
				s = -1; P = T; T = T->right;
			}
			else
			{
				f = 1;
			}
		}
		if (T == nullptr) // ключ не найден
		{
			return false;
		}
		if (T->left == 0 && T->right == 0) // удаляется элемент без потомков - лист
		{
			if (T == root) // в дереве только один элемент - корень дерева
			{
				clear();
				return true;
			}
			else
			{
				if (s == 1)
					P->left = nullptr;
				else
					P->right = nullptr;
			}
			delete T;  
			return true;
		}
		if (T->left != nullptr && T->right != nullptr) // удаляется элемент с двумя потомками
		{
			Q = T->left; // по левой ветви на уровень ниже
			if (Q->right == nullptr) // если у него нет правого поддерева
			{
				Rp = T->right; // то он заменяет удаляемый узел
				*T = *Q; T->right = Rp;
			}
			else // правое поддерево есть
			{
				while (Q->right != nullptr)  // по нему до конца правой ветви
				{
					P = Q;  Q = Q->right;
				}
				Lp = T->left; Rp = T->right;  // удаляемый элемент заменяем
				*T = *Q; T->right = Rp; T->left = Lp; // на конечный правый,
				P->right = Q->left; // сохраняя указатели удаляемого
			}
			delete Q;
			return true;
		}
		if (T->left != nullptr) // удаляется элемент с одним потомком
		{
			if (s == 1)
				P->left = T->right;
			else
				if (s == -1)
					P->right = T->left;
				else
				{
					Q = T->left;
					*T = *Q;
					delete Q; return true;
				}
		}
		else
		{
			if (s == 1)
				P->left = T->right;
			else
				if (s == -1)
					P->right = T->right;
				else
				{
					Q = T->right;
					*T = *Q;
					delete Q; return true;
				}
		}
		delete T;
		return true;
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
