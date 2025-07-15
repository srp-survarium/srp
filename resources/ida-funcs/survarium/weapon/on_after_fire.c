void __thiscall survarium::weapon::on_after_fire(survarium::weapon *this)
{
  survarium::game_world_ui *m_game_ui; // edx
  survarium::game_world_ui *v3; // edx

  m_game_ui = this->m_game_ui;
  if ( m_game_ui )
    survarium::game_world_ui::set_ammo_in_magazine(m_game_ui, this->m_ammo_in_magazine);
  survarium::weapon::play_weapon_fire_pfx(this, (int)this);
  v3 = this->m_game_ui;
  if ( v3 )
  {
    if ( this->m_inventory )
      survarium::game_world_ui::set_ammo_in_magazine(
        v3,
        (unsigned __int16)(this->m_ammo_in_magazine + this->m_is_round_chambered));
  }
}
