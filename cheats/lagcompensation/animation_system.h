//#pragma once
//
//#include "..\..\includes.hpp"
//#include "..\..\sdk\structs.hpp"
//#include "c_resolver.h"
//
//enum
//{
//	MAIN,
//	NONE,
//	FIRST,
//	SECOND,
//	LOW_FIRST,
//	LOW_SECOND,
//	LOW_FIRST_20,
//	LOW_SECOND_20
//};
//
//enum resolve_type
//{
//	RESOLVE_STAND,
//	RESOLVE_MOVE,
//	RESOLVE_WALK,
//	RESOLVE_LBY,
//	RESOLVE_AIR
//};
//
//struct matrixes
//{
//	matrix3x4_t main[MAXSTUDIOBONES];
//	matrix3x4_t zero[MAXSTUDIOBONES];
//	matrix3x4_t first[MAXSTUDIOBONES];
//	matrix3x4_t second[MAXSTUDIOBONES];
//	matrix3x4_t low_first[MAXSTUDIOBONES];
//	matrix3x4_t low_second[MAXSTUDIOBONES];
//	matrix3x4_t low_first_20[MAXSTUDIOBONES];
//	matrix3x4_t low_second_20[MAXSTUDIOBONES];
//};
//
//class adjust_data;
//
//enum resolver_side
//{
//	RESOLVER_ORIGINAL,
//	RESOLVER_ZERO,
//	RESOLVER_FIRST,
//	RESOLVER_SECOND,
//	RESOLVER_LOW_FIRST,
//	RESOLVER_LOW_SECOND,
//	RESOLVER_LOW_FIRST1,
//	RESOLVER_LOW_SECOND1,
//	RESOLVER_LOW_FIRST_20,
//	RESOLVER_LOW_SECOND_20,
//	RESOLVER_ON_SHOT
//};
//
//enum animstate_layer_t
//{
//	ANIMATION_LAYER_AIMMATRIX = 0,
//	ANIMATION_LAYER_WEAPON_ACTION,
//	ANIMATION_LAYER_WEAPON_ACTION_RECROUCH,
//	ANIMATION_LAYER_ADJUST,
//	ANIMATION_LAYER_MOVEMENT_JUMP_OR_FALL,
//	ANIMATION_LAYER_MOVEMENT_LAND_OR_CLIMB,
//	ANIMATION_LAYER_MOVEMENT_MOVE,
//	ANIMATION_LAYER_MOVEMENT_STRAFECHANGE,
//	ANIMATION_LAYER_WHOLE_BODY,
//	ANIMATION_LAYER_FLASHED,
//	ANIMATION_LAYER_FLINCH,
//	ANIMATION_LAYER_ALIVELOOP,
//	ANIMATION_LAYER_LEAN,
//	ANIMATION_LAYER_COUNT,
//};
//
//class resolver
//{
//	player_t* player = nullptr;
//	adjust_data* player_record = nullptr;
//	bool low_delta();
//	bool low_delta2();
//	bool side = false;
//	float GetForwardYaw(player_t* ent);
//	float GetBackwardYaw(player_t* ent);
//	bool was_first_bruteforce = false;
//	bool was_second_bruteforce = false;
//	int CalculatedSide;
//	float desync_angle = 0.0f;
//	float last_anims_update_time;
//	bool fake = false;
//
//	int FreestandSide[64];
//	int last_ticks[65];
//
//	bool was_first_low_bruteforce = false;
//	bool was_second_low_bruteforce = false;
//
//	float lock_side = 0.0f;
//	float original_goal_feet_yaw = 0.0f;
//	float original_pitch = 0.0f;
//public:
//	void initialize(player_t* e, adjust_data* record, const float& goal_feet_yaw, const float& pitch);
//	void reset();
//	bool Side();
//	void resolve_yaw();
//	float resolve_pitch();
//	void StoreAntifreestand();
//
//	void setmode();
//	bool is_slow_walking();
//	bool update_walk_data();
//	bool is_breaking_lby(AnimationLayer cur_layer, AnimationLayer prev_layer);
//	bool IsAdjustingBalance();
//
//	bool TargetJitter(player_t* player, bool v2);
//	bool TargetSide(player_t* player);
//	int GetChokedPackets();
//	void DetectStand(player_t* player, int* side);
//	bool DoesHaveJitter(player_t* player, int* new_side);
//	void ResolveAngles(player_t* player);
//	void NoSpreadResolver();
//	float calculate_desync();
//	bool DoesHaveFakeAngles(player_t* player);
//	void initialize_yaw(player_t* e, adjust_data* record);
//	float b_yaw(player_t* player, float angle, int n);
//
//	AnimationLayer resolver_layers[3][13];
//	AnimationLayer previous_layers[13];
//
//	float gfy_default = 0.0f;
//	float positive_side = 0.0f;
//	float negative_side = 0.0f;
//
//	float resolver_goal_feet_yaw[7];
//
//	resolver_side last_side = RESOLVER_ORIGINAL;
//};
//
//enum resolver_type
//{
//	ORIGINAL,
//	BRUTEFORCE,
//	LBY,
//	TRACE,
//	DIRECTIONAL,
//	LAYERS,
//	ANIM_s,
//	ANIM_m,
//	ANIM_l,
//	LOCKED_SIDE,
//	HISTORY_SIDE,
//	SHOT,
//	ENGINE,
//	FREESTAND,
//	HURT,
//};
//
//enum resolver_history
//{
//	HISTORY_UNKNOWN = -1,
//	HISTORY_ORIGINAL,
//	HISTORY_ZERO,
//	HISTORY_DEFAULT,
//	HISTORY_LOW
//};
//
//enum modes
//{
//	AIR,
//	SLOW_WALKING,
//	MOVING,
//	STANDING,
//	FREESTANDING,
//	NO_MODE
//};
//
//class adjust_data //-V730
//{
//public:
//	player_t* player;
//	int i;
//	AnimationLayer right_layers[13];
//	AnimationLayer left_layers[13];
//	AnimationLayer center_layers[13];
//	AnimationLayer layers[13];
//	AnimationLayer previous_layers[13];
//	matrixes matrixes_data;
//	float exit_angle = 0;
//	resolver_type type;
//	resolver_side side;
//
//	bool m_flLowDelta;
//	bool m_flHighDelta;
//
//	float left;
//	float right;
//	float middle;
//
//	modes curMode;
//	int desync_amount = 0;
//
//	bool invalid;
//	bool immune;
//	bool dormant;
//	bool bot;
//	bool shot;
//
//	bool break_lagcomp;
//
//	int flags;
//	int bone_count;
//
//	float simulation_time;
//	float duck_amount;
//	float lby;
//	int m_ChokedTicks;
//
//	Vector angles;
//	Vector abs_angles;
//	Vector velocity;
//	Vector origin;
//	Vector mins;
//	Vector maxs;
//
//	adjust_data() //-V730
//	{
//		reset();
//	}
//
//	void reset()
//	{
//		player = nullptr;
//		i = -1;
//
//		type = ORIGINAL;
//		side = RESOLVER_ORIGINAL;
//
//		invalid = false;
//		immune = false;
//		dormant = false;
//		bot = false;
//		shot = false;
//
//		flags = 0;
//		bone_count = 0;
//
//		simulation_time = 0.0f;
//		duck_amount = 0.0f;
//		lby = 0.0f;
//
//		angles.Zero();
//		abs_angles.Zero();
//		velocity.Zero();
//		origin.Zero();
//		mins.Zero();
//		maxs.Zero();
//	}
//
//	adjust_data(player_t* e, bool store = true)
//	{
//		type = ORIGINAL;
//		side = RESOLVER_ORIGINAL;
//
//		invalid = false;
//		store_data(e, store);
//	}
//
//	void store_data(player_t* e, bool store = true)
//	{
//		if (!e->is_alive())
//			return;
//
//		player = e;
//		i = player->EntIndex();
//
//		if (store)
//		{
//			memcpy(layers, e->get_animlayers(), e->animlayer_count() * sizeof(AnimationLayer));
//			memcpy(matrixes_data.main, player->m_CachedBoneData().Base(), player->m_CachedBoneData().Count() * sizeof(matrix3x4_t));
//		}
//
//		immune = player->m_bGunGameImmunity() || player->m_fFlags() & FL_FROZEN;
//		dormant = player->IsDormant();
//
//		player_info_t player_info;
//		m_engine()->GetPlayerInfo(i, &player_info);
//
//		bot = player_info.fakeplayer;
//		shot = player->m_hActiveWeapon() && (player->m_hActiveWeapon()->m_fLastShotTime() == player->m_flSimulationTime());
//
//		flags = player->m_fFlags();
//		bone_count = player->m_CachedBoneData().Count();
//
//		simulation_time = player->m_flSimulationTime();
//		duck_amount = player->m_flDuckAmount();
//		lby = player->m_flLowerBodyYawTarget();
//
//		angles = player->m_angEyeAngles();
//		abs_angles = player->GetAbsAngles();
//		velocity = player->m_vecVelocity();
//		origin = player->m_vecOrigin();
//		mins = player->GetCollideable()->OBBMins();
//		maxs = player->GetCollideable()->OBBMaxs();
//	}
//
//	void adjust_player()
//	{
//		if (!valid(false))
//			return;
//
//		memcpy(player->get_animlayers(), layers, player->animlayer_count() * sizeof(AnimationLayer));
//		memcpy(player->m_CachedBoneData().Base(), matrixes_data.main, player->m_CachedBoneData().Count() * sizeof(matrix3x4_t)); //-V807
//
//		player->m_fFlags() = flags;
//		player->m_CachedBoneData().m_Size = bone_count;
//
//		player->m_flSimulationTime() = simulation_time;
//		player->m_flDuckAmount() = duck_amount;
//		player->m_flLowerBodyYawTarget() = lby;
//
//		player->m_angEyeAngles() = angles;
//		player->set_abs_angles(abs_angles);
//		player->m_vecVelocity() = velocity;
//		player->m_vecOrigin() = origin;
//		player->set_abs_origin(origin);
//		player->GetCollideable()->OBBMins() = mins;
//		player->GetCollideable()->OBBMaxs() = maxs;
//	}
//
//	bool valid(bool extra_checks = true)
//	{
//		if (!this) //-V704
//			return false;
//
//		if (i > 0)
//			player = (player_t*)m_entitylist()->GetClientEntity(i);
//
//		if (!player)
//			return false;
//
//		if (player->m_lifeState() != LIFE_ALIVE)
//			return false;
//
//		if (immune)
//			return false;
//
//		if (dormant)
//			return false;
//
//		if (!extra_checks)
//			return true;
//
//		if (invalid)
//			return false;
//
//		auto net_channel_info = m_engine()->GetNetChannelInfo();
//
//		if (!net_channel_info)
//			return false;
//
//		static auto sv_maxunlag = m_cvar()->FindVar(crypt_str("sv_maxunlag"));
//
//		auto outgoing = net_channel_info->GetLatency(FLOW_OUTGOING);
//		auto incoming = net_channel_info->GetLatency(FLOW_INCOMING);
//
//		auto correct = math::clamp(outgoing + incoming + util::get_interpolation(), 0.0f, sv_maxunlag->GetFloat());
//		
//		auto curtime = csgo.local()->is_alive() ? TICKS_TO_TIME(csgo.globals.fixed_tickbase) : m_globals()->m_curtime; //-V807
//		auto delta_time = correct - (curtime - simulation_time);
//
//		if (fabs(delta_time) > 0.2f)
//			return false;
//
//		auto extra_choke = 0;
//
//		if (csgo.globals.fakeducking)
//			extra_choke = 14 - m_clientstate()->iChokedCommands;
//
//		auto server_tickcount = extra_choke + m_globals()->m_tickcount + TIME_TO_TICKS(outgoing + incoming);
//		auto dead_time = (int)(TICKS_TO_TIME(server_tickcount) - sv_maxunlag->GetFloat());
//
//		if (simulation_time < (float)dead_time)
//			return false;
//
//		return true;
//	}
//};
//
//class optimized_adjust_data
//{
//public:
//	int i;
//	player_t* player;
//
//	float simulation_time;
//	float duck_amount;
//
//	Vector angles;
//	Vector origin;
//
//	bool shot;
//
//	optimized_adjust_data() //-V730
//	{
//		reset();
//	}
//
//	void reset()
//	{
//		i = 0;
//		player = nullptr;
//
//		simulation_time = 0.0f;
//		duck_amount = 0.0f;
//		shot = false;
//		angles.Zero();
//		origin.Zero();
//	}
//};
//
//extern std::deque <adjust_data> player_records[65];
//struct player_settings
//{
//	__int64 id;
//	resolver_history res_type;
//	bool low_stand;
//	bool low_move;
//	bool faking;
//	int neg;
//	int pos;
//
//	player_settings(__int64 id, resolver_history res_type, bool low_stand, bool low_move, bool faking, int left, int right) noexcept : id(id), res_type(res_type), low_stand(low_stand), low_move(low_move), faking(faking), neg(neg), pos(pos)
//	{
//
//	}
//};
//class lagcompensation : public singleton <lagcompensation>
//{
//public:
//	void stop(ClientFrameStage_t stage);
//	std::vector<player_settings> player_sets;
//	void extrapolate(player_t* player, Vector& origin, Vector& velocity, int& flags, bool wasonground);
//	void fsn(ClientFrameStage_t stage);
//	bool valid(int i, player_t* e);
//	void update_player_animations(player_t* e);
//
//	void FixPvs();
//	void apply_interpolation_flags(player_t* e);
//	float GetAngle(player_t* player);
//	void init();
//	resolver player_resolver[65];
//	bool is_dormant[65];
//	float previous_goal_feet_yaw[65];
//};

