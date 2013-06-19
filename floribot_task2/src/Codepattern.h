/*
 * Codepattern.h
 *
 *  Created on: 19.06.2013
 *      Author: jps
 */

#ifndef CODEPATTERN_H_
#define CODEPATTERN_H_

namespace floribot_task2 {

class Codepattern {
public:
	Codepattern(std::string code);
	virtual ~Codepattern();

	bool check();
	bool get_Direction(int n);
	int get_Rows(int n);
	int get_Amount_Commands();
	int* get_Starts_Commands();


private:
	std::string code;
	int starts[get_Amount_Commands()];
};
} /* namespace floribot_task2 */
#endif /* CODEPATTERN_H_ */
