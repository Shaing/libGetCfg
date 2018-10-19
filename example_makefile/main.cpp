#include <iostream>
#include "lib_get_cfg.h"
using namespace std;

int main(int argc, char* argv[])
{
	// cout << write_cfg_ByTag("cfg.ini", "99", "FirmwareVer", "DeviceSetting") << endl;
	// cout << write_cfg_ByTag("cfg.ini", "99", "DrvCurrent", "FlashSetting") << endl;
	// cout << write_cfg_ByTag("cfg.ini", "99", "ScrambleEnable", "FwSetting") << endl;
	// cout << write_cfg_ByTag("cfg.ini", "99", "123", "456") << endl;
	// cout << write_cfg_ByTag("cfg.ini", "99", "123999", "456") << endl;
	// cout << write_cfg_ByTag("cfg.ini", "99", "789", "DeviceSetting") << endl;
	cout << ICFG::WritePrivateProfileString("DeviceSetting", "ModelNum", "99", "t1.ini") << endl; // MN
	cout << ICFG::WritePrivateProfileString("Inno", "2", "99", "t1.ini") << endl; // MN
	cout << ICFG::WritePrivateProfileString("Inno", "3", "99", "t1.ini") << endl; // MN

	// char buf[512] = {0};
	// cout << get_cfg_ByTag("t1.ini", buf, "drive_current", "Flash_Setting") << endl;
	// cout << "ret:" << buf << endl;

    return 0;
}