#pragma once

#include "..\..\includes.hpp"
#include "..\..\sdk\structs.hpp"

enum
{
    MAIN,
    NONE,
    FIRST,
    SECOND
};

enum resolver_type
{
    ORIGINAL,
    BRUTEFORCE,
    LBY,
    TRACE,
    DIRECTIONAL, 
    LAYERS
};

enum resolver_history
{
    HISTORY_UNKNOWN = -1,
    HISTORY_ORIGINAL,
    HISTORY_ZERO,
    HISTORY_DEFAULT,
    HISTORY_LOW
};

enum resolver_side
{
    RESOLVER_ORIGINAL,
    RESOLVER_ZERO,
    RESOLVER_FIRST,
    RESOLVER_SECOND,
    RESOLVER_LOW_FIRST,
    RESOLVER_LOW_SECOND,
    RESOLVER_LOW_FIRST1,
    RESOLVER_LOW_SECOND1
};

struct matrixes
{
    matrix3x4_t main[MAXSTUDIOBONES];
    matrix3x4_t zero[MAXSTUDIOBONES];
    matrix3x4_t first[MAXSTUDIOBONES];
    matrix3x4_t second[MAXSTUDIOBONES];
};

class adjust_data;

class resolver
{
    player_t* player = nullptr;
    adjust_data* player_record = nullptr;
    float gfy_default = 0.0f;
    bool side = false;
    bool fake = false;
    bool was_first_bruteforce = false;
    bool was_second_bruteforce = false;
    bool was_first_low_bruteforce;
    bool was_second_low_bruteforce;
    AnimationLayer resolver_layers[3][13];
	AnimationLayer previous_layers[13];
    float lock_side = 0.0f;
    float original_goal_feet_yaw = 0.0f;
    float original_pitch = 0.0f;
public:
    void initialize(player_t* e, adjust_data* record, const float& goal_feet_yaw, const float& pitch);
    void reset();
    void resolve_yaw();
    float resolve_pitch();

