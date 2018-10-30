#include "global.h"

struct listNode {
	Object* value;
	listNode* pre;
	listNode* next;
	uint64_t index;  
	//从0开始，链表是有序的，但删除和左插代价很大，有什么解决办法？？？
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
	uint64_t get_len();

	//记得维护node的索引值
	bool lpush(Object* value);

	bool rpush(Object* value);

	/*例如pos值为1，则插入的这个object的下标为1，
	原下标1的node变为2，往后的node依次顺延
	需要判断pos的大小是否超过链表的长度*/
	bool insert_before(Object* value, uint64_t pos);

	//pop操作除了返回还需要删除该listNode，但不释放value的object
	Object* lpop(Object* value);

	Object* rpop(Object* value);


	Object* get_by_index(uint64_t pos);

	Object** get_between(uint64_t begin, uint64_t end);

	listNode* get_head() {
		return head_;
	}

	listNode* get_tail() {
		return get_by_index(len_-1);
	}

	bool remove_by_index(uint64_t pos);

	bool remove_by_value(Object* value);

	bool update_by_index(uint64_t pos, Object* new_value);

	bool update_by_value(Object* value, Object* new_value);

	//删除所有node
	bool release();
}
