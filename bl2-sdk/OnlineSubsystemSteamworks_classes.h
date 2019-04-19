#pragma once
// Borderlands 2 (1.8.5) SDK

#ifdef _MSC_VER
	#pragma pack(push, 0x4)
#endif

#include "stdafx.h"

//---------------------------------------------------------------------------
//Classes
//---------------------------------------------------------------------------

// Class OnlineSubsystemSteamworks.OnlineAuthInterfaceSteamworks
// 0x0004 (0x0194 - 0x0198)
class UOnlineAuthInterfaceSteamworks : public UOnlineAuthInterfaceImpl
{
public:
	struct FPointer                                    AuthCallbackBridge;                                       // 0x0194(0x0004) (Native)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("OnlineAuthInterfaceSteamworks");
		return ptr;
	}


	bool GetServerAddr(int* OutServerIP, int* OutServerPort);
	bool GetServerUniqueId(struct FUniqueNetId* OutServerUID);
	void EndRemoteServerAuthSession(const struct FUniqueNetId& ServerUID, int ServerIP);
	void EndLocalServerAuthSession(const struct FUniqueNetId& ClientUID, int ClientIP);
	bool VerifyServerAuthSession(const struct FUniqueNetId& ServerUID, int ServerIP, int AuthBlobUID);
	bool CreateServerAuthSession(const struct FUniqueNetId& ClientUID, int ClientIP, int ClientPort, int* OutAuthBlobUID);
	void EndRemoteClientAuthSession(const struct FUniqueNetId& ClientUID, int ClientIP);
	void EndLocalClientAuthSession(const struct FUniqueNetId& ServerUID, int ServerIP, int ServerPort);
	bool VerifyClientAuthSession(const struct FUniqueNetId& ClientUID, int ClientIP, int ClientPort, int AuthBlobUID);
	bool CreateClientAuthSession(const struct FUniqueNetId& ServerUID, int ServerIP, int ServerPort, bool bSecure, int* OutAuthBlobUID);
	bool SendAuthRequestServer(const struct FUniqueNetId& ServerUID);
	bool SendAuthRequestClient(class UPlayer* ClientConnection, const struct FUniqueNetId& ClientUID);
};


// Class OnlineSubsystemSteamworks.OnlineGameInterfaceSteamworks
// 0x0094 (0x01C4 - 0x0258)
class UOnlineGameInterfaceSteamworks : public UOnlineGameInterfaceImpl
{
public:
	TArray<struct FServerQueryToRulesResponseMapping>  QueryToRulesResponseMap;                                  // 0x01C4(0x000C) (NeedCtorLink)
	TArray<struct FServerQueryToPingResponseMapping>   QueryToPingResponseMap;                                   // 0x01D0(0x000C) (NeedCtorLink)
	struct FPointer                                    ServerListResponse;                                       // 0x01DC(0x0004) (Const, Native, Transient)
	unsigned char                                      CurrentMatchmakingType;                                   // 0x01E0(0x0001)
	unsigned char                                      UnknownData00[0x3];                                       // 0x01E1(0x0003) MISSED OFFSET
	struct FPointer                                    CurrentMatchmakingQuery;                                  // 0x01E4(0x0004) (Const, Native, Transient)
	TArray<struct FScriptDelegate>                     GameInviteAcceptedDelegates;                              // 0x01E8(0x000C) (NeedCtorLink)
	class UOnlineGameSearch*                           InviteGameSearch;                                         // 0x01F4(0x0004) (Const)
	TArray<struct FScriptDelegate>                     RegisterPlayerCompleteDelegates;                          // 0x01F8(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     UnregisterPlayerCompleteDelegates;                        // 0x0204(0x000C) (NeedCtorLink)
	TArray<struct FClientFilterORClause>               ActiveClientsideFilters;                                  // 0x0210(0x000C) (Const, Native, Transient)
	unsigned long                                      bFilterEngineBuild : 1;                                   // 0x021C(0x0004)
	TArray<struct FFilterKeyToSteamKeyMapping>         FilterKeyToSteamKeyMap;                                   // 0x0220(0x000C) (Config, NeedCtorLink)
	struct FName                                       ServerSessionName;                                        // 0x022C(0x0008) (Const)
	struct FScriptDelegate                             __OnGameInviteAccepted__Delegate;                         // 0x0234(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnRegisterPlayerComplete__Delegate;                     // 0x0240(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnUnregisterPlayerComplete__Delegate;                   // 0x024C(0x000C) (NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("OnlineGameInterfaceSteamworks");
		return ptr;
	}


	class UOnlineGameSettings* GetGameSettings(const struct FName& SessionName);
	bool GetResolvedConnectString(const struct FName& SessionName, struct FString* ConnectInfo);
	bool BindPlatformSpecificSessionToSearch(unsigned char SearchingPlayerNum, class UOnlineGameSearch* SearchSettings, unsigned char PlatformSpecificInfo);
	bool ReadPlatformSpecificSessionInfoBySessionName(const struct FName& SessionName, unsigned char* PlatformSpecificInfo);
	bool ReadPlatformSpecificSessionInfo(struct FOnlineGameSearchResult* DesiredGame, unsigned char* PlatformSpecificInfo);
	bool QueryNonAdvertisedData(int StartAt, int NumberToQuery);
	void ClearUnregisterPlayerCompleteDelegate(const struct FScriptDelegate& UnregisterPlayerCompleteDelegate);
	void AddUnregisterPlayerCompleteDelegate(const struct FScriptDelegate& UnregisterPlayerCompleteDelegate);
	void OnUnregisterPlayerComplete(const struct FName& SessionName, const struct FUniqueNetId& PlayerID, bool bWasSuccessful);
	bool UnregisterPlayer(const struct FName& SessionName, const struct FUniqueNetId& PlayerID);
	void ClearRegisterPlayerCompleteDelegate(const struct FScriptDelegate& RegisterPlayerCompleteDelegate);
	void AddRegisterPlayerCompleteDelegate(const struct FScriptDelegate& RegisterPlayerCompleteDelegate);
	void OnRegisterPlayerComplete(const struct FName& SessionName, const struct FUniqueNetId& PlayerID, bool bWasSuccessful);
	bool RegisterPlayer(const struct FName& SessionName, const struct FUniqueNetId& PlayerID, bool bWasInvited);
	bool AcceptGameInvite(unsigned char LocalUserNum, const struct FName& SessionName);
	void OnGameInviteAccepted(struct FOnlineGameSearchResult* InviteResult);
	void ClearGameInviteAcceptedDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& GameInviteAcceptedDelegate);
	void AddGameInviteAcceptedDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& GameInviteAcceptedDelegate);
	bool UpdateOnlineGame(const struct FName& SessionName, class UOnlineGameSettings* UpdatedGameSettings, bool bShouldRefreshOnlineData);
};


// Class OnlineSubsystemSteamworks.OnlineLobbyInterfaceSteamworks
// 0x0000 (0x003C - 0x003C)
class UOnlineLobbyInterfaceSteamworks : public UObject
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("OnlineLobbyInterfaceSteamworks");
		return ptr;
	}

};


