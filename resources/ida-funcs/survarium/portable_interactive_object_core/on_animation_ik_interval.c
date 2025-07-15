vostok::animation::callback_return_type_enum __thiscall survarium::portable_interactive_object_core::on_animation_ik_interval(
        survarium::portable_interactive_object_core *this,
        vostok::animation::animation_callback_params *params)
{
  survarium::base_player *animated_object; // eax
  const char *channel_id; // ebx
  bool v5; // zf
  vostok::animation::legs_ik_solver *p_m_legs_ik_solver; // eax
  vostok::animation::legs_ik_solver::leg_params *p_m_left_leg_params; // esi
  vostok::animation::legs_ik_solver *v8; // eax
  vostok::animation::legs_ik_solver::leg_params *p_m_right_leg_params; // ecx

  animated_object = (survarium::base_player *)params->animated_object;
  params->interrupt_animation_player_tick = 0;
  if ( animated_object == this->m_user )
  {
    channel_id = params->channel_id;
    if ( !vostok::strings::compare(channel_id, "Left heel") )
    {
      v5 = params->domain_data == 0xFF;
      p_m_legs_ik_solver = &this->m_legs_ik_solver;
      p_m_left_leg_params = &this->m_legs_ik_solver.m_left_leg_params;
LABEL_8:
      vostok::animation::legs_ik_solver::set_heel_on_ground(p_m_legs_ik_solver, p_m_left_leg_params, !v5);
      return 0;
    }
    if ( vostok::strings::compare(channel_id, "Left toe") )
    {
      if ( !vostok::strings::compare(channel_id, "Right heel") )
      {
        v5 = params->domain_data == 0xFF;
        p_m_legs_ik_solver = &this->m_legs_ik_solver;
        p_m_left_leg_params = &this->m_legs_ik_solver.m_right_leg_params;
        goto LABEL_8;
      }
      if ( vostok::strings::compare(channel_id, "Right toe") )
        return 0;
      v8 = &this->m_legs_ik_solver;
      p_m_right_leg_params = &this->m_legs_ik_solver.m_right_leg_params;
    }
    else
    {
      v8 = &this->m_legs_ik_solver;
      p_m_right_leg_params = &this->m_legs_ik_solver.m_left_leg_params;
    }
    vostok::animation::legs_ik_solver::set_toe_on_ground(p_m_right_leg_params, params->domain_data != 0xFF, v8);
  }
  return 0;
}
