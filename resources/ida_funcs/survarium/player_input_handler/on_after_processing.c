void __thiscall survarium::player_input_handler::on_after_processing(
        survarium::player_input_handler *this,
        vostok::input::world *input_world)
{
  bool v2; // zf
  float time_delta; // [esp+8h] [ebp-10h]
  float v4; // [esp+Ch] [ebp-Ch]
  vostok::math::float2 v5; // [esp+10h] [ebp-8h]

  v2 = this->m_input_mode == first_person_mode;
  time_delta = (double)this->m_time_delta_in_ms * 0.001;
  v5.x = this->m_rotation_delta.x * (float)(*(float *)&clear_value / time_delta);
  v5.y = this->m_rotation_delta.y * (float)(*(float *)&clear_value / time_delta);
  v4 = (float)(*(float *)&clear_value / time_delta) * (float)((float)(v5.y - this->m_input.angular_velocity.y) * 2.0);
  this->m_input.angular_acceleration.x = (float)(*(float *)&clear_value / time_delta)
                                       * (float)((float)(v5.x - this->m_input.angular_velocity.x) * 2.0);
  this->m_input.angular_acceleration.y = v4;
  this->m_input.angular_velocity = v5;
  if ( v2 )
    survarium::player_input_handler::process_first_person_mode(
      (survarium::player_input_handler *)LODWORD(v5.y),
      (int)this,
      1);
  else
    survarium::player_input_handler::process_third_person_mode(
      (survarium::player_input_handler *)LODWORD(v5.y),
      (int)this);
}
