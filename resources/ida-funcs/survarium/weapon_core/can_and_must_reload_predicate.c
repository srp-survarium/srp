bool __thiscall survarium::weapon_core::can_and_must_reload_predicate(survarium::weapon_core *this)
{
  return survarium::weapon_core::ready_to_reload(this) && !this->m_ammo_in_magazine && !this->m_is_round_chambered;
}
