#include "PowerManager.h"
#include <memory>

// High Performance: 4c2b08c0-6a72-4fb0-8c70-2349b2d3132e
const GUID PowerManager::HIGH_PERFORMANCE_GUID = 
{ 0x4c2b08c0, 0x6a72, 0x4fb0, { 0x8c, 0x70, 0x23, 0x49, 0xb2, 0xd3, 0x13, 0x2e } };

// Custom Plan 1: f4d5f87d-d2d1-4752-b7c2-652c97a98986
const GUID PowerManager::CUSTOM_PLAN_GUID = 
{ 0xf4d5f87d, 0xd2d1, 0x4752, { 0xb7, 0xc2, 0x65, 0x2c, 0x97, 0xa9, 0x89, 0x86 } };

GUID PowerManager::GetActivePlan() {
    GUID* pGuid = nullptr;
    if (PowerGetActiveScheme(NULL, &pGuid) == ERROR_SUCCESS && pGuid != nullptr) {
        GUID active = *pGuid;
        LocalFree(pGuid);
        return active;
    }
    return HIGH_PERFORMANCE_GUID; // Fallback
}

bool PowerManager::SetActivePlan(const GUID& planGuid) {
    // Cast away constness as PowerSetActiveScheme requires non-const pointer, 
    // but we can pass a copy.
    GUID copy = planGuid;
    return PowerSetActiveScheme(NULL, &copy) == ERROR_SUCCESS;
}



bool PowerManager::IsHighPerformance() {
    return GetActivePlan() == HIGH_PERFORMANCE_GUID;
}

bool PowerManager::IsCustomPlan() {
    return GetActivePlan() == CUSTOM_PLAN_GUID;
}

std::string PowerManager::GetPlanName(const GUID& planGuid) {
    if (planGuid == HIGH_PERFORMANCE_GUID) return "High Performance";
    if (planGuid == CUSTOM_PLAN_GUID) return "My Custom Plan 1";
    return "Other Plan";
}
