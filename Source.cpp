#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<Windows.h>
#include<fstream>
#include<ctime>
using namespace std;

string f_pass()
{
string code = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
string res = "";
srand(time(0)); //генерация пароля из букв и цифр из алфавита code
res.push_back(code[rand() % code.size()]);
res.push_back(code[rand() % code.size()]);
res.push_back(code[rand() % code.size()]);
res.push_back(code[rand() % code.size()]);
res.push_back(code[rand() % code.size()]);
res.push_back(code[rand() % code.size()]);
res.push_back(code[rand() % code.size()]);
res.push_back(code[rand() % code.size()]);
res.push_back(code[rand() % code.size()]);
res.push_back(code[rand() % code.size()]);
return res; //Функция возвращает сгенерированный пароль из 10 символов
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	//ScientistName#preparation#date#components
	string ScientistName, preparation, date, components;
	ifstream f("scientist.txt");
	vector<vector<string>> v(503, vector<string>(4));
	int i = 0;
	while (f.good()) {//чтение файла с разделителями в вектор v
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

	//	cout << v[500][2];
	ofstream f2;//файл с выходными данными - с логином и паролем для каждого человека
	string fm="", im="", ot="", s="", pass="";
	f2.open("scientist_password.txt");
	f2 << "ScientistName" << ',' << "preparation" << ',' << "date" << ',' << "components" <<',' <<"login" <<',' <<"password" << '\n';
	for (int i = 1; i <= 500; i++) {
	//Ланчеков Алексей Тимофеевич
		s = v[i][2];
		fm = s.substr(0, s.find(" ")); //фамилия для логина
		im = s.substr(s.find(" ")+1, 1); //инициалы для логина
		s.replace(s.find(" "), 1, "*"); 
		ot= s.substr(s.find(" ")+1, 1); //инициалы для логина
		s = fm + "_" + im + ot; //логин
		pass = f_pass(); //пароль из функции
		f2<< v[i][2] << ',' << v[i][1] << ',' << v[i][0] << ',' << v[i][3] << ','<<s<<','<<pass<<'\n';

	}
	cout << "файл scientist_password.txt в корне проекта";
}