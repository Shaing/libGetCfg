#include "lib_get_cfg.h"
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

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
	using std::cout;
	using std::endl;
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

unsigned int write_cfg_ByTag(const char* cfilePath, const char* value, const char* ckey, const char* ctag)
{
	using std::cout;
	using std::endl;
	using std::string;

	string 	Buf, Buf_key_chk, filePath(cfilePath), key(ckey), tag(ctag), value_(value), storetag, oldkey, oldvalue;
	std::size_t		found = 0, found_equal_chk = 0, errorCode = CANNT_FIND;
	std::fstream 	readPath;
	std::fstream 	writePath;
	bool tagChk = false;
	bool keyChk = false;

	std::map<string,std::vector<std::pair<string,string>>> IniAllValues;
	std::set<string> CollectAllTag;

	tag = "[" + tag + "]";

	readPath.open(filePath.c_str(), std::ios::in);

	if(!readPath)
	{
		readPath.open(filePath.c_str(), std::ios::app);
		if(!readPath)
			return OPEN_FILE_ERROR;
	}
	
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
		else if(Buf[0] == ';' || Buf[0] == '#' )	
			continue;
		else if(Buf[0] == '[' || tagChk == true)
		{
			if(Buf[0] == '[')
			{
				storetag.clear();
				storetag = Buf;
				CollectAllTag.insert(Buf);
				tagChk = true;
			}
			else if(tagChk == true && Buf[0] != '[')
			{   
				found_equal_chk = Buf.find("=");
				if (found_equal_chk == std::string::npos)
					continue;	

				Buf_key_chk = Buf.substr(0, found_equal_chk);
				found = Buf.find(key);

				if(found != std::string::npos && storetag == tag && Buf_key_chk.size() == key.size())
				{
					IniAllValues[storetag].push_back(std::pair<string,string>(key, value_));
					keyChk = true;
				}
				else
				{
					oldkey = Buf.substr(0, found_equal_chk);
					oldvalue = Buf.substr(found_equal_chk + 1);
					IniAllValues[storetag].push_back(std::pair<string,string>(oldkey, oldvalue));
				}
			}
		}
		continue;	
	}

	readPath.clear();
	readPath.close();

	// cout << "=before added=" << endl;
	// for (auto x: IniAllValues)
	// {
	// 	for(auto i: x.second)
	// 	{
	// 		cout << i.first << " = " << i.second << "\n";
	// 	}
	// }

	if (!keyChk)
	{
		IniAllValues[tag].push_back(std::pair<string,string>(key, value_));
		CollectAllTag.insert(tag);
	}

	// for (auto x: IniAllValues)
	// {
	// 	for(auto i: x.second)
	// 	{
	// 		cout << i.first << " = " << i.second << "\n";
	// 	}
	// }

	if(IniAllValues.size() == 0)
	{
		errorCode = WRITE_FAIL;
	}
	else
	{
		writePath.open(filePath.c_str(), std::ios::out | std::ios::trunc);

		if(!writePath)
			 return OPEN_FILE_ERROR;

		for(auto i = CollectAllTag.begin(); i != CollectAllTag.end(); ++i)
		{
			writePath << i->c_str() << "\n";
			for(auto j = 0; j < IniAllValues[*i].size(); ++j)
    		{
				writePath << IniAllValues[*i][j].first + "=" + IniAllValues[*i][j].second + "\n";
    		}
		}

		// cout << "=after=" << endl;
		// for (auto x: IniAllValues)
		// {
		// 	for(auto i: x.second)
		// 	{
		// 		cout << i.first << " = " << i.second << "\n";
		// 	}
		// }

		writePath.clear();
		writePath.close();
		errorCode = SUCCESSFUL;
	}

	return errorCode;
}

unsigned int ICFG::WritePrivateProfileString(const char* tag, const char* key, const char* value, const char* path)
{
	return write_cfg_ByTag(path, value, key, tag);
}