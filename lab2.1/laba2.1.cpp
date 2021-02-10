#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <conio.h>
#include <istream>
#include <string>
using namespace std;

struct customer {
	int index;
	char name[20];
	int password;
	bool admin;
	bool seen = 1;
	void print()
	{
		if (seen) {
			cout << index << ", ";
			cout << name << ", ";
			cout << password << ", ";
			cout << admin << endl;
		}
	}
};



struct route {
	int id;
	char station[100];
	int delay;
	void print()
	{
		cout << id << ", ";
		cout << station << " ";
		cout << delay;
		cout << endl;


	}
};
struct transport {
	int id;
	char type[12];

	void print()
	{
		cout << id << " ";
		cout << type<<endl;
	}

};

void signup(int& quantity, customer data[], int& id, int& number, route routes[],transport transport[]);
void saveToFileBin(int quantity, customer p[]);
void loadFromFileBin(int quantity, customer p[]) {
	ifstream users("users.dat");
	
	for (size_t i = 0; i < quantity; i++) {
		users.read((char*)&p[i], sizeof(customer));

	}

	for (size_t i = 0; i < quantity; i++)
	{
		p[i].print();
	}

}
void chooseRoute(int number, route p[]) {
	cout << "Choose your route: ";
	int decision;
	cin >> decision;
	int time = rand() % 15;
	cout << "your transport will arrive in:" << endl;
	switch (decision) {
	case 1:cout << time << "->" << p[0].delay + time << "->" << 2 * p[0].delay + time << "->" << 3 * p[0].delay + time; break;
	case 2:cout << time << "->" << p[1].delay + time << "->" << 2 * p[1].delay + time << "->" << 3 * p[1].delay + time; break;;
	case 3:cout << time << "->" << p[2].delay + time << "->" << 2 * p[2].delay + time << "->" << 3 * p[2].delay + time; break;;
	case 4:cout << time << "->" << p[3].delay + time << "->" << 2 * p[3].delay + time << "->" << 3 * p[3].delay + time; break;;
	default:cout << "An error occured"; break;

	}


}
void loadRoutes(int number, route p[]) {
	ifstream users("routes.dat");

	for (size_t i = 0; i < number; i++) {
		users.read((char*)&p[i], sizeof(route));

	}

	for (size_t i = 0; i < number; i++)
	{
		p[i].print();
	}

}
void loadTransp(int number, transport p[]) {
	ifstream users("transport.dat");

	for (size_t i = 0; i < number; i++) {
		users.read((char*)&p[i], sizeof(transport));

	}

	for (size_t i = 0; i < number; i++)
	{
		p[i].print();
	}

}
void loadPairs(int number, transport p[],route s[]) {
	ifstream users("pairs.dat");
	loadTransp(number, p);
	loadRoutes(number, s);
	for (size_t i = 0; i < number; i++) {
		users.read((char*)&p[i].id, sizeof(transport));
		users.read((char*)&s[i].id, sizeof(route));

	}

	for (size_t i = 0; i < number; i++)
	{
		cout<<p[i].id<<"->"<<s[i].id<<" ";
	}

}
char* substr(char* arr, int begin, int len)
{
	char* res = new char[len + 1];
	for (int i = 0; i < len; i++)
		res[i] = *(arr + begin + i);
	res[len] = 0;
	return res;
}
/*void sqlRequests() {
	/*char* command;
	/*char** word=NULL;
	char* tok;
	int count = 0;*/
	/*command=new char[50];
	cin >> command;
	if ((strcmp(substr(command, 0, 6), "SELECT")) == 0 && (strcmp(substr(command, 8, 11), "from")))
	{
		if ((strcmp(substr(command, 12, 16), "route") == 0) || (strcmp(substr(command, 12, 16), "tranp") == 0))
			if ((strcmp(substr(command, 18, 23), "WHERE") == 0) && ((strcmp(substr(command, 25, 29), "delay") == 0))) { if ((command[31] == '>' || '<' || '=') && (atoi(command) }

	}
	else if (strcmp(substr(command, 0, 6), "DELETE") == 0) {
	/*for (tok = strtok(command, " "); tok != NULL; tok = strtok(NULL, " ")) {
		
		
		++count;
	}
	if ((strcmp(word[0], "SELECT") == 0) && (strcmp(word[1], "FROM") == 0)) { cout << "pidr"; }

	/*const char* separators = " ";
	char* tok;
	tok = strtok(command, separators);
	while (tok) {
		cout << tok << endl;
		//if (strcmp(tok, "SELECT") == 0) {}
		tok = strtok(0, separators);
	}


	/*for (int i = 0; i < strlen(command); i++)
	{
		if (command[i] == ' ') {
			for (int j = 0; j < i; j++) {if(command)}
			
			
			
			
			)}
	}	/*	if ((strcmp(substr(command, 0, 6), "SELECT"))==0 && (strcmp(substr(command, 8, 11), "from")))
		{if((strcmp(substr(command, 12, 16), "route") == 0)|| (strcmp(substr(command, 12, 16), "tranp") == 0))
			if ((strcmp(substr(command, 18, 23), "WHERE") == 0)&&((strcmp(substr(command, 25, 29), "delay") == 0))) {if((command[31]=='>'||'<'||'=')&&stoi(command[32]))}
		
		}
		else if (strcmp(substr(command, 0, 6), "DELETE") == 0) {
		}*/
	

		
