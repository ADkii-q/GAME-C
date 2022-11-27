# Портирование игры на Бейсике в C
Игра [Rabbit Chase](https://www.atariarchives.org/morebasicgames/showpage.php?page=132)

## Windows

=dfs=
-asd-

![Alt-текст](https://raw.githubusercontent.com/ADkii-q/GAME-C/main/screen/win.png)

## Linux
![Alt-текст](https://raw.githubusercontent.com/ADkii-q/GAME-C/main/screen/gcc.png)

## Web
Инструкции по установке с использованием emsdk

Основной драйвер Emscripten SDK (emsdk) представляет собой сценарий Python. Вы можете получить его в первый раз с

#Get the 
* emsdk repo
[git clone](https://github.com/emscripten-core/emsdk.git)

#Enter that directory
* cd emsdk

Выполните следующие команды emsdk, чтобы получить последние инструменты с GitHub и сделать их активными:
* git pull
* ./emsdk install latest
* ./emsdk activate latest
* source ./emsdk_env.sh

В Windows запустите emsdk вместо ./emsdk и emsdk_env.bat вместо исходного ./emsdk_env.sh.

![Alt-текст](https://raw.githubusercontent.com/ADkii-q/GAME-C/main/screen/web.png)
## Android
Для запуска игры на Android вам необходимо скачать и установить компилятор C/C++. Затем сохраните файл с исходным кодом из этого репозитория с расширением .c и запустите компилятор.

![Alt-текст](https://github.com/ADkii-q/GAME-C/blob/main/screen/Screen.c.png?raw=true)
