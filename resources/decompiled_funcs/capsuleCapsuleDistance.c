int __usercall capsuleCapsuleDistance@<xmm0>(
        btVector3 *normalOnB@<edi>,
        int capsuleAxisB@<ecx>,
        const btTransform *transformA@<eax>,
        const btTransform *transformB@<esi>,
        btVector3 *pointOnB,
        float capsuleLengthA,
        float capsuleRadiusA,
        float capsuleLengthB,
        float capsuleRadiusB,
        int capsuleAxisA,
        float distanceThreshold)
{
  float v11; // xmm7_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm6_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  long double v24; // st7
  float v25; // xmm1_4
  long double v26; // st7
  long double v27; // st7
  long double v28; // st7
  unsigned int v29; // xmm2_4
  float v31; // [esp+134h] [ebp-48h]
  float v32; // [esp+134h] [ebp-48h]
  float v33; // [esp+138h] [ebp-44h]
  float v34; // [esp+13Ch] [ebp-40h]
  unsigned __int64 v35; // [esp+13Ch] [ebp-40h]
  float v36; // [esp+140h] [ebp-3Ch]
  unsigned int v37; // [esp+144h] [ebp-38h]
  float v38; // [esp+14Ch] [ebp-30h]
  float v39; // [esp+150h] [ebp-2Ch]
  float v40; // [esp+154h] [ebp-28h]
  float v41; // [esp+154h] [ebp-28h]
  unsigned __int64 v42; // [esp+15Ch] [ebp-20h]
  unsigned __int64 v43; // [esp+15Ch] [ebp-20h]
  float v44; // [esp+164h] [ebp-18h]
  unsigned __int64 v45; // [esp+16Ch] [ebp-10h]

  v11 = transformA->m_basis.m_el[2].mVec128.m128_f32[capsuleAxisA];
  v12 = transformA->m_basis.m_el[0].mVec128.m128_f32[capsuleAxisA];
  v45 = transformA->m_origin.mVec128.m128_u64[0];
  v38 = transformB->m_basis.m_el[0].mVec128.m128_f32[capsuleAxisB];
  v40 = transformB->m_basis.m_el[2].mVec128.m128_f32[capsuleAxisB];
  v39 = transformB->m_basis.m_el[1].mVec128.m128_f32[capsuleAxisB];
  v36 = transformA->m_basis.m_el[1].mVec128.m128_f32[capsuleAxisA];
  v42 = transformB->m_origin.mVec128.m128_u64[0];
  v13 = (float)((float)(v39 * v36) + (float)(v40 * v11)) + (float)(v38 * v12);
  v14 = transformB->m_origin.mVec128.m128_f32[2] - transformA->m_origin.mVec128.m128_f32[2];
  v34 = v12;
  v15 = (float)((float)((float)(*((float *)&v42 + 1) - *((float *)&v45 + 1)) * v36) + (float)(v14 * v11))
      + (float)((float)(*(float *)&v42 - *(float *)&v45) * v12);
  v16 = (float)((float)(v14 * v40) + (float)((float)(*((float *)&v42 + 1) - *((float *)&v45 + 1)) * v39))
      + (float)((float)(*(float *)&v42 - *(float *)&v45) * v38);
  v17 = *(float *)&clear_value - (float)(v13 * v13);
  v31 = v15;
  if ( v17 == 0.0 )
  {
    v18 = 0.0;
  }
  else
  {
    v18 = (float)(v15 - (float)(v16 * v13)) / v17;
    v19 = -capsuleLengthA;
    if ( (float)-capsuleLengthA > v18 || (v19 = capsuleLengthA, v18 > capsuleLengthA) )
      v18 = v19;
  }
  v20 = (float)(v13 * v18) - v16;
  if ( (float)-capsuleLengthB <= v20 )
  {
    if ( v20 <= capsuleLengthB )
      goto LABEL_14;
    v20 = capsuleLengthB;
    v21 = v13 * capsuleLengthB;
  }
  else
  {
    v20 = -capsuleLengthB;
    v21 = v13 * (float)-capsuleLengthB;
  }
  v18 = v21 + v31;
  if ( (float)-capsuleLengthA <= (float)(v21 + v31) )
  {
    if ( v18 > capsuleLengthA )
      v18 = capsuleLengthA;
  }
  else
  {
    v18 = -capsuleLengthA;
  }
LABEL_14:
  v22 = (float)((float)(*(float *)&v42 - *(float *)&v45) - (float)(v34 * v18)) + (float)(v38 * v20);
  v44 = v40 * v20;
  v23 = (float)((float)(*((float *)&v42 + 1) - *((float *)&v45 + 1)) - (float)(v36 * v18)) + (float)(v39 * v20);
  v41 = (float)(v14 - (float)(v11 * v18)) + (float)(v40 * v20);
  v32 = (float)((float)(v41 * v41) + (float)(v23 * v23)) + (float)(v22 * v22);
  v24 = sqrtf(v32) - capsuleRadiusA - capsuleRadiusB;
  v33 = v24;
  if ( v24 <= distanceThreshold )
  {
    if ( v32 > 1.4210855e-14 )
    {
      v28 = -(1.0 / sqrtf(v32));
      *(float *)&v35 = v22 * v28;
      *((float *)&v35 + 1) = v23 * v28;
      normalOnB->mVec128.m128_u64[0] = v35;
      *(float *)&v37 = v28 * v41;
      normalOnB->mVec128.m128_u64[1] = v37;
    }
    else
    {
      v25 = v36 * v36;
      if ( fabsf(v11) <= hsqt2 )
      {
        v27 = 1.0 / sqrtf(v25 + (float)(v34 * v34));
        normalOnB->mVec128.m128_i32[2] = 0;
        normalOnB->mVec128.m128_f32[0] = -(v36 * v27);
        normalOnB->mVec128.m128_f32[1] = v27 * v34;
      }
      else
      {
        v26 = 1.0 / sqrtf(v25 + (float)(v11 * v11));
        normalOnB->mVec128.m128_i32[0] = 0;
        normalOnB->mVec128.m128_f32[1] = -(v11 * v26);
        normalOnB->mVec128.m128_f32[2] = v26 * v36;
      }
    }
    *(float *)&v43 = (float)(transformB->m_origin.mVec128.m128_f32[0] + (float)(v38 * v20))
                   + (float)(normalOnB->mVec128.m128_f32[0] * capsuleRadiusB);
    *((float *)&v43 + 1) = (float)(transformB->m_origin.mVec128.m128_f32[1] + (float)(v39 * v20))
                         + (float)(normalOnB->mVec128.m128_f32[1] * capsuleRadiusB);
    *(float *)&v29 = (float)(transformB->m_origin.mVec128.m128_f32[2] + v44)
                   + (float)(normalOnB->mVec128.m128_f32[2] * capsuleRadiusB);
    pointOnB->mVec128.m128_u64[0] = v43;
    pointOnB->mVec128.m128_u64[1] = v29;
  }
  return LODWORD(v33);
}