    resolver_side last_side = RESOLVER_ORIGINAL;
};
static float fl_stored_brute[65];
class adjust_data //-V730
{
public:
    player_t* player;
    int i;

    AnimationLayer layers[15];
    AnimationLayer center_layers[15];
    AnimationLayer left_layers[15];
    AnimationLayer right_layers[15];
    matrixes matrixes_data;

    resolver_type type;
    resolver_side side;

    bool break_lagcomp;

    bool invalid;
    bool immune;
    bool dormant;
    bool bot;

    int flags;
    int bone_count;

    float simulation_time;
    float duck_amount;
    float lby;

    Vector angles;
    Vector abs_angles;
    Vector velocity;
    Vector origin;
    Vector mins;
    Vector maxs;

    adjust_data() //-V730
    {
        reset();
    }

    void reset()
    {
        player = nullptr;
        i = -1;

        type = ORIGINAL;
        side = RESOLVER_ORIGINAL;

        invalid = false;
        immune = false;
        dormant = false;
        bot = false;

        flags = 0;
        bone_count = 0;

        simulation_time = 0.0f;
        duck_amount = 0.0f;
        lby = 0.0f;

        angles.Zero();
        abs_angles.Zero();
        velocity.Zero();
        origin.Zero();
        mins.Zero();
        maxs.Zero();
    }

