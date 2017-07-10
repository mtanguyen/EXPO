#include "functions"

#include <iostream>
#include <string>
#include <fstream>
#include <vector> 

class Word{
private:
	string word;
	string type;
	int place;
public:
	Word();
} word;

class Subject{
private:
	vector<word> *subjects;
public:
	Subject();
	void find_Subjects();
}subject;

class Action{
private:
	vector<word> *actions;
public:
	Action();
	void find_Actions();
}action;

class Result{
private:
	vector<word> *result;
public:
	Result();
	void find_Results();
}result;