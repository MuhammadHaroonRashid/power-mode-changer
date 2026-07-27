#include "ThemeManager.h"

int ThemeManager::currentThemeIndex = 0;

std::vector<ThemeColors> ThemeManager::themes = {
    // Dark (Default)
    {
        ftxui::Color::White,      // Primary
        ftxui::Color::GrayDark,   // Secondary
        ftxui::Color::Black,      // Background
        ftxui::Color::Black,      // Surface
        ftxui::Color::White       // Text
    },
    // Blue
    {
        ftxui::Color::RGB(0, 120, 215),   // Primary
        ftxui::Color::RGB(43, 136, 216),  // Secondary
        ftxui::Color::Black,              // Background
        ftxui::Color::RGB(10, 25, 47),    // Surface
        ftxui::Color::White               // Text
    },
    // Green
    {
        ftxui::Color::RGB(16, 124, 16),   // Primary
        ftxui::Color::RGB(33, 165, 33),   // Secondary
        ftxui::Color::Black,              // Background
        ftxui::Color::RGB(5, 26, 5),      // Surface
        ftxui::Color::White               // Text
    },
    // Amber
    {
        ftxui::Color::RGB(255, 185, 0),   // Primary
        ftxui::Color::RGB(248, 210, 78),  // Secondary
        ftxui::Color::Black,              // Background
        ftxui::Color::RGB(31, 22, 0),     // Surface
        ftxui::Color::White               // Text
    }
};

void ThemeManager::NextTheme() {
    currentThemeIndex = (currentThemeIndex + 1) % themes.size();
}

ThemeColors ThemeManager::GetCurrentTheme() {
    return themes[currentThemeIndex];
}
