#include <stdint.h>

class Buffer {
private:
	uint64_t capacity_;
	uint64_t used_;
	char* content_;
public:
	Buffer():capacity_(0),used_(0),content_(0){}
	~Buffer(){
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

	uint64_t get_free() {
		return capacity_ - used_;
	}

	//注意检查是否能容得下，容不下申请一块新的内存
	bool write(char* input);

	bool write(uint64_t pos, char* input);

	void append(char* input) {
		write(used_,input);
	}
}