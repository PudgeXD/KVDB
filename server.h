#include "global.h"
#include "clietnStatus.h"
#include <time.h>
class server
{
private:
	uint32_t db_count_;
	DB* db_list_;
	LLpair* save_parameter_ ;
	uint64_t dirty_;
	time_t last_save_;

	LinkedClientStatus* client_list_;

public:
	server();
	~server();



	
};