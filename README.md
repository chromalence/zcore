# ZCORE
```text
________  ________  ________  ________  _______      

|\_____  \|\   ____\|\   __  \|\   __  \|\  ___ \     
 \|___/  /\ \  \___|\ \  \|\  \ \  \|\  \ \   __/|    
     /  / /\ \  \    \ \  \\\  \ \   _  _\ \  \_|/__  
    /  /_/__\ \  \____\ \  \\\  \ \  \\  \\ \  \_|  \ 

   |\________\ \_______\ \_______\ \__\\ _\\ \_______\
    \|_______|\|_______|\|_______|\|__|\|__|\|_______|
```
what is zcore? zcore is a tiny & simple syscall wrapper 
that is designed to be used in tiny and modular projects.
## v1.2: WHAT'S NEW???
loads new syscalls. pretty much it, tbt update and minor fixes
### HOW DO I UPDATE???
to update, re-git-clone it and run the install script again, see INSTALL ;)
## STAT FLEXES ( using tbt )
shell ( with cd & args ) at 680 bytes ( wow! )
hello world in 331 bytes 
see demos for proof
## DEPENDENCIES 
zcore: none. just a c compiler  
tbt: elf-kickers (strip, sstrip) & a c compiler
## WHY SHOULD I TRY ZCORE??
well, YOU ( yes, you! ) should try zcore because it is TINY..
and i mean TINY.. if you use tbt ( tiny binary tool ) which helps 
compiling with the agressive flags and stripping needed to make it 
EVEN. SMALLER. you can get a hello world in like 300~ bytes which is
really cool. i got a SHELL. in 680~ bytes. thats kinda crazy. but if
you want a STABLE, NO TROUBLESHOOTING project that doesnt aim for
binary size, maybe skip zcore.
### IF YOU DONT WANT TBT
compile flags:
```bash
cc -Os -nostdlib -static -fno-asynchronous-unwind-tables -fno-stack-protector \
    -Wl,--build-id=none -Wl,-nmagic  -s <your-file.c> -o <your-binary>
```
strip & sstrip flags:
```bash
    strip -R .comment -R .note.gnu.property --strip-all <your-binary> &&
    sstrip <your-binary>
```
## INSTALL 
```bash
git clone https://github.com/chromalence/zcore && 
cd zcore &&
chmod +x install.sh &&
./install.sh
```
## IMPORTANT INFO 
if you arent using tbt, atleast get the compile flags out of it :sob: 
like PLEASE or if you dont care about binary size at ALL just MAKE SURE 
TO USE: -nostdlib -static in your compile. ( and also void _start() instead of 
int main() )
## TBT 
a tiny binary tool, see tbt help or just read this:
    -h > shows this, for help
    -f > compiles and strips
    -cc > compiles
    -s > strips
anyways, it makes your binaries really small. its a small tool written in bash
## CODE EXAMPLE 
```c
#include <zcore/print.h> // we are getting print, ONLY PRINT!!
#include <zcore/exit.h> // its so modular & minimal it doesnt even give you exit.

void _start() { // no int main(); . 
    zprint(1, "hello world\n", 12); // its just write, without the BLOAT.
    zexit(0); // and this is just, _exit, without the BLOAT!!!!!
}
```
## WEBSITE
[the site](https://chromalence.github.io/zcore)
i didnt write it i got ai to write it for me i know sad
but i dont wanna learn html js and css :sob: but hey
i wrote all the c and assembly :D
## ZCORE VERSIONS
i dont archive them like in chroctl every update previous headers are UNTOUCHED 
unless it needed a fix. no syntax changing ok. its modular, not like stdio where 
if they put something new you GOTTA use it even if you are ONLY printing hello world
## LICENSE
GPLv3 see LICENSE file for more info its copyleft so if you take my code 
and add more stuff to it and keep it closed source you cant do that :P >:D
## PR's
keep in mind im a solo dev that only checks github to push updates & fixes, if you have a PR here are my rules 
1. keep it simple
2. make it modular 
3. make it useful
4. ( MOST IMPORTANT ) make it tiny 
if it doesnt abide by these i likely wont like pull it 
## BYEBYE
have a nice day
