#include "Protocol.h"

namespace Minecraft::Protocol {
	int spawn_object_handler(PacketIn* p) { std::cout << "WARNING SPAWN_OBJECT TRIGGERED" << std::endl; return 0; }
	int spawn_experience_orb_handler(PacketIn* p) { std::cout << "WARNING SPAWN_EXPERIENCE_ORB TRIGGERED" << std::endl; return 0; }
	int spawn_global_entity_handler(PacketIn* p) { std::cout << "WARNING SPAWN_GLOBAL_ENTITY TRIGGERED" << std::endl; return 0; }
	int spawn_mob_handler(PacketIn* p) { std::cout << "WARNING SPAWN_MOB TRIGGERED" << std::endl; return 0; }
	int spawn_painting_handler(PacketIn* p) { std::cout << "WARNING SPAWN_PAINTING TRIGGERED" << std::endl; return 0; }
	int spawn_player_handler(PacketIn* p) { std::cout << "WARNING SPAWN_PLAYER TRIGGERED" << std::endl; return 0; }
	int animation_handler(PacketIn* p) { std::cout << "WARNING ANIMATION TRIGGERED" << std::endl; return 0; }
	int statistics_handler(PacketIn* p) { std::cout << "WARNING STATISTICS TRIGGERED" << std::endl; return 0; }
	int block_break_animation_handler(PacketIn* p) { std::cout << "WARNING BLOCK_BREAK_ANIMATION TRIGGERED" << std::endl; return 0; }
	int update_block_entity_handler(PacketIn* p) { std::cout << "WARNING UPDATE_BLOCK_ENTITY TRIGGERED" << std::endl; return 0; }
	int block_action_handler(PacketIn* p) { std::cout << "WARNING BLOCK_ACTION TRIGGERED" << std::endl; return 0; }
	int block_change_handler(PacketIn* p) { std::cout << "WARNING BLOCK_CHANGE TRIGGERED" << std::endl; return 0; }
	int boss_bar_handler(PacketIn* p) { std::cout << "WARNING BOSS_BAR TRIGGERED" << std::endl; return 0; }
	
	int server_difficulty_handler(PacketIn* p) { 
		
		uint8_t difficulty;
		p->buffer->ReadBEUInt8(difficulty);

		std::cout << "DIFFICULTY: " << difficulty << std::endl;

		return 0; 
	}
	
	int chat_message_handler(PacketIn* p) { std::cout << "WARNING CHAT_MESSAGE TRIGGERED" << std::endl; return 0; }
	int multi_block_change_handler(PacketIn* p) { std::cout << "WARNING MULTI_BLOCK_CHANGE TRIGGERED" << std::endl; return 0; }
	int tab_complete_handler(PacketIn * p) { std::cout << "WARNING TAB-COMPLETE TRIGGERED" << std::endl; return 0; }
	int declare_commands_handler(PacketIn* p) { std::cout << "WARNING DECLARE_COMMANDS TRIGGERED" << std::endl; return 0; }
	int confirm_transaction_handler(PacketIn* p) { std::cout << "WARNING CONFIRM_TRANSACTION TRIGGERED" << std::endl; return 0; }
	int close_window_handler(PacketIn* p) { std::cout << "WARNING CLOSE_WINDOW TRIGGERED" << std::endl; return 0; }
	int open_window_handler(PacketIn* p) { std::cout << "WARNING OPEN_WINDOW TRIGGERED" << std::endl; return 0; }
	int window_items_handler(PacketIn* p) { std::cout << "WARNING WINDOW_ITEMS TRIGGERED" << std::endl; return 0; }
	int window_property_handler(PacketIn* p) { std::cout << "WARNING WINDOW_PROPERTY TRIGGERED" << std::endl; return 0; }
	int set_slot_handler(PacketIn* p) { std::cout << "WARNING SET_SLOT TRIGGERED" << std::endl; return 0; }
	int set_cooldown_handler(PacketIn* p) { std::cout << "WARNING SET_COOLDOWN TRIGGERED" << std::endl; return 0; }
	
