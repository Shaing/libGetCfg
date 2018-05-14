#include "lib_get_cfg.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

unsigned int get_cfg(const char* cfilePath, char* result, const char* ckey)
{
		std::string 	Buf, Buf_chk, filePath(cfilePath), key(ckey);
		std::size_t		found = 0, found_chk = 0, errorCode = CANNT_FIND;
		std::fstream 	readPath;
		
		//std::cout << "filePath:" << filePath << std::endl;
		//std::cout << "getPath:" << result << std::endl;
		//std::cout << "key:" << key << std::endl;
		
		readPath.open(filePath.c_str(), std::ios::in);
		if(!readPath)
			 return OPEN_FILE_ERROR;
		
		while(getline(readPath, Buf), !readPath.eof())
		{
			if(readPath.bad())
			{
				errorCode = FILE_BAD;
				break;
			}						
			else if(readPath.fail())
			{
				errorCode = READ_FAIL;
				break;
			}
			
			if(Buf.size() == 0)
				continue;
			else if(Buf[0] == '[' || Buf[0] == ';' || Buf[0] == '#')
				continue;

			//std::cout << Buf << std::endl;	
			found = Buf.find(key);		
			if(found != std::string::npos)
			{
				found_chk = Buf.find("=");
				if(found_chk != std::string::npos)
				{
					//std::cout << "found_chk:" << found_chk << std::endl;
					Buf_chk = Buf.substr(0, found_chk);
					//std::cout << "Buf_chk:" << Buf_chk << std::endl;
					if(Buf_chk.size() == key.size())
					{
						//std::cout << "KEY:" << key << std::endl;
						//std::cout << "KEY SIZE:" << key.size() << std::endl;
						//std::cout << "found:" << found << std::endl;
						Buf = Buf.substr(found + key.size() + 1); // 1 means "="
						//std::cout << "Buf:" << Buf << std::endl;
						strcpy(result, Buf.c_str());
						errorCode = SUCCESSFUL;
						break;
					}
				}	
			}
		}
		
		readPath.clear();
		readPath.close();	
		
		//std::cout << "getPath:" << result << std::endl;

		return errorCode;	 
}

unsigned int get_cfg_ByTag(const char* cfilePath, char* result, const char* ckey, const char* ctag)
{
	std::string 	Buf, Buf_chk, filePath(cfilePath), key(ckey), tag(ctag);
	std::size_t		found = 0, found_chk = 0, errorCode = CANNT_FIND;
	std::fstream 	readPath;
	bool tagChk = false;

	tag = "[" + tag + "]";
	
	readPath.open(filePath.c_str(), std::ios::in);
	if(!readPath)
		 return OPEN_FILE_ERROR;
	
	while(getline(readPath, Buf), !readPath.eof())
	{
		if(readPath.bad())
		{
			errorCode = FILE_BAD;
			break;
		}						
		else if(readPath.fail())
		{
			errorCode = READ_FAIL;
			break;
		}
		
		if(Buf.size() == 0)	continue;
		else if(Buf[0] == ';' || Buf[0] == '#')	continue;
		else if(Buf[0] == '[' || tagChk == true)
		{
			if(Buf == tag || tagChk == true)
			{
				if(!tagChk)
				{
					tagChk = true; // first get tag
					continue;
				}
				else
				{   
					found = Buf.find(key);	// start find key
					if(found != std::string::npos)
					{
						found_chk = Buf.find("=");
						if(found_chk != std::string::npos)
						{
							Buf_chk = Buf.substr(0, found_chk);
							if(Buf_chk.size() == key.size())
							{
								Buf = Buf.substr(found + key.size() + 1); // 1 means "="
								strcpy(result, Buf.c_str());
								errorCode = SUCCESSFUL;
								break;
							}
						}	
					}
					else
					{
						if(Buf[0] == '[') // find key till meet next '[', it's a stop point.
						{
							break;
						}
					}
				}
			}		
		}
		continue;	
	}
	
	readPath.clear();
	readPath.close();	
	return errorCode;	 
}

