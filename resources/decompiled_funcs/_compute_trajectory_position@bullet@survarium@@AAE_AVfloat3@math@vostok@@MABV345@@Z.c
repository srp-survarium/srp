vostok::math::float3 *__thiscall survarium::bullet::compute_trajectory_position(
        survarium::bullet *this,
        vostok::math::float3 *result,
        float time,
        const vostok::math::float3 *gravity)
{
  vostok::math::float3 *v5; // esi
  vostok::math::float3 *v6; // eax
  vostok::math::float3 *v7; // eax
  vostok::math::float3 v9; // [esp+14h] [ebp-50h] BYREF
  vostok::math::float3 v10; // [esp+20h] [ebp-44h] BYREF
  vostok::math::float3 v11; // [esp+2Ch] [ebp-38h] BYREF
  float value; // [esp+38h] [ebp-2Ch] BYREF
  const vostok::math::float3 *parabolic_pos; // [esp+3Ch] [ebp-28h]
  vostok::math::float3 v14; // [esp+40h] [ebp-24h] BYREF
  const vostok::math::float3 *parabolic_vel; // [esp+4Ch] [ebp-18h]
  float fall_down_time; // [esp+50h] [ebp-14h] BYREF
  vostok::math::float3 v17; // [esp+54h] [ebp-10h] BYREF
  float parabolic_time; // [esp+60h] [ebp-4h]

  parabolic_time = survarium::bullet::get_parabolic_time(this);
  fall_down_time = time - parabolic_time;
  if ( (float)(time - parabolic_time) >= 0.0 )
  {
    survarium::bullet::compute_parabolic_position(this, &v17, parabolic_time, gravity);
    parabolic_pos = &v17;
    survarium::bullet::compute_parabolic_velocity(this, &v14, parabolic_time, gravity);
    parabolic_vel = &v14;
    value = vostok::math::sqr<float>(&fall_down_time) * 0.5;
    v5 = vostok::math::operator*(gravity, &v11, &value);
    v6 = vostok::math::operator*(parabolic_vel, &v10, &fall_down_time);
    v7 = vostok::math::operator+(v6, parabolic_pos, &v9);
    vostok::math::operator+(v5, v7, result);
  }
  else
  {
    survarium::bullet::compute_parabolic_position(this, result, time, gravity);
  }
  return result;
}