// Class OnlineSubsystemSteamworks.OnlineSubsystemSteamworks
// 0x0668 (0x00F8 - 0x0760)
class UOnlineSubsystemSteamworks : public UOnlineSubsystemCommonImpl
{
public:
	struct FPointer                                    CallbackBridge;                                           // 0x00F8(0x0004) (Native)
	TArray<struct FPointer>                            AsyncTasks;                                               // 0x00FC(0x000C) (Const, Native)
	unsigned long                                      bStoringAchievement : 1;                                  // 0x0108(0x0004)
	unsigned long                                      bGSStatsStoresSuccess : 1;                                // 0x0108(0x0004)
	unsigned long                                      bNeedsKeyboardTicking : 1;                                // 0x0108(0x0004) (Const)
	unsigned long                                      bLastHasConnection : 1;                                   // 0x0108(0x0004)
	unsigned long                                      bHasSteamworksAccount : 1;                                // 0x0108(0x0004) (Const, Config)
	unsigned long                                      bShouldUseMcp : 1;                                        // 0x0108(0x0004) (Const, Config)
	unsigned long                                      bIncrementStatValues : 1;                                 // 0x0108(0x0004)
	unsigned long                                      bEnableSteamQoS : 1;                                      // 0x0108(0x0004) (Transient)
	int                                                TotalGSStatsStoresPending;                                // 0x010C(0x0004)
	unsigned char                                      UserStatsReceivedState;                                   // 0x0110(0x0001)
	unsigned char                                      LoggedInStatus;                                           // 0x0111(0x0001) (Const)
	unsigned char                                      bWasKeyboardInputCanceled;                                // 0x0112(0x0001) (Const)
	unsigned char                                      CurrentNotificationPosition;                              // 0x0113(0x0001) (Config)
	class UOnlineGameInterfaceSteamworks*              CachedGameInt;                                            // 0x0114(0x0004) (Const)
	struct FString                                     LocalProfileName;                                         // 0x0118(0x000C) (Const, Localized, NeedCtorLink)
	struct FString                                     LoggedInPlayerName;                                       // 0x0124(0x000C) (Const, NeedCtorLink)
	struct FUniqueNetId                                LoggedInPlayerId;                                         // 0x0130(0x0018) (Const)
	int                                                LoggedInPlayerNum;                                        // 0x0148(0x0004) (Const)
	struct FString                                     ProfileDataDirectory;                                     // 0x014C(0x000C) (Config, NeedCtorLink)
	struct FString                                     ProfileDataExtension;                                     // 0x0158(0x000C) (Config, NeedCtorLink)
	TArray<struct FScriptDelegate>                     WriteProfileSettingsDelegates;                            // 0x0164(0x000C) (NeedCtorLink)
	class UOnlineProfileSettings*                      CachedProfile;                                            // 0x0170(0x0004)
	TArray<struct FScriptDelegate>                     LocalPlayerStorageReadDelegates;                          // 0x0174(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     LocalPlayerStorageWriteDelegates;                         // 0x0180(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     RemotePlayerStorageReadDelegates;                         // 0x018C(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     SpeechRecognitionCompleteDelegates;                       // 0x0198(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     ReadFriendsDelegates;                                     // 0x01A4(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     FriendsChangeDelegates;                                   // 0x01B0(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     MutingChangeDelegates;                                    // 0x01BC(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     LoginChangeDelegates;                                     // 0x01C8(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     LoginFailedDelegates;                                     // 0x01D4(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     LogoutCompletedDelegates;                                 // 0x01E0(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     GetUserAgeGroupCompletedDelegates;                        // 0x01EC(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     LoginStatusChangeDelegates;                               // 0x01F8(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     AccountCreateDelegates;                                   // 0x0204(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     TalkingDelegates;                                         // 0x0210(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     ReadOnlineStatsCompleteDelegates;                         // 0x021C(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     FlushOnlineStatsDelegates;                                // 0x0228(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     ConnectionStatusChangeDelegates;                          // 0x0234(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     ControllerChangeDelegates;                                // 0x0240(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     LinkStatusDelegates;                                      // 0x024C(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     ShareTitleFileCompleteDelegates;                          // 0x0258(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     ReadTitleFileCompleteDelegates;                           // 0x0264(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     AchievementDelegates;                                     // 0x0270(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     AchievementReadDelegates;                                 // 0x027C(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     AnyContentChangeDelegates;                                // 0x0288(0x000C) (NeedCtorLink)
	struct FLocalTalker                                CurrentLocalTalker;                                       // 0x0294(0x0004)
	TArray<struct FRemoteTalker>                       RemoteTalkers;                                            // 0x0298(0x000C) (NeedCtorLink)
	int                                                GameID;                                                   // 0x02A4(0x0004) (Const, Config)
	class UOnlineStatsRead*                            CurrentStatsRead;                                         // 0x02A8(0x0004) (Const)
	TArray<struct FPropertyToColumn>                   StatWriteKeyMapping;                                      // 0x02AC(0x000C) (Config, NeedCtorLink)
	TArray<struct FPendingPlayerStats>                 PendingStats;                                             // 0x02B8(0x000C) (Const, NeedCtorLink)
	struct FString                                     KeyboardResultsString;                                    // 0x02C4(0x000C) (Const, NeedCtorLink)
	TArray<struct FScriptDelegate>                     KeyboardInputDelegates;                                   // 0x02D0(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     FriendInviteReceivedDelegates;                            // 0x02DC(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     AddFriendByNameCompleteDelegates;                         // 0x02E8(0x000C) (NeedCtorLink)
	struct FProfileSettingsCache                       ProfileCache;                                             // 0x02F4(0x0028) (NeedCtorLink)
	class UOnlinePlayerStorage*                        PlayerStorageCache;                                       // 0x031C(0x0004)
	struct FDeviceIdCache                              DeviceCache;                                              // 0x0320(0x001C) (NeedCtorLink)
	struct FString                                     LocationUrl;                                              // 0x033C(0x000C) (Const, Config, NeedCtorLink)
	TArray<struct FScriptDelegate>                     SentGameInviteDelegates;                                  // 0x0348(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     ReceivedGameInviteDelegates;                              // 0x0354(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     JoinFriendGameCompleteDelegates;                          // 0x0360(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     GetNumberOfCurrentPlayersCompleteDelegates;               // 0x036C(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     RegisterHostStatGuidCompleteDelegates;                    // 0x0378(0x000C) (NeedCtorLink)
	TArray<struct FScriptDelegate>                     CheckDownloadableContentListDelegates;                    // 0x0384(0x000C) (NeedCtorLink)
	TArray<struct FOnlineStatusMapping>                StatusMappings;                                           // 0x0390(0x000C) (Const, Config, NeedCtorLink)
	TArray<struct FOnlineStatusPropertyMapping>        StatusPropertyMappings;                                   // 0x039C(0x000C) (Const, Config, NeedCtorLink)
	TArray<struct FOnlineStatusContextMapping>         StatusContextMappings;                                    // 0x03A8(0x000C) (Const, Config, NeedCtorLink)
	struct FString                                     DefaultStatus;                                            // 0x03B4(0x000C) (Const, Localized, NeedCtorLink)
	struct FString                                     GameInviteMessage;                                        // 0x03C0(0x000C) (Const, Localized, NeedCtorLink)
	struct FControllerConnectionState                  ControllerStates[0x4];                                    // 0x03CC(0x0008)
	float                                              ConnectionPresenceTimeInterval;                           // 0x03EC(0x0004)
	float                                              ConnectionPresenceElapsedTime;                            // 0x03F0(0x0004)
	struct FString                                     EncryptedProductKey;                                      // 0x03F4(0x000C) (Const, Config, NeedCtorLink)
	TArray<struct FUniqueNetId>                        MuteList;                                                 // 0x0400(0x000C) (Const, NeedCtorLink)
	TArray<struct FTitleFile>                          TitleManagedFiles;                                        // 0x040C(0x000C) (NeedCtorLink)
	TArray<struct FTitleFileMapping>                   TitleFileMappings;                                        // 0x0418(0x000C) (Config, NeedCtorLink)
	TArray<struct FQueuedAvatarRequest>                QueuedAvatarRequests;                                     // 0x0424(0x000C) (Const, NeedCtorLink)
	TArray<struct FAchievementMappingInfo>             AchievementMappings;                                      // 0x0430(0x000C) (NeedCtorLink)
	TArray<struct FAchievementProgressStat>            PendingAchievementProgress;                               // 0x043C(0x000C) (Const, NeedCtorLink)
	TArray<struct FLeaderboardTemplate>                LeaderboardList;                                          // 0x0448(0x000C) (NeedCtorLink)
	TArray<struct FDeferredLeaderboardRead>            DeferredLeaderboardReads;                                 // 0x0454(0x000C) (Const, NeedCtorLink)
	TArray<struct FDeferredLeaderboardWrite>           DeferredLeaderboardWrites;                                // 0x0460(0x000C) (Const, NeedCtorLink)
	TArray<struct FDeferredLeaderboardWrite>           PendingLeaderboardStats;                                  // 0x046C(0x000C) (Const, NeedCtorLink)
	TArray<struct FLeaderboardEntry>                   ProcessedLeaderboardReads;                                // 0x0478(0x000C) (Const, NeedCtorLink)
	TArray<struct FViewIdToLeaderboardName>            LeaderboardNameMappings;                                  // 0x0484(0x000C) (Config, NeedCtorLink)
	class UOnlineAuthInterfaceSteamworks*              CachedAuthInt;                                            // 0x0490(0x0004) (Const)
	TArray<struct FIpAddr>                             PendingRedirects;                                         // 0x0494(0x000C) (Const, NeedCtorLink)
	TArray<struct FScriptDelegate>                     ExternalUIChangeDelegates;                                // 0x04A0(0x000C) (NeedCtorLink)
	struct FMarketplaceListCache                       DLCListCache;                                             // 0x04AC(0x001C) (NeedCtorLink)
	TArray<struct FMarketplaceOfferData>               MarketplaceOffers;                                        // 0x04C8(0x000C) (Config, NeedCtorLink)
	class UQoSHandlerSteamworks*                       QoSHandler;                                               // 0x04D4(0x0004)
	struct FScriptDelegate                             __OnLoginChange__Delegate;                                // 0x04D8(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnLoginCancelled__Delegate;                             // 0x04E4(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnMutingChange__Delegate;                               // 0x04F0(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnFriendsChange__Delegate;                              // 0x04FC(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnLoginFailed__Delegate;                                // 0x0508(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnLogoutCompleted__Delegate;                            // 0x0514(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnGetUserAgeGroup__Delegate;                            // 0x0520(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnLoginStatusChange__Delegate;                          // 0x052C(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReadProfileSettingsComplete__Delegate;                // 0x0538(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnWriteProfileSettingsComplete__Delegate;               // 0x0544(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReadPlayerStorageComplete__Delegate;                  // 0x0550(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReadPlayerStorageForNetIdComplete__Delegate;          // 0x055C(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnWritePlayerStorageComplete__Delegate;                 // 0x0568(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReadFriendsComplete__Delegate;                        // 0x0574(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnPlayerTalkingStateChange__Delegate;                   // 0x0580(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnRecognitionComplete__Delegate;                        // 0x058C(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReadOnlineStatsComplete__Delegate;                    // 0x0598(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnFlushOnlineStatsComplete__Delegate;                   // 0x05A4(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnLinkStatusChange__Delegate;                           // 0x05B0(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnExternalUIChange__Delegate;                           // 0x05BC(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnControllerChange__Delegate;                           // 0x05C8(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnConnectionStatusChange__Delegate;                     // 0x05D4(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnStorageDeviceChange__Delegate;                        // 0x05E0(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnShareTitleFileComplete__Delegate;                     // 0x05EC(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReadTitleFileComplete__Delegate;                      // 0x05F8(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnCreateOnlineAccountCompleted__Delegate;               // 0x0604(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnKeyboardInputComplete__Delegate;                      // 0x0610(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnAddFriendByNameComplete__Delegate;                    // 0x061C(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnFriendInviteReceived__Delegate;                       // 0x0628(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnSentGameInvite__Delegate;                             // 0x0634(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReceivedGameInvite__Delegate;                         // 0x0640(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnJoinFriendGameComplete__Delegate;                     // 0x064C(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnFriendMessageReceived__Delegate;                      // 0x0658(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnRegisterHostStatGuidComplete__Delegate;               // 0x0664(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnDeviceSelectionComplete__Delegate;                    // 0x0670(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnUnlockAchievementComplete__Delegate;                  // 0x067C(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnProfileDataChanged__Delegate;                         // 0x0688(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReadAchievementsComplete__Delegate;                   // 0x0694(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReadOnlineAvatarComplete__Delegate;                   // 0x06A0(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnGetNumberOfCurrentPlayersComplete__Delegate;          // 0x06AC(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReadCrossTitleProfileSettingsComplete__Delegate;      // 0x06B8(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnUnlockAvatarAwardComplete__Delegate;                  // 0x06C4(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnContentChange__Delegate;                              // 0x06D0(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReadContentComplete__Delegate;                        // 0x06DC(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReadCrossTitleContentComplete__Delegate;              // 0x06E8(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReadCrossTitleSaveGameDataComplete__Delegate;         // 0x06F4(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnQueryAvailableDownloadsComplete__Delegate;            // 0x0700(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReadSaveGameDataComplete__Delegate;                   // 0x070C(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnWriteSaveGameDataComplete__Delegate;                  // 0x0718(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReadSaveGamesComplete__Delegate;                      // 0x0724(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReadDownloadableContentListComplete__Delegate;        // 0x0730(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReadHiddenDownloadableContentListComplete__Delegate;  // 0x073C(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnReadCriticalDownloadableContentListComplete__Delegate;// 0x0748(0x000C) (NeedCtorLink)
	struct FScriptDelegate                             __OnCheckDownloadableContentList__Delegate;               // 0x0754(0x000C) (NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("OnlineSubsystemSteamworks");
		return ptr;
	}


	struct FString GetCountryString();
	void ClearCheckDownloadableContentListDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& CheckDownloadableContentListDelegate);
	void AddCheckDownloadableContentListDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& CheckDownloadableContentListDelegate);
	bool CheckDownloadableContentList(unsigned char LocalUserNum);
	void OnCheckDownloadableContentList(unsigned char LocalUserNum, bool bDownloadableContentListAvailable);
	unsigned char GetCriticalDownloadableContentList(unsigned char LocalUserNum, TArray<struct FMarketplaceContent>* DLCList);
	bool ReadCriticalDownloadableContentList(unsigned char LocalUserNum, int CategoryMask);
	void ClearReadCriticalDownloadableContentListComplete(unsigned char LocalUserNum, const struct FScriptDelegate& ReadCriticalDownloadableContentListCompleteDelegate);
	void AddReadCriticalDownloadableContentListComplete(unsigned char LocalUserNum, const struct FScriptDelegate& ReadCriticalDownloadableContentListCompleteDelegate);
	void OnReadCriticalDownloadableContentListComplete(bool bWasSuccessful);
	unsigned char GetHiddenDownloadableContentList(unsigned char LocalUserNum, TArray<struct FMarketplaceContent>* DLCList);
	bool ReadHiddenDownloadableContentList(unsigned char LocalUserNum, TArray<int> OfferIds);
	void ClearReadHiddenDownloadableContentListComplete(unsigned char LocalUserNum, const struct FScriptDelegate& ReadHiddenDownloadableContentListCompleteDelegate);
	void AddReadHiddenDownloadableContentListComplete(unsigned char LocalUserNum, const struct FScriptDelegate& ReadHiddenDownloadableContentListCompleteDelegate);
	void OnReadHiddenDownloadableContentListComplete(bool bWasSuccessful);
	unsigned char GetDownloadableContentList(unsigned char LocalUserNum, TArray<struct FMarketplaceContent>* DLCList);
	bool ReadDownloadableContentList(unsigned char LocalUserNum, int CategoryMask);
	void ClearReadDownloadableContentListComplete(unsigned char LocalUserNum, const struct FScriptDelegate& ReadDownloadableContentListCompleteDelegate);
	void AddReadDownloadableContentListComplete(unsigned char LocalUserNum, const struct FScriptDelegate& ReadDownloadableContentListCompleteDelegate);
	void OnReadDownloadableContentListComplete(bool bWasSuccessful);
	unsigned char GetSaveGamesList(unsigned char LocalUserNum, TArray<struct FOnlineContent>* SaveGamesList);
	bool ReadSaveGamesList(unsigned char LocalUserNum, int DeviceID, const struct FString& SaveFilePrefix);
	void ClearReadSaveGamesComplete(unsigned char LocalUserNum, const struct FScriptDelegate& ReadSaveGamesCompleteDelegate);
	void AddReadSaveGamesComplete(unsigned char LocalUserNum, const struct FScriptDelegate& ReadSaveGamesCompleteDelegate);
	void OnReadSaveGamesComplete(bool bWasSuccessful);
	bool ClearSaveGames(unsigned char LocalUserNum);
	bool DeleteSaveGame(unsigned char LocalUserNum, int DeviceID, const struct FString& FriendlyName, const struct FString& Filename);
	void ClearWriteSaveGameDataComplete(unsigned char LocalUserNum, const struct FScriptDelegate& WriteSaveGameDataCompleteDelegate);
	void AddWriteSaveGameDataComplete(unsigned char LocalUserNum, const struct FScriptDelegate& WriteSaveGameDataCompleteDelegate);
	void OnWriteSaveGameDataComplete(bool bWasSuccessful, unsigned char LocalUserNum, int DeviceID, const struct FString& FriendlyName, const struct FString& Filename, const struct FString& SaveFileName);
	bool WriteSaveGameData(unsigned char LocalUserNum, int DeviceID, const struct FString& FriendlyName, const struct FString& Filename, const struct FString& SaveFileName, TArray<unsigned char>* SaveGameData);
	void ClearReadSaveGameDataComplete(unsigned char LocalUserNum, const struct FScriptDelegate& ReadSaveGameDataCompleteDelegate);
	void AddReadSaveGameDataComplete(unsigned char LocalUserNum, const struct FScriptDelegate& ReadSaveGameDataCompleteDelegate);
	void OnReadSaveGameDataComplete(bool bWasSuccessful, unsigned char LocalUserNum, int DeviceID, const struct FString& FriendlyName, const struct FString& Filename, const struct FString& SaveFileName);
	bool GetSaveGameData(unsigned char LocalUserNum, int DeviceID, const struct FString& FriendlyName, const struct FString& Filename, const struct FString& SaveFileName, unsigned char* bIsValid, TArray<unsigned char>* SaveGameData);
	bool ReadSaveGameData(unsigned char LocalUserNum, int DeviceID, const struct FString& FriendlyName, const struct FString& Filename, const struct FString& SaveFileName);
	void GetAvailableDownloadCounts(unsigned char LocalUserNum, int* NewDownloads, int* TotalDownloads);
	void ClearQueryAvailableDownloadsComplete(unsigned char LocalUserNum, const struct FScriptDelegate& QueryDownloadsDelegate);
	void AddQueryAvailableDownloadsComplete(unsigned char LocalUserNum, const struct FScriptDelegate& QueryDownloadsDelegate);
	void OnQueryAvailableDownloadsComplete(bool bWasSuccessful);
	bool QueryAvailableDownloads(unsigned char LocalUserNum, int CategoryMask);
	bool ClearCrossTitleSaveGames(unsigned char LocalUserNum);
	void ClearReadCrossTitleSaveGameDataComplete(unsigned char LocalUserNum, const struct FScriptDelegate& ReadSaveGameDataCompleteDelegate);
	void AddReadCrossTitleSaveGameDataComplete(unsigned char LocalUserNum, const struct FScriptDelegate& ReadSaveGameDataCompleteDelegate);
	void OnReadCrossTitleSaveGameDataComplete(bool bWasSuccessful, unsigned char LocalUserNum, int DeviceID, int TitleId, const struct FString& FriendlyName, const struct FString& Filename, const struct FString& SaveFileName);
	bool GetCrossTitleSaveGameData(unsigned char LocalUserNum, int DeviceID, int TitleId, const struct FString& FriendlyName, const struct FString& Filename, const struct FString& SaveFileName, unsigned char* bIsValid, TArray<unsigned char>* SaveGameData);
	bool ReadCrossTitleSaveGameData(unsigned char LocalUserNum, int DeviceID, int TitleId, const struct FString& FriendlyName, const struct FString& Filename, const struct FString& SaveFileName);
	void ClearReadCrossTitleContentCompleteDelegate(unsigned char LocalUserNum, unsigned char ContentType, const struct FScriptDelegate& ReadContentCompleteDelegate);
	void AddReadCrossTitleContentCompleteDelegate(unsigned char LocalUserNum, unsigned char ContentType, const struct FScriptDelegate& ReadContentCompleteDelegate);
	void OnReadCrossTitleContentComplete(bool bWasSuccessful);
	unsigned char GetCrossTitleContentList(unsigned char LocalUserNum, unsigned char ContentType, TArray<struct FOnlineCrossTitleContent>* ContentList);
	void ClearCrossTitleContentList(unsigned char LocalUserNum, unsigned char ContentType);
	bool ReadCrossTitleContentList(unsigned char LocalUserNum, unsigned char ContentType, int TitleId, int DeviceID);
	unsigned char GetContentList(unsigned char LocalUserNum, unsigned char ContentType, TArray<struct FOnlineContent>* ContentList);
	void ClearContentList(unsigned char LocalUserNum, unsigned char ContentType);
	bool ReadContentList(unsigned char LocalUserNum, unsigned char ContentType, int DeviceID);
	void ClearReadContentComplete(unsigned char LocalUserNum, unsigned char ContentType, const struct FScriptDelegate& ReadContentCompleteDelegate);
	void AddReadContentComplete(unsigned char LocalUserNum, unsigned char ContentType, const struct FScriptDelegate& ReadContentCompleteDelegate);
	void OnReadContentComplete(bool bWasSuccessful);
	void ClearContentChangeDelegate(const struct FScriptDelegate& ContentDelegate, unsigned char LocalUserNum);
	void AddContentChangeDelegate(const struct FScriptDelegate& ContentDelegate, unsigned char LocalUserNum);
	void ClearContentChangeDelegateEx(const struct FScriptDelegate& ContentDelegate);
	void AddContentChangeDelegateEx(const struct FScriptDelegate& ContentDelegate);
	void OnContentChange();
	bool ShowRedeemCodeUI(unsigned char LocalUserNum);
	void DumpSteamworksSessionState();
	void DumpSessionState();
	bool SetVoiceVolume(unsigned char VolType, float VolumeParam);
	void ClearUnlockAvatarAwardCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& UnlockAvatarAwardCompleteDelegate);
	void AddUnlockAvatarAwardCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& UnlockAvatarAwardCompleteDelegate);
	void OnUnlockAvatarAwardComplete(bool bWasSuccessful);
	bool GetFriendJoinURL(const struct FUniqueNetId& FriendUID, struct FString* ServerURL, struct FString* ServerUID);
	bool GetCommandlineJoinURL(bool bMarkAsJoined, struct FString* ServerURL, struct FString* ServerUID);
	bool Int64ToUniqueNetId(const struct FString& UIDString, struct FUniqueNetId* OutUID);
	struct FString UniqueNetIdToInt64(struct FUniqueNetId* Uid);
	void NotifyVOIPPlaybackFinished(class UAudioComponent* VOIPAudioComponent);
	void OnVOIPPlaybackFinished(class UAudioComponent* AC);
	bool ShowProfileUI(unsigned char LocalUserNum, const struct FString& SubURL, const struct FUniqueNetId& PlayerUID);
	struct FString UniqueNetIdToPlayerName(struct FUniqueNetId* Uid);
	bool DisplayAchievementProgress(int AchievementId, int ProgressCount, int MaxProgress);
	bool CreateLeaderboard(const struct FString& LeaderboardName, unsigned char SortType, unsigned char DisplayFormat);
	bool ResetStats(bool bResetAchievements);
	bool ShowCustomMessageUI(unsigned char LocalUserNum, const struct FString& MessageTitle, const struct FString& NonEditableMessage, const struct FString& EditableMessage, TArray<struct FUniqueNetId>* Recipients);
	void ClearCrossTitleProfileSettings(unsigned char LocalUserNum, int TitleId);
	class UOnlineProfileSettings* GetCrossTitleProfileSettings(unsigned char LocalUserNum, int TitleId);
	void ClearReadCrossTitleProfileSettingsCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& ReadProfileSettingsCompleteDelegate);
	void AddReadCrossTitleProfileSettingsCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& ReadProfileSettingsCompleteDelegate);
	void OnReadCrossTitleProfileSettingsComplete(unsigned char LocalUserNum, int TitleId, bool bWasSuccessful);
	bool ReadCrossTitleProfileSettings(unsigned char LocalUserNum, int TitleId, class UOnlineProfileSettings* ProfileSettings);
	bool UnlockAvatarAward(unsigned char LocalUserNum, int AvatarItemId);
	TArray<struct FString> EnumerateFilesOnRemoteStorage();
	bool DeleteFileFromRemoteStorage(const struct FString& Filename);
	bool ReadBytesFromRemoteStorage(const struct FString& Filename, TArray<unsigned char>* Data);
	bool ReadStringFromRemoteStorage(const struct FString& Filename, struct FString* Data);
	bool WriteBytesToRemoteStorage(const struct FString& Filename, TArray<unsigned char> Data);
	bool WriteStringToRemoteStorage(const struct FString& Filename, const struct FString& Data);
	void GetSteamClanData(TArray<struct FSteamPlayerClanData>* Results);
	void ClearGetNumberOfCurrentPlayersCompleteDelegate(const struct FScriptDelegate& GetNumberOfCurrentPlayersCompleteDelegate);
	void AddGetNumberOfCurrentPlayersCompleteDelegate(const struct FScriptDelegate& GetNumberOfCurrentPlayersCompleteDelegate);
	void OnGetNumberOfCurrentPlayersComplete(int TotalPlayers);
	bool GetNumberOfCurrentPlayers();
	void ReadOnlineAvatar(const struct FUniqueNetId& PlayerNetId, int Size, const struct FScriptDelegate& ReadOnlineAvatarCompleteDelegate);
	void OnReadOnlineAvatarComplete(const struct FUniqueNetId& PlayerNetId, class UTexture2D* Avatar);
	bool ShowCustomPlayersUI(unsigned char LocalUserNum, const struct FString& Title, const struct FString& Description, TArray<struct FUniqueNetId>* Players);
	unsigned char GetAchievements(unsigned char LocalUserNum, int TitleId, TArray<struct FAchievementDetails>* Achievements);
	void ClearReadAchievementsCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& ReadAchievementsCompleteDelegate);
	void AddReadAchievementsCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& ReadAchievementsCompleteDelegate);
	void OnReadAchievementsComplete(int TitleId);
	bool ReadAchievements(unsigned char LocalUserNum, int TitleId, bool bShouldReadText, bool bShouldReadImages);
	bool ShowPlayersUI(unsigned char LocalUserNum);
	bool ShowFriendsInviteUI(unsigned char LocalUserNum, const struct FUniqueNetId& PlayerID);
	bool ShowFriendsUI(unsigned char LocalUserNum);
	void ClearProfileDataChangedDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& ProfileDataChangedDelegate);
	void AddProfileDataChangedDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& ProfileDataChangedDelegate);
	void OnProfileDataChanged();
	bool UnlockGamerPicture(unsigned char LocalUserNum, int PictureId);
	void ClearUnlockAchievementCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& UnlockAchievementCompleteDelegate);
	void AddUnlockAchievementCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& UnlockAchievementCompleteDelegate);
	void OnUnlockAchievementComplete(bool bWasSuccessful);
	bool UnlockAchievement(unsigned char LocalUserNum, int AchievementId);
	bool IsDeviceValid(int DeviceID, int SizeNeeded);
	int GetDeviceSelectionResults(unsigned char LocalUserNum, struct FString* DeviceName);
	void ClearDeviceSelectionDoneDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& DeviceDelegate);
	void AddDeviceSelectionDoneDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& DeviceDelegate);
	void OnDeviceSelectionComplete(bool bWasSuccessful);
	bool ShowDeviceSelectionUI(unsigned char LocalUserNum, int SizeNeeded, bool bForceShow, bool bManageStorage);
	bool ShowMembershipMarketplaceUI(unsigned char LocalUserNum);
	bool ShowContentPurchaseWebPage(unsigned char LocalUserNum, const struct FString& OfferURL);
	bool ShowContentPurchaseUI(unsigned char LocalUserNum, const struct FString& Offer, bool bCheckOut, bool bPreOrder);
	bool ShowContentMarketplaceUI(unsigned char LocalUserNum, int CategoryMask, int OfferId);
	bool ShowInviteUI(unsigned char LocalUserNum, const struct FString& InviteText);
	bool ShowAchievementsUI(unsigned char LocalUserNum);
	bool ShowMessagesUI(unsigned char LocalUserNum);
	bool ShowGamerCardUI(unsigned char LocalUserNum, const struct FUniqueNetId& PlayerID);
	bool ShowFeedbackUI(unsigned char LocalUserNum, const struct FUniqueNetId& PlayerID);
	bool DeleteMessage(unsigned char LocalUserNum, int MessageIndex);
	bool UnmuteAll(unsigned char LocalUserNum);
	bool MuteAll(unsigned char LocalUserNum, bool bAllowFriends);
	void CalcAggregateSkill(TArray<struct FDouble> Mus, TArray<struct FDouble> Sigmas, struct FDouble* OutAggregateMu, struct FDouble* OutAggregateSigma);
	bool RegisterStatGuid(const struct FUniqueNetId& PlayerID, struct FString* ClientStatGuid);
	struct FString GetClientStatGuid();
	void ClearRegisterHostStatGuidCompleteDelegateDelegate(const struct FScriptDelegate& RegisterHostStatGuidCompleteDelegate);
	void AddRegisterHostStatGuidCompleteDelegate(const struct FScriptDelegate& RegisterHostStatGuidCompleteDelegate);
	void OnRegisterHostStatGuidComplete(bool bWasSuccessful);
	bool RegisterHostStatGuid(struct FString* HostStatGuid);
	struct FString GetHostStatGuid();
	void ClearFriendMessageReceivedDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& MessageDelegate);
	void AddFriendMessageReceivedDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& MessageDelegate);
	void OnFriendMessageReceived(unsigned char LocalUserNum, const struct FUniqueNetId& SendingPlayer, const struct FString& SendingNick, const struct FString& Message);
	void GetFriendMessages(unsigned char LocalUserNum, TArray<struct FOnlineFriendMessage>* FriendMessages);
	void ClearJoinFriendGameCompleteDelegate(const struct FScriptDelegate& JoinFriendGameCompleteDelegate);
	void AddJoinFriendGameCompleteDelegate(const struct FScriptDelegate& JoinFriendGameCompleteDelegate);
	void OnJoinFriendGameComplete(bool bWasSuccessful);
	bool JoinFriendGame(unsigned char LocalUserNum, const struct FUniqueNetId& Friend);
	void ClearReceivedGameInviteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& ReceivedGameInviteDelegate);
	void AddReceivedGameInviteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& ReceivedGameInviteDelegate);
	void OnReceivedGameInvite(unsigned char LocalUserNum, const struct FString& InviterName);
	void ClearSentGameInviteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& SentGameInviteDelegate);
	void AddSentGameInviteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& SentGameInviteDelegate);
	void OnSentGameInvite(unsigned char LocalUserNum, bool bWasSuccessful);
	bool SendGameInviteToFriends(unsigned char LocalUserNum, TArray<struct FUniqueNetId> Friends, const struct FString& Text);
	bool SendGameInviteToFriend(unsigned char LocalUserNum, const struct FUniqueNetId& Friend, const struct FString& Text);
	bool SendMessageToFriend(unsigned char LocalUserNum, const struct FUniqueNetId& Friend, const struct FString& Message);
	void ClearFriendInviteReceivedDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& InviteDelegate);
	void AddFriendInviteReceivedDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& InviteDelegate);
	void OnFriendInviteReceived(unsigned char LocalUserNum, const struct FUniqueNetId& RequestingPlayer, const struct FString& RequestingNick, const struct FString& Message);
	bool DenyFriendInvite(unsigned char LocalUserNum, const struct FUniqueNetId& RequestingPlayer);
	bool AcceptFriendInvite(unsigned char LocalUserNum, const struct FUniqueNetId& RequestingPlayer);
	bool RemoveFriend(unsigned char LocalUserNum, const struct FUniqueNetId& FormerFriend);
	void ClearAddFriendByNameCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& FriendDelegate);
	void AddAddFriendByNameCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& FriendDelegate);
	void OnAddFriendByNameComplete(bool bWasSuccessful);
	bool AddFriendByName(unsigned char LocalUserNum, const struct FString& FriendName, const struct FString& Message);
	bool AddFriend(unsigned char LocalUserNum, const struct FUniqueNetId& NewFriend, const struct FString& Message);
	struct FString GetKeyboardInputResults(unsigned char* bWasCanceled);
	void ClearKeyboardInputDoneDelegate(const struct FScriptDelegate& InputDelegate);
	void AddKeyboardInputDoneDelegate(const struct FScriptDelegate& InputDelegate);
	void OnKeyboardInputComplete(bool bWasSuccessful);
	bool ShowKeyboardUI(unsigned char LocalUserNum, const struct FString& TitleText, const struct FString& DescriptionText, unsigned char KeyboardType, bool bShouldValidate, const struct FString& DefaultText, int MaxResultLength);
	void SetOnlineStatus(unsigned char LocalUserNum, int StatusId, TArray<struct FLocalizedStringSetting>* LocalizedStringSettings, TArray<struct FSettingsProperty>* Properties);
	bool GetLocalAccountNames(TArray<struct FString>* Accounts);
	bool DeleteLocalAccount(const struct FString& UserName, const struct FString& Password);
	bool RenameLocalAccount(const struct FString& NewUserName, const struct FString& OldUserName, const struct FString& Password);
	bool CreateLocalAccount(const struct FString& UserName, const struct FString& Password);
	void ClearCreateOnlineAccountCompletedDelegate(const struct FScriptDelegate& AccountCreateDelegate);
	void AddCreateOnlineAccountCompletedDelegate(const struct FScriptDelegate& AccountCreateDelegate);
	void OnCreateOnlineAccountCompleted(unsigned char ErrorStatus);
	bool CreateOnlineAccount(const struct FString& UserName, const struct FString& Password, const struct FString& EmailAddress, const struct FString& ProductKey);
	bool ClearDownloadedFile(const struct FString& Filename);
	bool ClearDownloadedFiles();
	unsigned char GetTitleFileState(const struct FString& Filename);
	bool GetTitleFileContents(const struct FString& Filename, TArray<unsigned char>* FileContents);
	void ClearReadTitleFileCompleteDelegate(const struct FScriptDelegate& ReadTitleFileCompleteDelegate);
	void AddReadTitleFileCompleteDelegate(const struct FScriptDelegate& ReadTitleFileCompleteDelegate);
	bool ReadTitleFile(unsigned char LocalUserNum, const struct FString& FileToRead);
	void OnReadTitleFileComplete(bool bWasSuccessful, const struct FString& Filename);
	void ClearShareTitleFileCompleteDelegate(const struct FScriptDelegate& ShareTitleFileCompleteDelegate);
	void AddShareTitleFileCompleteDelegate(const struct FScriptDelegate& ShareTitleFileCompleteDelegate);
	bool ShareTitleFile(const struct FString& FileToShare);
	void OnShareTitleFileComplete(bool bWasSuccessful, const struct FString& Filename, const struct FString& UGCHandle);
	void ClearStorageDeviceChangeDelegate(const struct FScriptDelegate& StorageDeviceChangeDelegate);
	void AddStorageDeviceChangeDelegate(const struct FScriptDelegate& StorageDeviceChangeDelegate);
	void OnStorageDeviceChange();
	int GetLocale();
	unsigned char GetNATType();
	void ClearConnectionStatusChangeDelegate(const struct FScriptDelegate& ConnectionStatusDelegate);
	void AddConnectionStatusChangeDelegate(const struct FScriptDelegate& ConnectionStatusDelegate);
	void OnConnectionStatusChange(unsigned char ConnectionStatus);
	bool IsControllerConnected(int ControllerId);
	void ClearControllerChangeDelegate(const struct FScriptDelegate& ControllerChangeDelegate);
	void AddControllerChangeDelegate(const struct FScriptDelegate& ControllerChangeDelegate);
	void OnControllerChange(int ControllerId, bool bIsConnected);
	void SetNetworkNotificationPosition(unsigned char NewPos);
	unsigned char GetNetworkNotificationPosition();
	void ClearExternalUIChangeDelegate(const struct FScriptDelegate& ExternalUIDelegate);
	void AddExternalUIChangeDelegate(const struct FScriptDelegate& ExternalUIDelegate);
	void OnExternalUIChange(bool bIsOpening);
	void ClearLinkStatusChangeDelegate(const struct FScriptDelegate& LinkStatusDelegate);
	void AddLinkStatusChangeDelegate(const struct FScriptDelegate& LinkStatusDelegate);
	void OnLinkStatusChange(bool bIsConnected);
	bool HasLinkConnection();
	struct FUniqueNetId GetPlayerUniqueNetIdFromIndex(int UserIndex);
	struct FString GetPlayerNicknameFromIndex(int UserIndex);
	bool WriteOnlinePlayerScores(const struct FName& SessionName, int LeaderboardId, TArray<struct FOnlinePlayerScore>* PlayerScores);
	void ClearFlushOnlineStatsCompleteDelegate(const struct FScriptDelegate& FlushOnlineStatsCompleteDelegate);
	void AddFlushOnlineStatsCompleteDelegate(const struct FScriptDelegate& FlushOnlineStatsCompleteDelegate);
	void OnFlushOnlineStatsComplete(const struct FName& SessionName, bool bWasSuccessful);
	bool FlushOnlineStats(const struct FName& SessionName);
	bool WriteOnlineStats(const struct FName& SessionName, const struct FUniqueNetId& Player, class UOnlineStatsWrite* StatsWrite);
	void FreeStats(class UOnlineStatsRead* StatsRead);
	void ClearReadOnlineStatsCompleteDelegate(const struct FScriptDelegate& ReadOnlineStatsCompleteDelegate);
	void AddReadOnlineStatsCompleteDelegate(const struct FScriptDelegate& ReadOnlineStatsCompleteDelegate);
	void OnReadOnlineStatsComplete(bool bWasSuccessful);
	bool ReadOnlineStatsByRankAroundPlayer(unsigned char LocalUserNum, class UOnlineStatsRead* StatsRead, int NumRows);
	bool ReadOnlineStatsByRank(class UOnlineStatsRead* StatsRead, int StartIndex, int NumToRead);
	bool ReadOnlineStatsForFriends(unsigned char LocalUserNum, class UOnlineStatsRead* StatsRead);
	bool ReadOnlineStats(class UOnlineStatsRead* StatsRead, TArray<struct FUniqueNetId>* Players);
	bool SetSpeechRecognitionObject(unsigned char LocalUserNum, class USpeechRecognition* SpeechRecogObj);
	bool SelectVocabulary(unsigned char LocalUserNum, int VocabularyId);
	void ClearRecognitionCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& RecognitionDelegate);
	void AddRecognitionCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& RecognitionDelegate);
	void OnRecognitionComplete();
	bool GetRecognitionResults(unsigned char LocalUserNum, TArray<struct FSpeechRecognizedWord>* Words);
	bool StopSpeechRecognition(unsigned char LocalUserNum);
	bool StartSpeechRecognition(unsigned char LocalUserNum);
	void StopNetworkedVoice(unsigned char LocalUserNum);
	void StartNetworkedVoice(unsigned char LocalUserNum);
	void ClearPlayerTalkingDelegate(const struct FScriptDelegate& TalkerDelegate);
	void AddPlayerTalkingDelegate(const struct FScriptDelegate& TalkerDelegate);
	void OnPlayerTalkingStateChange(const struct FUniqueNetId& Player, bool bIsTalking);
	bool UnmuteRemoteTalker(unsigned char LocalUserNum, const struct FUniqueNetId& PlayerID, bool bIsSystemWide);
	bool MuteRemoteTalker(unsigned char LocalUserNum, const struct FUniqueNetId& PlayerID, bool bIsSystemWide);
	bool SetRemoteTalkerPriority(unsigned char LocalUserNum, const struct FUniqueNetId& PlayerID, int Priority);
	bool IsHeadsetPresent(unsigned char LocalUserNum);
	bool IsRemotePlayerTalking(const struct FUniqueNetId& PlayerID);
	bool IsLocalPlayerTalking(unsigned char LocalUserNum);
	bool UnregisterRemoteTalker(const struct FUniqueNetId& PlayerID);
	bool RegisterRemoteTalker(const struct FUniqueNetId& PlayerID);
	bool UnregisterLocalTalker(unsigned char LocalUserNum);
	bool RegisterLocalTalker(unsigned char LocalUserNum);
	unsigned char GetFriendsList(unsigned char LocalUserNum, int Count, int StartingAt, TArray<struct FOnlineFriend>* Friends);
	void ClearReadFriendsCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& ReadFriendsCompleteDelegate);
	void AddReadFriendsCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& ReadFriendsCompleteDelegate);
	void OnReadFriendsComplete(bool bWasSuccessful);
	bool ReadFriendsList(unsigned char LocalUserNum, int Count, int StartingAt);
	void ClearWritePlayerStorageCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& WritePlayerStorageCompleteDelegate);
	void AddWritePlayerStorageCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& WritePlayerStorageCompleteDelegate);
	void OnWritePlayerStorageComplete(unsigned char LocalUserNum, bool bWasSuccessful);
	bool WritePlayerStorage(unsigned char LocalUserNum, class UOnlinePlayerStorage* PlayerStorage, int DeviceID);
	class UOnlinePlayerStorage* GetPlayerStorage(unsigned char LocalUserNum);
	void ClearReadPlayerStorageForNetIdCompleteDelegate(const struct FUniqueNetId& NetId, const struct FScriptDelegate& ReadPlayerStorageForNetIdCompleteDelegate);
	void AddReadPlayerStorageForNetIdCompleteDelegate(const struct FUniqueNetId& NetId, const struct FScriptDelegate& ReadPlayerStorageForNetIdCompleteDelegate);
	void OnReadPlayerStorageForNetIdComplete(const struct FUniqueNetId& NetId, bool bWasSuccessful);
	bool ReadPlayerStorageForNetId(unsigned char LocalUserNum, const struct FUniqueNetId& NetId, class UOnlinePlayerStorage* PlayerStorage);
	void ClearReadPlayerStorageCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& ReadPlayerStorageCompleteDelegate);
	void AddReadPlayerStorageCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& ReadPlayerStorageCompleteDelegate);
	void OnReadPlayerStorageComplete(unsigned char LocalUserNum, bool bWasSuccessful);
	bool ReadPlayerStorage(unsigned char LocalUserNum, class UOnlinePlayerStorage* PlayerStorage, int DeviceID);
	void ClearWriteProfileSettingsCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& WriteProfileSettingsCompleteDelegate);
	void AddWriteProfileSettingsCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& WriteProfileSettingsCompleteDelegate);
	void OnWriteProfileSettingsComplete(unsigned char LocalUserNum, bool bWasSuccessful);
	bool WriteProfileSettings(unsigned char LocalUserNum, class UOnlineProfileSettings* ProfileSettings);
	class UOnlineProfileSettings* GetProfileSettings(unsigned char LocalUserNum);
	void ClearReadProfileSettingsCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& ReadProfileSettingsCompleteDelegate);
	void AddReadProfileSettingsCompleteDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& ReadProfileSettingsCompleteDelegate);
	void OnReadProfileSettingsComplete(unsigned char LocalUserNum, bool bWasSuccessful);
	bool ReadProfileSettings(unsigned char LocalUserNum, class UOnlineProfileSettings* ProfileSettings);
	void ClearFriendsChangeDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& FriendsDelegate);
	void AddFriendsChangeDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& FriendsDelegate);
	void ClearMutingChangeDelegate(const struct FScriptDelegate& MutingDelegate);
	void AddMutingChangeDelegate(const struct FScriptDelegate& MutingDelegate);
	void ClearLoginCancelledDelegate(const struct FScriptDelegate& CancelledDelegate);
	void AddLoginCancelledDelegate(const struct FScriptDelegate& CancelledDelegate);
	void ClearLoginStatusChangeDelegate(const struct FScriptDelegate& LoginStatusDelegate, unsigned char LocalUserNum);
	void AddLoginStatusChangeDelegate(const struct FScriptDelegate& LoginStatusDelegate, unsigned char LocalUserNum);
	void OnLoginStatusChange(unsigned char NewStatus, const struct FUniqueNetId& NewId);
	void ClearLoginChangeDelegate(const struct FScriptDelegate& LoginDelegate);
	void AddLoginChangeDelegate(const struct FScriptDelegate& LoginDelegate);
	bool IsMuted(unsigned char LocalUserNum, const struct FUniqueNetId& PlayerID);
	bool AreAnyFriends(unsigned char LocalUserNum, TArray<struct FFriendsQuery>* Query);
	bool IsFriend(unsigned char LocalUserNum, const struct FUniqueNetId& PlayerID);
	unsigned char CanShowPresenceInformation(unsigned char LocalUserNum);
	unsigned char CanViewPlayerProfiles(unsigned char LocalUserNum);
	unsigned char CanPurchaseContent(unsigned char LocalUserNum);
	unsigned char CanDownloadUserContent(unsigned char LocalUserNum);
	unsigned char CanCommunicate(unsigned char LocalUserNum);
	unsigned char CanPlayOnline(unsigned char LocalUserNum);
	void ClearGetUserAgeGroupDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& GetUserAgeGroupDelegate);
	void AddGetUserAgeGroupDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& GetUserAgeGroupDelegate);
	bool GetUserAgeGroup(unsigned char LocalUserNum);
	void OnGetUserAgeGroup(unsigned char LocalUserNum, unsigned char UserAgeGroup);
	struct FString GetPlayerNickname(unsigned char LocalUserNum);
	bool GetUniquePlayerId(unsigned char LocalUserNum, struct FUniqueNetId* PlayerID);
	bool IsLocalLogin(unsigned char LocalUserNum);
	bool IsGuestLogin(unsigned char LocalUserNum);
	unsigned char GetLoginStatus(unsigned char LocalUserNum);
	void ClearLogoutCompletedDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& LogoutDelegate);
	void AddLogoutCompletedDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& LogoutDelegate);
	void OnLogoutCompleted(bool bWasSuccessful);
	bool Logout(unsigned char LocalUserNum);
	void ClearLoginFailedDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& LoginFailedDelegate);
	void AddLoginFailedDelegate(unsigned char LocalUserNum, const struct FScriptDelegate& LoginFailedDelegate);
	void OnLoginFailed(unsigned char LocalUserNum, unsigned char ErrorCode);
	bool AutoLogin();
	bool Login(unsigned char LocalUserNum, const struct FString& LoginName, const struct FString& Password, bool bWantsLocalOnly);
	bool ShowLoginUI(bool bShowOnlineOnly, int NumLoginOverride, bool bAddUser);
	void OnFriendsChange();
	void OnMutingChange();
	void OnLoginCancelled();
	void OnLoginChange(unsigned char LocalUserNum);
	void Exit();
	bool Init();
};


