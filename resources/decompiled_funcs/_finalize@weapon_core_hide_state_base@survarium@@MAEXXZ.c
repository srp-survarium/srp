void __thiscall survarium::weapon_core_hide_state_base::finalize(survarium::weapon_core_hide_state_base *this)
{
  survarium::weapon_core_animation_end_aware_state::finalize(this);
  survarium::weapon_core::instant_toggle_end(this->m_weapon);
}
