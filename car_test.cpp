#include <string>// to use string
#include <iostream>//cout and cin 
#include <stdlib.h>
#include <stdio.h>// to use printf
#include <cstdlib>
using namespace std;
int g_kSize = 1024;


void menu()
{
	cout << "Smart Search\n";
	cout << "1: view vehicle inventory\n";
	cout << "2: search by make and model\n";
	cout << "3: smart search <c1,c2 >\n";
	cout << "4: quit\n";

}
void init_cars(string models[],int years[],double prices[], int g_kSize)
{
	for (int i = 0; i < g_kSize; ++i)
	{
		models[i] = "";
		prices[i] = 0.0;
		years[i] = 0;
	}
	//add 8 cars in arrays 
	models[0] = "Toyota Camry";
	models[1] = "Ford Taurus";
	models[2] = "Ford Taurus";
	models[3] = "Ferrari FF Coupe";
	models[4] = "BMW 325i";
	models[5] = "Rolls-Royce Phantom Coupe";
	models[6] = "Porsche 911 Convertible";
	models[7] = "Cadillac ATS Sedan";
	//prices 
	prices[0] = 22158.95;
	prices[1] = 9566.99;
	prices[2] = 17899.00;
	prices[3] = 302450.99;
	prices[4] = 37899.88;
	prices[5] = 471175.00;
	prices[6] = 103925.00;
	prices[7] = 42955.00;
	//n_of_cars -> 8;
	//
	//prices[8] = {, 9566.99, 17899.00, 302450.99, 37899.88, 471175.00, 103925.00, 42955.00};
}
int getUserChoice()
{
	int choice = 0;
	cin >> choice;
	return choice;
}
void showVehicleInventory(string models[],int years[],double prices[], int num_cars)
{
	string model, year, price;
	cout << "Vehicle Inventory\n";
	cout << "Make & Model----------Year----------Price\n";

	for (int i = 0; i < num_cars; ++i)
	{
		//model = model + model_list[i];
		printf("%s------------%d----------%0.2f\n", models[i].c_str(), years[i], prices[i]);
		//c_str() convert c++ string to c string(needed because printf is a c function)
	}
}
void quit()
{
	cout << "<see you again>\n"; 
	exit(0);
}
int loadVehicleInventory(string model_list[], int year_list[], double price_list[])
{
	string buffer;
	string make_model;
	int year = 0;
	double price = 0;
	int count = 0;

	cout << "WELCOME.....\n\n";
	//Pause(); //I do not know about lab2. so.... 
	while(1)
	{
		cout << "Enter make_model;year;price[Ford Taurus;2014;14578.99] or [END;] to quit";
		//read model 
		getline(cin, buffer,';');
		if ((buffer=="END") || (count == g_kSize))
		{
			break;
		}
		make_model = buffer;
		//read year
		getline(cin, buffer, ';');
		year = atoi(buffer.c_str());
		//read price 
		getline(cin, buffer, ';');
		//convert to buffer str to double 
		price = atof(buffer.c_str());
		//add info to each array
		model_list[count] = make_model;
		year_list[count] = year;
		price_list[count] = price;
		count = count + 1;
	}
	return count;
}

void searchByMakeModel(string model_list[], int year_list[], double price_list[])
{
	string token;
	string make; 
	string model;
	cout << "Enter make and model:";
	getline(cin,token,' ');
	make = token;
	getline(cin,token,' ');//when test need to add extra space and click enter
	model = token;
	cout << make + " "+model + "\n";
	


}

int main(int argc, char const *argv[])
{
	
	//cout << "hello world\n";
	int num_cars = 0;
	string model_list[g_kSize];
	int year_list[g_kSize];
	double price_list[g_kSize];
	init_cars(model_list,year_list,price_list,g_kSize);
	menu(); 
	cout << "list up all cars" ;
	showVehicleInventory(model_list, year_list,price_list, 8);
	//int c = getUserChoice();
	//printf("choice: %d\n",c);
	searchByMakeModel(model_list, year_list,price_list);
	quit();

	return 0;
}