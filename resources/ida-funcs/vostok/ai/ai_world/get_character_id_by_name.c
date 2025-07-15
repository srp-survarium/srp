unsigned int __thiscall vostok::ai::ai_world::get_character_id_by_name(
        vostok::ai::ai_world *this,
        const char *character_name)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  unsigned int i; // [esp+14h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    v2 = (survarium::game_camera *)(this->m_npc_characters.m_end - this->m_npc_characters.m_begin);
    if ( i >= (unsigned int)v2 )
      break;
    survarium::weapon_user_dead_state::finalize(v2);
    if ( vostok::strings::equal(this->m_npc_characters.m_begin[i].first, character_name) )
    {
      survarium::weapon_user_dead_state::finalize(v3);
      return this->m_npc_characters.m_begin[i].second;
    }
  }
  return -1;
}
