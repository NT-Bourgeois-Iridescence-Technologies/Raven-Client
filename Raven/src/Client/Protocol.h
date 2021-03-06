#pragma once
#include <Network//NetworkDriver.h>
#include <iostream>
using namespace Stardust::Network;

namespace Minecraft::Protocol{

	enum PacketsIn {
		SPAWN_OBJECT = 0x00,
		SPAWN_EXPERIENCE_ORB = 0x01,
		SPAWN_GLOBAL_ENTITY = 0x02,
		SPAWN_MOB = 0x03,
		SPAWN_PAINTING = 0x04,
		SPAWN_PLAYER = 0x05,
		ANIMATION = 0x06,
		STATISTICS = 0x07,
		BLOCK_BREAK_ANIMATION = 0x08,
		UPDATE_BLOCK_ENTITY = 0x09,
		BLOCK_ACTION = 0x0A,
		BLOCK_CHANGE = 0x0B,
		BOSS_BAR = 0x0C,
		SERVER_DIFFICULTY = 0x0D,
		CHAT_MESSAGE = 0x0E,
		MULTI_BLOCK_CHANGE = 0x0F,
		TAB_COMPLETE = 0x10,
		DECLARE_COMMANDS = 0x11,
		CONFIRM_TRANSACTION = 0x12,
		CLOSE_WINDOW = 0x13,
		OPEN_WINDOW = 0x14,
		WINDOW_ITEMS = 0x15,
		WINDOW_PROPERTY = 0x16,
		SET_SLOT = 0x17,
		SET_COOLDOWN = 0x18,
		PLUGIN_MESSAGE = 0x19,
		NAMED_SOUND_EFFECT = 0x1A,
		DISCONNECT = 0x1B,
		ENTITY_STATUS = 0x1C,
		NBT_QUERY_RESPONSE = 0x1D,
		EXPLOSION = 0x1E,
		UNLOAD_CHUNK = 0x1F,
		CHANGE_GAME_STATE = 0x20,
		KEEP_ALIVE = 0x21,
		CHUNK_DATA = 0x22,
		EFFECT = 0x23,
		PARTICLE = 0x24,
		JOIN_GAME = 0x25,
		MAP_DATA = 0x26,
		ENTITY = 0x27,
		ENTITY_RELATIVE_MOVE = 0x28,
		ENTITY_LOOK_AND_RELATIVE_MOVE = 0x29,
		ENTITY_LOOK = 0x2A,
		VEHICLE_MOVE = 0x2B,
		OPEN_SIGN_EDITOR = 0x2C,
		CRAFT_RECIPE_RESPONSE = 0x2D,
		PLAYER_ABILITIES = 0x2E,
		COMBAT_EVENT = 0x2F,
		PLAYER_INFO = 0x30,
		FACE_PLAYER = 0x31,
		PLAYER_POSITION_AND_LOOK = 0x32,
		USE_BED = 0x33,
		UNLOCK_RECIPES = 0x34,
		DESTROY_ENTITIES = 0x35,
		REMOVE_ENTITY_EFFECT = 0x36,
		RESOURCE_PACK_SEND = 0x37,
		RESPAWN = 0x38,
		ENTITY_HEAD_LOOK = 0x39,
		SELECT_ADVANCEMENT_TAB = 0x3A,
		WORLD_BORDER = 0x3B,
		CAMERA = 0x3C,
		HELD_ITEM_CHANGE = 0x3D,
		DISPLAY_SCOREBOARD = 0x3E,
		ENTITY_METADATA = 0x3F,
		ATTACH_ENTITY = 0x40,
		ENTITY_VELOCITY = 0x41,
		ENTITY_EQUIPMENT = 0x42,
		SET_EXPERIENCE = 0x43,
		UPDATE_HEALTH = 0x44,
		SCOREBOARD_OBJECTIVE = 0x45,
		SET_PASSENGERS = 0x46,
		TEAMS = 0x47,
		UPDATE_SCORE = 0x48,
		SPAWN_POSITION = 0x49,
		TIME_UPDATE = 0x4A,
		TITLE = 0x4B,
		STOP_SOUND = 0x4C,
		SOUND_EFFECT = 0x4D,
		PLAYER_LIST_HEADER_AND_FOOTER = 0x4E,
		COLLECT_ITEM = 0x4F,
		ENTITY_TELEPORT = 0x50,
		ADVANCEMENTS = 0x51,
		ENTITY_PROPERTIES = 0x52,
		ENTITY_EFFECT = 0x53,
		DECLARE_RECIPES = 0x54,
		TAGS = 0x55
	};

