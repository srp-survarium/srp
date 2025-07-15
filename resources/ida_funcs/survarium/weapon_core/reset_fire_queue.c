void __thiscall survarium::weapon_core::reset_fire_queue(survarium::weapon_core *this)
{
  unsigned __int16 v2; // [esp+6h] [ebp-6h]
  unsigned __int16 v3; // [esp+8h] [ebp-4h]

  if ( survarium::weapon_core::fire_queue_length(this, (int)this) == 255 )
  {
    this->m_bullets_in_queue = this->m_ammo_in_magazine;
    if ( this->m_is_round_chambered )
      ++this->m_bullets_in_queue;
  }
  else
  {
    v2 = this->m_is_round_chambered + this->m_ammo_in_magazine;
    v3 = survarium::weapon_core::fire_queue_length(
           (survarium::weapon_core *)(this->m_is_round_chambered + this->m_ammo_in_magazine),
           (int)this);
    this->m_bullets_in_queue = (v3 < (int)v2 ? v3 - v2 : 0) + v2;
  }
}
