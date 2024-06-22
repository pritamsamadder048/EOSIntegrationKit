﻿// Copyright (c) 2023 Betide Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemEIK/SdkFunctions/EIK_SharedFunctionFile.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EIK_LobbySubsystem.generated.h"

DECLARE_DYNAMIC_DELEGATE_TwoParams(FEIK_Lobby_OnJoinLobbyAcceptedCallback, FEIK_ProductUserId, LocalUserId, const FEIK_UI_EventId&, UiEventId);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FEIK_Lobby_OnLeaveLobbyRequestedCallback, FEIK_ProductUserId, LocalUserId, const FEIK_LobbyId&, LobbyId);
DECLARE_DYNAMIC_DELEGATE_FourParams(FEIK_Lobby_OnLobbyInviteAcceptedCallback, FEIK_ProductUserId, LocalUserId, FEIK_ProductUserId, TargetUserId, const FEIK_LobbyId&, LobbyId, const FString&, InviteId);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FEIK_Lobby_OnLobbyInviteReceivedCallback, FEIK_ProductUserId, LocalUserId, FEIK_ProductUserId, TargetUserId, const FString&, InviteId);
DECLARE_DYNAMIC_DELEGATE_FourParams(FEIK_Lobby_OnLobbyInviteRejectedCallback, FEIK_ProductUserId, LocalUserId, FEIK_ProductUserId, TargetUserId, const FEIK_LobbyId&, LobbyId, const FString&, InviteId);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FEIK_Lobby_OnLobbyMemberStatusReceivedCallback, FEIK_ProductUserId, TargetUserId, const FEIK_LobbyId&, LobbyId, const TEnumAsByte<EEIK_ELobbyMemberStatus>&, CurrentStatus);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FEIK_Lobby_OnLobbyMemberUpdateReceivedCallback, FEIK_ProductUserId, TargetUserId, const FEIK_LobbyId&, LobbyId);
DECLARE_DYNAMIC_DELEGATE_OneParam(FEIK_Lobby_OnLobbyUpdateReceivedCallback, const FEIK_LobbyId&, LobbyId);
DECLARE_DYNAMIC_DELEGATE_FourParams(FEIK_Lobby_OnRTCRoomConnectionChangedCallback, const FEIK_LobbyId&, LobbyId, const FEIK_ProductUserId&, LocalUserId, bool, bIsConnected, const TEnumAsByte<EEIK_Result>&, DisconnectReason);
DECLARE_DYNAMIC_DELEGATE_FiveParams(FEIK_Lobby_OnSendLobbyNativeInviteCallback, FEIK_UI_EventId, UiEventId, FEIK_ProductUserId, LocalUserId, const FString&, TargetNativeAccountType, const FString&, TargetUserNativeAccountId, const FEIK_LobbyId&, LobbyId);