unsigned int get_path(const char* cfilePath, char* result, const char* ckey)
{
	std::string 	Buf, Buf_chk, filePath(cfilePath), key(ckey);
	std::size_t		found = 0, found_chk = 0, errorCode = CANNT_FIND;
	std::fstream 	readPath;

	//std::cout << "filePath:" << filePath << std::endl;
	//std::cout << "getPath:" << result << std::endl;
	//std::cout << "key:" << key << std::endl;

	readPath.open(filePath.c_str(), std::ios::in);
	if(!readPath)
		return OPEN_FILE_ERROR;

	while(getline(readPath, Buf), !readPath.eof())
	{
		if(readPath.bad())
		{
			errorCode = FILE_BAD;
			break;
		}
		else if(readPath.fail())
		{
			errorCode = READ_FAIL;
			break;
		}

		if(Buf.size() == 0)
			continue;
		else if(Buf[0] == '[' || Buf[0] == ';' || Buf[0] == '#')
			continue;

		//std::cout << Buf << std::endl;	
		found = Buf.find(key);
		if(found != std::string::npos)
		{
			found_chk = Buf.find("=");
			if(found_chk != std::string::npos)
			{
				//std::cout << "found_chk:" << found_chk << std::endl;
				Buf_chk = Buf.substr(0, found_chk);
				//std::cout << "Buf_chk:" << Buf_chk << std::endl;
				if(Buf_chk.size() == key.size())
				{
					//std::cout << "KEY:" << key << std::endl;
					//std::cout << "KEY SIZE:" << key.size() << std::endl;
					//std::cout << "found:" << found << std::endl;
					Buf = Buf.substr(found + key.size() + 1); // 1 means "="
															  //std::cout << "Buf:" << Buf << std::endl;
					strcpy(result, Buf.c_str());
					errorCode = SUCCESSFUL;
					break;
				}
			}
		}
	}

	readPath.clear();
	readPath.close();

	//std::cout << "getPath:" << result << std::endl;

	return errorCode;
}

unsigned int get_path_ByTag(const char* cfilePath, char* result, const char* ckey, const char* ctag)
{
	std::string 	Buf, Buf_chk, filePath(cfilePath), key(ckey), tag(ctag);
	std::size_t		found = 0, found_chk = 0, errorCode = CANNT_FIND;
	std::fstream 	readPath;
	bool tagChk = false;

	tag = "[" + tag + "]";

	readPath.open(filePath.c_str(), std::ios::in);
	if(!readPath)
		return OPEN_FILE_ERROR;

	while(getline(readPath, Buf), !readPath.eof())
	{

		if(readPath.bad())
		{
			errorCode = FILE_BAD;
			break;
		}
		else if(readPath.fail())
		{
			errorCode = READ_FAIL;
			break;
		}

		if(Buf.size() == 0)	continue;
		else if(Buf[0] == ';' || Buf[0] == '#')	continue;
		else if(Buf[0] == '[' || tagChk == true)
		{
			if(Buf == tag || tagChk == true)
			{
				if(!tagChk)
				{
					tagChk = true;
					continue;
				}
				else
				{
					found = Buf.find(key);
					if(found != std::string::npos)
					{
						found_chk = Buf.find("=");
						if(found_chk != std::string::npos)
						{
							Buf_chk = Buf.substr(0, found_chk);
							if(Buf_chk.size() == key.size())
							{
								Buf = Buf.substr(found + key.size() + 1); // 1 means "="
								strcpy(result, Buf.c_str());
								errorCode = SUCCESSFUL;
								break;
							}
						}
					}
					else
					{
						if(Buf[0] == '[') // find key till meet next '[', it's a stop point.
						{
							break;
						}
					}
				}
			}
		}
		continue;
	}

	readPath.clear();
	readPath.close();
	return errorCode;
}

