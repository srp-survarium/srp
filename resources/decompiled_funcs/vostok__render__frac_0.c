float __usercall vostok::render::frac_0@<xmm0>(__m128 a1@<xmm3>)
{
  __m128 v2; // xmm1
  __m128 v3; // xmm0
  __m128 v4; // xmm2

  v2.m128_i32[0] = a1.m128_i32[0] & 0x80000000;
  v3 = a1;
  v3.m128_f32[0] = (float)(a1.m128_f32[0] + COERCE_FLOAT(v2.m128_i32[0] | 0x4B000000))
                 - COERCE_FLOAT(v2.m128_i32[0] | 0x4B000000);
  v4 = v3;
  v4.m128_f32[0] = v3.m128_f32[0] - a1.m128_f32[0];
  return COERCE_FLOAT(a1.m128_i32[0] & 0x7FFFFFFF)
       - fabs(v3.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v4, v2).m128_u32[0] & (unsigned int)clear_value));
}
