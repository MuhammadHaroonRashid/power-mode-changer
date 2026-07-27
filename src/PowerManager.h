#pragma once

#include <string>
#include <windows.h>
#include <powrprof.h>
#include <iostream>

class PowerManager {
public:
    static const GUID HIGH_PERFORMANCE_GUID;
    static const GUID CUSTOM_PLAN_GUID;

    static GUID GetActivePlan();
    static bool SetActivePlan(const GUID& planGuid);
    
    static bool IsHighPerformance();
    static bool IsCustomPlan();
    
    static std::string GetPlanName(const GUID& planGuid);
};
