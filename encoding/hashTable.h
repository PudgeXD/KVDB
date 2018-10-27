#include "global.h"
#include "object.h"

struct HTNode {
	//key must be String, no other types
	Object* key;    
	Object* value;
	HTNode* pre;
	HTNode* next;
}
class HashTable {
private:
	uint64_t len_;
	uint64_t used_;
	HTNode** table_[2];
	int64_t rehash_progress_;
	bool is_dbHT_; 
	//true时允许HTNode的value为HashTable类型的Object，反之不允许
public:
	HashTable():len_(0),used_(0),table_(0){}

	~HashTable(){} //delete all nodes in table 

	//malloc for table_, init len_,used_,rehash_progress_, is_dbHT_
	//if is_dbHT_ is true, the initial len_ is bigger
	bool init_ht(uint64_t len);

	uint64_t get_used(){
		return used_;
	}

	uint64_t get_hash_value(Object* key);

	//Murmurhash3哈希算法
	uint64_t hash_function(Object* key);
	
	//if 
	bool hset_int(Object* key,int64_t value) {
		HTNode* node = get_ht_node(key);
		if(node->key->type != 0) {
			cout << "the type of key:" << key->ptr->c_str() << "isnot string" << endl;
			return key_type_error(key);
		}

	}

	bool key_type_error(Object* key) {
		cout << "the type of key:" << key->ptr->c_str() << "isnot string" << endl;
		return false;
	}
	bool hset_string(Object* key,Object* value) {
		HTNode* node = get_ht_node(key);
		if(node->key->type != 0) {
			return key_type_error(key);
		}
	}

	bool hset_list(Object* key, Object* values []);

	bool hset_set(Object* key, int64_t elements[]);

	bool hset_set(Object* key, Object* elements[]);

	bool hset_ht(Object* key, SSpair KVpairs[]);

	char** get_all_keys();

	HTNode* get_ht_node(Object* key);

	Object* get_object(Object* key);

	bool update

	

	bool rename_key(char* key);

	bool rename_key(String* key);
	
	//destroy the key and the value no matter what type of it
	void destroy(String* key);
}