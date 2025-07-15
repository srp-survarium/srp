void __thiscall survarium::weapon::on_chamber_a_round(survarium::weapon *this)
{
  survarium::game_world_ui *m_game_ui; // edx

  m_game_ui = this->m_game_ui;
  if ( m_game_ui )
  {
    if ( this->m_inventory )
      survarium::game_world_ui::set_ammo_in_magazine(
        m_game_ui,
        (unsigned __int16)(this->m_ammo_in_magazine + this->m_is_round_chambered));
  }
}
