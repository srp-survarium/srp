vostok::math::float4x4 *__thiscall vostok::render::temporal_projection_matrix_modifier::push_jittering(
        vostok::render::temporal_projection_matrix_modifier *this,
        vostok::math::float4x4 *result,
        vostok::math::float4x4 *a3)
{
  _BYTE *v4; // esi
  int x_low; // eax
  double y_low; // st7
  const void *v7; // edx
  int v8; // ecx
  bool v9; // zf
  float *v10; // ecx
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm7_4
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm6_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  vostok::math::float4x4 *v23; // eax
  _BYTE v24[64]; // [esp+10h] [ebp-98h] BYREF
  vostok::math::float4x4 v25; // [esp+50h] [ebp-58h] BYREF
  _DWORD v26[2]; // [esp+94h] [ebp-14h] BYREF
  _DWORD v27[2]; // [esp+9Ch] [ebp-Ch] BYREF
  float z_low; // [esp+A4h] [ebp-4h]
  float v29; // [esp+B0h] [ebp+8h]

  if ( LOBYTE(result->lines[0].elements[3]) )
  {
    x_low = LODWORD(result->i.x);
    y_low = (double)LODWORD(result->i.y);
    v7 = (const void *)(LODWORD(result->i.x) + 19828);
    qmemcpy(&v25, v7, sizeof(v25));
    qmemcpy(v24, v7, sizeof(v24));
    v8 = *(_DWORD *)(x_low + 16268);
    z_low = (float)LODWORD(result->i.z);
    v9 = (*((_BYTE *)&dword_10DF8 + v8) & 1) == 0;
    *(float *)v26 = FLOAT_0_25;
    *(float *)&v26[1] = FLOAT_N0_25;
    *(float *)v27 = FLOAT_N0_25;
    *(float *)&v27[1] = FLOAT_0_25;
    v10 = (float *)v26;
    if ( !v9 )
      v10 = (float *)v27;
    v11 = *(float *)(x_low + 16224);
    v12 = v11 * v25.j.y;
    v13 = v11 * v25.i.x;
    v14 = v12;
    LODWORD(v15) = LODWORD(v13) ^ _mask__NegFloat_;
    v29 = y_low;
    v16 = (float)((float)(v12 - COERCE_FLOAT(LODWORD(v12) ^ _mask__NegFloat_)) * (float)(-1.0 / v29)) * *v10;
    v17 = (float)((float)(v13 - COERCE_FLOAT(LODWORD(v13) ^ _mask__NegFloat_)) * v10[1]) * (float)(-1.0 / z_low);
    v18 = v17 + v13;
    v19 = v16;
    v20 = v16 + COERCE_FLOAT(LODWORD(v14) ^ _mask__NegFloat_);
    v21 = v19 + v14;
    v22 = v17 + v15;
    if ( fabs(v20 - v21) > 0.0000099999997 )
      v25.k.x = (float)(v20 + v21) / (float)(v20 - v21);
    if ( fabs(v22 - v18) > 0.0000099999997 )
      v25.k.y = (float)(v22 + v18) / (float)(v22 - v18);
    vostok::render::renderer_context::push_set_p((vostok::render::renderer_context *)&v25, x_low, &v25);
    BYTE1(result->lines[0].elements[3]) = 1;
    v4 = v24;
  }
  else
  {
    v4 = (_BYTE *)(LODWORD(result->i.x) + 19828);
  }
  v23 = a3;
  qmemcpy(a3, v4, sizeof(vostok::math::float4x4));
  return v23;
}
