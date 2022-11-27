MyProject : RabbitChase.o RabbitChase.c
        gcc RabbitChase.o -o RabbitChase
        ./a.exe
MyProject : RabbitChase.c
        gcc -c RabbitChase.c -o RabbitChase.o
installemsdk: 
	 cd .. && git clone https://github.com/emscripten-core/emsdk.git
	 cd ../emsdk && emsdk install latest && emsdk activate latest && emsdk_env.bat && emcc RabbitChase.c -s WASM=1 -o pge.html
	 npm i http-server -g
runserver:
	  cd ../emrun pge.html
