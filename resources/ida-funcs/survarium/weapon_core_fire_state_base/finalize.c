void __thiscall survarium::weapon_core_fire_state_base::finalize(survarium::weapon_core_fire_state_base *this)
{
  survarium::base_player *v2; // ecx

  survarium::weapon_core_animation_end_aware_state::finalize(this);
  survarium::base_player::unsubscribe_animation_player(v2, (int)this->m_weapon->m_user, "shoot", (int)this);
}
