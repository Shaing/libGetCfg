#include <iostream>
#include "lib_get_cfg.h"
using namespace std;

int main(int argc, char* argv[])
{
	char buf[512] = {0};
	cout << get_cfg_ByTag("cfg.ini", buf, "FirmwareVer", "DeviceSetting") << endl;
	cout << "ret:" << buf << endl;

    return 0;
}
