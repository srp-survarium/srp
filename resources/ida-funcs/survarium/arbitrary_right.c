vostok::math::float3 *__usercall survarium::arbitrary_right@<eax>(
        const vostok::math::float3 *forward@<eax>,
        vostok::math::float3 *a2)
{
  float v3; // xmm0_4
  float *p_y; // edi
  bool v5; // al
  vostok::math::float3 *result; // eax
  float v7; // xmm0_4
  float v8; // [esp+Ch] [ebp-1Ch]
  float v9; // [esp+10h] [ebp-18h]
  float v10; // [esp+14h] [ebp-14h]
  int v11; // [esp+24h] [ebp-4h] BYREF

  v11 = 0;
  if ( !vostok::math::is_similar<float>(&forward->x, (const float *)&v11, 0.0000099999997) )
  {
    LODWORD(v8) = COERCE_UNSIGNED_INT((float)(forward->z + forward->y) / forward->x) ^ _mask__NegFloat_;
    v3 = s_bm_current_air_resistance;
    v10 = s_bm_current_air_resistance;
LABEL_6:
    v9 = v3;
    goto LABEL_7;
  }
  p_y = &forward->y;
  v11 = 0;
  v5 = vostok::math::is_similar<float>(&forward->y, (const float *)&v11, 0.0000099999997);
  v3 = s_bm_current_air_resistance;
  v8 = s_bm_current_air_resistance;
  if ( v5 )
  {
    v10 = (float)(-1.0 / forward->z) * (float)(*p_y + forward->x);
    goto LABEL_6;
  }
  v9 = (float)(forward->z + forward->x) * (float)(-1.0 / *p_y);
  v10 = s_bm_current_air_resistance;
LABEL_7:
  result = a2;
  v7 = v3 / fsqrt((float)((float)(v10 * v10) + (float)(v9 * v9)) + (float)(v8 * v8));
  a2->x = v7 * v8;
  a2->y = v9 * v7;
  a2->z = v10 * v7;
  return result;
}
