stlp_std::pair<char *,unsigned int> *__thiscall vostok::ai::ai_world::get_character_attributes_by_index(
        vostok::ai::ai_world *this,
        stlp_std::pair<char *,unsigned int> *result,
        unsigned int index)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  *result = this->m_npc_characters.m_begin[index];
  return result;
}
