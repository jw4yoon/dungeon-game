CXX=g++-5
CXXFLAGS=-Wall -Werror=vla  -MMD -std=c++14
OBJECTS=main.o floor.o element.o character.o player.o drow.o goblin.o shade.o troll.o vampire.o enemy.o human.o dwarf.o elf.o halfling.o orcs.o merchant.o dragon.o item.o potion.o gold.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}
.PHONY: clean
clean:
	rm ${EXEC} ${OBJECTS} ${DEPENDS}
