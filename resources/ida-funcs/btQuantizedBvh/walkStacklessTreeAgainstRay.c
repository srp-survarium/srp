void __userpurge btQuantizedBvh::walkStacklessTreeAgainstRay(
        const btVector3 *rayTarget@<eax>,
        btQuantizedBvh *this,
        btNodeOverlapCallback *nodeCallback,
        const btVector3 *raySource,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax,
        int startNodeIndex,
        int endNodeIndex)
{
  float v8; // xmm0_4
  btOptimizedBvhNode *m_data; // ebx
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  const btVector3 *v13; // edx
  const btVector3 *v14; // ecx
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm6_4
  float v19; // xmm7_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm7_4
  bool v24; // cc
  char v25; // dl
  float v26; // xmm5_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm2_4
  float v31; // xmm5_4
  float v32; // xmm4_4
  float v33; // xmm2_4
  unsigned __int8 v34; // al
  int v35; // esi
  int m_escapeIndex; // eax
  bool v37; // [esp+17h] [ebp-69h]
  int v38; // [esp+18h] [ebp-68h]
  int v39; // [esp+1Ch] [ebp-64h]
  float v40; // [esp+20h] [ebp-60h]
  float v41; // [esp+20h] [ebp-60h]
  BOOL v42; // [esp+24h] [ebp-5Ch]
  BOOL v43; // [esp+28h] [ebp-58h]
  BOOL v44; // [esp+2Ch] [ebp-54h]
  unsigned __int64 v45; // [esp+30h] [ebp-50h]
  float v47; // [esp+38h] [ebp-48h]
  float v48; // [esp+38h] [ebp-48h]
  float v49; // [esp+40h] [ebp-40h]
  float v50; // [esp+44h] [ebp-3Ch]
  float v51; // [esp+48h] [ebp-38h]
  float v52; // [esp+50h] [ebp-30h]
  float v53; // [esp+54h] [ebp-2Ch]
  float v54; // [esp+58h] [ebp-28h]
  float v55; // [esp+60h] [ebp-20h]
  float v56; // [esp+64h] [ebp-1Ch]
  float v57[2]; // [esp+68h] [ebp-18h]
  float v58; // [esp+70h] [ebp-10h]
  float v59; // [esp+74h] [ebp-Ch]
  float v60[2]; // [esp+78h] [ebp-8h]

  v38 = 0;
  v39 = 0;
  v8 = rayTarget->mVec128.m128_f32[0];
  m_data = this->m_contiguousNodes.m_data;
  v10 = raySource->mVec128.m128_f32[0];
  v45 = raySource->mVec128.m128_u64[0];
  v47 = raySource->mVec128.m128_f32[2];
  if ( raySource->mVec128.m128_f32[0] > rayTarget->mVec128.m128_f32[0] )
    v10 = rayTarget->mVec128.m128_f32[0];
  v11 = raySource->mVec128.m128_f32[1];
  if ( v11 > rayTarget->mVec128.m128_f32[1] )
    v11 = rayTarget->mVec128.m128_f32[1];
  v12 = raySource->mVec128.m128_f32[2];
  if ( v12 > rayTarget->mVec128.m128_f32[2] )
    v12 = rayTarget->mVec128.m128_f32[2];
  if ( v8 > *(float *)&v45 )
    LODWORD(v45) = rayTarget->mVec128.m128_i32[0];
  if ( rayTarget->mVec128.m128_f32[1] > *((float *)&v45 + 1) )
    HIDWORD(v45) = rayTarget->mVec128.m128_i32[1];
  if ( rayTarget->mVec128.m128_f32[2] > v47 )
    v47 = rayTarget->mVec128.m128_f32[2];
  v13 = aabbMin;
  v14 = aabbMax;
  v54 = v12 + aabbMin->mVec128.m128_f32[2];
  *(float *)&v45 = aabbMax->mVec128.m128_f32[0] + *(float *)&v45;
  *((float *)&v45 + 1) = aabbMax->mVec128.m128_f32[1] + *((float *)&v45 + 1);
  v48 = aabbMax->mVec128.m128_f32[2] + v47;
  v15 = rayTarget->mVec128.m128_f32[2] - raySource->mVec128.m128_f32[2];
  v53 = v11 + aabbMin->mVec128.m128_f32[1];
  v16 = v8 - raySource->mVec128.m128_f32[0];
  v17 = rayTarget->mVec128.m128_f32[1] - raySource->mVec128.m128_f32[1];
  v18 = aabbMin->mVec128.m128_f32[0] + v10;
  v19 = fsqrt((float)((float)(v17 * v17) + (float)(v15 * v15)) + (float)(v16 * v16));
  v40 = v16;
  v20 = v16 * (float)(s_bm_current_air_resistance / v19);
  v21 = v17 * (float)(s_bm_current_air_resistance / v19);
  v22 = v15 * (float)(s_bm_current_air_resistance / v19);
  v41 = (float)((float)(v17 * v21) + (float)(v15 * v22)) + (float)(v40 * v20);
  v52 = v18;
  if ( v20 == 0.0 )
    v49 = FLOAT_9_9999998e17;
  else
    v49 = s_bm_current_air_resistance / v20;
  if ( v21 == 0.0 )
    v23 = FLOAT_9_9999998e17;
  else
    v23 = s_bm_current_air_resistance / v21;
  v50 = v23;
  if ( v22 == 0.0 )
    v51 = FLOAT_9_9999998e17;
  else
    v51 = s_bm_current_air_resistance / v22;
  v42 = v49 < 0.0;
  v43 = v23 < 0.0;
  v44 = v51 < 0.0;
  if ( this->m_curNodeIndex > 0 )
  {
    while ( 1 )
    {
      v55 = m_data->m_aabbMinOrg.mVec128.m128_f32[0];
      v56 = m_data->m_aabbMinOrg.mVec128.m128_f32[1];
      v57[0] = m_data->m_aabbMinOrg.mVec128.m128_f32[2];
      v57[1] = m_data->m_aabbMinOrg.mVec128.m128_f32[3];
      v58 = m_data->m_aabbMaxOrg.mVec128.m128_f32[0];
      v59 = m_data->m_aabbMaxOrg.mVec128.m128_f32[1];
      v60[0] = m_data->m_aabbMaxOrg.mVec128.m128_f32[2];
      ++v39;
      v24 = v18 <= m_data->m_aabbMaxOrg.mVec128.m128_f32[0];
      v60[1] = m_data->m_aabbMaxOrg.mVec128.m128_f32[3];
      v55 = v55 - v14->mVec128.m128_f32[0];
      v56 = v56 - v14->mVec128.m128_f32[1];
      v57[0] = v57[0] - v14->mVec128.m128_f32[2];
      v58 = v58 - v13->mVec128.m128_f32[0];
      v59 = v59 - v13->mVec128.m128_f32[1];
      v60[0] = v60[0] - v13->mVec128.m128_f32[2];
      v25 = 1;
      if ( !v24 || m_data->m_aabbMinOrg.mVec128.m128_f32[0] > *(float *)&v45 )
        v25 = 0;
      if ( v54 > m_data->m_aabbMaxOrg.mVec128.m128_f32[2] || m_data->m_aabbMinOrg.mVec128.m128_f32[2] > v48 )
        v25 = 0;
      if ( v53 > m_data->m_aabbMaxOrg.mVec128.m128_f32[1]
        || m_data->m_aabbMinOrg.mVec128.m128_f32[1] > *((float *)&v45 + 1) )
      {
        v25 = 0;
      }
      if ( !v25 )
        goto LABEL_48;
      v26 = raySource->mVec128.m128_f32[1];
      v27 = (float)(*(&v55 + 4 * v42) - raySource->mVec128.m128_f32[0]) * v49;
      v28 = (float)(*(&v58 - 4 * v42) - raySource->mVec128.m128_f32[0]) * v49;
      v29 = (float)(v60[-4 * v43 - 1] - v26) * v23;
      v30 = (float)(v57[4 * v43 - 1] - v26) * v23;
      if ( v27 > v29 || v30 > v28 )
        goto LABEL_48;
      if ( v30 > v27 )
        v27 = (float)(v57[4 * v43 - 1] - v26) * v23;
      if ( v28 > v29 )
        v28 = (float)(v60[-4 * v43 - 1] - v26) * v23;
      v31 = raySource->mVec128.m128_f32[2];
      v32 = (float)(v60[-4 * v44] - v31) * v51;
      v33 = (float)(v57[4 * v44] - v31) * v51;
      if ( v27 > v32 || v33 > v28 )
        goto LABEL_48;
      if ( v33 > v27 )
        v27 = (float)(v57[4 * v44] - v31) * v51;
      if ( v28 > v32 )
        v28 = (float)(v60[-4 * v44] - v31) * v51;
      if ( v41 > v27 && v28 > 0.0 )
        v34 = 1;
      else
LABEL_48:
        v34 = 0;
      v35 = v34;
      v37 = m_data->m_escapeIndex == -1;
      if ( m_data->m_escapeIndex != -1 )
        goto LABEL_52;
      if ( v34 )
        break;
      v13 = aabbMin;
LABEL_59:
      if ( !v37 )
      {
        m_escapeIndex = m_data->m_escapeIndex;
        m_data += m_escapeIndex;
        v38 += m_escapeIndex;
        goto LABEL_54;
      }
LABEL_53:
      ++m_data;
      ++v38;
LABEL_54:
      if ( v38 >= this->m_curNodeIndex )
        goto LABEL_55;
    }
    nodeCallback->processNode(nodeCallback, m_data->m_subPart, m_data->m_triangleIndex);
    v23 = v50;
    v18 = v52;
    v14 = aabbMax;
LABEL_52:
    v13 = aabbMin;
    if ( v35 )
      goto LABEL_53;
    goto LABEL_59;
  }
LABEL_55:
  if ( maxIterations < v39 )
    maxIterations = v39;
}
