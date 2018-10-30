
class ClientStatus {
private:
	DB* db_; //current use
	uint32_t db_index_;
	int32_t fd_;
	char* cmd_;
	char* addr_;
	uint16_t status_;

	Buffer* receive_;
	Buffer* reply_;

	uint16_t argc_;
	//char** argv_; Object* arv_;
}

class LinkedClientStatus {
private:
	LinkedClientStatus* pre;
	LinkedClientStatus* next;
}