	int plugin_message_handler(PacketIn* p) { 
		//TODO: FINISH PLUGINS
		//std::cout << "WARNING PLUGIN_MESSAGE TRIGGERED" << std::endl; 

		std::string channel;
		p->buffer->ReadVarUTF8String(channel);
		
		if(channel == "minecraft:brand"){
			PacketsOut::send_plugin_message(channel, "raven-recrafted");
		}else{
			std::cout << "UNKNOWN IDENTIFIER: " << channel << std::endl;
		}


		return 0; 
	}
	
	int named_sound_effect_handler(PacketIn* p) { std::cout << "WARNING NAMED_SOUND_EFFECT TRIGGERED" << std::endl; return 0; }
	int disconnect_handler(PacketIn* p) { std::cout << "WARNING DISCONNECT TRIGGERED" << std::endl; return 0; }
	int entity_status_handler(PacketIn* p) { std::cout << "WARNING ENTITY_STATUS TRIGGERED" << std::endl; return 0; }
	int nbt_query_response_handler(PacketIn* p) { std::cout << "WARNING NBT_QUERY_RESPONSE TRIGGERED" << std::endl; return 0; }
	int explosion_handler(PacketIn* p) { std::cout << "WARNING EXPLOSION TRIGGERED" << std::endl; return 0; }
	int unload_chunk_handler(PacketIn* p) { std::cout << "WARNING UNLOAD_CHUNK TRIGGERED" << std::endl; return 0; }
	int change_game_state_handler(PacketIn* p) { std::cout << "WARNING CHANGE_GAME_STATE TRIGGERED" << std::endl; return 0; }
	
	int keep_alive_handler(PacketIn* p) { 

		uint64_t longData;
		p->buffer->ReadBEUInt64(longData);

		PacketsOut::send_keep_alive(longData);

		return 0; 
	}
	
	int chunk_data_handler(PacketIn* p) { std::cout << "WARNING CHUNK_DATA TRIGGERED" << std::endl; return 0; }
	int effect_handler(PacketIn* p) { std::cout << "WARNING EFFECT TRIGGERED" << std::endl; return 0; }
	int particle_handler(PacketIn* p) { std::cout << "WARNING PARTICLE TRIGGERED" << std::endl; return 0; }
	
	int join_game_handler(PacketIn* p) { 
		int eid = 0;
		uint8_t gm = 0;
		int dimension = 0;
		uint8_t difficulty = 0;
		uint8_t max_players = 0;
		std::string levelType = "";
		bool debugInfo;

		p->buffer->ReadBEInt32(eid);
		p->buffer->ReadBEUInt8(gm);
		p->buffer->ReadBEInt32(dimension);
		p->buffer->ReadBEUInt8(difficulty);
		p->buffer->ReadBEUInt8(max_players);
		p->buffer->ReadVarUTF8String(levelType);
		p->buffer->ReadBool(debugInfo);

		std::cout << "EID: " << eid << std::endl;
		std::cout << "GM: " << (int)gm << std::endl;
		std::cout << "DIM: " << dimension << std::endl;
		std::cout << "DIF: " << (int)difficulty << std::endl;
		std::cout << "MAX: " << (int)max_players << std::endl;
		std::cout << "LEV: " << levelType << std::endl;
		std::cout << "DEB: " << debugInfo << std::endl;

		//Default settings
		PacketsOut::send_client_settings("en_us", 2, 0, false, 0b01111111, 1);
		
		return 0; 
	}
	
	int map_data_handler(PacketIn* p) { std::cout << "WARNING MAP_DATA TRIGGERED" << std::endl; return 0; }
	int entity_handler(PacketIn* p) { std::cout << "WARNING ENTITY TRIGGERED" << std::endl; return 0; }
	int entity_relative_move_handler(PacketIn* p) { std::cout << "WARNING ENTITY_RELATIVE_MOVE TRIGGERED" << std::endl; return 0; }
	int entity_look_and_relative_move_handler(PacketIn* p) { std::cout << "WARNING ENTITY_LOOK_AND_RELATIVE_MOVE TRIGGERED" << std::endl; return 0; }
	int entity_look_handler(PacketIn* p) { std::cout << "WARNING ENTITY_LOOK TRIGGERED" << std::endl; return 0; }
	int vehicle_move_handler(PacketIn* p) { std::cout << "WARNING VEHICLE_MOVE TRIGGERED" << std::endl; return 0; }
	int open_sign_editor_handler(PacketIn* p) { std::cout << "WARNING OPEN_SIGN_EDITOR TRIGGERED" << std::endl; return 0; }
	int craft_recipe_response_handler(PacketIn* p) { std::cout << "WARNING CRAFT_RECIPE_RESPONSE TRIGGERED" << std::endl; return 0; }
	
