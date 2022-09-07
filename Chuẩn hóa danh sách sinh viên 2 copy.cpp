#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
class SinhVien{
private:
	string MSV, Class, Name, ngay, thang, nam;
	friend istream &operator>>(istream &in, SinhVien &sv);
	friend ostream &operator<<(ostream &out, SinhVien &sv);	
};
 
istream &operator>>(istream &in, SinhVien &sv){
	cin >> sv.MSV ;
	cin.ignore();
	cin >> sv.Class;
	cin.ignore();
	getline(cin, sv.Name);
	getline(cin, sv.ngay, '/'); 
	getline(cin, sv.thang, '/'); 
	getline(cin, sv.nam);
	return in;
}
ostream &operator<<(ostream &out, SinhVien &sv){
    cout << sv.MSV << " ";
	cout << sv.Class << " ";
	string s = sv.Name;
	stringstream ss(s);
	while(ss >> s){
		s[0] = toupper(s[0]);
		for(int i = 1; i < s.size(); i++) s[i] = tolower(s[i]);
		cout << s << " ";
	}
	cout << sv.ngay << "/";
    cout << sv.thang << "/";
	cout << sv.nam << endl;
	return out;
}
 
int main(){
    faster()
	int n;
	cin >> n;
	SinhVien arr[105];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	for(int i = 0; i < n; i++){
		cout<<arr[i];
	}
 
}