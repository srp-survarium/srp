double __thiscall survarium::human_npc::get_velocity(survarium::human_npc *this)
{
  return *(float *)&this->m_game_attributes.description.m_buffer[28];
}
