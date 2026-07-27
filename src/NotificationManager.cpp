#include "NotificationManager.h"
#include <windows.h>
#include <string>

void NotificationManager::ShowToast(const std::string& title, const std::string& message) {
    // Generate PowerShell command to show a Windows Toast Notification natively.
    std::string psCmd = "powershell -WindowStyle Hidden -Command \""
        "[Windows.UI.Notifications.ToastNotificationManager, Windows.UI.Notifications, ContentType = WindowsRuntime] | Out-Null;"
        "$xml = [Windows.Data.Xml.Dom.XmlDocument]::new();"
        "$xml.LoadXml('<toast><visual><binding template=\"\"ToastText02\"\"><text id=\"\"1\"\">" + title + "</text><text id=\"\"2\"\">" + message + "</text></binding></visual></toast>');"
        "[Windows.UI.Notifications.ToastNotificationManager]::CreateToastNotifier('Power Mode Manager').Show([Windows.UI.Notifications.ToastNotification]::new($xml))\"";
        
    // Execute asynchronously using CreateProcess
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    // Hide window
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;
    ZeroMemory(&pi, sizeof(pi));

    if (CreateProcessA(NULL, (LPSTR)psCmd.c_str(), NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi)) {
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
}