	//Bunch of handlers
	int spawn_object_handler(PacketIn* p);
	int spawn_experience_orb_handler(PacketIn* p);
	int spawn_global_entity_handler(PacketIn* p);
	int spawn_mob_handler(PacketIn* p);
	int spawn_painting_handler(PacketIn* p);
	int spawn_player_handler(PacketIn* p);
	int animation_handler(PacketIn* p);
	int statistics_handler(PacketIn* p);
	int block_break_animation_handler(PacketIn* p);
	int update_block_entity_handler(PacketIn* p);
	int block_action_handler(PacketIn* p);
	int block_change_handler(PacketIn* p);
	int boss_bar_handler(PacketIn* p);
	int server_difficulty_handler(PacketIn* p);
	int chat_message_handler(PacketIn* p);
	int multi_block_change_handler(PacketIn* p);
	int tab_complete_handler(PacketIn * p);
	int declare_commands_handler(PacketIn* p);
	int confirm_transaction_handler(PacketIn* p);
	int close_window_handler(PacketIn* p);
	int open_window_handler(PacketIn* p);
	int window_items_handler(PacketIn* p);
	int window_property_handler(PacketIn* p);
	int set_slot_handler(PacketIn* p);
	int set_cooldown_handler(PacketIn* p);
	int plugin_message_handler(PacketIn* p);
	int named_sound_effect_handler(PacketIn* p);
	int disconnect_handler(PacketIn* p);
	int entity_status_handler(PacketIn* p);
	int nbt_query_response_handler(PacketIn* p);
	int explosion_handler(PacketIn* p);
	int unload_chunk_handler(PacketIn* p);
	int change_game_state_handler(PacketIn* p);
	int keep_alive_handler(PacketIn* p);
	int chunk_data_handler(PacketIn* p);
	int effect_handler(PacketIn* p);
	int particle_handler(PacketIn* p);
	int join_game_handler(PacketIn* p);
	int map_data_handler(PacketIn* p);
	int entity_handler(PacketIn* p);
	int entity_relative_move_handler(PacketIn* p);
	int entity_look_and_relative_move_handler(PacketIn* p);
	int entity_look_handler(PacketIn* p);
	int vehicle_move_handler(PacketIn* p);
	int open_sign_editor_handler(PacketIn* p);
	int craft_recipe_response_handler(PacketIn* p);
	int player_abilities_handler(PacketIn* p);
	int combat_event_handler(PacketIn* p);
	int player_info_handler(PacketIn* p);
	int face_player_handler(PacketIn* p);
	int player_position_and_look_handler(PacketIn* p);
	int use_bed_handler(PacketIn* p);
	int unlock_recipes_handler(PacketIn* p);
	int destroy_entities_handler(PacketIn* p);
	int remove_entity_effect_handler(PacketIn* p);
	int resource_pack_send_handler(PacketIn* p);
	int respawn_handler(PacketIn* p);
	int entity_head_look_handler(PacketIn* p);
	int select_advancement_tab_handler(PacketIn* p);
	int world_border_handler(PacketIn* p);
	int camera_handler(PacketIn* p);
	int held_item_change_handler(PacketIn* p);
	int display_scoreboard_handler(PacketIn* p);
	int entity_metadata_handler(PacketIn* p);
	int attach_entity_handler(PacketIn* p);
	int entity_velocity_handler(PacketIn* p);
	int entity_equipment_handler(PacketIn* p);
	int set_experience_handler(PacketIn* p);
	int update_health_handler(PacketIn* p);
	int scoreboard_objective_handler(PacketIn* p);
	int set_passengers_handler(PacketIn* p);
	int teams_handler(PacketIn* p);
	int update_score_handler(PacketIn* p);
	int spawn_position_handler(PacketIn* p);
	int time_update_handler(PacketIn* p);
	int title_handler(PacketIn* p);
	int stop_sound_handler(PacketIn* p);
	int sound_effect_handler(PacketIn* p);
	int player_list_header_and_footer_handler(PacketIn* p);
	int collect_item_handler(PacketIn* p);
	int entity_teleport_handler(PacketIn* p);
	int advancements_handler(PacketIn* p);
	int entity_properties_handler(PacketIn* p);
	int entity_effect_handler(PacketIn* p);
	int declare_recipes_handler(PacketIn* p);
	int tags_handler(PacketIn* p);

	namespace PacketsOut{
		//Bunch of utility packet writing functions
		void send_plugin_message(std::string identifier, std::string data);
		void send_client_settings(std::string locale, uint8_t distance, uint8_t c_mode, bool colors, uint8_t bitmask, uint8_t hand);
		void send_keep_alive(uint64_t longData);
		void send_teleport_confirm(uint32_t id);

		void send_player();
		void send_player_position();
		void send_player_position_look();
		void send_player_look();
	}
}