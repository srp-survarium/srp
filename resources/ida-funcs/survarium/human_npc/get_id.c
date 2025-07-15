unsigned int __thiscall survarium::human_npc::get_id(survarium::human_npc *this)
{
  return LODWORD(this->m_game_attributes.initial_luminosity);
}
