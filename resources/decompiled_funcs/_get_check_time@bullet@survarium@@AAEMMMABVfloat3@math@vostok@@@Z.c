double __thiscall survarium::bullet::get_check_time(
        survarium::bullet *this,
        float start_low,
        float high,
        const vostok::math::float3 *gravity)
{
  bool v4; // al
  vostok::math::float3 *v5; // eax
  vostok::math::float3_pod *v6; // ecx
  vostok::math::float3 *v7; // eax
  vostok::math::float3_pod *v8; // ecx
  float v10; // [esp+8h] [ebp-64h]
  vostok::math::float3 v12; // [esp+20h] [ebp-4Ch] BYREF
  vostok::math::float3 v13; // [esp+2Ch] [ebp-40h] BYREF
  vostok::math::float3 intermediate; // [esp+38h] [ebp-34h] BYREF
  vostok::math::float3 target; // [esp+44h] [ebp-28h] BYREF
  float distance; // [esp+50h] [ebp-1Ch]
  float max_test_distance; // [esp+54h] [ebp-18h]
  float low; // [esp+58h] [ebp-14h] BYREF
  vostok::math::float3 start; // [esp+5Ch] [ebp-10h] BYREF
  float check_time; // [esp+68h] [ebp-4h]

  max_test_distance = this->m_max_distance - this->m_flown_distance;
  survarium::bullet::compute_trajectory_position(this, &start, start_low, gravity);
  low = start_low;
  for ( check_time = high; ; check_time = (float)(low + high) * 0.5 )
  {
    v4 = vostok::math::is_similar<float>(&low, &high, 0.0000099999997);
    if ( v4 )
      break;
    survarium::bullet::compute_trajectory_position(this, &intermediate, (float)(check_time + start_low) * 0.5, gravity);
    survarium::bullet::compute_trajectory_position(this, &target, check_time, gravity);
    v5 = vostok::math::operator-(&start, &intermediate, &v13);
    v10 = vostok::math::float3_pod::length(v6, &v5->x);
    v7 = vostok::math::operator-(&target, &intermediate, &v12);
    distance = vostok::math::float3_pod::length(v8, &v7->x) + v10;
    if ( max_test_distance <= distance )
      high = check_time;
    else
      low = check_time;
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v4);
  return low;
}
