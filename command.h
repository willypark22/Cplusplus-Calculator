#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	public:
		OpCommand(double value) {
			init = 1;
			root = new Op(value);
	};
};

class AddCommand : public Command {
	public:
		AddCommand(Command* c, double value) {
			Op* lhs = new Op(c->execute());
			Op* rhs = new Op(value);
			root = new Add(lhs, rhs);
		};
};

class SubCommand : public Command {
	
};

class MultCommand : public Command {
	//MultCommand Code Here
};

class SqrCommand : public Command {
	//SqrCommand Code Here
};

#endif //__COMMAND_CLASS__
