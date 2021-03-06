#pragma once
#include "il2cpp-appdata.h"
#include "game.hpp"
#include "state.hpp"

using namespace app;

void DetourInitilization();
void DetourUninitialization();

bool dAutoOpenDoor_DoUpdate(AutoOpenDoor* __this, float dt, MethodInfo* method);
bool dConstants_ShouldFlipSkeld(MethodInfo* method);
void dInnerNetClient_Update(InnerNetClient* __this, MethodInfo* method);
bool dStatsManager_get_AmBanned(StatsManager* __this, MethodInfo* method);
float dShipStatus_CalculateLightRadius(ShipStatus* __this, GameData_PlayerInfo* player, MethodInfo* method);
float dStatsManager_get_BanPoints(StatsManager* __this, MethodInfo* method);
float dVent_CanUse(Vent* __this, GameData_PlayerInfo* pc, bool* canUse, bool* couldUse, MethodInfo* method);
GameOptionsData* dGameOptionsData_Deserialize(BinaryReader* reader, MethodInfo* method);
GameOptionsData* dGameOptionsData_Deserialize_1(MessageReader* reader, MethodInfo* method);
HatBehaviour__Array* dHatManager_GetUnlockedHats(HatManager* __this, MethodInfo* method);
int32_t dStatsManager_get_BanMinutesLeft(StatsManager* __this, MethodInfo* method);
PetBehaviour__Array* dHatManager_GetUnlockedPets(HatManager* __this, MethodInfo* method);
SkinData__Array* dHatManager_GetUnlockedSkins(HatManager* __this, MethodInfo* method);
void dChatBubble_SetName(ChatBubble* __this, String* playerName, bool isDead, bool voted, Color color, MethodInfo* method);
void dChatController_AddChat(ChatController* __this, PlayerControl* sourcePlayer, String* chatText, MethodInfo* method);
void dChatController_SetVisible(ChatController* __this, bool visible, MethodInfo* method);
void dHudManager_ShowMap(HudManager* __this, Action_1_MapBehaviour_* mapAction, MethodInfo* method);
void dHudManager_Update(HudManager* __this, MethodInfo* method);
void dKeyboardJoystick_Update(KeyboardJoystick* __this, MethodInfo* method);
void dMeetingHud_Awake(MeetingHud* __this, MethodInfo* method);
void dMeetingHud_Close(MeetingHud* __this, MethodInfo* method);
void dMeetingHud_Update(MeetingHud* __this, MethodInfo* method);
void dPlainDoor_SetDoorway(PlainDoor* __this, bool open, MethodInfo* method);
void dPlayerControl_CompleteTask(PlayerControl* __this, uint32_t idx, MethodInfo* method);
void dPlayerControl_FixedUpdate(PlayerControl* __this, MethodInfo* method);
void dPlayerControl_MurderPlayer(PlayerControl* __this, PlayerControl* target, MethodInfo* method);
void dPlayerControl_ReportDeadBody(PlayerControl*__this, GameData_PlayerInfo* target, MethodInfo *method);
void dPlayerControl_RpcSetInfected(PlayerControl* __this, GameData_PlayerInfo__Array* infected, MethodInfo* method);
void dPlayerControl_RpcSyncSettings(PlayerControl* __this, GameOptionsData* gameOptions, MethodInfo* method);
void dRenderer_set_enabled(Renderer * __this, bool value, MethodInfo * method);
void dSceneManager_Internal_ActiveSceneChanged(Scene previousActiveScene, Scene newActiveScene, MethodInfo* method);
void dShipStatus_OnEnable(ShipStatus* __this, MethodInfo* method);
void dVent_EnterVent(Vent* __this, PlayerControl* pc, MethodInfo * method);
void dVent_ExitVent(Vent* __this, PlayerControl* pc, MethodInfo * method);