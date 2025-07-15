void __thiscall vostok::render::temporal_projection_matrix_modifier::push_jittering(
        vostok::render::temporal_projection_matrix_modifier *this,
        int *w)
{
  int v3; // eax
  double v4; // st7
  double v5; // st7
  bool v6; // zf
  float *v7; // ecx
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm5_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm6_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // ecx
  void *v22; // edi
  float h; // [esp+Ch] [ebp-54h]
  float jitter0[2]; // [esp+10h] [ebp-50h] BYREF
  float jitter1[2]; // [esp+18h] [ebp-48h] BYREF
  vostok::math::float4x4 p; // [esp+20h] [ebp-40h] BYREF
  float wa; // [esp+64h] [ebp+4h]

  if ( *((_BYTE *)w + 12) )
  {
    v3 = *w;
    v4 = (double)(unsigned int)w[1];
    qmemcpy((void *)&p, (const void *)(*w + 15940), sizeof(p));
    wa = v4;
    v5 = (double)(unsigned int)w[2];
    v6 = (*(_BYTE *)(*(_DWORD *)(v3 + 12392) + 1216) & 1) == 0;
    jitter0[0] = 0.25;
    jitter0[1] = -0.25;
    jitter1[0] = -0.25;
    jitter1[1] = 0.25;
    v7 = jitter0;
    if ( !v6 )
      v7 = jitter1;
    v8 = *(float *)(v3 + 12372);
    v9 = v8 * p.j.y;
    v10 = v8 * p.i.x;
    v11 = v9;
    LODWORD(v12) = LODWORD(v10) ^ 0x80000000;
    LODWORD(v13) = LODWORD(v9) ^ 0x80000000;
    v14 = (float)((float)(v9 - COERCE_FLOAT(LODWORD(v9) ^ 0x80000000)) * (float)(-1.0 / wa)) * *v7;
    h = v5;
    v15 = (float)((float)(v10 - COERCE_FLOAT(LODWORD(v10) ^ 0x80000000)) * v7[1]) * (float)(-1.0 / h);
    v16 = v15 + v10;
    v17 = v14;
    v18 = v15 + v12;
    v19 = v14 + v13;
    v20 = v17 + v11;
    if ( fabs(v19 - v20) > 0.0000099999997 )
      p.k.x = (float)(v19 + v20) / (float)(v19 - v20);
    v21 = fabs(v18 - v16);
    if ( v21 > 0.0000099999997 )
      p.k.y = (float)(v18 + v16) / (float)(v18 - v16);
    v22 = *(void **)(v3 + 14464);
    if ( v22 )
    {
      qmemcpy(v22, (const void *)(v3 + 15940), 0x40u);
      v21 = 0.0;
    }
    *(_DWORD *)(v3 + 14464) += 64;
    vostok::render::renderer_context::set_p(
      (vostok::render::renderer_context *)LODWORD(v21),
      (const vostok::math::float4x4 *)v3);
    *((_BYTE *)w + 13) = 1;
  }
}
