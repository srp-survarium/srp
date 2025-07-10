float __usercall SegmentSqrDistance@<xmm0>(
        const btVector3 *to@<edx>,
        const btVector3 *p@<ecx>,
        btVector3 *nearest@<esi>,
        const btVector3 *from)
{
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm0_4
  float v8; // xmm6_4
  float v9; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm6_4
  float v14; // xmm3_4
  unsigned __int64 v16; // [esp+30h] [ebp-20h]
  float v17; // [esp+38h] [ebp-18h]
  unsigned int v18; // [esp+38h] [ebp-18h]

  v4 = from->mVec128.m128_f32[1];
  v5 = from->mVec128.m128_f32[2];
  v6 = p->mVec128.m128_f32[0] - from->mVec128.m128_f32[0];
  v7 = to->mVec128.m128_f32[0] - from->mVec128.m128_f32[0];
  v8 = p->mVec128.m128_f32[2] - v5;
  v9 = p->mVec128.m128_f32[1] - v4;
  v10 = to->mVec128.m128_f32[1] - v4;
  v11 = to->mVec128.m128_f32[2] - v5;
  v12 = (float)((float)(v10 * v9) + (float)(v11 * v8)) + (float)(v7 * v6);
  v17 = v8;
  if ( v12 <= 0.0 )
  {
    v14 = 0.0;
  }
  else
  {
    v13 = (float)((float)(v11 * v11) + (float)(v10 * v10)) + (float)(v7 * v7);
    if ( v13 <= v12 )
    {
      v14 = *(float *)&clear_value;
      v6 = v6 - v7;
      v9 = v9 - v10;
      v8 = v17 - v11;
    }
    else
    {
      v14 = v12 / v13;
      v9 = v9 - (float)(v10 * v14);
      v6 = v6 - (float)(v7 * v14);
      v8 = v17 - (float)(v11 * v14);
    }
  }
  *(float *)&v18 = from->mVec128.m128_f32[2] + (float)(v11 * v14);
  *((float *)&v16 + 1) = (float)(v10 * v14) + from->mVec128.m128_f32[1];
  *(float *)&v16 = from->mVec128.m128_f32[0] + (float)(v7 * v14);
  nearest->mVec128.m128_u64[0] = v16;
  nearest->mVec128.m128_u64[1] = v18;
  return (float)((float)(v6 * v6) + (float)(v9 * v9)) + (float)(v8 * v8);
}
