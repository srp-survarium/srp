void __thiscall survarium::weapon_core::instant_idle_start(survarium::weapon_core *this)
{
  this->m_is_idle = 1;
  if ( (this->m_user->input(this->m_user)->actions_mask & 0x20) == 0 )
    survarium::weapon_core::reset_fire_queue(this);
}
