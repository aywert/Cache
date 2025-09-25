.PHONY : Release r_run Debug d_run

Release:
	cmake -S ./ -B build/Release -DCMAKE_BUILD_TYPE=Release
	cmake --build build/Release

Debug:
	cmake -S ./ -B build/Debug -DCMAKE_BUILD_TYPE=Debug 
	cmake --build build/Debug 

run_lru:
	./build/Release/Cache_LRU

test_lru:
	./build/Debug/Cache_LRU

run_opt:
	./build/Release/Cache_OPT

test_opt:
	./build/Debug/Cache_OPT