#include <SDL.h>

int main(int argc, char* argv[]) {
  SDL_Window* window;
  SDL_Renderer* renderer;

  // Initialize SDL.
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    return 1;
    printf("Could not init SDL: %s\n", SDL_GetError());
  }

  // Create the window where we will draw.
  window = SDL_CreateWindow("SDL_RenderClear",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    512, 512,
    SDL_WINDOW_SHOWN
  );

  if (window == NULL) {
    // In the case that the window could not be made...
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  // // We must call SDL_CreateRenderer in order for draw calls to affect this window.
  // renderer = SDL_CreateRenderer(window, -1, 0);

  // // Select the color for drawing. It is set to red here.
  // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

  // // Clear the entire screen to our selected color.
  // SDL_RenderClear(renderer);

  // // Up until now everything was drawn behind the scenes.
  // // This will show the new, red contents of the window.
  // SDL_RenderPresent(renderer);

  // Give us time to see the window.
  bool isquit = false;
  SDL_Event event;
  while (!isquit) {
    if (SDL_PollEvent( & event)) {
      if (event.type == SDL_QUIT) {
        isquit = true;
      }
    }
  }

  SDL_DestroyWindow(window);

  // Always be sure to clean up
  SDL_Quit();
  return 0;
}
