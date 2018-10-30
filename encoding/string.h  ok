#include <stdint.h>
#include "Buffer.h"

//string : public Buffer
class String : public Buffer{  //重载+ - << >> =
public:
	String(){}

	~String(){}

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

	//把字符串des的内容拷贝到本字符串
	void copy(String* des);

	String truncation(uint64_t begin, uint64_t end);

	void print(uint32_t fp=1);
}