// CMakeProject1.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <cmath>
using namespace std;
/*
Порядок операций:
()
^
'*'
/
+
-
*/
class TVectorStack {
	int top;
	std::vector<string> mem;
public:
	TVectorStack() : top(-1) {}
	size_t size() const { return top + 1; }
	bool IsEmpty() const { return top == -1; }
	void Push(string val) {
		mem.push_back(val);
		top++;
	}
	void Push(char val) {  
		mem.push_back(string(1, val));
		top++;
	}
	void Pop() { mem.pop_back(); top--; }
	string Top() { return mem[top]; }
};


template <typename T>
class Calculator
{
private:
	string ishodnoe;
	string working;
	TVectorStack stack;
	T output;
	unsigned type;


	string Plus(string dano){
		string tmp = dano;
		int found = tmp.find(',');
		while (found != -1) {
			tmp.erase(found, 1);
			found = tmp.find(',');
		}
		int ind_symbol = tmp.find('+');
		if (ind_symbol == -1) throw "there is no + in Plus operation";
		int firsti, secondi;
		double firstd, secondd;
		switch (type)
		{
		case 1 :
			firsti = stoi(tmp.substr(0, ind_symbol)); secondi = stoi(tmp.substr(ind_symbol + 1, tmp.length() - 1 - ind_symbol));
			return to_string(firsti + secondi) + ",";
			break;
		case 2 :
			firstd = stod(tmp.substr(0, ind_symbol)); secondd = stod(tmp.substr(ind_symbol + 1, tmp.length() - 1 - ind_symbol));
			return to_string(firstd + secondd) + ",";
			break;
		default:
			throw "it's not int or double type";
		}
	}
	string Minus(string dano)
	{
		string tmp = dano;
		int found = tmp.find(',');
		while (found != -1) {
			tmp.erase(found, 1);
			found = tmp.find(',');
		}
		int ind_symbol = tmp.find('-');
		if (ind_symbol == -1) throw "there is no - in Minus operation";
		int firsti, secondi;
		double firstd, secondd;
		switch (type)
		{
		case 1 :
			firsti = stoi(tmp.substr(0, ind_symbol)); secondi = stoi(tmp.substr(ind_symbol + 1, tmp.length() - 1 - ind_symbol));
			return to_string(firsti - secondi) + ",";
			break;
		case 2:
			firstd = stod(tmp.substr(0, ind_symbol)); secondd = stod(tmp.substr(ind_symbol + 1, tmp.length() - 1 - ind_symbol));
			return to_string(firstd - secondd) + ",";
			break;
		default:
			throw "it's not int or double type";
		}
	}
	string Multiply(string dano)
	{
		string tmp = dano;
		int found = tmp.find(',');
		while (found != -1) {
			tmp.erase(found, 1);
			found = tmp.find(',');
		}
		int ind_symbol = tmp.find('*');
		if (ind_symbol == -1) throw "there is no * in Multiply operation";
		int firsti, secondi;
		double firstd, secondd;
		switch (type)
		{
		case 1 :
			firsti = stoi(tmp.substr(0, ind_symbol)); secondi = stoi(tmp.substr(ind_symbol + 1, tmp.length() - 1 - ind_symbol));
			return to_string(firsti * secondi) + ",";
			break;
		case 2 :
			firstd = stod(tmp.substr(0, ind_symbol)); secondd = stod(tmp.substr(ind_symbol + 1, tmp.length() - 1 - ind_symbol));
			return to_string(firstd * secondd) + ",";
			break;
		default:
			throw "it's not int or double type";
		}
	}
	string Divide(string dano)
	{
		string tmp = dano;
		int found = tmp.find(',');
		while (found != -1) {
			tmp.erase(found, 1);
			found = tmp.find(',');
		}
		int ind_symbol = tmp.find('/');
		if (ind_symbol == -1) throw "there is no / in Divide operation";
		int firsti, secondi;
		double firstd, secondd;
		switch (type)
		{
		case 1 :
			firsti = stoi(tmp.substr(0, ind_symbol)); secondi = stoi(tmp.substr(ind_symbol + 1, tmp.length() - 1 - ind_symbol));
			return to_string(firsti / secondi) + ",";
			break;
		case 2 :
			firstd = stod(tmp.substr(0, ind_symbol)); secondd = stod(tmp.substr(ind_symbol + 1, tmp.length() - 1 - ind_symbol));
			return to_string(firstd / secondd) + ",";
			break;
		default:
			throw "it's not int or double type";
		}
	}
	string Exponentiation(string dano)
	{
		string tmp = dano;
		int found = tmp.find(',');
		while (found != -1) {
			tmp.erase(found, 1);
			found = tmp.find(',');
		}
		int ind_symbol = tmp.find('^');
		if (ind_symbol == -1) throw "there is no ^ in Exponentiation operation";
		int firsti, secondi, resulti;
		double firstd, secondd, resultd;
		switch (type)
		{
		case 1 :
			firsti = stoi(tmp.substr(0, ind_symbol)); secondi = stoi(tmp.substr(ind_symbol + 1, tmp.length() - 1 - ind_symbol));
			resulti = 1;
			for (int i = 0; i < secondi; i++) {
				resulti = resulti * firsti;
			}
			return to_string(resulti) + ",";
			break;
		case 2 :
			firstd = stod(tmp.substr(0, ind_symbol)); secondd = stod(tmp.substr(ind_symbol + 1, tmp.length() - 1 - ind_symbol));
			resultd = 1.0;
			for (double i = 0; i < secondd; i++) {
				resultd = resultd * firstd;
			}
			return to_string(resultd) + ",";
			break;
		default:
			throw "it's not int or double type";
		}
		
	}
	string Sinus(string dano) {
		string tmp = dano;
		int found = tmp.find(',');
		while (found != -1) {
			tmp.erase(found, 1);
			found = tmp.find(',');
		}

		int ind_symbol = tmp.find('s');
		if (ind_symbol == -1) throw "there is no s in Sinus operation";
		int secondi;
		double secondd;
		switch (type)
		{
		case 1:
			secondi = stoi(tmp.substr(ind_symbol + 1, tmp.length() - 1 - ind_symbol));
			if (secondi == 0 || secondi == 180) return "0,";
			if (secondi == 90 || secondi == 270) return "1,";
			return to_string(round(sin(secondi*3.14/180))) + ",";
			break;
		case 2:
			secondd = stod(tmp.substr(ind_symbol + 1, tmp.length() - 1 - ind_symbol));
			if (secondd == 0 || secondd == 180) return "0,";
			if (secondd == 90 || secondd == 270) return "1,";

			return to_string(sin(secondd*3.14/180)) + ",";
			break;
		default:
			throw "it's not int or double type";
		}
	}
	string Cosinus(string dano) {
		string tmp = dano;
		int found = tmp.find(',');
		while (found != -1) {
			tmp.erase(found, 1);
			found = tmp.find(',');
		}
		int ind_symbol = tmp.find('c');
		if (ind_symbol == -1) throw "there is no c in Cosinus operation";
		int secondi;
		double secondd;
		switch (type)
		{
		case 1:
			secondi = stoi(tmp.substr(ind_symbol + 1, tmp.length() - 1 - ind_symbol));
			if (secondi == 90 || secondi == 270) return "0,";
			if (secondi == 0 || secondi == 180) return "1,";
			return to_string(round(cos(secondi * 3.14 / 180))) + ",";
			break;
		case 2:
			secondd = stod(tmp.substr(ind_symbol + 1, tmp.length() - 1 - ind_symbol));
			if (secondd == 90 || secondd == 270) return "0,";
			if (secondd == 0 || secondd == 180) return "1,";
			return to_string(cos(secondd * 3.14 / 180)) + ",";
			break;
		default:
			throw "it's not int or double type";
		}
	}
	int priority(string goyda)
	{
		if (goyda == "(" || goyda == ")") return 0;
		if (goyda == "+" || goyda == "-") return 1;
		if (goyda == "*" || goyda == "/" ) return 2;
		if (goyda == "^" || goyda == "c" || goyda == "s") return 3;
		cout << "===" << goyda;
		throw "isnt operator";
	}
public:
	Calculator(string input, T& out)
	{
		
		if (typeid(out) != typeid(int) && typeid(out) != typeid(double)) throw "output is not int or double type";
		if (typeid(out) == typeid(int)) type = 1;
		else type = 2;
		ishodnoe = input;
		output = out;
		int found = ishodnoe.find(' ');
		while (found != -1) {
			ishodnoe.erase(found, 1);
			found = ishodnoe.find(' ');
		}
		int checked = -1;
		//тут идет преоброзавание в постфиксную
		for (int i = 0; i < ishodnoe.length(); i++) { 

			if (i > checked) {
				
				if (ishodnoe[i] >= '0' && ishodnoe[i] <= '9') {
					checked = i;
					for (int j = i; j < ishodnoe.length(); j++){
						if (ishodnoe[j] >= '0' && ishodnoe[j] <= '9') {
							checked = j;
						}
						else break;
				}
				working.append(ishodnoe.substr(i, checked - i + 1) + ",");
				
				}
				else {
					switch (ishodnoe[i])
					{
					case '(': {
						stack.Push(ishodnoe[i]); break;
					}
					case ')': {
						while (stack.Top() != "(") {
							if (stack.IsEmpty()) {
								throw "wtf man what does ) in the start of your sentence";
							}
							working.append(stack.Top());
							stack.Pop();

						}
						stack.Pop();
						break;
					}
					case '+':
					case '-':
					case 'c':
					case 's':
					case '*':
					case '/':
					case '^': {
						
						if (stack.IsEmpty()) stack.Push(ishodnoe[i]);
						else {

							while (priority(string(1, ishodnoe[i])) <= priority(stack.Top())) {
								working.append(stack.Top());
								stack.Pop();
								if (stack.IsEmpty()) break;
							}
							stack.Push(ishodnoe[i]);
							
							
						}
						break;
					}
					default: throw "idk thats exception";
					}
				}
			}
			else continue;
		}
		while (stack.IsEmpty() == false) {
			working.append(stack.Top());
			stack.Pop();
		}
		//тут идет из постпрефиксной в стек и вычисления
		cout << working << '\n';
		checked = -1;
		string second1;
		string first1;
		for (int i = 0; i < working.length(); i++) {
;			if (i > checked) {
				if (working[i] >= '0' && working[i] <= '9') {

					checked = i;
					for (int j = i; j < working.length(); j++) {
						if (working[j] >= '0' && working[j] <= '9') {


							checked = j;
						}
						else break;
					}
					stack.Push(working.substr(i, checked - i + 2));
					checked += 1;
				}
				else {
					checked = i;
					if (working[i] != 'c' && working[i] != 's') {
						second1 = stack.Top();
						stack.Pop();
						first1 = stack.Top();
						stack.Pop();
						switch (working[i])
						{
						case '+':
							stack.Push(Plus(first1 + "+" + second1));
							break;
						case '-':
							stack.Push(Minus(first1 + "-" + second1));
							break;
						case '*':
							stack.Push(Multiply(first1 + "*" + second1));
							break;
						case '/':
							stack.Push(Divide(first1 + "/" + second1));
							break;
						case '^':
							stack.Push(Exponentiation(first1 + "^" + second1));
							break;
						default: throw "something isnt good";
						}
					}
					else {
						
						second1 = stack.Top();
						stack.Pop();
						switch (working[i])
						{
						case 's':
							stack.Push(Sinus("s" + second1));
							break;
						case 'c':
							stack.Push(Cosinus("c" + second1));
							break;
						default: throw "something isnt good";
						}
					}
				}
			}
		}
		//тут идет запись результата с вершины стека в out
		if (type == 1) out = stoi(stack.Top().erase(stack.Top().length()-1, 1));
		else out = stod(stack.Top().erase(stack.Top().length() - 1, 1));

	}
	~Calculator()
	{
		ishodnoe.clear();
		working.clear();
	}
};

