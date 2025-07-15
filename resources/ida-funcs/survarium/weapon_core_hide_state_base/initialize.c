void __thiscall survarium::weapon_core_hide_state_base::initialize(survarium::weapon_core_hide_state_base *this)
{
  survarium::weapon_core_animation_end_aware_state::initialize(this);
  this->m_is_ready_to_be_deactivated = 0;
}
