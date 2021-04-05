// laba4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include< iostream >
#include< conio.h >
#include< vector >


using namespace std;

struct elem //Ёлемент
{
	char data;
	int value;
	bool minus;
	elem* left, * right;

	elem(char data = '\0', int value = 0, bool minus = false) : left(NULL),
		right(NULL),
		data(data),
		value(value),
		minus(minus) {}
};

struct expression_tree //ƒерево
{
	elem* top;

	expression_tree(elem* t = NULL) : top(t) {}
};

elem* add(elem* l, elem* r, elem* new_top) //‘ормирование нового поддерева
{
	new_top->left = l;
	new_top->right = r;

	return new_top;
}

void infix(elem* top) //инфиксный обход
{
	if (!top) return;
	infix(top->left);
	cout << top->data << " ";
	infix(top->right);
}

void prefix(elem* top) //префиксный обход
{
	if (!top) return;
	cout << top->data << " ";
	prefix(top->left);
	prefix(top->right);
}

void postfix(elem* top) //постфиксный обход
{
	if (!top) return;
	postfix(top->left);
	postfix(top->right);
	cout << top->data << " ";
}

void create_tree(expression_tree& expr_tr, vector< elem* >& elems) //создание дерева из списка вершин
{
	if (elems[0]->data == '-')
	{
		elems[1]->minus = true;
		elems.erase(elems.begin());
	}

	for (int i = 0; (i < elems.size()) && (elems.size() > 1);)
		if (elems[i]->data == '*' ||
			elems[i]->data == '/' ||
			elems[i]->data == '^' ||
			elems[i]->data == '%')
		{
			expr_tr.top = add(elems[i - 1], elems[i + 1], elems[i]);
			elems.erase(elems.begin() + i - 1);
			elems.erase(elems.begin() + i - 1);
			elems.erase(elems.begin() + i - 1);
			elems.insert(elems.begin() + (i - 1), expr_tr.top);
		}
		else
			i++;

	while (elems.size() > 1)
	{
		expr_tr.top = add(elems[0], elems[2], elems[1]);
		elems.erase(elems.begin()); elems.erase(elems.begin()); elems.erase(elems.begin());
		elems.insert(elems.begin(), expr_tr.top);
	}
}

int return_value(char data, int* variables) //возврат значени€ переменной
{
	switch (data)
	{
	case 'x':
		return variables[0];
	case 'y':
		return variables[1];
	case 'z':
		return variables[2];
	case 'k':
		return variables[3];
	case 'l':
		return variables[4];
	}
}

int operation(elem* top) //проведение бинарной арифметической операций
{
	int a = top->left->value,
		b = top->right->value;
	a = top->left->minus ? -a : a;
	b = top->right->minus ? -b : b;

	switch (top->data)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	case '%':
		return a % b;
	case '^':
		return pow(a, b);
	}
}

int calculate(elem* top, int* peremenniye) //ресчет всей формулы
{
	if (!top) return 0;
	calculate(top->left, peremenniye);
	calculate(top->right, peremenniye);

	if (!(top->left && top->right))
		top->value = return_value(top->data, peremenniye);
	else
		top->value = operation(top);

	return top->value;
}

int* createVectorPeremennih(void) //считывание переменных с клавиатуры
{
	int* peremenniye = new int[5];
	cout << "Enter x: ";
	cin >> peremenniye[0];
	cout << "Enter y: ";
	cin >> peremenniye[1];
	cout << "Enter z: ";
	cin >> peremenniye[2];
	cout << "Enter k: ";
	cin >> peremenniye[3];
	cout << "Enter l: ";
	cin >> peremenniye[4];

	return peremenniye;
}

int main(void)
{
	expression_tree expr_tr;

	const int N = 100;
	char formula[N];
	cout << "Enter formula: ";
	cin >> formula;

	vector< elem* > elems(strlen(formula));
	for (int i = 0; i < elems.size(); i++)
		elems[i] = new elem(formula[i]);

	create_tree(expr_tr, elems);
	int* peremenniye = createVectorPeremennih();
	cout << "\nResult: " << calculate(expr_tr.top, peremenniye);

	cout << "\n\nOur tree: " << endl;
	infix(expr_tr.top); cout << " (infix)" << endl;
	prefix(expr_tr.top); cout << " (prefix)" << endl;
	postfix(expr_tr.top); cout << " (postfix)";

	delete[] peremenniye;
	//_getch();
	return 0;
}