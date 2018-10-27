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
	HashTable* ht_;
	uint16_t connect_cli_;

public:
	DB(uint64_t default_size = DEFAULT_INIT_HT_SIZE){
		ht_ = new HashTable(default_size);
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
}