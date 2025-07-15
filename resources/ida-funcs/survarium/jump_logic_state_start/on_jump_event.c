vostok::animation::callback_return_type_enum __userpurge survarium::jump_logic_state_start::on_jump_event@<eax>(
        survarium::jump_logic_state_start *this@<ecx>,
        float a2@<xmm0>,
        vostok::animation::animation_callback_params *params)
{
  survarium::weapon_user_animations_selector *m_owner; // ecx

  m_owner = this->m_jump_logic->m_owner;
  if ( params->animated_object == m_owner->m_user )
  {
    params->interrupt_animation_player_tick = 0;
    survarium::player_stamina::jump(
      (survarium::player_stamina *)m_owner,
      (survarium::player_stamina *)((char *)&loc_1106F + (unsigned int)this->m_user + 1),
      a2);
    survarium::base_player::jump(this->m_jump_logic->m_user, this->m_jump_logic->m_jump_type);
  }
  return 0;
}
