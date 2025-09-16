.PHONY : Release r_run Debag d_run

Release:
	cmake -S ./ -B build/Release -DCMAKE_BUILD_TYPE=Release
	cmake --build build/Release
r_run:
	./build/Release/MyHash

Debag:
	cmake -S ./ -B build/Debag -DCMAKE_BUILD_TYPE=Debag
	cmake --build build/Debag
d_run:
	./build/Debag/MyHash

