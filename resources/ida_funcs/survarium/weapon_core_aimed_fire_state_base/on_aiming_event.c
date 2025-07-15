vostok::animation::callback_return_type_enum __thiscall survarium::weapon_core_aimed_fire_state_base::on_aiming_event(
        survarium::weapon_core_aimed_fire_state_base *this,
        vostok::animation::animation_callback_params *params)
{
  survarium::game_camera *v2; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  if ( params->domain_data == 9 )
    this->m_weapon->instant_aim_start(this->m_weapon);
  else
    this->m_weapon->instant_aim_end(this->m_weapon);
  return 0;
}
