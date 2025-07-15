void __thiscall survarium::weapon_core::chamber_a_round(survarium::weapon_core *this)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v1);
  survarium::weapon_user_dead_state::finalize(v2);
  --this->m_ammo_in_magazine;
  this->m_is_round_chambered = 1;
}
