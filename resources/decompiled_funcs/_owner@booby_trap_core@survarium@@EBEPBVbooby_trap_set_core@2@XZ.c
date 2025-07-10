const survarium::booby_trap_set_core *__thiscall survarium::booby_trap_core::owner(survarium::booby_trap_core *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return this->m_owner;
}
