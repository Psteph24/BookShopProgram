#include<iostream>
#include<string.h>
#include<stdlib.h>

//Ionescu Stefan Paul


using namespace std;


class book {

private:
	char* author, * title, * publisher;
	float* price;
	int* stock;


public:
	book() {
		author = new char[20];
		title = new char[20];
		publisher = new char[20];
		price = new float;
		stock = new int;
	}

	void feeddata();
	void editdata();
	void showdata();
	int search(char[], char[]);
	void buybook();


};

void book :: feeddata() {

	cin.ignore();
	cout << "\nEnter Author Name: "; cin.getline(author, 20);
	cout << "Enter Title Name: "; cin.getline(title, 20);
	cout << "Enter Publisher Name: "; cin.getline(publisher, 20);
	cout << "Enter Price: "; cin >> *price;
	cout << "Enter Stock Position: "; cin >> *stock;
    
}

void book::editdata() {
	cout << "\nEnter Author Name: "; cin.getline(author, 20);
	cout << "Enter Title Name: "; cin.getline(title, 20);
	cout << "Enter Publisher Name: "; cin.getline(publisher, 20);
	cout << "Enter Price: "; cin >> *price;
	cout << "Enter Stock Position: "; cin >> *stock;

}

void book :: showdata(){

	cout << "\Author Name: " << author;
	cout << "\Title Name: " << title;
	cout << "\nPublisher Name: " << publisher;
	cout << "\nPrice: " << *price;
	cout << "\nStock Position: " << *stock;

}

int book::search(char tbuy[20],char abuy[20]) {
	if (strcmp(tbuy, title) == 0 && strcmp(abuy, author) == 0) {
		return 1;
	}
	else return 0;

}

void book::buybook() {
	int count;
	cout << "\nEnter Number of Books to buy: ";
	cin >> count;
	if (count <= *stock) {
		*stock = *stock - count;
		cout << "\nBooks Bought Sucessfully";
		cout << "\nAmount: RS." << (*price) * count;
	}
	else {
		cout << "\nReguired Copies not in Stock";
	}
}




	int main()
	{
		book* B[20];
		int i = 0, r, t, choice;
		char titlebuy[20], authorbuy[20];
		while (1) {
			cout << "\n1. Entry of New Book"
				<< "\n2. Buy Book"
				<< "\n3. Search for Book"
				<< "\n4. Edit Details of Book"
				<< "\n5. Exit"
				<< "\n\n\Enter your Choice: ";
			   cin >> choice;


			   switch (choice){

			     case 1: B[i] = new book;
					     B[i]->feeddata();
						 i++;   break;


				 case 2: cin.ignore();
					 cout << "\nEnter Title of Book: "; cin.getline(titlebuy, 20);
					 cout << "Enter Author of Book: "; cin.getline(authorbuy, 20);
					 
					 for (t = 0; t < 1; t++) {

						 if (B[t]->search(titlebuy, authorbuy)) {
							 B[t]->buybook();
							 break;
						 }
					 }
					 if (t = 1) {
						 cout << "\nThis Book is not in stock";
					 }

					 break;

				 case 3: cin.ignore();
					 cout << "\nEnter Title of Book: "; cin.getline(titlebuy, 20);
					 cout << "Enter Author of Book: "; cin.getline(authorbuy, 20);

					 for (t = 0; t < i; t++) {
						 if (B[t]->search(titlebuy, authorbuy)) {
							 cout << "\nBook Found Successfully";
							 B[t]->showdata();
							 break;
						 }
					 }
					 if (t == i) {
						 cout << "\nThis Book is not in Stock";
					 }
					 break;

				 case 4: cin.ignore();
					 cout << "\nEnter Title of Book: "; cin.getline(titlebuy, 20);
					 cout << "Enter Author of Book: "; cin.getline(authorbuy, 20);

					 for (t = 0; t < i; t++) {
						 if (B[t]->search(titlebuy, authorbuy)) {
							 cout << "\nBook Found Successfully";
							 B[t]->editdata();
							 break;
						 }
					 }
					 if (t == i) {
						 cout << "\nThis Book is not in Stock";
					 }
					 break;

				 case 5: exit(0);
				 default: cout << "\nInvalid choice entered";
			   }


		}



		return 0;


	}













































