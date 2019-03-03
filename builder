rm main3
g++ -o mainer -std=c++0x -pedantic -Wall small_render.cpp \
`sdl2-config --cflags --libs` \
-lEGL -lGLESv2


