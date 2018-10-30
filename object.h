#include "global.h"

enum obj_type {STRING,LIST,SET,HT};
enum obj_encoding {LONGINT,EMBSTR,STRING,LINKEDLIST,INTSET,STRINGHT,NESTHT};

/*
0.不必进行类型检查，类型检查在NestHashTable内进行
1.init函数内会自动根据所给的参数为对象设置相应的编码格式,若参数为空则报错.
2.注意是否会出现编码的变化
3.update一开始执行时，可能存在编码的转换，不存在类型转换的可能，想更改某个键所对应值的类型，
只能删除这个键再创建.
4.remove记得delete掉所占用的内存.
*/

class Object {
private:
	uint16_t type_;
	uint8_t encoding_;
	void* ptr_;   
	uint64_t ref_cout_;
	uint32_t lru_;
public:
	uint16_t get_type();

	uint16_t get_encoding();

	uint64_t get_ref_count();

	void increase_ref();

	void decrease_ref();
	/*------------------------string--------------------------*/
	int64_t str_to_ascii();

	//需考虑整型情况
	char* c_str();

	//判断两个字符串类型的对象是否相等
	void string_equal(Object* another);

	void string_init(const char* value);

	void string_init(string* value);

	//需判断value是否为整型，且大小被int64_t cover
	bool string_update(Object* value);

	uint64_t string_len();

	bool string_append(const char* value);

	char* string_get_range(uint64_t start,uint64_t end);

	bool string_increase(uint64_t inc);

	bool string_decrease(uint64_t dec);

	/*------------------------list----------------------------*/

	//多次调用linkedList的rpush
	void list_init(const char* lines []);

	void list_init(Object* lines []);

	bool list_add(Object* str,uint64_t pos);

	//调用add_list(str,0);
	bool list_lpush(Object* str);

	//调用add_list(str,ptr->get_len());
	bool list_rpush(Object* str);

	Object* list_lpop();

	Object* list_rpop();

	bool list_update(uint64_t index,Object* new_value);

	uint64_t list_len();	

	bool list_remove(uint64_t index);

	//Object** list_get_all();

	//Object** list_get_between(uint64_t beign,uint64_t end);

	Object* list_get_index(uint64_t pos);
	/*------------------------set-----------------------------*/

	void set_init(int64_t elements[]);

	void set_init(Object* elements[]);

	void set_init(String* elements[]);

	//须检查添加后是否会重复
	bool set_add(Object* elements[]);

	bool set_update(int64_t elements[]);

	bool set_update(Object* values[]);

	bool set_update(Object* old_value, Object* new_value);

	bool set_remove(Object* value);
	/*------------------------ht------------------------------*/

	void ht_init(SSpair KVpairs[]);

	bool ht_add(Object* key,Object* value);

	bool ht_update(SSpair KVpairs[]);

	bool ht_update_value(Object* key, Object* new_value);

	bool ht_update_key(Object* key,Object* new_key);

	bool ht_remove(Object* key);

	/*------------------------end-----------------------------*/
	bool key_type_error() {
		cout << "the type of key (" << ptr->c_str() << ") is error." << endl;
		return false;
	}




	//释放ptr指针并置为null
	bool release();
}

