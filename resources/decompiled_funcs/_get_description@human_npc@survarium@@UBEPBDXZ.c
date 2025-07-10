const char *__thiscall survarium::human_npc::get_description(survarium::human_npc *this)
{
  return *(const char **)&this->m_game_attributes.name.m_buffer[20];
}
