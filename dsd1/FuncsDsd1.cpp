#include <iostream>
#include "Header.h"

Set::Set() {
	start = NULL;
}

bool Set::f2() {
	return start == NULL;
}

bool Set::f3(int a) {
	Elem* curEl = start;
	if (f2()) return false;
	while (curEl != NULL)
	{
		if (curEl->val == a) return true;
		curEl = curEl->next;
	}
	return false;
}

void Set::f4(int val)
{
	if (f3(val)) return;
	start = new Elem(val, start);
}

Set::Set(int count, int min,int max, int del)
{
	Elem*prev;
	if (count < 0) 
	{
		start = NULL;
	}
	else if (max - min < count)
	{
		start = NULL;
	}
	for (int i = 1; i < count+1; i++)
	{
		int minR = 0;
		int maxR = max / del - 1;
		int mult = del;
		prev = start;
		while (start == prev)
		{
			f4(min + (rand() % (maxR - minR + 1) + minR) * mult);
		}
	}
}

int Set::f6() 
{
	int len = 0;
	Elem* cur = start;
	if (f2()) return 0;
	while (cur != NULL)
	{
		cur = cur->next;
		len++;
	}
	return len;
}

string Set::f7(char divider)
{
	string rez = "";
	Elem* cur = start;
	if (f2()) return "";
	while (cur != NULL)
	{
		rez+= to_string(cur->val);
		rez += divider;
		cur = cur->next;
	}
	return rez.substr(0,(rez.length() - 1));
}

Set::~Set()
{	
	Elem* prev;
	if (f2()) start =  NULL;
	while (start != NULL)
	{
		prev = start;
		start = start->next;
		delete prev;
	}
}

bool Set::f9 (Set* B)
{
	if (f2()) return true;
	Elem* curA = start;
	while (curA != NULL)
	{		
		if (!B->f3(curA->val)) return false;
		curA = curA->next;
	}
	return true;
}

bool Set::f10(Set* B)
{
	return (f9(B) && B->f9(this));
}

Set Set::f11(Set* B)
{
	Elem* curA = start;
	Elem* curB = B->start;
	Set C = Set();
	Elem* addingElem;
	while (curA != NULL) {
		C.f4(curA->val);
		curA = curA->next;
	}
	while (curB != NULL) {
		C.f4(curB->val);
		curB = curB->next;
	}
	return C;
}

Set Set::f12(Set* B)
{
	Set Crossinng = Set();
	if (f2() || B->f2() )return Crossinng;
	Elem* curB = B->start;
	while (curB != NULL)
	{
		if(f3(curB->val)) Crossinng.f4(curB->val);
		curB = curB->next;
	}
	return Crossinng;
}

Set Set::f13(Set* B)
{	
	Set Diff = Set();
	Elem* curA = start;
	if (f2()) return Diff;
	while (curA != NULL)
	{
		if (!B->f3(curA->val)) Diff.f4(curA->val);
		curA = curA->next;
	}
	return Diff;
}

Set Set::f14(Set* B)
{
	return f13(B).f11(&B->f13(this));
}