/*void sqlRequest(char str[]) {
	char** command;
	char* tok;
	int count=0;
	command = new char* [100];
	//cin >> command;

	if ((strcmp(substr(str, 0, 6), "SELECT")) == 0 && (strcmp(substr(str, 8, 11), "from")==0)&&(strcmp(substr(str, 13, 17), "route") == 0))
	{
		cout << "12";
		if ((strcmp(substr(str, 13, 17), "route") == 0)) {
			cout << "11"; if ((strcmp(substr(str, 19, 24), "WHERE") == 0) && ((strcmp(substr(str, 26, 30), "delay") == 0))) { cout << "OOO"; if ((str[32] == '>')) { int k = (str[34] - '0'); cout << k; } }
		}

	}




}*/
void deleteUser(int quantity, customer p[]) {
	cout << "Enter user's id to delete this user:";
	int del;
	cin >> del;
	for (int i = 0; i < quantity; i++)
	{
		if (p[i].index == del) { p[i].seen = 0; }
	}
	saveToFileBin(quantity, p);
	loadFromFileBin(quantity, p);
}
void admin(int quantity, customer p[], int id, int number, route routes[],transport transport[]) {
	cout << "You have administrator rights, choose what you want to do:";
	cout << endl;
	int choice;
	cout << "1.Show users" << endl;
	cout << "2.Create users" << endl;
	cout << "3.Delete users" << endl;
	cout << "4.Show routes" << endl;
	cout << "5.Show pairs (route-vehicle)" << endl;


	cin >> choice;
	switch (choice) {
	case 1:loadFromFileBin(quantity, p); break;
	case 2:signup(quantity, p, id, number, routes,transport); break;
	case 3:deleteUser(quantity, p); break;
	case 4:loadRoutes(number, routes); break;
	case 5:loadPairs(number,transport,routes); break;
	default:cout << "Try again later"; break;
	}



}
void user(int& number, route routes[]) {
	cout << "You have user rights, choose what you want to do: " << endl;
	cout << "1.Show available routes" << endl;;
	cout << "2.SQL request" << endl;;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:loadRoutes(number, routes); chooseRoute(number, routes); break;
	//case 2:sql(); break;
	}
}
int login(int max, customer data[], int& id, int& number, route routes[],transport transport[]) {
	char log[256];
	char pas[20];
	loadFromFileBin(max, data);
	cout << "Enter login and password:" << endl;
	cout << "Enter login: ";
	cin >> log;
	bool success = 0;
	int sum = 0;
	for (int i = 0; i < max; i++) {

		if (strcmp(data[i].name, log) == 0 && data[i].seen != 0)
		{
			cout << "Enter password: ";
			cin >> pas;
			int j = i;
			for (int k = 0; k <= strlen(pas); k++) {

				sum += (int)pas[k];

			}
			if (data[j].password != sum)
			{
				cout << "Wrong password,try again" << endl;
				while (data[j].password != sum) {
					sum = 0;
					cin.clear();
					cin >> pas;
					for (int k = 0; k <= strlen(pas); k++) {

						sum += (int)pas[k];

					}


				}
			}
			system("cls");
			cout << "Hello," << log << "!" << endl; success = 1;
			if (success) {
				if (data[j].admin) { admin(max, data, id, number, routes,transport); }
				else { user(number, routes); }



			}
			return 0;
		}
	}

	if (success == 0)
	{

		cout << "This user doesn't seem to exist!(" << endl;
		cout << "1.Enter another username" << endl;
		cout << "2.Sign up now" << endl;
		int decision;
		cin >> decision;
		switch (decision) {
		case 1: {system("cls"); cin.clear();
			login(max, data, id, number, routes,transport); break; }
		case 2:signup(max, data, id, number, routes,transport); break;
		default:cout << "An error occured" << endl; break;
		}
	}




}



