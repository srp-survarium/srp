float __userpurge vostok::render::environment_probe::calc_attenuation@<st0>(
        vostok::render::environment_probe *this@<ecx>,
        int a2@<eax>,
        const vostok::math::float3 *position)
{
  int v3; // ecx
  double v4; // st7
  float z; // xmm1_4
  float y; // xmm0_4
  float x; // xmm2_4
  vostok::math::float3 *v8; // eax
  float v9; // xmm2_4
  float v10; // xmm0_4
  long double v12; // [esp+4h] [ebp-10Ch]
  long double v13; // [esp+Ch] [ebp-104h]
  vostok::math::float4x4 v14; // [esp+14h] [ebp-FCh] BYREF
  vostok::math::float4x4 v15; // [esp+54h] [ebp-BCh] BYREF
  vostok::math::float3 v16; // [esp+98h] [ebp-78h] BYREF
  float v17[16]; // [esp+A4h] [ebp-6Ch] BYREF
  vostok::math::float3 v18; // [esp+E4h] [ebp-2Ch] BYREF
  vostok::math::float3 v19; // [esp+F0h] [ebp-20h] BYREF
  float v20; // [esp+FCh] [ebp-14h]
  vostok::math::float3 v21; // [esp+100h] [ebp-10h] BYREF

  v3 = *(_DWORD *)(a2 + 548);
  v21 = *(vostok::math::float3 *)(a2 + 332);
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      qmemcpy(&v15, (const void *)(a2 + 284), sizeof(v15));
      qmemcpy(&v14, (const void *)(a2 + 348), sizeof(v14));
      qmemcpy(v17, (const void *)(a2 + 284), sizeof(v17));
      vostok::math::float4x4::get_scale(&v15, &v21);
      vostok::math::float4x4::get_scale(&v14, &v18);
      z = position->z;
      y = position->y;
      x = position->x;
      v19.x = (float)((float)((float)(y * v17[4]) + (float)(z * v17[8])) + (float)(position->x * v17[0])) + v17[12];
      v19.y = (float)((float)((float)(z * v17[9]) + (float)(y * v17[5])) + (float)(x * v17[1])) + v17[13];
      v19.z = (float)((float)((float)(y * v17[6]) + (float)(z * v17[10])) + (float)(x * v17[2])) + v17[14];
      v8 = vostok::math::abs(&v19, &v16);
      v19.x = v8->x * v21.x;
      v19.y = v8->y * v21.y;
      v9 = vostok::math::smoothstep(v8->z * v21.z, v21.z, (vostok::math *)LODWORD(v18.z));
      v10 = s_bm_current_air_resistance;
      if ( s_bm_current_air_resistance > (float)(s_bm_current_air_resistance - v9) )
        v10 = s_bm_current_air_resistance - v9;
      if ( v10 >= 0.0 )
        v20 = v10;
      else
        v20 = 0.0;
      vostok::math::smoothstep(v19.y, v21.y, (vostok::math *)LODWORD(v18.y));
      v4 = v18.x;
      vostok::math::smoothstep(v19.x, v21.x, (vostok::math *)LODWORD(v18.x));
    }
  }
  else
  {
    return __libm_sse2_pow(v12, v13);
  }
  return v4;
}
