#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;
int registration(string name,string password,ofstream &file){
		ifstream fp("database.txt");
		string line;
		bool duplicate=false;
		while(getline(fp,line)){
			stringstream ss(line);
			string uname;
			getline(ss,uname,',');
			if (uname==name){
				duplicate=true;
				break;}}
				if (duplicate){
					cout<<"Sorry!Already a user exists with that name";
					return 9;
					}
					else{
						file<<name<<","<<password<<"\n";
						file.flush();
						return 1;}
						fp.close();}
void login(string name,string password){
		bool exist=false;
		ifstream fp("database.txt");
		string line;
		while(getline(fp,line)){
					string l;
					stringstream s(line);
					getline(s,l,',');
					if(l==name){
							string pas;
							exist=true;
							getline(s,pas);
									if (password==pas){
										cout<<"You have successfully logged in!"<<endl;
										break;
									}
									else{
										cout<<"Wrong Password"<<endl;
										break;}}}
			if(!exist){
					cout<<"The given username doesn't exists"<<endl;}
											fp.close();}
	
int main(){
	int n;
	cout<<setw(79)<<"LOGIN AND REGISTRATION SYSTEM"<<endl;
	ofstream file("database.txt");

	int ch=0;
	bool choice=true;
	if (!file.is_open()){
		cout<<"Error in creating the database file";
	}
	while(choice){
		cout<<"Enter 1 for registration , 2 for logging in and 3 to stop"<<endl;
		cin>>ch;
		if (ch==1){
	cout<<"Enter the number of users to register";
	cin>>n;
	for(int i=0;i<n;i++){
		string name,password;
		cout<<"Enter the username of user "<<i+1<<": ";
		cin>>name;
		cout<<"Enter the password: ";
		cin>>password;
		int h=registration(name,password,file);
		if (h==9){i--;
		continue;
		}
		else{cout<<"Registered successfully!"<<endl;
		}}}		
        else if(ch==2){
        	string name,password;
        	cout<<"Enter username of the user to login";
        	cin>>name;
        	cout<<"Enter password of the user to login";
        	cin>>password;
        	login(name,password);}
        	else if(ch==3){
        		choice=false;
        		break;
			}
			else{
				cout<<"Invalid choice entered"<<endl;
				}}
				return 0;}
