vostok::math::float4x4 *__usercall vostok::render::fix_view_matrix@<eax>(
        const vostok::math::float4x4 *in_view_matrix@<eax>,
        int a2)
{
  const vostok::math::float4x4 *v2; // xmm5_4
  float v3; // xmm2_4
  bool v4; // cl
  bool v5; // al
  int v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float value; // [esp+10h] [ebp-4h]

  v2 = clear_value;
  qmemcpy((void *)a2, in_view_matrix, 0x40u);
  value = *(float *)(a2 + 24);
  v3 = *(float *)(a2 + 40);
  v4 = COERCE_FLOAT(*(_DWORD *)(a2 + 8) & 0x7FFFFFFF) < 0.1
    && fabs(value - *(float *)&v2) < 0.1
    && COERCE_FLOAT(LODWORD(v3) & 0x7FFFFFFF) < 0.1;
  v5 = COERCE_FLOAT(*(_DWORD *)(a2 + 8) & 0x7FFFFFFF) < 0.1
    && fabs(value - -1.0) < 0.1
    && COERCE_FLOAT(LODWORD(v3) & 0x7FFFFFFF) < 0.1;
  v6 = -1082298204;
  if ( v4 || v5 )
  {
    *(float *)(a2 + 8) = *(float *)(a2 + 8) + *(float *)&v2;
    *(float *)(a2 + 40) = v3 + *(float *)&v2;
    v7 = (float)(int)vostok::math::floor(value);
    *(float *)(a2 + 24) = v7;
    v6 = -1082298204;
    if ( v7 > -0.99000001 )
    {
      if ( v7 > 0.99000001 )
        v7 = 0.99000001;
    }
    else
    {
      v7 = -0.99000001;
    }
    *(float *)(a2 + 24) = v7;
    if ( v7 > -0.99000001 )
    {
      if ( v7 > 0.99000001 )
        v7 = 0.99000001;
    }
    else
    {
      v7 = -0.99000001;
    }
    *(float *)(a2 + 24) = v7;
    v8 = *(float *)(a2 + 40);
    if ( v8 > -0.99000001 )
    {
      if ( v8 > 0.99000001 )
        v8 = 0.99000001;
    }
    else
    {
      v8 = -0.99000001;
    }
    *(float *)(a2 + 40) = v8;
  }
  v9 = *(float *)(a2 + 16);
  if ( v9 > -0.99000001 )
  {
    if ( v9 > 0.99000001 )
      v9 = 0.99000001;
  }
  else
  {
    v9 = -0.99000001;
  }
  *(float *)(a2 + 16) = v9;
  if ( v9 > -0.99000001 )
  {
    if ( v9 > 0.99000001 )
      v9 = 0.99000001;
  }
  else
  {
    v9 = -0.99000001;
  }
  *(float *)(a2 + 16) = v9;
  v10 = *(float *)(a2 + 32);
  if ( v10 > -0.99000001 )
  {
    if ( v10 > 0.99000001 )
      v10 = 0.99000001;
  }
  else
  {
    v10 = -0.99000001;
  }
  *(float *)(a2 + 32) = v10;
  v11 = *(float *)(a2 + 20);
  if ( v11 > -0.99000001 )
  {
    if ( v11 > 0.99000001 )
      v11 = 0.99000001;
  }
  else
  {
    v11 = -0.99000001;
  }
  *(float *)(a2 + 20) = v11;
  if ( v11 > -0.99000001 )
  {
    if ( v11 > 0.99000001 )
      v11 = 0.99000001;
  }
  else
  {
    v11 = -0.99000001;
  }
  *(float *)(a2 + 20) = v11;
  v12 = *(float *)(a2 + 36);
  if ( v12 > -0.99000001 )
  {
    if ( v12 > 0.99000001 )
      v12 = 0.99000001;
  }
  else
  {
    v12 = -0.99000001;
  }
  *(float *)(a2 + 36) = v12;
  v13 = *(float *)(a2 + 24);
  if ( v13 > -0.99000001 )
  {
    if ( v13 > 0.99000001 )
      v13 = 0.99000001;
  }
  else
  {
    v13 = -0.99000001;
  }
  *(float *)(a2 + 24) = v13;
  if ( v13 > -0.99000001 )
  {
    if ( v13 > 0.99000001 )
      v13 = 0.99000001;
  }
  else
  {
    v13 = -0.99000001;
  }
  *(float *)(a2 + 24) = v13;
  v14 = *(float *)(a2 + 40);
  if ( v14 > -0.99000001 )
  {
    if ( v14 <= 0.99000001 )
    {
      *(float *)(a2 + 40) = v14;
      return (vostok::math::float4x4 *)a2;
    }
    v6 = 1065185444;
  }
  *(_DWORD *)(a2 + 40) = v6;
  return (vostok::math::float4x4 *)a2;
}
