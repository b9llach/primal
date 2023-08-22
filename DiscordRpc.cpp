#include "DiscordRpc.h"
#include <DiscordRPCSDK/Includes/discord_rpc.h>

void Discord::Initialize()
{
    DiscordEventHandlers Handle;
    memset(&Handle, 0, sizeof(Handle));
    Discord_Initialize("1070922036161019974", &Handle, 1, NULL);
}

void Discord::Update()
{
    DiscordRichPresence discord;
    memset(&discord, 0, sizeof(discord));
    discord.details = "Playing CS:GO";
    discord.state = "With Latinaware";
    discord.largeImageKey = "image2";
    discord.smallImageKey = "image1";
    Discord_UpdatePresence(&discord);
}