// Class OnlineSubsystemSteamworks.QoSHandlerSteamworks
// 0x00A4 (0x003C - 0x00E0)
class UQoSHandlerSteamworks : public UObject
{
public:
	int                                                MaxQoSRequest;                                            // 0x003C(0x0004) (Config)
	int                                                MaxQoSListen;                                             // 0x0040(0x0004) (Config)
	int                                                NumPingProbes;                                            // 0x0044(0x0004) (Config)
	int                                                PingProbeSize;                                            // 0x0048(0x0004) (Config)
	float                                              PingTimeout;                                              // 0x004C(0x0004) (Config)
	float                                              ChallengeTimeout;                                         // 0x0050(0x0004) (Config)
	float                                              ListenTimeout;                                            // 0x0054(0x0004) (Config)
	unsigned long                                      bEnabled : 1;                                             // 0x0058(0x0004)
	struct FMap_Mirror                                 ListenEntries;                                            // 0x005C(0x003C) (Native, Transient)
	struct FMap_Mirror                                 RequestEntries;                                           // 0x0098(0x003C) (Native, Transient)
	TArray<struct FPendingEntry>                       PendingRequests;                                          // 0x00D4(0x000C) (Transient, NeedCtorLink)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("QoSHandlerSteamworks");
		return ptr;
	}

};


// Class OnlineSubsystemSteamworks.SparkInterfaceSteamworks
// 0x0000 (0x00DC - 0x00DC)
class USparkInterfaceSteamworks : public USparkInterfaceImpl
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("SparkInterfaceSteamworks");
		return ptr;
	}

};


// Class OnlineSubsystemSteamworks.IpNetDriverSteamworks
// 0x0000 (0x01EC - 0x01EC)
class UIpNetDriverSteamworks : public UTcpNetDriver
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("IpNetDriverSteamworks");
		return ptr;
	}

};


// Class OnlineSubsystemSteamworks.IpNetConnectionSteamworks
// 0x0000 (0x5078 - 0x5078)
class UIpNetConnectionSteamworks : public UTcpipConnection
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("IpNetConnectionSteamworks");
		return ptr;
	}

};


#ifdef _MSC_VER
	#pragma pack(pop)
#endif
