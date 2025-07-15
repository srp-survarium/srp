bool __thiscall survarium::player_input::is_empty(survarium::player_input *this)
{
  return vostok::math::is_zero<float>(&this->angular_velocity.x, &epsilon_5_112)
      && vostok::math::is_zero<float>(&this->angular_velocity.y, &epsilon_5_112)
      && vostok::math::is_zero<float>(&this->angular_acceleration.x, &epsilon_5_112)
      && vostok::math::is_zero<float>(&this->angular_acceleration.y, &epsilon_5_112)
      && !this->actions_mask;
}
