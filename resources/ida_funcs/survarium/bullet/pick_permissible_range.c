char __thiscall survarium::bullet::pick_permissible_range(
        survarium::bullet *this,
        float *result,
        float low_time,
        float high_time,
        const vostok::math::float3 *gravity)
{
  double v6; // st7
  float parabolic_time; // [esp+18h] [ebp-4h] BYREF

  parabolic_time = survarium::bullet::get_parabolic_time(this);
  if ( low_time <= parabolic_time )
  {
    if ( parabolic_time <= high_time )
    {
      if ( vostok::math::is_similar<float>(&parabolic_time, &low_time, 0.0000099999997) )
        v6 = survarium::bullet::get_check_time_in_vacuum(this, parabolic_time, high_time, gravity);
      else
        v6 = survarium::bullet::get_check_time(this, low_time, parabolic_time, gravity);
      *result = v6;
      return 0;
    }
    else
    {
      *result = survarium::bullet::get_check_time(this, low_time, high_time, gravity);
      return 0;
    }
  }
  else
  {
    *result = survarium::bullet::get_check_time_in_vacuum(this, low_time, high_time, gravity);
    return 1;
  }
}
