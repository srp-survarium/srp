bool __thiscall survarium::weapon_core::hide_break_pred(survarium::weapon_core *this)
{
  return !this->m_user->m_is_alive;
}
