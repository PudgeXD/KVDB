#include <stdint.h>

class String {  //重载+ - << >> =
private:
	uint64_t capacity_;
	uint64_t used_;
	char* content_;
public:
	String():capacity_(0),used_(0),content_(0){}

	~String(){
		delete content_ [];
	}

	uint64_t get_capacity() {
		return capacity_;
	}

	uint64_t get_used(){
		return used_;
	}

	uint64_t get_len(){
		return used_;
	}

	bool set();

	bool set(char* input);

	//Count the ASCII of all character of the string
	int64_t to_int64();

	const char* c_str();

	//return to_int64(&this) - to_int64(another)
	//equal:0
	int64_t compare(String* another);

	void append(String* another);

	void append(String* another, uint64_t pos);

	String ret_append(String* another);

	String ret_append(String* another, uint64_t pos);

	void copy(String* des);

	String truncation(uint64_t begin, uint64_t end);

	bool write(void* addr);

	void print(uint32_t fp=1);
}