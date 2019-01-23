#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

ifstream in("input.txt");

int keyword = 0;
int id = 0;
int number = 0;
int delim = 0;
int delim2 = 0;
int literal = 0;

string buffer;
string delim2str;
char ch;

string lexemType[] = { "keyword", "id", "number", "delim", "delim2", "literal" };

struct Lexem {
	int type;
	int sequence;
	string value;
};

vector<Lexem> lexemList;

bool isError;

bool isDelim(char ch){
	return (ch == '.' || ch == ';' || ch == ':' || ch == '(' || ch == ')' || ch == ':' || ch == '<' || ch == '+' || ch == ',' || ch == '=') ? true : false;
}

bool isLiteral(char ch){
	return (ch == '\'') ? true : false;
}


void dfa(string &buffer, char ch){
	if (!(isalnum(ch) || isDelim(ch) || isLiteral(ch) || ch == ' ' || ch == '\n')){
		isError = true;
		cout << "ERROR ERROR ERROR" << endl;
		cout << "Unknown symbol [" << ch << "]" << endl;
	}
	if (isalpha(ch)){
		buffer = ch;
		while (isalnum(ch = in.get())){
			buffer += ch;
		}
		cout << "id [" << buffer << "]" << endl;
	}
	if (isdigit(ch)){
		buffer = ch;
		while (isalnum(ch = in.get())){
			buffer += ch;
			if (isalpha(ch)){
				isError = true;
				cout << "Wrong number format !!! " << buffer << " !!!" << endl;
				break;
			}
		}
		cout << "number [" << buffer << "]" << endl;
	}
	if (isDelim(ch)){
		buffer = ch;
		if (buffer == ":"){
			ch = in.get();
			delim2str = ch;
			if (delim2str == "="){
				buffer += delim2str;
				cout << "delim2 [" << buffer << "]" << endl;
			}
			else {
				cout << "delim [" << buffer << "]" << endl;
				dfa(buffer, ch);
			}
		}
		else cout << "delim [" << buffer << "]" << endl;
	}
	if (isLiteral(ch)){
		buffer = "";
		while (!isLiteral(ch = in.get())){
			buffer += ch;
		}
		cout << "literal [" << buffer << "]" << endl;
	}
}

int main(){
	lexemList.push_back(Lexem());



	while ((ch = in.get()) != EOF) {
		dfa(buffer, ch);
		if (isError) break;
	}
	in.close();

	//cout<<v.at(0)<<"\n\n";  //Можете посмотреть первую строку, чтобы убедиться, что абзацы разделились.
	//copy(v.begin(), v.end(), std::ostream_iterator<string>(cout, "\n\n"));  //Вывожу вектор на экран
	system("pause");
}