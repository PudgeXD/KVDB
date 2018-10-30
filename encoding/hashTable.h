#include "global.h"
#include "object.h"

struct HTNode {
	//key must be String, no other types
	Object* key_;    
	Object* value_;
	HTNode* pre_;
	HTNode* next_;
}

class StringtHashTable {
	//the type of object of the value must be string
private:
	uint64_t len_;
	uint64_t used_;
	HTNode** table_[2];
	int64_t rehash_progress_;
	bool is_dbHT_;
public:
	StringHashTable():len_(0),used_(0),table_(0){}

	~StringHashTable(){} //delete all nodes in table 

	//malloc for table_, init len_,used_,rehash_progress_, is_dbHT_
	//if is_dbHT_ is true, the initial len_ is bigger
	bool init_ht(uint64_t len);

	uint64_t get_used(){
		return used_;
	}

	double get_ratio(){
		return (double)used_/len_;
	}

	uint64_t get_hash_value(Object* key);

	//Murmurhash3哈希算法
	uint64_t hash_function(Object* key);

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

	Object* get_value_obj(Object* key);

	char* get_value_str(Object* key);

	Object* get_value_multi_obj(Object** key,uint64_t count);

	char* get_value_multi_str(Object** key,uint64_t count);

	Object** get_all_keys_obj();

	char** get_all_keys_str();

	void release();
}

class NestHashTable : public StringHashTable {
	//the type of object of the value can be STRING,SET,LIST,HT
	//if the type is HT,the encoding must be STRINGHT
public:
	NestHashTable(){}
	~NestHashTable(){}

	//去调用对应key的value的Object里的方法
	bool add_list(const char* key,)





}