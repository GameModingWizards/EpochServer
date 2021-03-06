/* Default Epochlib defines */
#include "defines.hpp"
#include <mutex>

#include <cstdarg>

#ifdef WIN32
#include "../../deps/redis/deps/hiredis/hiredis.h"
#include <time.h>
#define IS_WINDOWS_PLATFORM
#endif

#ifdef IS_WINDOWS_PLATFORM
#ifdef _WIN64
#pragma comment(lib, "../../deps/redis/msvs/x64/Release/hiredis.lib")
#pragma comment(lib, "../../deps/redis/msvs/x64/Release/Win32_Interop.lib")
#else
#pragma comment(lib, "../../deps/redis/msvs/Release/hiredis.lib")
#pragma comment(lib, "../../deps/redis/msvs/Release/Win32_Interop.lib")
#endif
#else
	//#include "../../deps/redis/deps/hiredis/hiredis.h"
	#include <hiredis.h>
	#include <sys/time.h>
#endif

#ifndef __REDISCONNECTOR_H__
#define __REDISCONNECTOR_H__

#define REDISCONNECTOR_MAXCONNECTION_RETRIES 3

class RedisConnector {
private:
	EpochlibConfigRedis config;

	std::mutex contextMutex;
	redisContext *context;

	void _reconnect(bool force);

public:
	RedisConnector(EpochlibConfigRedis Config);
	~RedisConnector();

	EpochlibRedisExecute execute(const char *RedisCommand, ...);
};

#endif
