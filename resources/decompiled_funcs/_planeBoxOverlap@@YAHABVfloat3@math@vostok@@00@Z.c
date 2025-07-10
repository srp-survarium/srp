BOOL __usercall planeBoxOverlap@<eax>(
        const vostok::math::float3 *vert@<eax>,
        const vostok::math::float3 *maxbox@<edx>,
        const vostok::math::float3 *normal)
{
  float x; // xmm3_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm5_4
  float y; // xmm7_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm5_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float z; // xmm4_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float vmax; // [esp+4h] [ebp-Ch]
  float vmax_4; // [esp+8h] [ebp-8h]
  float v; // [esp+14h] [ebp+4h]

  x = normal->x;
  v4 = maxbox->x;
  v5 = vert->x;
  v6 = maxbox->x;
  if ( normal->x <= 0.0 )
    v4 = -v4;
  else
    v6 = -v6;
  y = normal->y;
  v8 = vert->y;
  vmax = v4 - v5;
  v9 = maxbox->y;
  v10 = v6 - v5;
  v11 = v9;
  if ( y <= 0.0 )
    v9 = -v9;
  else
    v11 = -v9;
  vmax_4 = v9 - v8;
  v12 = v11 - v8;
  z = normal->z;
  v14 = maxbox->z;
  v = vert->z;
  if ( z <= 0.0 )
  {
    v15 = maxbox->z - v;
    v16 = (float)-v14 - v;
  }
  else
  {
    v15 = (float)-v14 - v;
    v16 = v14 - v;
  }
  return (float)((float)((float)(x * v10) + (float)(z * v15)) + (float)(y * v12)) <= 0.0
      && (float)((float)((float)(x * vmax) + (float)(z * v16)) + (float)(y * vmax_4)) >= 0.0;
}
