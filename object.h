#include "global.h"

enum obj_type {STRING,LIST,SET,HT};
enum obj_encoding {LONGINT,EMBSTR,STRING,LINKEDLIST,INTSET,STRINGHT,NESTHT};

class Object {
private:
	uint8_t type_;
	uint8_t encoding_;
	void* ptr_;   
	uint64_t ref_cout_;
	uint32_t lru_;
public:
	uint8_t get_type();

	uint8_t get_encoding();

	uint64_t get_ref_count();

	void increase_ref();

	void decrease_ref();

	//判断两个字符串类型的对象是否相等
	void string_equal(Object* another);

	/*init函数内会自动根据所给的参数为对象设置相应的编码格式,
	若参数为空则报错
	*/
	void init_string_object(const char* value);

	void init_string_object(string* value);

	//多次调用linkedList的rpush
	void init_list(const char* lines []);

	void init_list(String* lines []);

	void init_set(int64_t elements[]);

	void init_set(const char* elements[]);

	void init_set(String* elements[]);

	void init_ht(SSpair KVpairs[]);

	//special
	void init_DBht(uint64_t size);

	bool key_type_error() {
		cout << "the type of key (" << ptr->c_str() << ") is error." << endl;
		return false;
	}

	/*add为聚集类型的对象追加string时，需要先判断一下
	当前的对象类型是否符合，不符合直接报错。
	符合再将参数转换为string对象进行追加操作，
	可能存在编码的转换
	*/
	bool add_list(const char* elements[],uint64_t pos);

	//调用add_list(elements[],0);
	bool add_list_left(const char* elements[]);

	//调用add_list(elements[],ptr->get_len());
	bool add_list_right(const char* elements[]);

	//须检查添加后是否会重复
	bool add_set(const char* elements[]);

	bool add_ht(const char* key,const char* value);

	/*update一开始执行时，需要判断当前对象类型是否符合，
	不符合报错。可能存在编码的转换，不存在类型转换的可能，
	想更改某个键所对应值的类型，只能删除这个键再创建
	*/

	//需判断value是否为整型，且大小被int64_t cover
	bool update_string(const char* value);

	bool update_list(const char* values[]);

	bool update_list_by_index(uint64_t index,const char* new_value);

	bool update_set(int64_t elements[]);

	bool update_set(const char* values[]);

	bool update_set(const char* old_value, const char* new_value);

	bool update_ht(SSpair KVpairs[]);

	bool update_ht_value(const char* key, const char* new_value);

	bool update_ht_key(const char* key,const char* new_key);

	/*同样需要检查类型是否与命令对应,记得delete掉所占用的内存
	*/
	bool remove_list_by_index(uint64_t index);

	bool remove_list(const char* value);

	bool remove_set(const char* value);

	bool remove_ht(const char* key);

	/*GET,同样需要类型检查
	*/
	Object** get_list_all_obj();

	const char** get_list_all_str();

	Object** get_list_between_obj(uint64_t beign,uint64_t end);

	const char** get_list_between_str(uint64_t beign,uint64_t end);

	Object* get_list_by_index_obj(uint64_t pos);

	const char* get_list_by_index_str(uint64_t pos);

	Object* get_list_by_value_obj(const char* value);

	const char* get_list_by_value_str(const char* value);

	const char* get_string();

	//释放ptr指针并置为null
	bool release();
}