	int player_abilities_handler(PacketIn* p) { 

		uint8_t flags;
		float flySpeed;
		float fovMod;

		p->buffer->ReadBEUInt8(flags);
		p->buffer->ReadBEFloat(flySpeed);
		p->buffer->ReadBEFloat(fovMod);

		std::cout << "FLAGS: " << std::hex << flags << std::dec << std::endl;
		std::cout << "FLY SPEED: " << flySpeed << std::endl;
		std::cout << "FOV MOD: " << fovMod << std::endl;
		
		return 0; 
	}
	
	int combat_event_handler(PacketIn* p) { std::cout << "WARNING COMBAT_EVENT TRIGGERED" << std::endl; return 0; }
	int player_info_handler(PacketIn* p) { std::cout << "WARNING PLAYER_INFO TRIGGERED" << std::endl; return 0; }
	int face_player_handler(PacketIn* p) { std::cout << "WARNING FACE_PLAYER TRIGGERED" << std::endl; return 0; }
	int player_position_and_look_handler(PacketIn* p) { std::cout << "WARNING PLAYER_POSITION_AND_LOOK TRIGGERED" << std::endl; return 0; }
	int use_bed_handler(PacketIn* p) { std::cout << "WARNING USE_BED TRIGGERED" << std::endl; return 0; }
	int unlock_recipes_handler(PacketIn* p) { std::cout << "WARNING UNLOCK_RECIPES TRIGGERED" << std::endl; return 0; }
	int destroy_entities_handler(PacketIn* p) { std::cout << "WARNING DESTROY_ENTITIES TRIGGERED" << std::endl; return 0; }
	int remove_entity_effect_handler(PacketIn* p) { std::cout << "WARNING REMOVE_ENTITY_EFFECT TRIGGERED" << std::endl; return 0; }
	int resource_pack_send_handler(PacketIn* p) { std::cout << "WARNING RESOURCE_PACK_SEND TRIGGERED" << std::endl; return 0; }
	int respawn_handler(PacketIn* p) { std::cout << "WARNING RESPAWN TRIGGERED" << std::endl; return 0; }
	int entity_head_look_handler(PacketIn* p) { std::cout << "WARNING ENTITY_HEAD_LOOK TRIGGERED" << std::endl; return 0; }
	int select_advancement_tab_handler(PacketIn* p) { std::cout << "WARNING SELECT_ADVANCEMENT_TAB TRIGGERED" << std::endl; return 0; }
	int world_border_handler(PacketIn* p) { std::cout << "WARNING WORLD_BORDER TRIGGERED" << std::endl; return 0; }
	int camera_handler(PacketIn* p) { std::cout << "WARNING CAMERA TRIGGERED" << std::endl; return 0; }
	
	int held_item_change_handler(PacketIn* p) { 

		uint8_t slotID;

		p->buffer->ReadBEUInt8(slotID);

		std::cout << "SLOT SET: " << (int)slotID << std::endl;
		
		return 0; 
	}
	