    adjust_data(player_t* e, bool store = true)
    {
        type = ORIGINAL;
        side = RESOLVER_ORIGINAL;

        invalid = false;
        store_data(e, store);
    }

    void store_data(player_t* e, bool store = true)
    {
        if (!e->is_alive())
            return;

        player = e;
        i = player->EntIndex();

        if (store)
        {
            memcpy(layers, e->get_animlayers(), e->animlayer_count() * sizeof(AnimationLayer));
            memcpy(matrixes_data.main, player->m_CachedBoneData().Base(), player->m_CachedBoneData().Count() * sizeof(matrix3x4_t));
        }

        immune = player->m_bGunGameImmunity() || player->m_fFlags() & FL_FROZEN;
        dormant = player->IsDormant();

#if RELEASE
        player_info_t player_info;
        m_engine()->GetPlayerInfo(i, &player_info);

        bot = player_info.fakeplayer;
#else
        bot = false;
#endif

        flags = player->m_fFlags();
        bone_count = player->m_CachedBoneData().Count();

        simulation_time = player->m_flSimulationTime();
        duck_amount = player->m_flDuckAmount();
        lby = player->m_flLowerBodyYawTarget();

        angles = player->m_angEyeAngles();
        abs_angles = player->GetAbsAngles();
        velocity = player->m_vecVelocity();
        origin = player->m_vecOrigin();
        mins = player->GetCollideable()->OBBMins();
        maxs = player->GetCollideable()->OBBMaxs();
    }

