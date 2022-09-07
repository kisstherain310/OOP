#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
class SinhVien{
private:
	string MSV, Class, Name, ngay, thang, nam;
public:
	void get();
	string setMSV();
	string setClass();
	string setName();
	string setNgay();
	string setThang();
	string setNam();
};
 
void SinhVien::get(){
	cin >> this -> MSV ;
	cin.ignore();
	cin >> this -> Class;
	cin.ignore();
	getline(cin, Name);
	getline(cin, ngay, '/'); 
	getline(cin, thang, '/'); 
	getline(cin, nam);
}
string SinhVien::setMSV(){
	return this -> MSV;
}
string SinhVien::setClass(){
	return this -> Class;
}
string SinhVien::setName(){
	return this -> Name;
}
string SinhVien::setNgay(){
	return this -> ngay;
}
string SinhVien::setThang(){
	return this -> thang;
}
string SinhVien::setNam(){
	return this -> nam;
}
 
int main(){
    faster()
	int n;
	cin >> n;
	SinhVien arr[105];
	for(int i = 0; i < n; i++){
		arr[i].get();
	}
	for(int i = 0; i < n; i++){
		cout << arr[i].setMSV() << " " << arr[i].setClass() << " " << arr[i].setName() << " ";
		string s1 = arr[i].setNgay(), s2 = arr[i].setThang(), s3 = arr[i].setNam();
		if(s1.size() == 1) cout << '0';
		cout << s1 << "/";
		if(s2.size() == 1) cout << '0';
		cout << s2 << "/";
		for(int i = 0; i < 4 - s3.size(); i++) cout << '0';
		cout << s3 << endl;
	}
}