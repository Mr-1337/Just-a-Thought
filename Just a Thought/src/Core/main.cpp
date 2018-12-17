/*
Created February 3rd 2017 by Mr. 1337
This is my first real project that I have put a lot of thought and work into, and hopefully I can make something special
This is also a spiritual successor to "platformgame.swf", an earlier project. Some of you may probably remember that abomination, but it was my first attempt at something like this.
I know that this probably won't be the magnum opus that I'd really like it to be, but one can dream right?
*/

#include <iostream>
#include <string>
#include <cstdlib>

#include <Jangine.h>


/*
── █───▄▀█▀▀█▀▄▄───▐█──────▄▀█▀▀█▀▄▄
──█───▀─▐▌──▐▌─▀▀──▐█─────▀─▐▌──▐▌─█▀
─▐▌──────▀▄▄▀──────▐█▄▄──────▀▄▄▀──▐▌
─█────────────────────▀█────────────█
▐█─────────────────────█▌───────────█
▐█─────────────────────█▌───────────█
─█───────────────█▄───▄█────────────█
─▐▌───────────────▀███▀────────────▐▌
──█──────────▀▄───────────▄▀───────█
───█───────────▀▄▄▄▄▄▄▄▄▄▀────────█
*/
/*
                      _____
                   ,-'     `._
                 ,'           `.        ,-.
               ,'               \       ),.\
     ,.       /                  \     /(  \;
    /'\\     ,o.        ,ooooo.   \  ,'  `-')
    )) )`. d8P"Y8.    ,8P"""""Y8.  `'  .--"'
   (`-'   `Y'  `Y8    dP       `'     /
    `----.(   __ `    ,' ,---.       (
           ),--.`.   (  ;,---.        )
          / \O_,' )   \  \O_,'        |
         ;  `-- ,'       `---'        |
         |    -'         `.           |
        _;    ,            )          :
     _.'|     `.:._   ,.::" `..       |
  --'   |   .'     """         `      |`.
        |  :;      :   :     _.       |`.`.-'--.
        |  ' .     :   :__.,'|/       |  \
        `     \--.__.-'|_|_|-/        /   )
         \     \_   `--^"__,'        ,    |
   -hrr- ;  `    `--^---'          ,'     |
          \  `                    /      /
           \   `    _ _          /
            \           `       /
             \           '    ,'
              `.       ,   _,'
                `-.___.---'

*/
int main(int argc, char* args[])
{
	std::cout << "Welcome to the console output for Just a Thought!" << std::endl << std::endl;
	
	Jangine::GameSettings::setDimensions(800, 600);
	Jangine::GameEngine* JaT = new Jangine::GameEngine("Just a Thought");
	JaT->Run();

	std::cout << "Program closed, hit enter to terminate";
	std::cin.get();
	return 0;
}