void __userpurge btQuantizedBvh::walkStacklessTreeAgainstRay(
        const btVector3 *raySource@<edi>,
        const btVector3 *rayTarget@<eax>,
        btQuantizedBvh *this,
        btNodeOverlapCallback *nodeCallback,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax,
        int startNodeIndex,
        int endNodeIndex)
{
  float v8; // xmm1_4
  float v9; // xmm7_4
  btOptimizedBvhNode *m_data; // esi
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm6_4
  float v14; // xmm5_4
  float v15; // xmm4_4
  const btVector3 *v16; // ebx
  float v17; // xmm1_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm5_4
  char v23; // al
  float v24; // xmm4_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  int v32; // eax
  bool v33; // bl
  int m_escapeIndex; // eax
  int v35; // [esp+318h] [ebp-74h]
  int v36; // [esp+31Ch] [ebp-70h]
  float v37; // [esp+320h] [ebp-6Ch]
  float v38; // [esp+324h] [ebp-68h]
  int v39; // [esp+328h] [ebp-64h]
  float v40; // [esp+32Ch] [ebp-60h]
  BOOL v41; // [esp+330h] [ebp-5Ch]
  BOOL v42; // [esp+334h] [ebp-58h]
  BOOL v43; // [esp+338h] [ebp-54h]
  btVector3 v44; // [esp+33Ch] [ebp-50h]
  float v45; // [esp+33Ch] [ebp-50h]
  float v46; // [esp+340h] [ebp-4Ch]
  float v47; // [esp+344h] [ebp-48h]
  unsigned __int64 v48; // [esp+34Ch] [ebp-40h]
  float v49; // [esp+34Ch] [ebp-40h]
  float v50; // [esp+350h] [ebp-3Ch]
  float v51; // [esp+354h] [ebp-38h]
  float v52; // [esp+35Ch] [ebp-30h]
  float v53; // [esp+360h] [ebp-2Ch]
  float v54; // [esp+360h] [ebp-2Ch]
  float v55; // [esp+364h] [ebp-28h]
  unsigned __int64 v56; // [esp+36Ch] [ebp-20h]
  unsigned __int64 v57; // [esp+374h] [ebp-18h]
  unsigned __int64 v58; // [esp+37Ch] [ebp-10h]
  unsigned __int64 v59; // [esp+384h] [ebp-8h]

  v8 = rayTarget->mVec128.m128_f32[0];
  v44.mVec128 = raySource->mVec128;
  v9 = raySource->mVec128.m128_f32[0];
  m_data = this->m_contiguousNodes.m_data;
  v48 = raySource->mVec128.m128_u64[0];
  v35 = 0;
  v36 = 0;
  if ( raySource->mVec128.m128_f32[0] > rayTarget->mVec128.m128_f32[0] )
    v9 = rayTarget->mVec128.m128_f32[0];
  v11 = raySource->mVec128.m128_f32[1];
  if ( v44.mVec128.m128_f32[1] > rayTarget->mVec128.m128_f32[1] )
    v11 = rayTarget->mVec128.m128_f32[1];
  v12 = raySource->mVec128.m128_f32[2];
  if ( v44.mVec128.m128_f32[2] > rayTarget->mVec128.m128_f32[2] )
    v12 = rayTarget->mVec128.m128_f32[2];
  v13 = raySource->mVec128.m128_f32[0];
  if ( v8 > *(float *)&v48 )
    v13 = rayTarget->mVec128.m128_f32[0];
  v14 = raySource->mVec128.m128_f32[1];
  if ( rayTarget->mVec128.m128_f32[1] > *((float *)&v48 + 1) )
    v14 = rayTarget->mVec128.m128_f32[1];
  v15 = raySource->mVec128.m128_f32[2];
  if ( rayTarget->mVec128.m128_f32[2] > v44.mVec128.m128_f32[2] )
    v15 = rayTarget->mVec128.m128_f32[2];
  v16 = aabbMax;
  v45 = aabbMin->mVec128.m128_f32[0] + v9;
  v49 = aabbMax->mVec128.m128_f32[0] + v13;
  v50 = aabbMax->mVec128.m128_f32[1] + v14;
  v51 = aabbMax->mVec128.m128_f32[2] + v15;
  v46 = v11 + aabbMin->mVec128.m128_f32[1];
  v47 = v12 + aabbMin->mVec128.m128_f32[2];
  v38 = v8 - raySource->mVec128.m128_f32[0];
  v17 = rayTarget->mVec128.m128_f32[2] - raySource->mVec128.m128_f32[2];
  v53 = rayTarget->mVec128.m128_f32[1] - raySource->mVec128.m128_f32[1];
  v37 = 1.0 / sqrtf((float)((float)(v53 * v53) + (float)(v17 * v17)) + (float)(v38 * v38));
  v18 = v53 * v37;
  v19 = v17 * v37;
  v40 = (float)((float)(v53 * (float)(v53 * v37)) + (float)(v17 * (float)(v17 * v37)))
      + (float)(v38 * (float)(v38 * v37));
  if ( (float)(v38 * v37) == 0.0 )
    v20 = 9.9999998e17;
  else
    v20 = *(float *)&clear_value / (float)(v38 * v37);
  v52 = v20;
  if ( v18 == 0.0 )
    v21 = 9.9999998e17;
  else
    v21 = *(float *)&clear_value / v18;
  v54 = v21;
  if ( v19 == 0.0 )
    v22 = 9.9999998e17;
  else
    v22 = *(float *)&clear_value / v19;
  v55 = v22;
  v41 = v20 < 0.0;
  v42 = v21 < 0.0;
  v43 = v22 < 0.0;
  if ( this->m_curNodeIndex > 0 )
  {
    while ( 1 )
    {
      v56 = m_data->m_aabbMinOrg.mVec128.m128_u64[0];
      v57 = m_data->m_aabbMinOrg.mVec128.m128_u64[1];
      v58 = m_data->m_aabbMaxOrg.mVec128.m128_u64[0];
      ++v36;
      v59 = m_data->m_aabbMaxOrg.mVec128.m128_u64[1];
      *(float *)&v56 = *(float *)&v56 - v16->mVec128.m128_f32[0];
      *((float *)&v56 + 1) = *((float *)&v56 + 1) - v16->mVec128.m128_f32[1];
      *(float *)&v57 = *(float *)&v57 - v16->mVec128.m128_f32[2];
      *(float *)&v58 = *(float *)&v58 - aabbMin->mVec128.m128_f32[0];
      *((float *)&v58 + 1) = *((float *)&v58 + 1) - aabbMin->mVec128.m128_f32[1];
      *(float *)&v59 = *(float *)&v59 - aabbMin->mVec128.m128_f32[2];
      v23 = 1;
      if ( v45 > m_data->m_aabbMaxOrg.mVec128.m128_f32[0] || m_data->m_aabbMinOrg.mVec128.m128_f32[0] > v49 )
        v23 = 0;
      if ( v47 > m_data->m_aabbMaxOrg.mVec128.m128_f32[2] || m_data->m_aabbMinOrg.mVec128.m128_f32[2] > v51 )
        v23 = 0;
      if ( v46 > m_data->m_aabbMaxOrg.mVec128.m128_f32[1] )
        goto LABEL_49;
      if ( m_data->m_aabbMinOrg.mVec128.m128_f32[1] > v50 )
        goto LABEL_49;
      if ( !v23 )
        goto LABEL_49;
      v24 = raySource->mVec128.m128_f32[1];
      v25 = (float)(*((float *)&v56 + 4 * v41) - raySource->mVec128.m128_f32[0]) * v20;
      v26 = (float)(((float *)&v58 - 4 * v42)[1] - v24) * v21;
      v27 = (float)(*((float *)&v58 - 4 * v41) - raySource->mVec128.m128_f32[0]) * v20;
      v28 = (float)(*((float *)&v56 + 4 * v42 + 1) - v24) * v21;
      if ( v25 > v26 || v28 > v27 )
        goto LABEL_49;
      if ( v28 > v25 )
        v25 = (float)(*((float *)&v56 + 4 * v42 + 1) - v24) * v21;
      if ( v27 > v26 )
        v27 = (float)(((float *)&v58 - 4 * v42)[1] - v24) * v21;
      v29 = raySource->mVec128.m128_f32[2];
      v30 = (float)(*((float *)&v59 - 4 * v43) - v29) * v22;
      v31 = (float)(*((float *)&v57 + 4 * v43) - v29) * v22;
      if ( v25 > v30 || v31 > v27 )
        goto LABEL_49;
      if ( v31 > v25 )
        v25 = (float)(*((float *)&v57 + 4 * v43) - v29) * v22;
      if ( v27 > v30 )
        v27 = (float)(*((float *)&v59 - 4 * v43) - v29) * v22;
      if ( v40 > v25 && v27 > 0.0 )
        LOBYTE(v32) = 1;
      else
LABEL_49:
        LOBYTE(v32) = 0;
      v32 = (unsigned __int8)v32;
      v33 = m_data->m_escapeIndex == -1;
      v39 = (unsigned __int8)v32;
      if ( m_data->m_escapeIndex != -1 )
        goto LABEL_53;
      if ( (_BYTE)v32 )
        break;
LABEL_54:
      if ( !v33 )
      {
        m_escapeIndex = m_data->m_escapeIndex;
        m_data += m_escapeIndex;
        v35 += m_escapeIndex;
        goto LABEL_57;
      }
LABEL_56:
      ++m_data;
      ++v35;
LABEL_57:
      if ( v35 >= this->m_curNodeIndex )
        goto LABEL_58;
      v16 = aabbMax;
    }
    nodeCallback->processNode(nodeCallback, m_data->m_subPart, m_data->m_triangleIndex);
    v22 = v55;
    v21 = v54;
    v20 = v52;
    v32 = v39;
LABEL_53:
    if ( v32 )
      goto LABEL_56;
    goto LABEL_54;
  }
LABEL_58:
  if ( maxIterations < v36 )
    maxIterations = v36;
}
