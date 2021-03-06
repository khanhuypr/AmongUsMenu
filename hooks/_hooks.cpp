#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "_hooks.hpp"
#include "detours/detours.h"
#include "DirectX.h"
#include <iostream>

using namespace app;

bool HookFunction(PVOID* ppPointer, PVOID pDetour, const char* functionName) {
	if (DetourAttach(ppPointer, pDetour) != 0) {
		std::cout << "Failed to hook " << functionName << std::endl;
		return false;
	}
	//std::cout << "Hooked " << functionName << std::endl;
	return true;
}

#define HOOKFUNC(n) if (!HookFunction(&(PVOID&)n, d ## n, #n)) return;

bool UnhookFunction(PVOID* ppPointer, PVOID pDetour, const char* functionName) {
	if (DetourDetach(ppPointer, pDetour) != 0) {
		std::cout << "Failed to unhook " << functionName << std::endl;
		return false;
	}
	//std::cout << "Unhooked " << functionName << std::endl;
	return true;
}

#define UNHOOKFUNC(n) if (!UnhookFunction(&(PVOID&)n, d ## n, #n)) return;

void DetourInitilization() {
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	directx11 d3d11 = directx11();
	if (!d3d11.presentFunction) {
		std::cout << "Unable to retrieve IDXGISwapChain::Present method" << std::endl;
		return;
	} else {
		oPresent = d3d11.presentFunction;
	}

	HOOKFUNC(SceneManager_Internal_ActiveSceneChanged);
	HOOKFUNC(HatManager_GetUnlockedHats);
	HOOKFUNC(HatManager_GetUnlockedPets);
	HOOKFUNC(HatManager_GetUnlockedSkins);
	HOOKFUNC(PlayerControl_FixedUpdate);
	HOOKFUNC(PlayerControl_RpcSyncSettings);
	HOOKFUNC(MeetingHud_Update);
	HOOKFUNC(ShipStatus_CalculateLightRadius);
	HOOKFUNC(ShipStatus_OnEnable);
	HOOKFUNC(Vent_CanUse);
	HOOKFUNC(Vent_EnterVent);
	HOOKFUNC(Vent_ExitVent);
	HOOKFUNC(StatsManager_get_AmBanned);
	HOOKFUNC(StatsManager_get_BanMinutesLeft);
	HOOKFUNC(StatsManager_get_BanPoints);
	HOOKFUNC(AutoOpenDoor_DoUpdate);
	HOOKFUNC(ChatBubble_SetName);
	HOOKFUNC(ChatController_AddChat);
	HOOKFUNC(ChatController_SetVisible);
	HOOKFUNC(HudManager_ShowMap);
	HOOKFUNC(HudManager_Update);
	HOOKFUNC(KeyboardJoystick_Update);
	HOOKFUNC(PlainDoor_SetDoorway);
	HOOKFUNC(GameOptionsData_Deserialize);
	HOOKFUNC(GameOptionsData_Deserialize_1);
	HOOKFUNC(PlayerControl_MurderPlayer);
	HOOKFUNC(PlayerControl_CompleteTask);
	HOOKFUNC(PlayerControl_ReportDeadBody);
	HOOKFUNC(PlayerControl_RpcSetInfected);
	HOOKFUNC(Renderer_set_enabled);
	HOOKFUNC(MeetingHud_Awake);
	HOOKFUNC(MeetingHud_Close);
	HOOKFUNC(InnerNetClient_Update);
	HOOKFUNC(Constants_ShouldFlipSkeld);
	if (!HookFunction(&(PVOID&)oPresent, dPresent, "D3D_PRESENT_FUNCTION")) return;

	DetourTransactionCommit();
}

void DetourUninitialization()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	UNHOOKFUNC(SceneManager_Internal_ActiveSceneChanged);
	UNHOOKFUNC(HatManager_GetUnlockedHats);
	UNHOOKFUNC(HatManager_GetUnlockedPets);
	UNHOOKFUNC(HatManager_GetUnlockedSkins);
	UNHOOKFUNC(PlayerControl_FixedUpdate);
	UNHOOKFUNC(PlayerControl_RpcSyncSettings);
	UNHOOKFUNC(MeetingHud_Update);
	UNHOOKFUNC(ShipStatus_CalculateLightRadius);
	UNHOOKFUNC(ShipStatus_OnEnable);
	UNHOOKFUNC(Vent_CanUse);
	UNHOOKFUNC(Vent_EnterVent);
	UNHOOKFUNC(Vent_ExitVent);
	UNHOOKFUNC(StatsManager_get_AmBanned);
	UNHOOKFUNC(StatsManager_get_BanMinutesLeft);
	UNHOOKFUNC(StatsManager_get_BanPoints);
	UNHOOKFUNC(AutoOpenDoor_DoUpdate);
	UNHOOKFUNC(ChatBubble_SetName);
	UNHOOKFUNC(ChatController_AddChat);
	UNHOOKFUNC(ChatController_SetVisible);
	UNHOOKFUNC(HudManager_ShowMap);
	UNHOOKFUNC(HudManager_Update);
	UNHOOKFUNC(KeyboardJoystick_Update);
	UNHOOKFUNC(PlainDoor_SetDoorway);
	UNHOOKFUNC(GameOptionsData_Deserialize);
	UNHOOKFUNC(GameOptionsData_Deserialize_1);
	UNHOOKFUNC(PlayerControl_MurderPlayer);
	UNHOOKFUNC(PlayerControl_CompleteTask);
	UNHOOKFUNC(PlayerControl_ReportDeadBody);
	UNHOOKFUNC(PlayerControl_RpcSetInfected);
	UNHOOKFUNC(Renderer_set_enabled);
	UNHOOKFUNC(MeetingHud_Awake);
	UNHOOKFUNC(MeetingHud_Close);
	UNHOOKFUNC(InnerNetClient_Update);
	UNHOOKFUNC(Constants_ShouldFlipSkeld);
	if (DetourDetach(&(PVOID&)oPresent, dPresent) != 0) return;

	DetourTransactionCommit();
	DirectX::Shutdown();
}