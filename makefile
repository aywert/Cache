.PHONY : Release r_run Debug d_run

Release:
	cmake -S ./ -B build/Release -DCMAKE_BUILD_TYPE=Release
	cmake --build build/Release
r_run:
	./build/Release/MyHash

Debug:
	cmake -S ./ -B build/Debug -DCMAKE_BUILD_TYPE=Debug
	cmake --build build/Debug
d_run:
	./build/Debug/MyHash

