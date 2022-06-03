all:
        	g++ -ISDL2\include -LSDL2\lib -o main main.cpp boneGam.cpp setGam.cpp enermy.cpp Character.cpp background.cpp sound.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
