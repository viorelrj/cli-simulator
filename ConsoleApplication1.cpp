

#include <windows.h>
#include "cli.h"

using namespace std;


void check() {
	cout << "All devices checked\n";
}

void load() {
	cout << "OS was successfuly loaded\n";
}

void run() {
	cout << "Starting OS";
}


void boot() {
	check();

	Sleep(2000);
	load();
	Sleep(700);
	run();
	Sleep(4567);
}



int main(){
	//boot();
	startCLI();
}
