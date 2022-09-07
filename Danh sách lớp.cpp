#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
class person{
private:
	string ID, Class, Name, Sex, age;
public:
	string getClass(){
		return this -> Class;
	}
	void nhap(){
		cin >> ID; cin.ignore();
		cin >> Class;
		cin.ignore();
		getline(cin, Name);
		cin >> Sex; cin.ignore();
		cin >> age; cin.ignore();
	}
	void xuat(){
		cout << ID << " " << Name << ", " << age << " tuoi, gioi tinh " << Sex << ", ";
	}
};
class student : public person{
private:
	float gpa;
public:
	void nhap(){
		person::nhap();
		cin >> this -> gpa;
		cin.ignore();
	}
	void xuat(){
		person::xuat();
		cout << "GPA: " << setprecision(2) << fixed << this -> gpa << '.' << endl;
	}
};
class lecturer : public person{
private:
	string subject;
public:
    void nhap(){
		person::nhap();
		getline(cin, this -> subject);
	}
	void xuat(){
		person::xuat();
		cout << "day mon " << this -> subject << "." << endl;
	}		
};
 
int main()
{
	faster();
	map<string, vector<student> > mStu;
	map<string, lecturer> mLec;
	while(true){
        int nhapVao;
        cin >> nhapVao;
 		if(nhapVao == 1){
			student a;
			a.nhap();
			mStu[a.getClass()].push_back(a);
		}
		if(nhapVao == 2){
			lecturer b;
			b.nhap();
			mLec[b.getClass()] = b;
		}
		if(nhapVao == 0){
			for(auto i : mStu){
				cout << "LOP " << i.first << ":" << endl;
				cout << "GIANG VIEN: ";
				mLec[i.first].xuat();
				cout << "DANH SACH SINH VIEN:" << endl;
				for(student u : i.second) u.xuat();
				cout << endl;
			}
			break;
		}
	}
}