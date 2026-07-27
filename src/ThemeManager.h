#pragma once
#include <ftxui/dom/elements.hpp>
#include <vector>

struct ThemeColors {
    ftxui::Color primary;
    ftxui::Color secondary;
    ftxui::Color background;
    ftxui::Color surface;
    ftxui::Color text;
};

class ThemeManager {
public:
    enum class Theme {
        Dark,
        Blue,
        Green,
        Amber
    };

    static void NextTheme();
    static ThemeColors GetCurrentTheme();

private:
    static int currentThemeIndex;
    static std::vector<ThemeColors> themes;
};
