vostok::math::aabb *__usercall vostok::math::create_identity_aabb@<eax>(vostok::math::aabb *a1@<eax>)
{
  float v1; // xmm0_4

  v1 = s_bm_current_air_resistance;
  a1->min.x = FLOAT_N1_0;
  a1->min.y = FLOAT_N1_0;
  a1->min.z = FLOAT_N1_0;
  a1->max.x = v1;
  a1->max.y = v1;
  a1->max.z = v1;
  return a1;
}