UCLASS(DisplayName="Lobby Interface", meta=(DisplayName="Lobby Interface"))
class ONLINESUBSYSTEMEIK_API UEIK_LobbySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	FEIK_Lobby_OnJoinLobbyAcceptedCallback OnJoinLobbyAccepted;
	//Register to receive notifications about lobby "JOIN" performed by local user (when no invite) via the overlay.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_AddNotifyJoinLobbyAccepted")
	FEIK_NotificationId EIK_Lobby_AddNotifyJoinLobbyAccepted(FEIK_Lobby_OnJoinLobbyAcceptedCallback Callback);

	//Unregister from receiving notifications when a user accepts a lobby invitation via the overlay.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_RemoveNotifyJoinLobbyAccepted")
	void EIK_Lobby_RemoveNotifyJoinLobbyAccepted(FEIK_NotificationId InId);


	FEIK_Lobby_OnLeaveLobbyRequestedCallback OnLeaveLobbyRequested;
	//Register to receive notifications about leave lobby requests performed by the local user via the overlay. When user requests to leave the lobby in the social overlay, the SDK does not automatically leave the lobby, it is up to the game to perform any necessary cleanup and call the EOS_Lobby_LeaveLobby method using the lobbyId sent in the notification function.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_AddNotifyLeaveLobbyRequested")
	FEIK_NotificationId EIK_Lobby_AddNotifyLeaveLobbyRequested(FEIK_Lobby_OnLeaveLobbyRequestedCallback Callback);

	//Unregister from receiving notifications when a user performs a leave lobby action via the overlay.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_RemoveNotifyLeaveLobbyRequested")
	void EIK_Lobby_RemoveNotifyLeaveLobbyRequested(FEIK_NotificationId InId);
	
	FEIK_Lobby_OnLobbyInviteAcceptedCallback OnLobbyInviteAccepted;
	//Register to receive notifications about lobby invites accepted by local user via the overlay.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_AddNotifyLobbyInviteAccepted")
	FEIK_NotificationId EIK_Lobby_AddNotifyLobbyInviteAccepted(FEIK_Lobby_OnLobbyInviteAcceptedCallback Callback);

	//Unregister from receiving notifications when a user accepts a lobby invitation via the overlay.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_RemoveNotifyLobbyInviteAccepted")
	void EIK_Lobby_RemoveNotifyLobbyInviteAccepted(FEIK_NotificationId InId);

	
	FEIK_Lobby_OnLobbyInviteReceivedCallback OnLobbyInviteReceived;
	//Register to receive notifications about lobby invites sent to local users.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_AddNotifyLobbyInviteReceived")
	FEIK_NotificationId EIK_Lobby_AddNotifyLobbyInviteReceived(FEIK_Lobby_OnLobbyInviteReceivedCallback Callback);

	//Unregister from receiving notifications when a user receives a lobby invitation.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_RemoveNotifyLobbyInviteReceived")
	void EIK_Lobby_RemoveNotifyLobbyInviteReceived(FEIK_NotificationId InId);


	
	FEIK_Lobby_OnLobbyInviteRejectedCallback OnLobbyInviteRejected;
	//Register to receive notifications about lobby invites rejected by local user.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_AddNotifyLobbyInviteRejected")
	FEIK_NotificationId EIK_Lobby_AddNotifyLobbyInviteRejected(FEIK_Lobby_OnLobbyInviteRejectedCallback Callback);

	//Unregister from receiving notifications when a user rejects a lobby invitation via the overlay.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_RemoveNotifyLobbyInviteRejected")
	void EIK_Lobby_RemoveNotifyLobbyInviteRejected(FEIK_NotificationId InId);

	
	
	FEIK_Lobby_OnLobbyMemberStatusReceivedCallback OnLobbyMemberStatusReceived;
	//Register to receive notifications about the changing status of lobby members.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_AddNotifyLobbyMemberStatusReceived")
	FEIK_NotificationId EIK_Lobby_AddNotifyLobbyMemberStatusReceived(FEIK_Lobby_OnLobbyMemberStatusReceivedCallback Callback);

	//Unregister from receiving notifications when lobby members status change.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_RemoveNotifyLobbyMemberStatusReceived")
	void EIK_Lobby_RemoveNotifyLobbyMemberStatusReceived(FEIK_NotificationId InId);

	

	FEIK_Lobby_OnLobbyMemberUpdateReceivedCallback OnLobbyMemberUpdateReceived;
	//Register to receive notifications when a lobby member updates the attributes associated with themselves inside the lobby.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_AddNotifyLobbyMemberUpdateReceived")
	FEIK_NotificationId EIK_Lobby_AddNotifyLobbyMemberUpdateReceived(FEIK_Lobby_OnLobbyMemberUpdateReceivedCallback Callback);

	//Unregister from receiving notifications when lobby members change their data.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_RemoveNotifyLobbyMemberUpdateReceived")
	void EIK_Lobby_RemoveNotifyLobbyMemberUpdateReceived(FEIK_NotificationId InId);

	
	
	FEIK_Lobby_OnLobbyUpdateReceivedCallback OnLobbyUpdateReceived;
	//Register to receive notifications when a lobby owner updates the attributes associated with the lobby.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_AddNotifyLobbyUpdateReceived")
	FEIK_NotificationId EIK_Lobby_AddNotifyLobbyUpdateReceived(FEIK_Lobby_OnLobbyUpdateReceivedCallback Callback);

	//Unregister from receiving notifications when a lobby changes its data.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_RemoveNotifyLobbyUpdateReceived")
	void EIK_Lobby_RemoveNotifyLobbyUpdateReceived(FEIK_NotificationId InId);


	
	FEIK_Lobby_OnRTCRoomConnectionChangedCallback OnRTCRoomConnectionChanged;
	//Register to receive notifications of when the RTC Room for a particular lobby has a connection status change. The RTC Room connection status is independent of the lobby connection status, however the lobby system will attempt to keep them consistent, automatically connecting to the RTC room after joining a lobby which has an associated RTC room and disconnecting from the RTC room when a lobby is left or disconnected. This notification is entirely informational and requires no action in response by the application. If the connected status is offline (bIsConnected is EOS_FALSE), the connection will automatically attempt to reconnect. The purpose of this notification is to allow applications to show the current connection status of the RTC room when the connection is not established. Unlike EOS_RTC_AddNotifyDisconnected, EOS_RTC_LeaveRoom should not be called when the RTC room is disconnected. This function will only succeed when called on a lobby the local user is currently a member of.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_AddNotifyRTCRoomConnectionChanged")
	FEIK_NotificationId EIK_Lobby_AddNotifyRTCRoomConnectionChanged(FEIK_Lobby_OnRTCRoomConnectionChangedCallback Callback);

	//Unregister from receiving notifications when an RTC Room's connection status changes. This should be called when the local user is leaving a lobby.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_RemoveNotifyRTCRoomConnectionChanged")
	void EIK_Lobby_RemoveNotifyRTCRoomConnectionChanged(FEIK_NotificationId InId);


	
	FEIK_Lobby_OnSendLobbyNativeInviteCallback OnSendLobbyNativeInvite;
	//Register to receive notifications about a lobby "INVITE" performed by a local user via the overlay. This is only needed when a configured integrated platform has EOS_IPMF_DisableSDKManagedSessions set. The EOS SDK will then use the state of EOS_IPMF_PreferEOSIdentity and EOS_IPMF_PreferIntegratedIdentity to determine when the NotificationFn is called.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_AddNotifySendLobbyNativeInviteRequested")
	FEIK_NotificationId EIK_Lobby_AddNotifySendLobbyNativeInviteRequested(FEIK_Lobby_OnSendLobbyNativeInviteCallback Callback);

	//Unregister from receiving notifications when a user requests a send invite via the overlay.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_RemoveNotifySendLobbyNativeInviteRequested")
	void EIK_Lobby_RemoveNotifySendLobbyNativeInviteRequested(FEIK_NotificationId InId);





	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_Attribute_Release")
	void EIK_Lobby_Attribute_Release(const FEIK_Lobby_Attribute& Attribute);

	//Create a handle to an existing lobby. If the call returns an EOS_Success result, the out parameter, OutLobbyDetailsHandle, must be passed to EOS_LobbyDetails_Release to release the memory associated with it.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_CopyLobbyDetailsHandle")
	TEnumAsByte<EEIK_Result> EIK_Lobby_CopyLobbyDetailsHandle(FEIK_LobbyId LobbyId, FEIK_ProductUserId LocalUserId, FEIK_HLobbyDetails& OutLobbyDetailsHandle);

	//EOS_Lobby_CopyLobbyDetailsHandleByInviteId is used to immediately retrieve a handle to the lobby information from after notification of an invite If the call returns an EOS_Success result, the out parameter, OutLobbyDetailsHandle, must be passed to EOS_LobbyDetails_Release to release the memory associated with it.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_CopyLobbyDetailsHandleByInviteId")
	TEnumAsByte<EEIK_Result> EIK_Lobby_CopyLobbyDetailsHandleByInviteId(FString InviteId, FEIK_HLobbyDetails& OutLobbyDetailsHandle);

	//EOS_Lobby_CopyLobbyDetailsHandleByUiEventId is used to immediately retrieve a handle to the lobby information from after notification of an join game If the call returns an EOS_Success result, the out parameter, OutLobbyDetailsHandle, must be passed to EOS_LobbyDetails_Release to release the memory associated with it.
	UFUNCTION(BlueprintCallable, Category = "EOS Integration Kit | SDK Functions | Lobby Interface", DisplayName="EOS_Lobby_CopyLobbyDetailsHandleByUiEventId")
	TEnumAsByte<EEIK_Result> EIK_Lobby_CopyLobbyDetailsHandleByUiEventId(const FEIK_UI_EventId& UiEventId, FEIK_HLobbyDetails& OutLobbyDetailsHandle);
	
};
