#ifndef __CL_APPLICATION__H
#define __CL_APPLICATION__H
#include "cl_base.h"
#include "cl_1.h"
class cl_application : public cl_base {
public:
	cl_application(cl_base* p_head_object);
	void build_tree_objects ();
	int exec_app ();
	
};


#endif
