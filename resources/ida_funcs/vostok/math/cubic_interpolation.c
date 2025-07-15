double __cdecl vostok::math::cubic_interpolation<float,float>(float P0, float M0, float P1, float M1, float t)
{
  float t_pow_3; // [esp+4h] [ebp-Ch]

  t_pow_3 = (float)(t * t) * t;
  return (t_pow_3 - ((float)(t * t) + (float)(t * t)) + t) * M0
       + ((float)(t_pow_3 * 2.0) - (float)((float)(t * t) * 3.0) + *(float *)&clear_value) * P0
       + ((float)((float)(t * t) * 3.0) - (float)(t_pow_3 * 2.0)) * P1
       + (t_pow_3 - (float)(t * t)) * M1;
}


vostok::math::float4_pod *__cdecl vostok::math::cubic_interpolation<vostok::math::float4_pod,float>(
        vostok::math::float4_pod *result,
        vostok::math::float4_pod P0,
        vostok::math::float4_pod M0,
        vostok::math::float4_pod P1,
        vostok::math::float4_pod M1,
        float t)
{
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  vostok::math::float4_pod *v11; // eax
  vostok::math::float4_pod v12; // [esp+10h] [ebp-20h]

  v6 = (float)((float)(t * t) * t) - (float)(t * t);
  v7 = (float)((float)((float)(t * t) * t) - (float)((float)(t * t) * 2.0)) + t;
  v8 = (float)((float)(t * t) * t) * 2.0;
  v9 = (float)((float)(t * t) * 3.0) - v8;
  v10 = (float)(v8 - (float)((float)(t * t) * 3.0)) + *(float *)&clear_value;
  v11 = result;
  v12.x = (float)((float)((float)(P0.x * v10) + (float)(M0.x * v7)) + (float)(P1.x * v9)) + (float)(M1.x * v6);
  v12.y = (float)((float)((float)(P0.y * v10) + (float)(M0.y * v7)) + (float)(P1.y * v9)) + (float)(M1.y * v6);
  v12.z = (float)((float)((float)(P0.z * v10) + (float)(M0.z * v7)) + (float)(P1.z * v9)) + (float)(M1.z * v6);
  v12.w = (float)((float)((float)(P0.w * v10) + (float)(M0.w * v7)) + (float)(P1.w * v9)) + (float)(M1.w * v6);
  *result = v12;
  return v11;
}
