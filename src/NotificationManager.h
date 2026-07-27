#pragma once
#include <string>

class NotificationManager {
public:
    static void ShowToast(const std::string& title, const std::string& message);
};
