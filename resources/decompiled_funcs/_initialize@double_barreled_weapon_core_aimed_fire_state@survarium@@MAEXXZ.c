void __thiscall survarium::double_barreled_weapon_core_aimed_fire_state::initialize(
        survarium::double_barreled_weapon_core_aimed_fire_state *this)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_core_aimed_fire_state_base::initialize(this);
  survarium::weapon_user_dead_state::finalize(v1);
  this->m_weapon_animation_index = survarium::weapon_core::ammo_in_magazine(
                                     (survarium::weapon_core *)this,
                                     (int)this->m_weapon) != 2;
}
