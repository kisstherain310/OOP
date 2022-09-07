#include <bits/stdc++.h>
 
using namespace std;
 
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
class SinhVien{
private:
	string MSV, Class, Name, ngay, thang, nam;
	friend istream &operator>>(istream &in, SinhVien &sv);
	friend ostream &operator<<(ostream &out, SinhVien &sv);	
	friend bool cmp(SinhVien &a, SinhVien &b);
	friend sort();
};
 
bool cmp(SinhVien &a, SinhVien &b){
	string sA = a.Name;
	string sB = b.Name;
	vector<string> vs1, vs2;
	stringstream ss(sA);
	while(ss >> sA){
		sA[0] = toupper(sA[0]);
		for(int i = 1; i < sA.size(); i++) sA[i] = tolower(sA[i]);
		vs1.push_back(sA);
	}
	stringstream sss(sB);
	while(sss >> sB){
		sB[0] = toupper(sB[0]);
		for(int i = 1; i < sB.size(); i++) sB[i] = tolower(sB[i]);
		vs2.push_back(sB);
	}
	string ssA = "", ssB = "";
	for(int i = 0; i < vs1.size() - 1; i++) ssA += vs1[i];
	for(int i = 0; i < vs2.size() - 1; i++) ssB += vs2[i];
//	cout << vs1[vs1.size() - 1] << " " << ssA << endl;
	if(vs1[vs1.size() - 1] != vs2[vs2.size() - 1]) return vs1[vs1.size() - 1] < vs2[vs2.size() - 1];
	else return ssA < ssB;
}
 
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
	if(sv.ngay.size() == 1) cout << '0';
	cout << sv.ngay << "/";
	if(sv.thang.size() == 1) cout << '0';
    cout << sv.thang << "/";
    for(int i = 0; i < 4 - sv.nam.size(); i++) cout << '0';
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
	sort(arr, arr + n, cmp);
	for(int i = 0; i < n; i++){
		cout<<arr[i];
	}
 
}