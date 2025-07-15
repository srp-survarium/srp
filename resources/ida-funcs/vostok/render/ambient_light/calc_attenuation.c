float __thiscall vostok::render::ambient_light::calc_attenuation(
        vostok::render::ambient_light *this,
        const vostok::math::float3 *position,
        float *a3)
{
  float x; // ecx
  double v4; // st7
  float z; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  vostok::math::float3 *v10; // eax
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v14; // [esp+0h] [ebp-7Ch]
  long double v15; // [esp+4h] [ebp-78h]
  long double v16; // [esp+Ch] [ebp-70h]
  vostok::math::float4x4 v17; // [esp+14h] [ebp-68h] BYREF
  vostok::math::float3 v18; // [esp+58h] [ebp-24h] BYREF
  vostok::math::float3 v19; // [esp+64h] [ebp-18h] BYREF
  float v20; // [esp+70h] [ebp-Ch]
  float v21; // [esp+74h] [ebp-8h]
  float v22; // [esp+78h] [ebp-4h]

  x = position[9].x;
  v19 = *(const vostok::math::float3 *)((char *)position + 52);
  if ( x == 0.0 )
  {
    return __libm_sse2_pow(v15, v16);
  }
  else if ( LODWORD(x) == 1 )
  {
    qmemcpy(&v17, &position->elements[1], sizeof(v17));
    vostok::math::float4x4::get_scale(&v17, &v19);
    qmemcpy(&v17, &position->elements[1], sizeof(v17));
    vostok::math::float4x4::try_invert(&v17, &v17);
    z = position[8].z;
    v6 = *a3;
    v20 = z / v19.x;
    v7 = z;
    v22 = z / v19.z;
    v8 = a3[1];
    v21 = v7 / v19.y;
    v9 = a3[2];
    v19.x = (float)((float)((float)(v6 * v17.i.x) + (float)(v8 * v17.j.x)) + (float)(v9 * v17.k.x)) + v17.c.x;
    v19.y = (float)((float)((float)(v8 * v17.j.y) + (float)(v9 * v17.k.y)) + (float)(v6 * v17.i.y)) + v17.c.y;
    v19.z = (float)((float)((float)(v8 * v17.j.z) + (float)(v9 * v17.k.z)) + (float)(v6 * v17.i.z)) + v17.c.z;
    v10 = vostok::math::abs(&v19, &v18);
    v11 = v10->x;
    if ( v10->x > s_bm_current_air_resistance )
      v11 = s_bm_current_air_resistance;
    if ( v10->y <= s_bm_current_air_resistance )
      v19.y = v10->y;
    else
      v19.y = s_bm_current_air_resistance;
    if ( v10->z <= s_bm_current_air_resistance )
      v19.z = v10->z;
    else
      v19.z = s_bm_current_air_resistance;
    v18.z = s_bm_current_air_resistance - v22;
    v18.y = 1.0 - v21;
    v14 = 1.0 - v20;
    v20 = s_bm_current_air_resistance
        - vostok::math::smoothstep(v11, s_bm_current_air_resistance, (vostok::math *)LODWORD(v14));
    v12 = vostok::math::smoothstep(v19.y, s_bm_current_air_resistance, (vostok::math *)LODWORD(v18.y));
    v4 = v18.z;
    v21 = s_bm_current_air_resistance - v12;
    vostok::math::smoothstep(v19.z, s_bm_current_air_resistance, (vostok::math *)LODWORD(v18.z));
  }
  return v4;
}
