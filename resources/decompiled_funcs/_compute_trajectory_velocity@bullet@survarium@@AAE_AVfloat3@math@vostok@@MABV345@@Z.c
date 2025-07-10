vostok::math::float3 *__thiscall survarium::bullet::compute_trajectory_velocity(
        survarium::bullet *this,
        vostok::math::float3 *result,
        float time,
        const vostok::math::float3 *gravity)
{
  vostok::math::float3 *v5; // eax
  vostok::math::float3 v7; // [esp+Ch] [ebp-24h] BYREF
  vostok::math::float3 v8; // [esp+18h] [ebp-18h] BYREF
  const vostok::math::float3 *parabolic_vel; // [esp+24h] [ebp-Ch]
  float fall_down_time; // [esp+28h] [ebp-8h] BYREF
  float parabolic_time; // [esp+2Ch] [ebp-4h]

  parabolic_time = survarium::bullet::get_parabolic_time(this);
  fall_down_time = time - parabolic_time;
  if ( (float)(time - parabolic_time) >= 0.0 )
  {
    survarium::bullet::compute_parabolic_velocity(this, &v8, parabolic_time, gravity);
    parabolic_vel = &v8;
    v5 = vostok::math::operator*(gravity, &v7, &fall_down_time);
    vostok::math::operator+(v5, parabolic_vel, result);
  }
  else
  {
    survarium::bullet::compute_parabolic_velocity(this, result, time, gravity);
  }
  return result;
}
