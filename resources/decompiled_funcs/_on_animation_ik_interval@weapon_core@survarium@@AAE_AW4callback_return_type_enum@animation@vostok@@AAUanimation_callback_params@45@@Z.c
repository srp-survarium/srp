vostok::animation::callback_return_type_enum __thiscall survarium::weapon_core::on_animation_ik_interval(
        survarium::weapon_core *this,
        vostok::animation::animation_callback_params *params)
{
  params->interrupt_animation_player_tick = 0;
  if ( params->animated_object == this->m_user )
  {
    if ( vostok::strings::equal(params->channel_id, "Left heel") )
    {
      survarium::legs_ik_processor::set_left_heel_on_ground(
        &this->m_legs_ik_processor,
        (unsigned __int8)params->domain_data != 255);
    }
    else if ( vostok::strings::equal(params->channel_id, "Left toe") )
    {
      survarium::legs_ik_processor::set_left_toe_on_ground(
        &this->m_legs_ik_processor,
        (unsigned __int8)params->domain_data != 255);
    }
    else if ( vostok::strings::equal(params->channel_id, "Right heel") )
    {
      survarium::legs_ik_processor::set_right_heel_on_ground(
        &this->m_legs_ik_processor,
        (unsigned __int8)params->domain_data != 255);
    }
    else if ( vostok::strings::equal(params->channel_id, "Right toe") )
    {
      survarium::legs_ik_processor::set_right_toe_on_ground(
        &this->m_legs_ik_processor,
        (unsigned __int8)params->domain_data != 255);
    }
  }
  return 0;
}
