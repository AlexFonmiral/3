#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<Windows.h>
#include<fstream>
using namespace std;
vector<vector<string>> v(503, vector<string>(4));



int main()
{
	setlocale(LC_ALL, "Russian");
	//ScientistName#preparation#date#components
	string ScientistName, preparation, date, components;
	ifstream f("scientist.txt");

	int i = 0;
	while (f.good()) {
		getline(f, ScientistName, '#');
		getline(f, preparation, '#');
		getline(f, date, '#');
		getline(f, components, '\n');
		v[i][2] = ScientistName;
		v[i][1] = preparation;
		v[i][0] = date;
		v[i][3] = components;
		i++;
		//cout << v[i][0] << endl;
	}
	string dat;int flag = 1;
	cin >> dat;
	for (int i = 1; i <= 500; i++) {
		if (dat == v[i][0]) {
			flag = 0;
			cout << "Ученый " << v[i][2] << " создал препарат : " << v[i][1] << " - " << v[i][0] << '\n';

		}
	}
	if (flag == 1) cout << "В этот день ученые отдыхали";

}