    void adjust_player()
    {
        if (!valid(false))
            return;

        memcpy(player->get_animlayers(), layers, player->animlayer_count() * sizeof(AnimationLayer));
        memcpy(player->m_CachedBoneData().Base(), matrixes_data.main, player->m_CachedBoneData().Count() * sizeof(matrix3x4_t));

        player->m_fFlags() = flags;
        player->m_CachedBoneData().m_Size = bone_count;

        player->m_flSimulationTime() = simulation_time;
        player->m_flDuckAmount() = duck_amount;
        player->m_flLowerBodyYawTarget() = lby;

        player->m_angEyeAngles() = angles;
        player->set_abs_angles(abs_angles);
        player->m_vecVelocity() = velocity;
        player->m_vecOrigin() = origin;
        player->set_abs_origin(origin);
        player->GetCollideable()->OBBMins() = mins;
        player->GetCollideable()->OBBMaxs() = maxs;
    }

    bool valid(bool extra_checks = true)
    {
        if (!this) //-V704
            return false;

        if (i > 0)
            player = (player_t*)m_entitylist()->GetClientEntity(i);

        if (!player)
            return false;

        if (player->m_lifeState() != LIFE_ALIVE)
            return false;

        if (immune)
            return false;

        if (dormant)
            return false;

        if (!extra_checks)
            return true;

        if (invalid)
            return false;

        auto net_channel_info = m_engine()->GetNetChannelInfo();

        if (!net_channel_info)
            return false;

        static auto sv_maxunlag = m_cvar()->FindVar(crypt_str("sv_maxunlag"));

        auto outgoing = net_channel_info->GetLatency(FLOW_OUTGOING);
        auto incoming = net_channel_info->GetLatency(FLOW_INCOMING);

        auto correct = math::clamp(outgoing + incoming + util::get_interpolation(), 0.0f, sv_maxunlag->GetFloat());

        auto curtime = csgo.local()->is_alive() ? TICKS_TO_TIME(csgo.globals.fixed_tickbase) : m_globals()->m_curtime;
        auto delta_time = correct - (curtime - simulation_time);

        if (fabs(delta_time) > 0.2f)
            return false;

        auto extra_choke = 0;

        if (csgo.globals.fakeducking)
            extra_choke = 14 - m_clientstate()->iChokedCommands;

        auto server_tickcount = extra_choke + m_globals()->m_tickcount + TIME_TO_TICKS(outgoing + incoming);
        auto dead_time = (int)(TICKS_TO_TIME(server_tickcount) - sv_maxunlag->GetFloat());

        if (simulation_time < (float)dead_time)
            return false;

        return true;
    }
};

class optimized_adjust_data
{
public:
    int i;
    player_t* player;

    float simulation_time;
    float duck_amount;

    Vector angles;
    Vector origin;

    optimized_adjust_data() //-V730
    {
        reset();
    }

    void reset()
    {
        i = 0;
        player = nullptr;

        simulation_time = 0.0f;
        duck_amount = 0.0f;

        angles.Zero();
        origin.Zero();
    }
};

struct player_settings
{
    __int64 id;
    resolver_history res_type;
    bool faking;
    int neg;
    int pos;

    player_settings(__int64 id, resolver_history res_type, bool faking, int left, int right) noexcept : id(id), res_type(res_type), faking(faking), neg(neg), pos(pos)
    {

    }
};

extern std::deque <adjust_data> player_records[65];

class lagcompensation : public singleton <lagcompensation>
{
public:
    void fsn(ClientFrameStage_t stage);
    void extrapolate(player_t* player, Vector& origin, Vector& velocity, int& flags, bool wasonground);
    bool valid(int i, player_t* e);
    void update_player_animations(player_t* e);

    resolver player_resolver[65];
    std::vector<player_settings> player_sets;

    bool is_dormant[65];
    float previous_goal_feet_yaw[65];
};