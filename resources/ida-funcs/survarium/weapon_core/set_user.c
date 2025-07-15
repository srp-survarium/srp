void __thiscall survarium::weapon_core::set_user(survarium::weapon_core *this, survarium::base_player *user)
{
  survarium::hit_initiator *v3; // edx
  survarium::hit_receiver *v4; // edx
  const survarium::character_recoil_params *p_m_recoil_params; // edx
  vostok::ai::fsm_state *i; // ecx

  this->m_user = user;
  if ( user )
    v3 = &user->survarium::hit_initiator;
  else
    v3 = 0;
  this->m_initiator_holder = v3;
  if ( user )
    v4 = &user->survarium::hit_receiver;
  else
    v4 = 0;
  this->m_receiver_holder = v4;
  if ( user )
  {
    this->m_dispersion_calculator.m_character_params = &user->m_dispersion_params;
    this->m_dispersion_calculator.m_character_skill_factor_params = &user->m_dispersion_skill_influence;
  }
  else
  {
    this->m_dispersion_calculator.m_character_params = 0;
    this->m_dispersion_calculator.m_character_skill_factor_params = 0;
  }
  if ( user )
    p_m_recoil_params = &user->m_recoil_params;
  else
    p_m_recoil_params = 0;
  this->m_recoil_calculator.m_character_calculator.m_params = p_m_recoil_params;
  this->m_breath_vibration_calculator.m_user = user;
  for ( i = this->m_breath_vibration_calculator.m_logic.m_states.m_first; i; i = i->next )
    i[1].next = (vostok::ai::fsm_state *)this->m_breath_vibration_calculator.m_user;
  this->m_portable_interactive_object->set_user(this->m_portable_interactive_object, this->m_user);
}
