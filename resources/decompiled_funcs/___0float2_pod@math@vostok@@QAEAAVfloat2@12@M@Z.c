vostok::math::float2 *__thiscall vostok::math::float2_pod::operator/=(vostok::math::float2_pod *this, float value)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->x = this->x / value;
  this->y = this->y / value;
  return (vostok::math::float2 *)this;
}
