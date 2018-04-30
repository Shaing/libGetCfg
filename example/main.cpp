#include <iostream>
#include "lib_get_cfg.h"
#pragma comment(lib, "libGetCfg_vc140.lib")
using namespace std;

int main(int argc, char* argv[])
{
	char buf[512] = {0};
	//get_cfg_ByTag("cfg.ini", buf, "ALLEN", TAG_PUBLIC);
	get_path_ByTag("cfg.ini", buf, "ALLEN", TAG_PUBLIC);
	cout << "Hi! " << buf << endl;
	memset(buf, 0, 512);
	//get_cfg_ByTag("cfg.ini", buf, "DriverStrength", "Inno");
	get_path_ByTag("cfg.ini", buf, "DriverStrength", "Inno");
	cout << "Hi! " << buf << endl;
	memset(buf, 0, 512);
	//get_cfg_ByTag("cfg.ini", buf, "DriverStrength", "FlashSetting");
	get_path_ByTag("cfg.ini", buf, "DriverStrength", "FlashSetting");
	cout << "Hi! " << buf << endl;
	memset(buf, 0, 512);
	//get_cfg_ByTag("cfg.ini", buf, "ModelNum", "Inno");
	get_path_ByTag("cfg.ini", buf, "ModelNum", "Inno");
	cout << "Hi! " << buf << endl;
	memset(buf, 0, 512);
	//get_cfg_ByTag("cfg.ini", buf, "ModelNum", "DeviceSetting");
	get_path_ByTag("cfg.ini", buf, "ModelNum", "DeviceSetting");
	cout << "Hi! " << buf << endl;


	system("PAUSE");
	return 0;
}