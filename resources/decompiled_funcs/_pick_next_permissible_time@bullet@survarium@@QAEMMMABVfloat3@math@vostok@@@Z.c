double __thiscall survarium::bullet::pick_next_permissible_time(
        survarium::bullet *this,
        float low_time,
        float high_time,
        const vostok::math::float3 *gravity)
{
  bool v5; // al
  float distance; // [esp+1Ch] [ebp-14h]
  float low; // [esp+20h] [ebp-10h] BYREF
  float start_high_time; // [esp+24h] [ebp-Ch]
  float epsilon; // [esp+28h] [ebp-8h]
  float check_time; // [esp+2Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  start_high_time = high_time;
  if ( survarium::bullet::pick_permissible_range(this, &high_time, low_time, high_time, gravity) )
  {
    if ( start_high_time < high_time )
      return start_high_time;
    else
      return high_time;
  }
  else
  {
    low = low_time;
    check_time = high_time;
    epsilon = satisfaction_equality_tolerance;
    while ( 1 )
    {
      v5 = vostok::math::is_similar<float>(&low, &high_time, 0.0000099999997);
      if ( v5 )
        break;
      distance = survarium::bullet::compute_max_error(this, low_time, check_time, gravity);
      if ( epsilon <= distance )
        high_time = check_time;
      else
        low = check_time;
      check_time = (float)(low + high_time) * 0.5;
    }
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v5);
    return low;
  }
}
