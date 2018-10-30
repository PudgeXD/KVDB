#include "global.h"
#include "dict.h"

class DB {
/*
cmd:
	del key
	rename key newName
	type key
	object encoding key

*/
private:
	NestHashTable* ht_;
	uint16_t connect_cli_;
	char* db_name_;

public:
	DB(uint64_t default_size = DB_HT_SIZE){
		ht_->init(DB_HT_SIZE);
		connect_cli_ = 0;
	}
	
	~DB(){
		delete HashTable;
	}

	void increase_connect() {
		connect_cli_++;
	}

	void decrease_connect() {
		connect_cli_--;
	}

	uint16_t get_cli_count() {
		return connect_cli_;
	}

	uint64_t get_keys_count() {
		return nht_->get_used();
	}

	void rename_db(const char new_name) {
		db_name_ = new_name;
	}

	void watch(const char key);
	
	void flush_DB();
}