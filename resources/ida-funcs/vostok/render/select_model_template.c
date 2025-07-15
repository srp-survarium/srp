__m128 __cdecl vostok::render::select_model_template(float *const values, float sum)
{
  vostok::math::random32 *v2; // ecx
  __m128 result; // xmm0
  unsigned __int8 i; // al
  __m128 v5; // xmm1
  float v6; // [esp+4h] [ebp-4h]

  result.m128_i32[0] = 0;
  v6 = vostok::math::random32::random_f(v2, sum);
  for ( i = 0; ; ++i )
  {
    v5 = (__m128)LODWORD(values[i]);
    v5.m128_f32[0] = v5.m128_f32[0] + result.m128_f32[0];
    result = v5;
    if ( v5.m128_f32[0] >= v6 )
      break;
  }
  return result;
}
