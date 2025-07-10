void __thiscall survarium::weapon_core::instant_aim_end(survarium::weapon_core *this)
{
  this->m_aimed = 0;
  this->m_aiming_state_transition = 1;
}
