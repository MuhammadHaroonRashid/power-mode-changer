#include "UI.h"
#include "PowerManager.h"
#include "ThemeManager.h"
#include "NotificationManager.h"
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>

using namespace ftxui;

void UI::Run() {
    auto screen = ScreenInteractive::TerminalOutput();
    
    int selected = 0;
    std::vector<std::string> entries = {
        "> Toggle Power Plan",
        "High Performance",
        "My Custom Plan 1",
        "Refresh Status",
        "Change Theme",
        "Exit"
    };

    auto menu = Menu(&entries, &selected);
    
    auto renderer = Renderer(menu, [&] {
        ThemeColors theme = ThemeManager::GetCurrentTheme();
        
        GUID activeGuid = PowerManager::GetActivePlan();
        std::string activeName = PowerManager::GetPlanName(activeGuid);
        
        Element statusIndicator;
        if (PowerManager::IsHighPerformance()) {
            statusIndicator = text("[O] " + activeName) | color(Color::GreenLight) | bold;
        } else if (PowerManager::IsCustomPlan()) {
            statusIndicator = text("[O] " + activeName) | color(Color::YellowLight) | bold;
        } else {
            statusIndicator = text("[X] " + activeName) | color(Color::RedLight) | bold;
        }

        auto statusPanel = window(text("Current Plan"), 
            vbox({
                text(""),
                statusIndicator | center,
                text("")
            })
        ) | color(theme.secondary);

        auto content = vbox({
            text("Power Mode Manager") | bold | center | color(theme.primary),
            separator(),
            statusPanel,
            separator(),
            menu->Render() | center,
            separator(),
            text("Up/Down: Navigate   Enter: Select   Esc: Exit") | center | dim
        }) | borderRounded | bgcolor(theme.surface) | color(theme.text);
        
        return center(content) | bgcolor(theme.background);
    });

    auto final_component = CatchEvent(renderer, [&](Event event) {
        if (event == Event::Return) {
            if (selected == 0) {
                if (PowerManager::IsHighPerformance()) {
                    PowerManager::SetActivePlan(PowerManager::CUSTOM_PLAN_GUID);
                } else {
                    PowerManager::SetActivePlan(PowerManager::HIGH_PERFORMANCE_GUID);
                }
                NotificationManager::ShowToast("Power plan switched", PowerManager::GetPlanName(PowerManager::GetActivePlan()) + " Activated");
            } else if (selected == 1) {
                PowerManager::SetActivePlan(PowerManager::HIGH_PERFORMANCE_GUID);
                NotificationManager::ShowToast("Power plan switched", "High Performance Activated");
            } else if (selected == 2) {
                PowerManager::SetActivePlan(PowerManager::CUSTOM_PLAN_GUID);
                NotificationManager::ShowToast("Power plan switched", "My Custom Plan 1 Activated");
            } else if (selected == 3) {
                // Just refresh
            } else if (selected == 4) {
                ThemeManager::NextTheme();
            } else if (selected == 5) {
                screen.ExitLoopClosure()();
            }
            return true;
        }
        if (event == Event::Escape) {
            screen.ExitLoopClosure()();
            return true;
        }
        return false;
    });

    screen.Loop(final_component);
}
