void __thiscall survarium::weapon::set_next_fire_queue_type(survarium::weapon *this)
{
  survarium::game_world_ui *m_game_ui; // edx

  survarium::weapon_core::set_next_fire_queue_type(this);
  m_game_ui = this->m_game_ui;
  if ( m_game_ui )
    survarium::game_world_ui::set_fire_queue_size(m_game_ui, this->m_weapon_fire_queue_types[this->m_fire_queue_type]);
}
