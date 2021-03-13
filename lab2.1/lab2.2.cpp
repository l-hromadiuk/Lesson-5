// lab2.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
struct Polynom {
	int	coef;
	int power;
	Polynom* next;

	};

Polynom* beg1 = NULL;
Polynom* end1 = NULL;
Polynom* beg2 = NULL;
Polynom* resPol = NULL;
Polynom* res1 = NULL;
/*
struct Polynom* deletElem(Polynom* lst, Polynom* root)
{
	struct Polynom* temp;
	temp = root;
	while (temp->ptr != lst) // просматриваем список начиная с корня
	{ // пока не найдем узел, предшествующий lst
		temp = temp->ptr;
	}
	temp->ptr = lst->ptr; // переставляем указатель
	free(lst); // освобождаем память удаляемого узла
	return(temp);
}*/
void print(Polynom* b);
void firstPolynom(int cef, int pow)
{
	if (beg1 == NULL)
	{
		beg1 = new (Polynom);
		beg1->coef = cef;
		beg1->power = pow;
		beg1->next = NULL;
	}
	else
	{

		end1 = beg1;
		while  (end1->next != NULL)
			{
				end1 = end1->next;
			}
		
		end1->next = new(Polynom);
		end1 = end1->next;
		end1->coef = cef;
		end1->power = pow;
		end1->next = NULL;
	}
}
	
		void secondPolynom(int cef, int  pow)
		{ 
			if (beg2 == NULL)
			{
				beg2 = new (Polynom);
				beg2->coef = cef;
				beg2->power = pow;
				beg2->next = NULL;
			}
			else
			{
				Polynom* end2 = NULL;

				end2 = beg2;
				while (end2->next != NULL)
				{
					end2 = end2->next;
				}
				end2->next = new(Polynom);
				end2 = end2->next;
				end2->coef = cef;
				end2->power = pow;
				end2->next = NULL;
			}
	
	

		
	
	
}
		void thirdPolynom(int cef, int  pow)
		{
			if (res1 == NULL)
			{
				res1 = new (Polynom);
				res1->coef = cef;
				res1->power = pow;
				res1->next = NULL;
			}
			else
			{
				Polynom* endres = NULL;

				endres = res1;
				while (endres->next != NULL)
				{
					endres = endres->next;
				}
				endres->next = new(Polynom);
				endres = endres->next;
				endres->coef = cef;
				endres->power = pow;
				 endres->next = NULL;
			}
		}
		void resPolynom(int cef, int  pow)
		{
			if (resPol == NULL)
			{
				resPol = new (Polynom);
				resPol->coef = cef;
				resPol->power = pow;
				resPol->next = NULL;
			}
			else
			{
				Polynom* endres = NULL;

				endres = resPol;
				while (endres->next != NULL)
				{
					endres = endres->next;
				}
				endres->next = new(Polynom);
				endres = endres->next;
				endres->coef = cef;
				endres->power = pow;
				endres->next = NULL;
			}
		}
		void resultPolynom() {
		
			Polynom* tmp2 = NULL;
			Polynom* tmp = NULL;
			Polynom* restmp2 = NULL;
			Polynom* restmp = NULL;
			
			
			tmp2 = beg2;
			int resCof;
			int resPow;
			while (tmp2 != NULL) {
				tmp = beg1;
				while (tmp != NULL) {
					
						resPow = tmp->power+ tmp2->power;
						resCof = tmp->coef * tmp2->coef;
						thirdPolynom(resCof, resPow);
						tmp = tmp->next;
				}tmp2 = tmp2->next;
			}
			print(res1);
			restmp = res1;
			bool unique = 0;
			resPolynom(res1->coef, res1->power);
			while (restmp != NULL) {		
				restmp2 = restmp->next;
				while (restmp2 != NULL) {
	               restmp2 = restmp2->next;
				   tmp = restmp2;
				   if (restmp2) {
					   while (tmp != NULL) {
						   if (tmp->power != restmp->power) unique = 1;
						  tmp = tmp->next;
					   }
					   if(unique==0)resPolynom(restmp2->coef, restmp2->power);
					   else {
						   if (restmp2->power == restmp->power && restmp2 != res1) {
							   resPolynom((restmp2->coef + restmp->coef), restmp2->power);
							  
						   }
					   }if (restmp2->next == NULL)resPolynom((restmp2->coef), restmp2->power); break;
				   }
					
					
	

				}restmp = restmp->next;


			}	print(resPol);
		
		}
void print(Polynom* b)
{
	Polynom *print=b ;
	
	cout << "Polynom:" << endl;
		while (print->next!=NULL){
			cout << print->coef << "x^" << print->power << "+";
			print = print->next;
		}
		  cout << print->coef << "x^" << print->power << endl;  
	
}

	void saveToFileBin() {
		ofstream pol("polynom.dat");
		pol.write((char*)&beg1, sizeof(Polynom));
			pol.write((char*)&beg2, sizeof(Polynom));
		cout << "File was saved." << endl;
	}
	void loadFromFileBin() {
		ifstream pol("polynom.dat");
			pol.read((char*)&beg1, sizeof(Polynom));
			print(beg1);
			pol.read((char*)&beg2, sizeof(Polynom));
			print(beg2);
			

	}
int main()
{
	FILE* pol = fopen("polynom.dat", "wb");
	//firstPolynom(3,5);
	/*	firstPolynom(4,4);
		firstPolynom(8,2);
		firstPolynom(7,1);
		secondPolynom(2,3);
		secondPolynom(5,2);*/
	/*	secondPolynom(1,2);
		secondPolynom(2,1);*/
	firstPolynom(2, 2);
	firstPolynom(-1, 1);
	secondPolynom(2, 2);
	secondPolynom(1, 1);
		saveToFileBin();
		loadFromFileBin();
		/*print(beg1);
		print(beg2);*/	
		resultPolynom();


		fclose(pol);
}

