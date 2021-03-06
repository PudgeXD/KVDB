#include "global.h"


/*	cmdList
没有将一种类型的value转换成另一种类型的命令，
只能DEL相应的key，再使用SET，
命令与key的类型不一致时会直接报错
--------db----------------
CD dbname;
CD db_index;

--------Common------------
DEL key
TYPE key
ENCODING key
all clients
--------String------------
GET key
SET key string //不存在则创建，若
LEN key
APPEND key string
GETRANGE key start end
数字
INCRBY key amount
DECRBY key amount
---------List-------------
RPUSH key string          ok
LPUSH key String          ok
LINSERT key index string  ok
RPOP key                  ok
LPOP key                  ok
LSET key index string
LLEN key
LGET key index
!!!BLPOP
!!!BRPOP
---------Set--------------
SADD key string1,string2,...
SREMOVE key string1,string2,...
SISIN key strnig
SGET key
SCARD key
SMOVE sourKey desKey string
SINTER key1，key2,...
SUNION key1, key2,...
SDIFF  key1, key2,...
SINTERSTORE desKey, key1, key2,...
SUNIONSTORE desKey, key1, key2,...
SDIFFSTORE  desKey, key1, key2,...
--------HashTable--------
HGET key field
//hashTable multi get,若其中某些field不存在时不报错
HMGET key, field1,field2,...  
HSET key field string
HMSET key, field1,string1,field2,string2,...
HEXIST key field
HCOUNT key //field数，即used值
HDEL key field
HMDEL key field1,field2,...
HINCREBY key field increment
HDECREBY key field decrement
HGETALL key
HGETALLFIELDS key
HGETALLVALUES key
--------持久化-----------
SAVE
BGSAVE
*/
class ComandParser {
private:

public:

}


/*
tips:
	值为字符串时必须用双引号括起来。
*/