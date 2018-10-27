#include "global.h"

struct listNode {
	String* value;
	listNode* pre;
	listNode* next;
	uint64_t index;  //代价很大，有什么解决办法？？？
}

//ordered
class LinkedList {
private:
	listNode* head_;
	uint64_t len_;

public:
	
	LinkedList():head_(0),len_(0){}
	
	~LinkedList(){
		release();
	}

	listNode* get_head();

	listNode* get_tail();

	
	bool lpush(String* value);

	bool rpush(String* value);

	bool insert_before(String* value, uint64_t pos);

	String* lpop(String* value);

	String* rpop(String* value);

	String* get_by_index(uint64_t pos);

	String** get_between(uint64_t begin, uint64_t end);

	bool remove_by_index(uint64_t pos);

	bool remove_by_value(String* value);

	bool update_by_index(uint64_t pos, String* new_value);

	bool update_by_value(String* value, String* new_value);

	bool release();
}