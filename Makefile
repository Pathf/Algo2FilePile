all:
	g++ mainF.cpp -o File/prog.exe
	g++ mainP.cpp -o Pile/prog.exe

fcom:
	g++ mainF.cpp -o File/prog.exe

fcoex:
	g++ mainF.cpp -o File/prog.exe
	./File/prog.exe

fexe:
	./File/prog.exe

pcom:
	g++ mainP.cpp -o Pile/prog.exe

pcoex:
	g++ mainP.cpp -o Pile/prog.exe
	./Pile/prog.exe

pexe:
	./Pile/prog.exe
