# Si le make est activer sans paramètre alors simple compilation de Pile et File :
all:
	g++ mainF.cpp Test/testF.cpp -o File/prog.exe
	g++ mainP.cpp Test/testP.cpp -o Pile/prog.exe

###################################
####### Partie pour File ##########
###################################

# fcom : compilation simple pour la File
fcom:
	g++ mainF.cpp Test/testF.cpp -o File/prog.exe

# fcoex : compilation + execution de File
fcoex:
	g++ mainF.cpp Test/testF.cpp -o File/prog.exe
	./File/prog.exe

# fexe : execution simple de File
fexe:
	./File/prog.exe

###################################
####### Partie pour Pile ##########
###################################

# pcom : compilation simple pour la Pile
pcom:
	g++ mainP.cpp Test/testP.cpp -o Pile/prog.exe

# pcoex : compilation + execution de Pile
pcoex:
	g++ mainP.cpp Test/testP.cpp -o Pile/prog.exe
	./Pile/prog.exe

# pexe : execution simple de Pile
pexe:
	./Pile/prog.exe
