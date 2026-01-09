#include<iostream>
#include<iomanip>
using namespace std;
class Course{
	public:
		char grade;
		int credit_hours;};
int main(){
	cout<<setw(79)<<"CGPA CALCULATOR"<<endl;
	int no_of_courses;
	int total_credits=0,total_grade_points=0;
	cout<<"Enter the number of courses taken by the student: ";
	cin>>no_of_courses;
	Course student[no_of_courses];
	for(int i=0;i<no_of_courses;i++){
		cout<<"Enter the grade of course "<<i+1;
		cin>>student[i].grade;
		char j=student[i].grade;
		if(!(j=='O'||j=='A'||j=='B'||j=='C'||j=='D'||j=='E'||j=='F')){
			cout<<"Invalid grade!Enter again"<<endl;
			i--;
			continue;
			
		}
		cout<<"Enter the credit hours of course "<<i+1;
		cin>>student[i].credit_hours;
		if (student[i].credit_hours<=0){
			i--;
			cout<<"Invalid credit hour!Enter again"<<endl;
			continue;
		}
		total_credits+=student[i].credit_hours;}
		for(int i=0;i<no_of_courses;i++){
			switch(student[i].grade){
				case 'O':
					total_grade_points+=(10)*student[i].credit_hours;
					break;
				case 'A':
					total_grade_points+=(9)*student[i].credit_hours;
					break;
				case 'B':
					total_grade_points+=(8)*student[i].credit_hours;
					break;
				case 'C':
					total_grade_points+=(6)*student[i].credit_hours;
					break;
				case 'D':
					total_grade_points+=(5)*student[i].credit_hours;
					break;
				case 'F':
					total_grade_points+=0;
					break;
				case 'E':
					total_grade_points+=0;
					break;}}
				for(int i=0;i<no_of_courses;i++){
					cout<<"Course "<<i+1<<": Grade :"<<student[i].grade<<endl;
				}
				cout<<fixed;
				cout<<"CGPA: "<<setprecision(2)<<float(total_grade_points)/total_credits<<endl;
		return 0;}