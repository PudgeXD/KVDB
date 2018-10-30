#include "global.h"
#include "object.h"

struct HTNode {
	//key must be String, no other types
	Object* key_;    
	int64_t ascii_of_key_;  //加速查询
	Object* value_;
	HTNode* pre_;
	HTNode* next_;
}

class RawHashTable {
private:
	uint64_t len_;
	uint64_t used_;
	HTNode** table_[2];
	int64_t rehash_progress_;
public:
	RawHashTable():len_(0),used_(0),table_(0),rehash_progress_(-1){}
	~RawHashTable(){}

	uint64_t get_used(){
		return used_;
	}

	double get_ratio(){
		return (double)used_/len_;
	}

	bool init_ht(uint64_t len);

	uint64_t get_hash_value(Object* key);

	//Murmurhash3哈希算法
	uint64_t hash_function(Object* key);

	void rehash();
}

class StringtHashTable : public RawHashTable{
	//the type of object of value must be STRING
public:
	StringHashTable(){}

	~StringHashTable(){} //delete all nodes in table 

	//需要考虑rehash的情况，如果rehash_progress_大于等于0，则
	//先搜索table[1]，没有再搜索table[0]
	HTNode* get_ht_node(Object* key);

	bool add(Object* key,Object* value);

	bool remove(Object* key);

	bool remove(Object** key,uint64_t count);

	//不存在直接报错
	bool update_key(Object* old_key,Object* new_key);

	//update时，若key不存在则调用add
	bool update_value(Object* key,Object* new_value);

	bool update_value_multi(ObjPair KVpairs[],count);

	bool increase(Object* key,uint64_t inc);

	bool decrease(Object* key,uint64_t dec);

	bool exist(Object* key);

	char* get_value_str(Object* key);

	char* get_value_multi_str(Object** key,uint64_t count);

	char** get_all_keys_str();

	void release();
}

class NestHashTable : public RawHashTable {
	//the type of object of the value can be STRING,SET,LIST,HT
	//if the type is HT,the encoding must be STRINGHT
public:
	NestHashTable(){}
	~NestHashTable(){}

	bool obj_type_check(uint16_t type,uint16_t ecoding,Object* obj);

	//该函数通过key算出槽，再将key转换为Object去一个一个比对槽里的Node哪个匹配
	Node* get_ht_node(const char* key);

	/*-----------------------------common----------------------------*/

	//DEL key
	bool del_key(const char* key);

	//TYPE key
	uint16_t get_type(const char* key);

	//ENCODING key
	uint16_t get_encoding(const char* key);

	/*-----------------------------string----------------------------*/

	//SET key string
	bool string_set(const char* key,const chat* value);

	//LEN key
	uint64_t string_len(const char* key);

	//APPEND key string
	bool string_append(const char* key,const char* value);

	//GETRANGE key start end
	char* string_get_range(const char* key,uint64_t start,uint64_t end);

	//GET key
	Object* string_get(const char* key);

	//INCRE key amount
	bool string_increase(uint64_t inc);

	//DECRE key amount
	bool string_decrese(uint64_t dec);
	/*-----------------------------list------------------------------*/
	//LINSERT key index string,call node->value->list_add()
	bool list_add(const char* key,uint64_t pos,,const char* str);

	//LPUSH key string,call node->value->list_lpush()
	bool list_lpush(const char* key,const char* str);

	//RPUSH key string,call node->value->list_rpush()
	bool list_rpush(const char* key,const char* str);

	//RPOP key
	Object* list_lpop(const char* key);

	//LPOP key
	Object* list_rpop(const char* key);

	//LSET key index string
	bool list_update(const char* key,uint64_t index,const char* new_value);

	//LLEN key
	uint64_t list_len(const char* key);

	//LREMOVE key index
	bool list_remove(uint64_t index);

	//LGET key index
	Object* list_get_index(uint64_t index);

	







}