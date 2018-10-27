#include "global.h"


/*	cmdList
没有将一种类型的value转换成另一种类型的命令，
只能DEL相应的key，再使用SET，
命令与key的类型不一致时会直接报错
--------Common------------
DEL key
TYPE key
ENCODING key
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
RPUSH key string
LPUSH key string
LINSERT key index
RPOP key
LPOP key
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
HSET key field
HMSET key, field1,string1,field2,string2,...
HEXIST key field
HCOUNT key //field数，即used值
HDEL key field
HINCREBY key field increment
HGETALL key
HGETALLFIELDS key
HGETALLVALUES key
*/
class ComandParser {
private:

public:

}