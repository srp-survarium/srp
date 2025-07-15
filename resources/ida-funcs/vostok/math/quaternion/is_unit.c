BOOL __thiscall vostok::math::quaternion::is_unit(vostok::math::quaternion *this)
{
  float v2; // [esp+0h] [ebp-4h]

  v2 = sqrt(vostok::math::float4_pod::squared_length((vostok::math::float4_pod *)this)) - s_bm_current_air_resistance;
  return COERCE_FLOAT(LODWORD(v2) & 0x7FFFFFFF) < 0.0000099999997;
}
