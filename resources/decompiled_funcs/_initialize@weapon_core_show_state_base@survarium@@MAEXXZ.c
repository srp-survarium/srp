void __thiscall survarium::weapon_core_show_state_base::initialize(survarium::weapon_core_show_state_base *this)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_core_animation_end_aware_state::initialize(this);
  survarium::weapon_user_dead_state::finalize(v1);
  survarium::weapon_core::instant_toggle_start(this->m_weapon);
}
