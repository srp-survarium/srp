void __thiscall survarium::bullet::fix_collision_point_and_time(
        survarium::bullet *this,
        vostok::math::float3 *collide_point,
        float *collision_time,
        float start_time,
        float current_time,
        survarium::triangle_orientation orientation,
        const vostok::math::float3 *triangle_normal,
        const vostok::math::float3 *gravity)
{
  vostok::math::float3 *v8; // eax
  vostok::math::float3 *v9; // eax
  vostok::math::float3 v11; // [esp+24h] [ebp-3Ch] BYREF
  vostok::math::float3 result; // [esp+30h] [ebp-30h] BYREF
  vostok::math::float3 v13; // [esp+3Ch] [ebp-24h] BYREF
  float high_time; // [esp+48h] [ebp-18h]
  float low_time; // [esp+4Ch] [ebp-14h]
  float delta; // [esp+50h] [ebp-10h] BYREF
  vostok::math::float3 new_collide_point; // [esp+54h] [ebp-Ch] BYREF

  survarium::bullet::compute_trajectory_position(this, &new_collide_point, *collision_time, gravity);
  v8 = vostok::math::operator-(collide_point, &new_collide_point, &v13);
  delta = vostok::math::operator|(v8, triangle_normal);
  if ( !vostok::math::is_zero<float>(&delta, &epsilon_3_5) )
  {
    low_time = start_time;
    high_time = current_time;
    while ( !vostok::math::is_zero<float>(&delta, &epsilon_3_5) )
    {
      if ( (orientation || delta >= 0.0) && (orientation != triangle_orientation_back_face || delta <= 0.0) )
        low_time = *collision_time;
      else
        high_time = *collision_time;
      *collision_time = (float)(low_time + high_time) * 0.5;
      new_collide_point = *survarium::bullet::compute_trajectory_position(this, &result, *collision_time, gravity);
      v9 = vostok::math::operator-(collide_point, &new_collide_point, &v11);
      delta = vostok::math::operator|(v9, triangle_normal);
    }
    *collide_point = new_collide_point;
  }
}
