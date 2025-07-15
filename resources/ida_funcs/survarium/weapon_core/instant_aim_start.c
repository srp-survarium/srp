void __thiscall survarium::weapon_core::instant_aim_start(survarium::weapon_core *this)
{
  if ( !this->m_is_firing && (this->m_user->input(this->m_user)->actions_mask & 0x20) == 0 )
    survarium::weapon_core::reset_fire_queue(this);
  this->m_aimed = 1;
  this->m_aiming_state_transition = 1;
}
