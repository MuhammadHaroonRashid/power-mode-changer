#include "UI.h"
#include <windows.h>

int main() {
    // Set console output codepage to UTF-8 for proper box-drawing characters
    SetConsoleOutputCP(CP_UTF8);
    
    // Run the UI
    UI::Run();
    return 0;
}
