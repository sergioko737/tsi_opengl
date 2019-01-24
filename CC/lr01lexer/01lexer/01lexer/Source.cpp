#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <unordered_set>

using namespace std;

ifstream in("input.txt");
ifstream kw("keywords.txt");
ifstream delimList("delims.txt");
ofstream lexemTable("lextable.txt");
ofstream identTable("idtable.txt");
ofstream literTable("Lconst.txt");
ofstream numberTable("Nconst.txt");
ofstream uniqueTable("uniquetable.txt");

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

vector<string> lexemList;
vector<string> keywords;
vector<string> delims ;
vector<string> idList;
vector<string> literList;
vector<string> numberList;
unordered_set<string> uList;
vector<string>::iterator it;

bool isError;

void init(){
	string keyw;
	while (kw.peek() != EOF){
		kw >> keyw;
		keywords.push_back(keyw);
	}

	while (delimList.peek() != EOF){
		delimList >> keyw;
		delims.push_back(keyw);
	}
}

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
		if (keywords.end() != find(keywords.begin(), keywords.end(), buffer)){
			it = find(keywords.begin(), keywords.end(), buffer);
			cout << "K " << distance(keywords.begin(), it) << " " << buffer << endl;
			lexemTable << "K " << distance(keywords.begin(), it) << endl;
			uList.insert(buffer);
			keyword++;
		}
		else{
			if (idList.end() != find(idList.begin(), idList.end(), buffer)){
				it = find(idList.begin(), idList.end(), buffer);
				cout << "I " << distance(idList.begin(), it) << " " << buffer << endl;
				lexemTable << "I " << distance(idList.begin(), it) << endl;
			}
			else{
				cout << "I " << id << " " << buffer << endl;
				lexemTable << "I " << id << endl;
				idList.push_back(buffer);
			}		
			uList.insert(buffer);
			id++;
		}
	}
	if (isdigit(ch)){
		buffer = ch;
		while (isalnum(ch = in.get())){
			buffer += ch;
			if (isalpha(ch)){
				isError = true;
				cout << "ERROR ERROR ERROR" << endl;
				cout << "Wrong number format !!! " << buffer << " !!!" << endl;
				break;
			}
		}
		if (numberList.end() != find(numberList.begin(), numberList.end(), buffer)){
			it = find(numberList.begin(), numberList.end(), buffer);
			cout << "N " << distance(numberList.begin(), it) << " " << buffer << endl;
			lexemTable << "N " << distance(numberList.begin(), it) << endl;
		}
		else{
			cout << "N " << number << " " << buffer << endl;
			lexemTable << "N " << number << endl;
			numberList.push_back(buffer);
		}
		uList.insert(buffer);
		number++;
	}
	if (isDelim(ch)){
		buffer = ch;
		if (buffer == ":"){
			ch = in.get();
			delim2str = ch;
			if (delim2str == "="){
				buffer += delim2str;
				it = find(delims.begin(), delims.end(), buffer);
				cout << "W " << distance(delims.begin(), it) << " " << buffer << endl;
				lexemTable << "W " << distance(delims.begin(), it) << endl;
				uList.insert(buffer);
				delim2++;
			}
			else {
				it = find(delims.begin(), delims.end(), buffer);
				cout << "D " << distance(delims.begin(), it) << " " << buffer << endl;
				lexemTable << "D " << distance(delims.begin(), it) << endl;
				uList.insert(buffer);
				delim++;
				dfa(buffer, ch);
			}
		}
		else {
			it = find(delims.begin(), delims.end(), buffer);
			cout << "D " << distance(delims.begin(), it) << " " << buffer << endl;
			lexemTable << "D " << distance(delims.begin(), it) << endl;
			uList.insert(buffer);
			delim++;
		}
	}
	if (isLiteral(ch)){
		buffer = "";
		while (!isLiteral(ch = in.get())){
			buffer += ch;
		}
		if (buffer != ""){
			if (literList.end() != find(literList.begin(), literList.end(), buffer)){
				it = find(literList.begin(), literList.end(), buffer);
				cout << "L " << distance(literList.begin(), it) << " " << buffer << endl;
				lexemTable << "L " << distance(literList.begin(), it) << endl;
			}
			else{
				cout << "L " << literal << " " << buffer << endl;
				lexemTable << "L " << literal << endl;
				literList.push_back(buffer);
			}
			uList.insert(buffer);
		}

		else{
			if (literList.end() != find(literList.begin(), literList.end(), "NULL")){
				it = find(literList.begin(), literList.end(), "NULL");
				cout << "L " << distance(literList.begin(), it) << " " << buffer << endl;
				lexemTable << "L " << distance(literList.begin(), it) << endl;
			}
			else{
				cout << "L " << literal << " " << "NULL" << endl;
				lexemTable << "L " << literal << endl;
				literList.push_back("NULL");
			}

			uList.insert(buffer);
		}



		literal++;
	}
}

void finish(){
	in.close();
	kw.close();
	delimList.close();
	lexemTable.close();
	identTable.close();
	literTable.close();
	numberTable.close();
	uniqueTable.close();	
}

int main(){

	init();


	while ((ch = in.get()) != EOF) {
		dfa(buffer, ch);
		if (isError) break;
	}

	for (const string& x : idList) identTable  << x <<endl;
	for (const string& x : literList) literTable << x << endl;
	for (const string& x : numberList) numberTable << x << endl;
	for (const string& x : uList) uniqueTable << x << endl;

	finish();
	system("pause");
}