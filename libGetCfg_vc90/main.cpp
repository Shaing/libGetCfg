#include <iostream>
#include "lib_get_cfg.h"
#pragma comment(lib, "libGetCfg_vc90.lib")
using namespace std;

void test_tag(char *buf)
{
	get_path_ByTag(PATH_INI, buf, CSV_MV, TAG_PUBLIC);
	cout << "===================================================" << endl;
	cout << "TAG GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path_ByTag(PATH_INI, buf, LOG_MP, TAG_MP);
	cout << "===================================================" << endl;
	cout << "TAG GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path_ByTag(PATH_INI, buf, PACK_TARGET, TAG_PACK);
	cout << "===================================================" << endl;
	cout << "TAG GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path_ByTag(PATH_INI, buf, HYPE, TAG_PACK_SMI_HYPE);
	cout << "===================================================" << endl;
	cout << "TAG GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path_ByTag(PATH_INI, buf, JM_EXE, TAG_PACK_JM);
	cout << "===================================================" << endl;
	cout << "TAG GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path_ByTag(PATH_INI, buf, FLASH_INI_MV, TAG_PACK_MV);
	cout << "===================================================" << endl;
	cout << "TAG GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path_ByTag(PATH_INI, buf, PROCESS_INI, "TAG");
	cout << "===================================================" << endl;
	cout << "FAIL TAG GET:" << buf << endl;
	cout << "===================================================" << endl;
}


int main()
{
	char buf[512] = {'\0'};
	get_path(PATH_INI, buf, CSV_MV);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	
	get_path(PATH_INI, buf, CSV_JM);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, FW_MV);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, FW_JM);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, CONFIG);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, LOG_RETRY);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, LOG_RETRY_TIMEOUT);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, LOG_MP);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, LOG_SN_CHANGE);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, LOG_SN_CHECK);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, PACK_TARGET);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, SMI);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, HYPE);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, STD_FOLDER);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, FLASH_INI_MV);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, FLASH_INI_JM);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, CSV_MV_START_COL_POS);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, CSV_JM_START_COL_POS);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	
	
	get_path(PATH_INI, buf, JM_EXE);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, JM_INI);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, PACK_KEY);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, MV_FILE_FOLDER);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, MV_EXE);
	cout << "===================================================" << endl;
	cout << "GET:" << buf << endl;
	cout << "===================================================" << endl;
	get_path(PATH_INI, buf, PROCESS_INI);
	cout << "===================================================" << endl;
	cout << "FAIL GET:" << buf << endl;
	cout << "===================================================" << endl;
	test_tag(buf);

	system("PAUSE");
	return 0;
}