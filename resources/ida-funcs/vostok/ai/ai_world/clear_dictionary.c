void __thiscall vostok::ai::ai_world::clear_dictionary(vostok::ai::ai_world *this)
{
  vostok::ai::clear_characters((survarium::game_camera *)&this->m_npc_characters);
  vostok::ai::clear_objects_names((survarium::game_camera *)&this->m_energy_weapons);
  vostok::ai::clear_objects_names((survarium::game_camera *)&this->m_light_weapons);
  vostok::ai::clear_objects_names((survarium::game_camera *)&this->m_heavy_weapons);
  vostok::ai::clear_objects_names((survarium::game_camera *)&this->m_sniper_weapons);
  vostok::ai::clear_objects_names((survarium::game_camera *)&this->m_melee_weapons);
  vostok::ai::clear_objects_names((survarium::game_camera *)&this->m_npc_outfits);
  vostok::ai::clear_objects_names((survarium::game_camera *)&this->m_npc_classes);
  vostok::ai::clear_objects_names((survarium::game_camera *)&this->m_npc_groups);
}
