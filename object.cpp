#include "object.h"

bool Object::set_int(int64_t value) {
	if(type_ != STRING) {
		return key_type_error();
	}
	if(encoding_ != LONGINT) {
		encoding_ = LONGINT;
		delete ptr_;
		ptr_ = 0;
		int64_t* ptr = new uint64_t;
		*ptr = value;
		ptr_ = ptr;
		return ptr_;
	} else {
		*ptr_ = value;
		return true;
	}
}