	int display_scoreboard_handler(PacketIn* p) { std::cout << "WARNING DISPLAY_SCOREBOARD TRIGGERED" << std::endl; return 0; }
	int entity_metadata_handler(PacketIn* p) { std::cout << "WARNING ENTITY_METADATA TRIGGERED" << std::endl; return 0; }
	int attach_entity_handler(PacketIn* p) { std::cout << "WARNING ATTACH_ENTITY TRIGGERED" << std::endl; return 0; }
	int entity_velocity_handler(PacketIn* p) { std::cout << "WARNING ENTITY_VELOCITY TRIGGERED" << std::endl; return 0; }
	int entity_equipment_handler(PacketIn* p) { std::cout << "WARNING ENTITY_EQUIPMENT TRIGGERED" << std::endl; return 0; }
	int set_experience_handler(PacketIn* p) { std::cout << "WARNING SET_EXPERIENCE TRIGGERED" << std::endl; return 0; }
	int update_health_handler(PacketIn* p) { std::cout << "WARNING UPDATE_HEALTH TRIGGERED" << std::endl; return 0; }
	int scoreboard_objective_handler(PacketIn* p) { std::cout << "WARNING SCOREBOARD_OBJECTIVE TRIGGERED" << std::endl; return 0; }
	int set_passengers_handler(PacketIn* p) { std::cout << "WARNING SET_PASSENGERS TRIGGERED" << std::endl; return 0; }
	int teams_handler(PacketIn* p) { std::cout << "WARNING TEAMS TRIGGERED" << std::endl; return 0; }
	int update_score_handler(PacketIn* p) { std::cout << "WARNING UPDATE_SCORE TRIGGERED" << std::endl; return 0; }
	int spawn_position_handler(PacketIn* p) { std::cout << "WARNING SPAWN_POSITION TRIGGERED" << std::endl; return 0; }
	int time_update_handler(PacketIn* p) { std::cout << "WARNING TIME_UPDATE TRIGGERED" << std::endl; return 0; }
	int title_handler(PacketIn* p) { std::cout << "WARNING TITLE TRIGGERED" << std::endl; return 0; }
	int stop_sound_handler(PacketIn* p) { std::cout << "WARNING STOP_SOUND TRIGGERED" << std::endl; return 0; }
	int sound_effect_handler(PacketIn* p) { std::cout << "WARNING SOUND_EFFECT TRIGGERED" << std::endl; return 0; }
	int player_list_header_and_footer_handler(PacketIn* p) { std::cout << "WARNING PLAYER_LIST_HEADER_AND_FOOTER TRIGGERED" << std::endl; return 0; }
	int collect_item_handler(PacketIn* p) { std::cout << "WARNING COLLECT_ITEM TRIGGERED" << std::endl; return 0; }
	int entity_teleport_handler(PacketIn* p) { std::cout << "WARNING ENTITY_TELEPORT TRIGGERED" << std::endl; return 0; }
	int advancements_handler(PacketIn* p) { std::cout << "WARNING ADVANCEMENTS TRIGGERED" << std::endl; return 0; }
	int entity_properties_handler(PacketIn* p) { std::cout << "WARNING ENTITY_PROPERTIES TRIGGERED" << std::endl; return 0; }
	int entity_effect_handler(PacketIn* p) { std::cout << "WARNING ENTITY_EFFECT TRIGGERED" << std::endl; return 0; }
	int declare_recipes_handler(PacketIn* p) { std::cout << "WARNING DECLARE_RECIPES TRIGGERED" << std::endl; return 0; }
	int tags_handler(PacketIn* p) { std::cout << "WARNING TAGS TRIGGERED" << std::endl; return 0; }


	void PacketsOut::send_plugin_message(std::string identifier, std::string data)
	{
		PacketOut* p = new PacketOut(64);
		p->ID = 0x0A;
		p->buffer->WriteVarUTF8String(identifier);
		p->buffer->WriteVarUTF8String(data);

		g_NetworkDriver.AddPacket(p);
		g_NetworkDriver.SendPackets(p);
	}
	void PacketsOut::send_client_settings(std::string locale, uint8_t distance, uint8_t c_mode, bool colors, uint8_t bitmask, uint8_t hand)
	{
		PacketOut* p = new PacketOut(64);
		p->ID = 0x04;
		p->buffer->WriteVarUTF8String(locale);
		p->buffer->WriteBEUInt8(distance);
		p->buffer->WriteBEUInt8(c_mode);
		p->buffer->WriteBool(colors);
		p->buffer->WriteBEUInt8(bitmask);
		p->buffer->WriteBEUInt8(hand);

		g_NetworkDriver.AddPacket(p);
		g_NetworkDriver.SendPackets(p);
	}
	void PacketsOut::send_keep_alive(uint64_t longData)
	{
		PacketOut* p = new PacketOut(12);
		p->ID = 0x0E;
		p->buffer->WriteBEUInt64(longData);

		g_NetworkDriver.AddPacket(p);
		g_NetworkDriver.SendPackets(p);
	}
}

