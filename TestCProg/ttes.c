//
//  Test C Code on Visual Studio Code!! I'm gonna put this on GitHub for testing & learning
//  DEV. DO YOUNNG
//
#include <stdio.h>
#include <Windows.h>

#define err -1

BOOL setpnt(SHORT x, SHORT y);
BOOL setpntcrd(COORD crd);
void ErrorHandling(CHAR* WhereError, BOOL doExit);


int main(void){
    COORD consoleCenter = {25, 5};
    if(setpntcrd(consoleCenter) == err) {ErrorHandling("setpntcrt:17", TRUE);}
    puts("hello, Visual Studio Code!!\n");
    //add selection func hereV
    
    return 0;
}

BOOL setpnt(SHORT x, SHORT y) {
	COORD position = { x, y };
	if (!SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position)) {
		return -1;
	}
	else { return 0; }
}

BOOL setpntcrd(COORD crd) {
	if (!SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd)) {
		return -1;
	}
	else { return 0; }
}

void ErrorHandling(CHAR* WhereError, BOOL doExit) {
	//if doExit Parameter is FALSE, the Fucntion do not kill the process(calling ExitProcess function)
	LPTSTR lpMsgBuf;
	DWORD dw = GetLastError();

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dw,
		MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
		(LPTSTR)&lpMsgBuf,
		0,
		NULL);

	system("cls");
	printf_s("\n! ERROR OCCURED >>> ");
	puts(WhereError);
	printf_s("! SYSTEM ERROR CODE >>> %lu\n! ERROR >>> ", dw);
	puts(lpMsgBuf);
	puts("");

	LocalFree(lpMsgBuf);
	system("PAUSE");
	if (doExit != FALSE) {
		ExitProcess(dw);
	}
}