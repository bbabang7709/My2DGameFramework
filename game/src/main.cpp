#ifdef _WIN32
    #include <windows.h>
#endif

#include <SDL.h>
#include <iostream>

int main(int argc, char* argv[])
{
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif
    (void)argc;
    (void)argv;

    // ---- 1. SDL 시작 ---- //
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init 실패: " << SDL_GetError() << "\n";
        return 1;
    }

    // ---- 2. 창 만들기 ---- //
    SDL_Window* window = SDL_CreateWindow("My2DGameFramework", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);

    if (window == nullptr)
    {
        std::cerr << "SDL_CreateWindow 실패: " << SDL_GetError() << "\n";
        SDL_Quit();
        return 1;
    }

    // ---- 3. 이벤트 루프: X 버튼을 누를 때까지 반복 ---- //
    bool isRunning = true;
    while (isRunning)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning = false;
            }
        }

        SDL_Delay(16);  // 16ms 쉬기 -> 1초에 약 60번 반복 (CPU를 혹사하지 않도록)
    }

    // ---- 4. 정리: 분해는 조립의 역순 ---- //
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
