#ifndef MEMBER_MEMBER_H_
#define MEMBER_MEMBER_H_

#include <string>

typedef char Interest;
typedef char Member_t;

const Interest VERY = 1;
const Interest SOMEWHAT = 2;
const Interest NOT = 3;
const Interest NONINITIALIZED = 0;


const Member_t KEY = 1;
const Member_t NTH = 2; //nice to have
const Member_t UNINITIALIZED = 0;

class Member {
public:
	std::string name;
	std::string street;
	std::string city;
	std::string state;
	std::string zip_code;
	Interest interest_level;
	Member_t type;
	Member() {name = "NULL"; street = "NULL";
	city = "NULL"; state = "NULL"; zip_code = -1;
	interest_level = NONINITIALIZED;
	type = UNINITIALIZED; }
	~Member() {}
	Member(const Member &member) {
	}
};

#endif /* MEMBER_MEMBER_H_ */
