int __thiscall survarium::weapon_core::maximum_ammo_in_weapon(survarium::weapon_core *this)
{
  bool v2; // [esp+3h] [ebp-9h]

  v2 = this->m_is_there_chamber_a_round_state && !this->m_chamber_a_round_on_reload;
  return v2 + this->m_magazine_capacity;
}
