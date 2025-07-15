void __thiscall survarium::weapon_core::instant_chamber_a_round(survarium::weapon_core *this)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v1);
  this->m_aimed = 0;
  survarium::weapon_core::chamber_a_round(this);
  this->on_chamber_a_round(this);
  survarium::recoil_calculator::chamber_a_round(&this->m_recoil_calculator);
}
