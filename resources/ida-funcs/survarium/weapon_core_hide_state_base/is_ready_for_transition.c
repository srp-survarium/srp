bool __thiscall survarium::weapon_core_hide_state_base::is_ready_for_transition(
        survarium::weapon_core_show_state_base *this)
{
  return this->m_animation_has_been_ended;
}
