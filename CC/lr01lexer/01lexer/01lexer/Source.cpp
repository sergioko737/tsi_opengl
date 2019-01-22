#include <fstream>  //Для файловых потоков
#include <iostream> 
#include <string>   //Для контейнера string
#include <vector>  //Для контейнера vector
#include <iterator> //Для вывода элементов вектора  на экран с помощью алгоритма copy

using namespace std;

int keyword = 0;
int id = 0;
int number = 0;
int delim = 0;
int delim2 = 0;
int literal = 0;

string buffer;
char ch;
bool flagId, flagNumber, flagDelim, flagLiteral;

string lexemType[] = { "keyword", "id", "number", "delim", "delim2", "literal"};

struct Lexem {
	int type;
	int sequence;
	string value;
};

vector<Lexem> lexemList;

bool isDelim(char ch){
	return (ch == '.' || ';' || '(' || ')' || ':' || '<' || '+' || ',') ? true : false;
}

void dfa(string &buffer, char ch){
	if (buffer.length() == 0){ // skip whitespaces and newlines
		if (!(ch == ' ' || ch == '\n')){
			flagId = isalpha(ch);
			flagNumber = isdigit(ch);
			flagDelim = isDelim(ch);
			flagLiteral = (ch == '\'');
			buffer += ch;
			cout << ch;
			return;
		}
		else
			return;
	}

	if (!isDelim)
	cout << ch;
}

int main(){
	lexemList.push_back(Lexem());

	ifstream in("input.txt");

	while ((ch = in.get()) != EOF) {
		dfa(buffer, ch);
	}
	in.close();

	//cout<<v.at(0)<<"\n\n";  //Можете посмотреть первую строку, чтобы убедиться, что абзацы разделились.
	//copy(v.begin(), v.end(), std::ostream_iterator<string>(cout, "\n\n"));  //Вывожу вектор на экран
	system("pause");
}