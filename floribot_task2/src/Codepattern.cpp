/*
 * Codepattern.cpp
 *
 *  Created on: 19.06.2013
 *      Author: jps
 */

#include "Codepattern.h"

namespace floribot_task2 {

Codepattern::Codepattern(std::string codepattern) {
	// TODO Auto-generated constructor stub
	code = new std::string[codepattern.length()];
	code = codepattern;
	starts=get_Starts_Commands();

}

Codepattern::~Codepattern() {
	// TODO Auto-generated destructor stub
	delete code;
	delete starts;
}

bool Codepattern::check() {

	/*erlaubter Acsii-Code:
		 * | 70 -> "F" | 76 = "L" | 82 = "R" | 83 = "S" | 45 = "-" |
		 *  Zahlen "0" bis "9" entspricht ASCII 48 bis 57
		 */
		unsigned int i = 0;
		int iAscii; // Zeichen an Stelle i
		int iAsciiN;// Zeichen an Stelle i+1
		int iAsciiV;// Zeichen an Stelle i-1
		while (i < code.length())
			{
					iAscii = int(code[i]);
					if (i<code.size()-1) iAsciiN = int(code[i+1]);
					if (i>0) iAsciiV = int(code[i-1]);
				//printf("%i %i\n", iAscii, iAsciiN);

				if (iAscii == 70 or iAscii == 76 or iAscii == 82 or iAscii == 83 or iAscii == 45  or (iAscii >= 48 and iAscii <=57))
					{
						i++;
						if (i == code.length() and iAscii == 70)
							{
							printf("CodePattern akzeptiert\n");
							return true;
							}
						else if (i == code.length() and iAscii != 70){
							printf("CodePattern endet nicht mit 'F'");
							return false;
						}
						else	{
							printf("CodePattern unbekannt");
							return false;
							}
					}
				else
					{
						printf("###########################\n");
						printf("  Launchscript überprüfen\n");
						printf("   Fehler im CodePattern\n");
						if (iAscii == 32) printf("  Stelle %i , Leerzeichen \n",i);
						else printf("  Stelle %i, '%c' n.def.\n",i+1, code[i]);
						printf("###########################\n");
						i = code.length();
						return false;
					}
				if (iAscii >= 49 && iAscii <=57 && !(iAsciiN != 76 xor iAsciiN != 82) )
					{//Prüft ob nach Stelle i (mit Zahl) ein Richtungszeichen kommt, wenn nein
						printf("###########################\n");
						printf("  Launchscript überprüfen\n");
						printf("   Fehler im CodePattern\n");
						printf("  Stelle %i, Zeichen '%c'\n",i+1, code[i]);
						printf("  Muss 'L' oder 'R' sein\n");
						printf("###########################\n");
						i = code.length();
						return false;
					}
				if ((iAscii == 76 or iAscii == 82) && !(iAsciiV >= 49 && iAsciiV <=57) )
					{//Prüft ob vor Stelle i (mit Richtungszeichen) eine Zahl kommt
						printf("###########################\n");
						printf("  Launchscript überprüfen\n");
						printf("   Fehler im CodePattern\n");
						printf("  Stelle %i, Zeichen Fehler\n",i);
						//printf("  Zeichen zuviel \n");
						printf("###########################\n");
						i = code.length();
						return false;
					}
			}

}

bool Codepattern::get_Direction(int n) {
	// Directions: true = left , false = right
	if (code[n] = "R") return false;
	if (code[n] = "L") return true;
}

int Codepattern::get_Rows(int n) {
	/*erlaubter Acsii-Code:
	 *  Zahlen "0" bis "9" entspricht ASCII 48 bis 57
	 */
	int ascii = int(code[n]);

	switch (ascii){

	case 48: return 0;
		break;
	case 49: return 1;
		break;
	case 50: return 2;
		break;
	case 51: return 3;
		break;
	case 52: return 4;
		break;
	case 53: return 5;
		break;
	case 54: return 6;
		break;
	case 55: return 7;
		break;
	case 56: return 8;
		break;
	case 57: return 9;
		break;
	default: return 0;
	}
}


int Codepattern::get_Amount_Commands() {
	int starts = 0;
		int i = 0;
		while (i<code.length)
		{
			if (int(code[i]) == 45) starts++;
			i++;
		}
		return starts;
}

int* Codepattern::get_Starts_Commands() {


	int start[get_Amount_Commands()];
	int i=0, n=0;
	while (i<code.length)
	{
		if (int(code[i]) == 45) // Ascii 45 = "-"
			{
			start[n]=i+1;
			n++;
			}
		i++;
	}
	return start;
}

} /* namespace floribot_task2 */
