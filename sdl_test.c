#include <SDL/SDL.h>
#include <stdio.h>

//The event structure
SDL_Event event;

int main( int argc, char* args[] )
{
   //Инициализировать SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;
    }
    
	SDL_SetVideoMode (320, 200, 8, 0);
   
 	printf("Start\n");
   
   	while(1) {
   	if( SDL_PollEvent( &event ) ) {
        //Если была нажата клавиша
        if( event.type == SDL_KEYDOWN ) {
   			//Выбрать правильное сообщение
            switch( event.key.keysym.sym ) {
                case SDLK_UP: printf("UP pressed\n"); break;
                case SDLK_DOWN: printf("DOWN pressed\n"); break;
                case SDLK_LEFT: printf("LEFT pressed\n"); break;
                case SDLK_RIGHT: printf("RIGHT pressed\n"); break;
            }
        }
		else if( event.type == SDL_KEYUP ) {
   			//Выбрать правильное сообщение
            switch( event.key.keysym.sym ) {
                case SDLK_UP: printf("UP released\n"); break;
                case SDLK_DOWN: printf("DOWN released\n"); break;
                case SDLK_LEFT: printf("LEFT released\n"); break;
                case SDLK_RIGHT: printf("RIGHT released\n"); break;
            }
        }
        //Если пользователь хочет выйти
        else if( event.type == SDL_QUIT ) {
            //Выходим из программы
           	//Освободить ресурсы занятые SDL
   			SDL_Quit();
  			return 0;
        }
    }
    }
	return 0;
}
