double __cdecl survarium::get_angle(float adjacent0, float adjacent1, float opposite)
{
  float v3; // xmm1_4
  float v5; // [esp+4h] [ebp-14h]
  float v6; // [esp+8h] [ebp-10h]
  float angle_cos; // [esp+14h] [ebp-4h] BYREF

  v6 = vostok::math::sqr<float>(&adjacent0);
  v5 = v6 + vostok::math::sqr<float>(&adjacent1);
  v3 = v5 - vostok::math::sqr<float>(&opposite);
  angle_cos = v3 / (float)((float)(2.0 * adjacent0) * adjacent1);
  vostok::math::clamp<float>(&angle_cos, -1.0, 1.0);
  return vostok::math::acos(angle_cos);
}
