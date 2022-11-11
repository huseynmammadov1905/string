



#include <iostream>

using namespace std;


//class User :
//	string username;
//string password;
//
//class Database :
//	User* users;
//
//bool SignIn(User& user)
//bool SignUp(User& user)


class User {
	string username;
	string password;
public:

	User() {
		username = "huseyn";
		password = "12345";

	}

	User(const string username, const string password) {
		this->username = username;
		this->password = password;
	}

	User(const User& obj) {
		this->username = obj.username;
		this->password = obj.password;
	}


	void Print() {
		cout << "username : " << username << endl << "password : " << password << endl;
	}

	User& operator==(User& user) {
		if (user.username == this->username) {
			if (user.password == this->password)
				return *this;
		}
	}


	friend class Database;
};


class Database {
	int size = 3;
	User* users = new User[size]{
		User("huseyn","12345"),
		User("salfdgam","nessene"),
		User("salam", "23456")
	};

public:





	bool SignIn(User& user) {

		for (int i = 0; i < size; i++)
		{


			if (user.username == users[i].username) {
				if (user.password == users[i].password) {
					cout << "succesfull" << endl;
					return true;

				}

			}

		}
		cout << "wrong" << endl;
		return false;
	}



	bool SignUp(User& user) {
		User* temp = new User[size + 1];

		for (int i = 0; i < size; i++)
		{
			if (user.username == users[i].username) {
				cout << "Bu adda hesab var" << endl;
				return false;
			}
		}

		for (int i = 0; i < size; i++)
		{
			temp[i].username = users[i].username;
			temp[i].password = users[i].password;
		}
		temp[size].username = user.username;
		temp[size].password = user.password;

		delete[] users;
		users = temp;
		size++;
		temp = nullptr;
		return true;
	}

	~Database() {
		delete[] users;
	}
};


int main() {

	Database t;
	string username;
	string password;
	while (true)
	{


		cout << "username : ";
		cin >> username;
		cout << "password : ";
		cin >> password;
		User c(username, password);

		if (t.SignIn(c) == false) {

			cout << "Bu hesab movcud deyil\nHesab elave et : ";
			char yn;
			cout << "yes(y)/ no(n) : ";

			cin >> yn;
			cout << "username : ";
			cin >> username;
			cout << "password : ";
			cin >> password;
			User y(username, password);
			if (yn == 'y') {
				if (t.SignUp(y) == true)
					cout << "hesab elave olundu" << endl;
				else break;
			}
			else { cout << "goodbye" << endl; break; }
		}
		else {
			system("pause");
			break;
		}
	}



}