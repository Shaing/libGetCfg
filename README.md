# libGetCfg -- Library to get config from file.
> Follow [INI](https://en.wikipedia.org/wiki/INI_file) file format, it's easy to get items of config from ini file.

e.g.
> ["TAG"]  
> "KEY"="VALUE"  

On windows has [WritePrivateProfileStringA](https://docs.microsoft.com/en-us/windows/desktop/api/winbase/nf-winbase-writeprivateprofilestringa) and [GetPrivateProfileString](https://docs.microsoft.com/zh-tw/windows/desktop/api/winbase/nf-winbase-getprivateprofilestring), but there are not exist on Linux, so I reference the APIs from those.

# prototype of two main functions
```
unsigned int get_cfg_ByTag(const char* cfilePath, char* result, const char* ckey, const char* ctag);
unsigned int write_cfg_ByTag(const char* cfilePath, const char* value, const char* ckey, const char* ctag);	
```
- only support string type, but you get to cast any type.

# sample code
```
char buf[512] = {0};
get_cfg_ByTag("cfg.ini", buf, "ALLEN", TAG_PUBLIC);
cout << buf << endl;
```
# compiler
- visual studio 2008 & 2015
- gcc 5.x up

# OS
- windows 7/10
- ubuntu 16.04

# Release note
- v0.1.1
> fixed on linux can't read windows file(0x0d 0x0a), add dataClean() in cpp as private function.



