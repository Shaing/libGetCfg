#include <iostream>
#include "lib_get_cfg.h"
#pragma comment(lib, "libGetCfg_vc140.lib")
using namespace std;

int main(int argc, char* argv[])
{
	char buf[512];
	get_cfg_ByTag("cfg.ini", buf, "ALLEN", TAG_PUBLIC);

	cout << "Hi! " << buf << endl;

	system("PAUSE");
	return 0;
}