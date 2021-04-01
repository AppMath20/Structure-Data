#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>

using namespace std;

class PNode
{
public:
	int count;
	char symbol;
	PNode *left;
	PNode *right;

	PNode(char symb, int cnt)
	{
		symbol = symb;
		count = cnt;
	}

	PNode(PNode *l, PNode *r)
	{
		symbol = 0;
		left = l;
		right = r;
		count = l->count + r->count;
	}

	void Print_Table(PNode *root, int depth = 0)
	{
		if (root == NULL) return;

		if (root->symbol)
		{
			for (int i = 0; i < depth; i++)
				cout << "+";
			cout << root->symbol << endl;
		}
		else depth++;
		Print_Table(root->left, depth);
		Print_Table(root->right, depth);
	}
};

bool Sort_PNode(const PNode *a, const PNode *b)
{
	return a->count < b->count;
}

void Build_Table(PNode *root, vector<bool> &code, map<char, vector<bool>> &table)
{
	if (root->left)
	{
		code.push_back(0);
		Build_Table(root->left, code, table);
	}

	if (root->right)
	{
		code.push_back(1);
		Build_Table(root->right, code, table);
	}

	if (root->symbol)
		table[root->symbol] = code;
	if (code.size())
		code.pop_back();
}

string Decode_Huffman(string &str, map<vector<bool>, char> &tab)
{
	string out = "";
	vector<bool> code;
	for (int i = 0; i < str.length(); i++)
	{
		code.push_back(str[i] == '0' ? false : true);
		if (tab[code])
		{
			out += tab[code];
			code.clear();
		}
	}
	return out;
}

int main()
{
	setlocale(LC_ALL,"ru");
	int a = 0, c;
	cout << "Введите кодируемый текст:" << endl;
	string raw;
	getline(cin, raw);
	map<char, int> symbols;

	cout << "Число + - это приоритетность присвоения кода меньшей длины,чем меньше +,тем короче код" << endl << endl;
	for (int i = 0; i < raw.length(); i++)
		symbols[raw[i]]++;

	list<PNode*> kucha;
	map<char, int>::iterator itr;
	for (itr = symbols.begin(); itr != symbols.end(); itr++)
	{
		PNode *p = new PNode(itr->first, itr->second);
		kucha.push_back(p);
	}
	     if (kucha.size() == 0) {
		    cout << "Текст отсутствует" << endl;
		    system("pause");
		    return 0;
	     }
	     else
	     {
			 while (kucha.size() != 1)
			 {
				kucha.sort(Sort_PNode);

				PNode *l = kucha.front();
				kucha.pop_front();
				PNode *r = kucha.front();
				kucha.pop_front();

				PNode *parent = new PNode(l, r);
				kucha.push_back(parent);
			 }

			    PNode *root = kucha.front();
			    root->Print_Table(root);

			    vector<bool> code;
			    map<char, vector<bool> > table;
			    Build_Table(root, code, table);


			  for (itr = symbols.begin(); itr != symbols.end(); itr++)
			  {
				    cout << itr->first << " -> ";
				    for (int j = 0; j < table[itr->first].size(); j++)
				    cout << table[itr->first][j];
				    cout << endl;
			  }

			   string out = "";
			   cout << endl<< endl << "Декодированный текст" << endl;
			   for (int i = 0; i < raw.length(); i++)
			   for (int j = 0; j < table[raw[i]].size(); j++)
			   {
					out += table[raw[i]][j] + '0';

			   }
	             
		          cout << endl;
                  cout << out.c_str() << endl;

	              map<vector<bool>, char> ftable;
                  for (auto i = table.begin(); i != table.end(); i++)
                  ftable[i->second] = i->first;
		          cout << Decode_Huffman(out, ftable).c_str() << endl;
       

			      system("pause");
	            }
}

