#include "cl_application.h"

cl_application::cl_application(cl_base* p_head_object) : cl_base(p_head_object){}
	
	
void cl_application::build_tree_objects()
{
	string s_head, s_sub;
	cl_base* p_head = this;
	cl_base* p_sub = nullptr;
	
	cin >> s_head;
	this->set_object_name(s_head);
	p_head = this;
	
	while(true)
	{
		cin >> s_head >> s_sub;
		
		if(s_head == s_sub)
			break;
		if(p_sub != nullptr && s_head == p_sub->get_object_name())
			p_head = p_sub;
		
		if (p_sub != nullptr && p_head->get_subordinate_object(s_sub) == nullptr && s_head == p_head->get_object_name())
			p_sub = new cl_1(p_head, s_sub);
	}
}
int cl_application :: exec_app() {
	
	cout << this->get_object_name();
	this->print_tree();
	return 0;
};
