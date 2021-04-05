// laba5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include< iostream >
#include< conio.h >
#include< string >
#include< windows.h >

using namespace std;

struct elem
{
	string key;
	string data;
	int counter;

	elem* left, * right;

	elem(string& key, string& data, int& count) :
		left(NULL), right(NULL), key(key), data(data), counter(count) {}
};

struct binary_tree
{
	elem* top;

	binary_tree(void) : top(NULL) {}
};

void prefix(elem* top)
{
	if (!top) return;
	char buffer[20];
	OemToCharBuffA(top->data.c_str(), buffer, 20);
	cout << "(" << top->key << ", "
		<< buffer << ", "
		<< top->counter << ") ";
	prefix(top->left);
	prefix(top->right);
}

elem* add(elem* p, string& key, string& data, int& count)
{
	if (!p) return new elem(key, data, count);
	if (key < p->key)
		p->left = add(p->left, key, data, count);
	else if (key > p->key)
		p->right = add(p->right, key, data, count);
	else
	{
		p->data = data;
		p->counter = count;
	}
	return p;
}

elem* findmin(elem* p)
{
	return p->left ? findmin(p->left) : p;
}

elem* removemin(elem* p)
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return p;
}

elem* del(elem* p, string& key)
{
	if (!p) return 0;
	if (key < p->key)
		p->left = del(p->left, key);
	else if (key > p->key)
		p->right = del(p->right, key);
	else
	{
		elem* q = p->left;
		elem* r = p->right;
		delete p;
		if (!r) return q;
		elem* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return min;
	}
	return p;
}

elem* find(binary_tree& bin_tr, string& key)
{
	elem* p = bin_tr.top;
	while (p)
		if (key < p->key)
			p = p->left;
		else if (key > p->key)
			p = p->right;
		else if (p->key == key)
		{
			p->counter++;
			return p;
		}

	return NULL;
}

elem* pfind = NULL;
int findCount = 0;
void find(elem* top)
{
	if (!top) return;
	if (top->counter > findCount)
		pfind = top;
	find(top->left);
	find(top->right);
}

void clear(binary_tree& bin_tr)
{
	while (bin_tr.top)
		bin_tr.top = del(bin_tr.top, bin_tr.top->key);
}

void newWordToVocabulary(binary_tree& bin_tr)
{
	string engWord, rusWord;
	int count;
	cout << "\nВведите английское слово: " << endl;
	cin >> engWord;
	cout << "Введите соответствующий русский перевод: " << endl;
	cin >> rusWord;
	cout << "Введите начальное количество обращений: " << endl;
	cin >> count;
	cout << endl;

	bin_tr.top = add(bin_tr.top, engWord, rusWord, count);
}

void wordTranslate(binary_tree& bin_tr)
{
	string engWord;
	cout << "\nВведите английское слово: " << endl;
	cin >> engWord;

	elem* p = NULL;
	if (p = find(bin_tr, engWord))
	{
		char buffer[20];
		OemToCharBuffA(p->data.c_str(), buffer, 20);
		cout << buffer << endl << endl;
	}
}

void createNewVocabulary(binary_tree& bin_tr, binary_tree& new_bin_tree)
{
	cout << "\nИсходный словарь: " << endl;
	prefix(bin_tr.top);
	cout << "\n\n";

	while (bin_tr.top)
	{
		find(bin_tr.top);
		elem* p = pfind;
		new_bin_tree.top = add(new_bin_tree.top, p->key, p->data, p->counter);
		bin_tr.top = del(bin_tr.top, p->key);
	}

	cout << "Новый словарь: " << endl;
	prefix(new_bin_tree.top);
	cout << "\n\n";
	clear(new_bin_tree);
}

bool menu(binary_tree& bin_tr, binary_tree& new_bin_tree)
{
	cout << "Выберите действие и нажмите Enter: " << endl;
	cout << "1 - Ввести новое слово в словарь" << endl;
	cout << "2 - Перевести английское слово на русский" << endl;
	cout << "3 - Построить новый словарь согласно заданию" << endl;
	cout << "4 - Выйти из программы" << endl;

	string command;
	cin >> command;
	if (command.size() > 1)
		return false;

	switch (command[0])
	{
	case '1':
		newWordToVocabulary(bin_tr);
		break;
	case '2':
		wordTranslate(bin_tr);
		break;
	case '3':
		createNewVocabulary(bin_tr, new_bin_tree);
		break;
	case '4':
		clear(bin_tr);
		clear(new_bin_tree);
		exit(0);
	default:
		return false;
	};

	return true;
}

int main(void)
{
	setlocale(LC_ALL, "Russian");

	binary_tree bin_tr, new_bin_tree;

	while (true)
		if (!menu(bin_tr, new_bin_tree))
			cout << "Ошиба ввода команды!!! Повторите ввод.\n\n";
}