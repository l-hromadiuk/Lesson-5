#include<iostream>
#include<cmath>
using namespace std;
int  outStack(int& num, char* stack)
{

	return (stack[num--]);
}
void  addStack(int operat, int& num, char* stack)
{

	stack[++num] = operat;
}

int  prior(char operat)
{
	switch (operat)
	{
	case '(':return 3;
	case '^':return 2;
	case '/':case'*':
	case '%':return 1;
	default:  return 0;
	}
}

void  swap(char* rpn, char* nn, char* stack, int& num)
{
	int j(0);
	char element;
	char operat;
	for (int i = 0; i < strlen(nn); i++)
	{
		operat = nn[i];
		switch (operat)
		{
		case '(':
			addStack(operat, num, stack);
			break;
		case ')':
			while ((element = outStack(num, stack)) != '(') { rpn[j++] = element; }

			break;
		case '/':case '%':case '^':
			while (prior(prior(operat) >= stack[num]))
				rpn[j++] = outStack(num, stack);
			addStack(operat, num, stack);
			break;
		default:
			rpn[j++] = operat;
		}

	}rpn[j++] = outStack(num, stack);
	rpn[j] = '\0';
}


int calculate(char* rpn, int& num, char* stack)
{
	int x, y;
	double res;
	for (int i = 0; i < strlen(rpn); i++)
	{
		if (rpn[i] >= '0' && rpn[i] <= '9' )
			addStack(rpn[i] - '0', num, stack);
		else
		{
			x = outStack(num, stack);
			y = outStack(num, stack);
			switch (rpn[i])
			{
			case '*':
				res = y * x;
				break;
	          case '/':
				res = y / x;
				break;
			case '%':
				res = y % x;
				break;
			case '^':
				res = pow(y, x); break;
			default:res = y + x; break;
			}

			addStack(res, num, stack);
		}
	}
	res = outStack(num, stack);
	return res;
}

int main()
{
	char nn[50], rpn[50], stack[50];
	int num;
	num = 0;
	cout << "Enter task : ";
	cin.getline(nn, sizeof(nn));
	swap(rpn, nn, stack, num);
	cout << "Rpn: " << rpn << endl;
	cout << "Res = " << calculate(rpn, num, stack) << endl;

}
