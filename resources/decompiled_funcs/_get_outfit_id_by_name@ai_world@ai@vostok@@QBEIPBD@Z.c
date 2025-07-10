void __thiscall vostok::ai::ai_world::get_outfit_id_by_name(vostok::ai::ai_world *this, const char *outfit_name)
{
  vostok::ai::get_id_by_name((survarium::game_camera *)&this->m_npc_outfits, outfit_name);
}
