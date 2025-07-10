void __thiscall survarium::weapon::set_next_ammo_type(survarium::weapon *this)
{
  survarium::profile_slot_enum m_ammo_slot; // edi
  survarium::profile_slot_enum ammo_slot; // eax

  survarium::weapon_core::set_next_ammo_type(this);
  if ( this->m_game_ui )
  {
    m_ammo_slot = this->m_ammo_slot;
    ammo_slot = survarium::weapon_core::get_ammo_slot(this, first_ammo);
    survarium::game_world_ui::set_ammo_type(this->m_game_ui, (m_ammo_slot != ammo_slot) + 1);
  }
}
