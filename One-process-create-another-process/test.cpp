#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <Windows.h>
#include <WinBase.h>

using namespace std;

#define MAX_COMMAND_LENGTH 100

bool input = false;
bool output = false;
int number_input = 0;
int number_output = 0;
int *Array;
char cmd[MAX_COMMAND_LENGTH];

void function() {
	if (input) {
		cmd[0] = 0;
		cout << GetCurrentProcessId() << endl;
		for (int i = 0; i < number_input;i++) {
			cin >> Array[i];
		}
		//cout << (int)Array<<endl;
		//int *a = Array;
#pragma warning(default:4996);
		char tmp[MAX_COMMAND_LENGTH >> 1];
		sprintf(tmp, "%d", number_input);
		strcpy(cmd, "test.exe -output ");
		strcat(cmd, tmp);
		strcat(cmd, " -array ");
		sprintf(tmp, "%d", Array);
		strcat(cmd, tmp);
		//WinExec(cmd,SW_SHOW);
		system(cmd);
	}
	if (output) {
		cout << GetCurrentProcessId() << endl;
		for (int i = 0; i < number_output; i++) {
			//cout <<Array[i]<<" dp ";
		}
	}
}

int AgrPos(char *str, int agrc, char**agrv) {
	int a;
	for (a = 1; a < agrc; a++) {
		if (!strcmp(str, agrv[a])) {	
			if (a == agrc - 1) {
				cout << "Agrument missing for " << str << endl;
				exit(1);
			}
			return a;
		}
	}
	return -1;
}

int main(int agrc, char **agrv) {
	int i;
	//cout << "agrc :" << agrc << endl;
	/*for (int a = 1; a < agrc; a++) {
		cout << agrv[a] << endl;
	}*/
	if (agrc == 1) {
		cout << "\t-input\n";
		cout << "\t-output\n";
		return 0;
	}
	if ((i = AgrPos("-input", agrc, agrv)) > 0) {
		input = true;
		number_input = atoi(agrv[i+1]);
		Array = new int[number_input];
		//cout << Array << endl;
	}
	if ((i = AgrPos("-output", agrc, agrv)) > 0) {
		output = true;
		number_output = atoi(agrv[i+1]);
	}
	if ((i = AgrPos("-array", agrc, agrv)) > 0) {
		Array = 0;
		Array = (int *)atoi(agrv[i + 1]);
		//cout << atoi(agrv[i + 1])<<endl;
		//cout << Array<<endl;
	}
	function();
	system("pause");
	return 0;
}