void signup(int& quantity, customer data[], int& id, int& number, route routes[],transport transport[]) {
	char newlog[256];
	char newpas[256];
	loadFromFileBin(quantity, data);
	quantity++;
	system("cls");
	cout << "Create your login: ";
	cin >> newlog;

	for (int i = 0; i < quantity; i++) {

		if (strcmp(data[i].name, newlog) == 0)
		{
			cout << "This nickname is already used,enter another one" << endl;
			while (strcmp(data[i].name, newlog) == 0) {
				cout << "Create your login: ";

				cin >> newlog;
			}
		}
	}

	strcpy(data[quantity - 1].name, newlog);
	cout << "Enter password: ";
	cin >> newpas;
	int summ = 0;
	for (int k = 0; k <= strlen(newpas); k++) {
		summ += (int)newpas[k];
	}
	data[quantity - 1].password = summ;
	cout << "Choose your role: " << endl;
	cout << "1.User" << endl << "2.Admin" << endl;
	int role;
	data[quantity - 1].index = id;
	id++;
	cin >> role;
	switch (role) {
	case 1:data[quantity - 1].admin = 0; cout << "An account was created."; break;
	case 2:data[quantity - 1].admin = 1; cout << "An account will be created after another existing admin accepts your request"; break;
	default:cout << "An error occured" << endl; break;
	}
	ofstream users("users.dat");
	saveToFileBin(quantity, data);
	login(quantity, data, id, number, routes,transport);


}
void menu(int& quantity, customer data[], int& id, int& number, route routes[],transport transport[]) {
	int choice;
	cout << "1.Sign in" << endl;
	cout << "2.Sign up" << endl;
	cin >> choice;
	switch (choice) {
	case 1:login(quantity, data, id, number, routes,transport); break;
	case 2:signup(quantity, data, id, number, routes,transport); break;
	default:cout << "please,try again" << endl;
		menu(quantity, data, id, number, routes,transport);


	}

}


void saveToFileBin(int quantity, customer p[]) {
	ofstream users("users.dat");
	for (size_t i = 0; i < quantity; i++) {
		users.write((char*)&p[i], sizeof(customer));
	}
	cout << "File was saved." << endl;
}
void saveRoute(int number, route p[]) {
	ofstream users("routes.dat");
	for (size_t i = 0; i < number; i++) {
		users.write((char*)&p[i], sizeof(route));
	}
	cout << "File was saved." << endl;


}
void saveTransp(int number, transport p[]) {
	ofstream users("transport.dat");
	for (size_t i = 0; i < number; i++) {
		users.write((char*)&p[i], sizeof(transport));
	}
	cout << "File was saved." << endl;


}
void savePairs(int number, transport p[],route s[]) {
	ofstream users("pairs.dat");
	for (size_t i = 0; i < number; i++) {
		users.write((char*)&p[i], sizeof(transport));
		users.write((char*)&s[i], sizeof(route));
	}
	cout << "File was saved." << endl;

}
int main()
{
	
	 FILE* users = fopen("users.dat", "r+b");
	FILE* stations = fopen("routes.dat", "r+b");
	FILE* tranp = fopen("transport.dat", "r+b");
	FILE* pairs = fopen("pairs.dat", "wb");
	ifstream in("users.dat");
	in.seekg(0, ios::end);
	long i = (long)in.tellg();
	ifstream on("routes.dat");
	on.seekg(0, ios::end);
	long into = (long)on.tellg();
	int number = into / sizeof(route);
	int index = into / sizeof(route) + 1;
	int max = 20;
	int quantity = i / sizeof(customer);
	int id = i / sizeof(customer) + 1;
	customer* data;
	data = new customer[max];
	route* routes;
	routes = new route[max];
	transport* vehicle ;
	vehicle = new transport[max];
	/*char* a
		;
	a = new char[100];
	cin >> a;
	sqlRequest(a);
	
	/*vehicle[0].id = 10;
	vehicle[1].id = 11;
	vehicle[2].id = 12;
	vehicle[3].id = 13;
	strcpy(vehicle[0].type,"bus");
	strcpy(vehicle[1].type, "trolleybus");
	strcpy(vehicle[2].type, "bus");
	strcpy(vehicle[3].type, "tram");
	saveTransp(number, vehicle);
	loadTransp(number, vehicle);*/
	
	//savePairs(number, vehicle, routes);
	//loadPairs(number, vehicle, routes);
	menu(quantity, data, id, number, routes, vehicle);
	fclose(stations);
	fclose(pairs);
	fclose(tranp);
	fclose(users);
}

