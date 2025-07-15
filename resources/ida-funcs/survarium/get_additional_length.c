double __cdecl survarium::get_additional_length(
        const vostok::math::float3 *upleg_dir,
        const vostok::math::float3 *leg_dir,
        float knee_len)
{
  vostok::math::float3 *v3; // eax
  float v4; // xmm0_4
  const vostok::math::float4x4 *right; // [esp+10h] [ebp-14h] BYREF
  vostok::math::float3 v8; // [esp+14h] [ebp-10h] BYREF
  float knee_angle_cos; // [esp+20h] [ebp-4h] BYREF

  v3 = vostok::math::float3_pod::operator-(&leg_dir->vostok::math::float3_pod, &v8);
  knee_angle_cos = vostok::math::operator|(upleg_dir, v3);
  right = clear_value;
  if ( vostok::math::is_similar<float>(&knee_angle_cos, (const float *)&right, 0.0000099999997) )
  {
    return (float)(knee_len * 0.5);
  }
  else
  {
    v4 = vostok::math::sqr<float>(&knee_len);
    return (float)vostok::math::sqrt((float)(v4 * 0.5) / (float)(*(float *)&clear_value - knee_angle_cos));
  }
}
