vostok::animation::callback_return_type_enum __userpurge survarium::weapon_core_fire_state_base::on_shot_event@<eax>(
        survarium::weapon_core_fire_state_base *this@<ecx>,
        float a2@<xmm0>,
        vostok::animation::animation_callback_params *params)
{
  survarium::weapon_core *m_weapon; // esi
  survarium::weapon_core *v5; // eax
  bool v6; // cl

  m_weapon = this->m_weapon;
  if ( m_weapon->m_bullets_in_queue )
  {
    survarium::weapon_core::instant_fire(
      (survarium::weapon_core *)this,
      (int)m_weapon,
      a2,
      (const survarium::weapon_core *)params->callback_time_in_ms);
    v5 = this->m_weapon;
    v6 = v5->m_weapon_fire_queue_types[v5->m_fire_queue_type] != 0xFF && v5->m_bullets_in_queue;
    this->m_keep_shooting = v6;
    params->interrupt_animation_player_tick = v5->m_bullets_in_queue == 0;
  }
  return 0;
}
