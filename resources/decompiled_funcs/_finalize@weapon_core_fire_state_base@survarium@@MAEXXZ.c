void __thiscall survarium::weapon_core_fire_state_base::finalize(survarium::weapon_core_fire_state_base *this)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_core_animation_end_aware_state::finalize(this);
  survarium::weapon_core::remove_animation_callback(this->m_weapon, "shoot", this);
  survarium::weapon_user_dead_state::finalize(v1);
  *this->m_is_firing_ptr = 0;
}
