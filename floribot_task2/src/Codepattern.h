/*
 * Codepattern.h
 *
 *  Created on: 19.06.2013
 *      Author: jps
 */

#ifndef CODEPATTERN_H_
#define CODEPATTERN_H_
#include <string>
namespace floribot_task2 {

class Codepattern {
public:
	Codepattern(std::string code);
	virtual ~Codepattern();

	bool check();
	int get_Direction(int n);
	int get_Rows(int n);
	int get_Amount_Commands();
	void get_Starts_Commands();
	int command [20];


private:
	std::string code;
	static int gro;

};
} /* namespace floribot_task2 */
#endif /* CODEPATTERN_H_ */
