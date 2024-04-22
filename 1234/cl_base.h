#ifndef __CL_BASE__H
#define __CL_BASE__H
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class cl_base
{
private:
	string s_object_name;
	cl_base * p_head_object;
	vector <cl_base*> subordinate_objects;
public:
	cl_base (cl_base * p_head_object, string s_object_name = "Object_root");
	cl_base();
	bool set_object_name (string s_new_object_name);
	string get_object_name ();
	void print_tree();
	//void change_head_object (cl_base * p_head_object);
	//cl_base* get_head_object ();
	cl_base* get_subordinate_object(string s_object_name);
	//unsigned int subordinate_objects_count ();
	~cl_base();
	int getsize();
};
#endif