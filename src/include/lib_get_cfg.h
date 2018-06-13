#ifndef __LIB_GET_PATH_H__  
#define __LIB_GET_PATH_H__
#define GCFGVER "v0.0.2"

#define	PATH_INI ".\\path.ini"
#define	J_INI	".\\jsetting.ini"
#define	CONFIG_INI ".\\qcheck_setting.ini"
/* ===================================================== */
#define TAG_PUBLIC "PUBLIC"
#define CSV_MV	"CSV_MV"
#define CSV_JM	"CSV_JM"
#define	FW_MV		"FW_MV"
#define	FW_JM		"FW_JM"
#define	CONFIG		"CONFIG"
#define MV_FILE_FOLDER	"MV_FILE_FOLDER"
/* ===================================================== */
#define TAG_MP "MP"
#define	LOG_RETRY	"LOG_RETRY"
#define	LOG_RETRY_TIMEOUT	"LOG_RETRY_TIMEOUT"
#define	LOG_MP			"LOG_MP"
#define	LOG_SN_CHANGE	"LOG_SN_CHANGE"
#define	LOG_SN_CHECK	"LOG_SN_CHECK"
#define PACK_MP_SMI "PACK_MP_SMI"

/* ===================================================== */
#define TAG_SATA "SATA"
#define	SATA_MP	"SATA_MP"
#define SATA_DIO "DIO"
#define ST_DIR "ST_DIR"
#define ST_EXE "ST_EXE"
/* ===================================================== */
#define TAG_PACK "PACK"
#define PACK_EXE "PACK_EXE"
#define	PACK_TARGET	"PACK_TARGET"
/* ===================================================== */
#define TAG_PACK_SMI_HYPE "PACK_SMI_HYPE"
#define	SMI		"SMI"
#define	HYPE	"HYPE"
#define	STD_FOLDER	"STD_FOLDER"
/* ===================================================== */
#define TAG_PACK_JM "PACK_JM"
#define	CSV_JM_START_COL_POS	"CSV_JM_START_COLUMN_POS"
#define	FLASH_INI_JM	"FLASH_INI_JM"
#define	JM_EXE	"JM_EXE"
#define	JM_INI	"JM_INI"
#define	PACK_KEY	"PACK_KEY"
#define JM_FLASH_CHECK "JM_FLASH_CHECK"
/* ===================================================== */
#define TAG_PACK_MV "PACK_MV"
#define	FLASH_INI_MV	"FLASH_INI_MV"
#define	CSV_MV_START_COL_POS	"CSV_MV_START_COLUMN_POS"
#define	PROCESS_INI	"PROCESS_INI"
#define	MV_EXE	"MV_EXE"
/* ===================================================== */
#define TAG_J_SETTING "setting"
#define J_COMPORT "comport_num"
#define J_t_interval "timer_interval"

#define	CONFIG_INI ".\\qcheck_setting.ini"
#define TAG_MODE "MODE"
#define CMP_SOURCE "CmpSource"
#define CHK_MODE "CheckMode"
#define CHK_SN "CheckSN"
#define TAG_SMART "SMART"
#define LTB "LTB"
#define R_LTB "RLTB"
#define W_LTB "WLTB"
#define E_LTB "ELTB"
#define UPC "UPC"
#define MV_CHK_UPC "MV_CHK_UPC"
#define ANG_EC "AVG_EC"
#define ECC_CNT "ECC"
#define MAX_ECC "MAX_ECC"
#define RETRY_CNT "RETRY_CNT"
#define TAG_LOG "LOG"
#define LOG_PATH "LogPath"
#define RTY_FIND_CNT "RetryFindCount"
#define CRC_CNT "CRC_CNT"
#define INNOURL "PSC_URL"

#define LIB_EXPORT	__declspec(dllexport)

enum
{
	SUCCESSFUL = 0,
	FILE_BAD,
	READ_FAIL,
	OPEN_FILE_ERROR,
	CANNT_FIND,
};

/* ===================================================== */

#ifdef _WIN32
#ifdef __cplusplus
	extern "C" 
	{
#endif
		LIB_EXPORT unsigned int get_cfg(const char* cfilePath, char* result, const char* ckey);
		LIB_EXPORT unsigned int get_cfg_ByTag(const char* cfilePath, char* result, const char* ckey, const char* ctag);
		LIB_EXPORT unsigned int get_path(const char* cfilePath, char* result, const char* ckey); //keep old for old proj
		LIB_EXPORT unsigned int get_path_ByTag(const char* cfilePath, char* result, const char* ckey, const char* ctag); //keep old for old proj
#ifdef __cplusplus
	}
#endif
#else
	unsigned int get_cfg(const char* cfilePath, char* result, const char* ckey);
	unsigned int get_cfg_ByTag(const char* cfilePath, char* result, const char* ckey, const char* ctag);
	unsigned int get_path(const char* cfilePath, char* result, const char* ckey); //keep old for old proj
	unsigned int get_path_ByTag(const char* cfilePath, char* result, const char* ckey, const char* ctag); //keep old for old proj
#endif

#endif //__LIB_GET_PATH_H__