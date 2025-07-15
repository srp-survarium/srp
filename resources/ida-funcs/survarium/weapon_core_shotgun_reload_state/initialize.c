void __thiscall survarium::weapon_core_shotgun_reload_state::initialize(
        survarium::weapon_core_shotgun_reload_state *this)
{
  vostok::ai::fsm::set_initial_state(this->m_logic, this->m_logic->m_states.m_first, ignore_current_state);
  this->m_animation_has_been_ended = 0;
}
