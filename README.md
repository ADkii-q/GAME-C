# Портирование игры на Бейсике в C
Игра [Rabbit Chase](https://www.atariarchives.org/morebasicgames/showpage.php?page=132)

## Windows

Чтобы запустить игру на Windows, вам нужно установить MinGW-w64, затем создать файл make.bat в каталоге, где находится ваш исходный код, и написать строки, указанные ниже:

* `PATH=path to mingw64/bin`
* `gcc RabbitChase.c`

Затем, например, в VS Code откройте терминал и введите:

* `./make.bat`

Затем запустите приложение a.exe.

![Alt-текст](https://raw.githubusercontent.com/ADkii-q/GAME-C/main/screen/win.png)

## Linux

Для запуска игры на Linux вам необходимо скачать компилятор gcc:

* `sudo apt update`
* `sudo apt install build-essential`

Затем скомпилируйте файл с исходным кодом:

* `gcc RabbitChase.c -o game` где `game` это имя скомпилированного файла

Затем запустите:

* `./game` для запуска игры.

![Alt-текст](https://raw.githubusercontent.com/ADkii-q/GAME-C/main/screen/gcc.png)

## Web
Инструкции по установке с использованием emsdk

Основной драйвер Emscripten SDK (emsdk) представляет собой сценарий Python. Вы можете получить его в первый раз с

#Get the emsdk repo

* `git clone https://github.com/emscripten-core/emsdk.git`

#Enter that directory
* `cd emsdk`

Выполните следующие команды emsdk, чтобы получить последние инструменты с GitHub и сделать их активными:
* `git pull`
* `./emsdk install latest`
* `./emsdk activate latest`
* `source ./emsdk_env.sh`

В Windows запустите emsdk вместо ./emsdk и emsdk_env.bat вместо исходного ./emsdk_env.sh.

![Alt-текст](https://raw.githubusercontent.com/ADkii-q/GAME-C/main/screen/web.png)
## Android
Для запуска игры на Android вам необходимо скачать и установить компилятор C/C++. Затем сохраните файл с исходным кодом из этого репозитория с расширением .c и запустите компилятор.

![Alt-текст](https://github.com/ADkii-q/GAME-C/blob/main/screen/Screen.c.png?raw=true)
