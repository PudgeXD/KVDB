#include "global.h"

enum obj_type {string,list,set,ht};
enum obj_encoding {long_,embstr,string,linkedlist,intset,ht};

class Object { //多态的解决方案！！！！
private:
	uint8_t type;
	uint8_t encoding;
	void* ptr;   //string* or uint64_t* or 
	uint64_t ref_cout;
public:
	uint8_t get_type();

	uint8_t get_encoding();

	void* get_value();

	bool set_type();

	bool set_encoding();

	bool set_key(char* input);

	bool set_key(string input);

	void increase_ref();

	void decrease_ref();

	Object* create_string_object(string* value);

	Object* create_list_object(String* lines []);

	Object* create_set_object(int64_t elements[]);

	Object* create_set_object(String* elements[]);

	Object* create_ht_object(SSpair KVpairs[]);

	/*bool insert();

	bool remove();

	bool update_key(char* input);

	bool update_key(string input);

	bool update_ptr();*/

	bool release();
}

/*
字符串对象：ptr指向String类
列表对象：ptr指向LinkedList类，LinkedList内的Node的value指向
(ptr指向String类的Object类)
*/