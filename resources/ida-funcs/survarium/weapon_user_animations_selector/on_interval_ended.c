vostok::animation::callback_return_type_enum __thiscall survarium::weapon_user_animations_selector::on_interval_ended(
        survarium::weapon_user_animations_selector *this,
        vostok::animation::animation_callback_params *params)
{
  if ( params->animation_user_data == 1 )
    this->m_right_leg_is_supporting = params->animation_interval_id != 0;
  return 0;
}
