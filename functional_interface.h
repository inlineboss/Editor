#ifndef FUNCTIONAL_INTERFACE_H_
#define FUNCTIONAL_INTERFACE_H_

class Draw_interface{
public:
	virtual void draw () = 0;
	virtual ~Draw_interface(){};
};

class Remove_interface{
public:
	virtual void remove () = 0;
	virtual ~Remove_interface(){};
};

class Name_interface{
public:
	virtual std::string is_name() = 0;
	virtual ~Name_interface(){};
};

#endif /* FUNCTIONAL_INTERFACE_H_ */
