long double __cdecl survarium::distance_from_box_center_to_point_on_shape(
        const vostok::math::float4x4 *transform,
        const vostok::math::float3 *dim,
        const vostok::math::float3 *source_position)
{
  survarium::game_camera *v3; // ecx
  const vostok::math::float3_pod *v4; // eax
  survarium::game_camera *v5; // ecx
  vostok::math::float3 *v6; // eax
  float x; // ecx
  vostok::math::float3 *v8; // eax
  const float *v9; // eax
  const float *v10; // eax
  vostok::math::float3 *v11; // eax
  const vostok::math::float3_pod *v12; // eax
  vostok::math::float3 *v13; // eax
  vostok::math::float3_pod *v14; // ecx
  vostok::math::float3 v16; // [esp+Ch] [ebp-50h] BYREF
  vostok::math::float3 v17; // [esp+18h] [ebp-44h] BYREF
  float dist; // [esp+24h] [ebp-38h] BYREF
  vostok::math::float3 axis; // [esp+28h] [ebp-34h] BYREF
  int i; // [esp+34h] [ebp-28h]
  vostok::math::float3 dir; // [esp+38h] [ebp-24h] BYREF
  vostok::math::float3 result; // [esp+44h] [ebp-18h] BYREF
  vostok::math::float3 half_sides; // [esp+50h] [ebp-Ch] BYREF

  survarium::weapon_user_dead_state::finalize(v3);
  vostok::math::operator-(v4, source_position, &dir);
  survarium::weapon_user_dead_state::finalize(v5);
  result = *v6;
  x = dim->x;
  half_sides = *dim;
  for ( i = 0; i < 3; ++i )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)LODWORD(x));
    axis = *v8;
    vostok::math::float3_pod::normalize(&axis);
    dist = vostok::math::float3_pod::dot_product(&dir, &axis);
    v9 = vostok::math::float3_pod::operator[]((vostok::math::float3_pod *)i, (int)&half_sides);
    if ( dist > *v9 )
      dist = *vostok::math::float3_pod::operator[]((vostok::math::float3_pod *)i, (int)&half_sides);
    v10 = vostok::math::float3_pod::operator[]((vostok::math::float3_pod *)i, (int)&half_sides);
    if ( (float)-*v10 > dist )
      dist = -*vostok::math::float3_pod::operator[]((vostok::math::float3_pod *)i, (int)&half_sides);
    v11 = vostok::math::operator*(&axis, &v17, &dist);
    vostok::math::float3_pod::operator+=(v11, &result);
    LODWORD(x) = i + 1;
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)LODWORD(x));
  v13 = vostok::math::operator-(&result, v12, &v16);
  return vostok::math::float3_pod::length(v14, &v13->x);
}
