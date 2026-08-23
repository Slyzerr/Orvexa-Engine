#include "Runtime.h"

int main()
{
    engine::core::Runtime runtime;

    if (!runtime.Initialize())
        return -1;

    runtime.Run();

    return 0;
}