#pragma once
#include <string>

using namespace std;

struct  Elem {
	int val = NULL;
	Elem* next = NULL;
	Elem(int val, Elem* next) : val(val), next(next) {};
};

class Set {
	Elem* start;
public:
	Set();
	bool f2();
	bool f3(int a);
	void f4(int val);
	Set(int count, int min, int max, int del);
	int f6();
	string f7(char divider);
	~Set();
	bool f9(Set* B);
	bool f10(Set* B);
	Set f11(Set* B);
	Set f12(Set* B);
	Set f13(Set* B);
	Set f14(Set* B);
};
