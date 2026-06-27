#pragma once
#include "Admin.h"
#include "Client.h"
#include "Employee.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Parser
{
public:
	static vector<string> split(string line) {
		vector<string> result;
		stringstream ss(line);
		string word;
		while (getline(ss, word, '&')) {
			result.push_back(word);
		}
		return result;
	}
	static Client parserToClient(string line) {
		vector<string> info = split(line);
		int id = stoi(info[0]);
		double balance = stod(info[3]);
		return Client(id, info[1], info[2], balance);
	
	}
	static Employee parserToEmployee(string line) {
		vector<string> info = split(line);
		int id = stoi(info[0]);
		double salary = stod(info[3]);
		return Employee(id, info[1], info[2], salary);
	
	}
	static Admin parserToAdmin(string line) {
		vector<string> info = split(line);
		int id = stoi(info[0]);
		double salary = stod(info[3]);
		return Admin(id, info[1], info[2], salary);
	}


};

