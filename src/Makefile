STD := -std=c++11 -c
WARN := -Wall

FINAL_CFLAGS=$(STD) $(WARN) -I/hbb_shlib/include/hiredis -fPIC #$(CFLAGS)

.DEFAULT:
	g++ $(FINAL_CFLAGS) main.cpp
	g++ $(FINAL_CFLAGS) Epochlib/Epochlib.cpp
	g++ $(FINAL_CFLAGS) Epochlib/RedisConnector.cpp
	g++ $(FINAL_CFLAGS) Epochlib/SQF.cpp
	g++ $(FINAL_CFLAGS) Epochlib/Logger.cpp
	g++ $(FINAL_CFLAGS) external/Chameleon.cpp
	g++ $(FINAL_CFLAGS) external/ConfigFile.cpp
	g++ $(FINAL_CFLAGS) external/md5.cpp
	g++ $(FINAL_CFLAGS) SteamAPI/SteamAPI.cpp
	g++ $(FINAL_CFLAGS) BattlEye/BEClient.cpp
	g++ $(FINAL_CFLAGS) ../deps/happyhttp/happyhttp.cpp

	g++ -shared -fPIC -L. -o epochserver.so *.o /hbb_shlib/hbb_shlib/lib/libhiredis.a /hbb_shlib/lib/libpcre.a -static-libstdc++

clear:
	rm *.o -r -f
	rm epochserver.so -f
