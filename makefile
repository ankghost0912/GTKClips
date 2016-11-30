CC=g++
GTK_COMPILE_FLAGS=pkg-config gtkmm-3.0 --cflags --libs


main: main_app.o clipswindow.o
	$(CC) main_app.o clipswindow.o -o main`$(GTK_COMPILE_FLAGS)`

main_app.o: main_app.cpp clipswindow.h
	$(CC)  main_app.cpp -o main.o `$(GTK_COMPILE_FLAGS)`

clipswindow.o: clipswindow.cpp clipswindow.h
	$(CC)  clipswindow.cpp  `$(GTK_COMPILE_FLAGS)`


