void __userpurge btQuantizedBvh::walkStacklessQuantizedTreeAgainstRay(
        const btVector3 *rayTarget@<edx>,
        btQuantizedBvh *this,
        btNodeOverlapCallback *nodeCallback,
        const btVector3 *raySource,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax,
        int startNodeIndex,
        int endNodeIndex)
{
  btQuantizedBvhNode *m_data; // ecx
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm6_4
  float v13; // xmm5_4
  float v14; // xmm4_4
  float v15; // xmm7_4
  float v16; // xmm6_4
  float v17; // xmm5_4
  float v18; // xmm4_4
  float v19; // xmm1_4
  float v20; // xmm4_4
  float v21; // xmm1_4
  float v22; // xmm6_4
  float v23; // xmm5_4
  float v24; // xmm4_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm7_4
  float v28; // xmm0_4
  float v29; // xmm4_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  unsigned __int16 v32; // di
  int v33; // esi
  int v34; // eax
  float v35; // xmm6_4
  float v36; // xmm7_4
  float v37; // xmm1_4
  float v38; // xmm4_4
  int v39; // eax
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm6_4
  float v45; // xmm0_4
  float v46; // xmm5_4
  float v47; // xmm1_4
  float v48; // xmm4_4
  float v49; // xmm6_4
  float v50; // xmm4_4
  float v51; // xmm1_4
  unsigned __int8 v52; // al
  int v53; // esi
  int v54; // eax
  bool v55; // [esp+Fh] [ebp-95h]
  int v56; // [esp+10h] [ebp-94h]
  float v57; // [esp+14h] [ebp-90h]
  float v58; // [esp+18h] [ebp-8Ch]
  float v59; // [esp+18h] [ebp-8Ch]
  float v60; // [esp+1Ch] [ebp-88h]
  float v61; // [esp+1Ch] [ebp-88h]
  float v62; // [esp+20h] [ebp-84h]
  unsigned __int16 v63; // [esp+28h] [ebp-7Ch]
  unsigned __int16 v64; // [esp+2Ah] [ebp-7Ah]
  unsigned __int16 v65; // [esp+2Ch] [ebp-78h]
  unsigned __int16 v66; // [esp+30h] [ebp-74h]
  unsigned __int16 v67; // [esp+32h] [ebp-72h]
  unsigned __int16 v68; // [esp+34h] [ebp-70h]
  float v69; // [esp+38h] [ebp-6Ch]
  float v70; // [esp+38h] [ebp-6Ch]
  btQuantizedBvhNode *v71; // [esp+3Ch] [ebp-68h]
  int v72; // [esp+40h] [ebp-64h]
  float v73; // [esp+48h] [ebp-5Ch]
  float v74; // [esp+48h] [ebp-5Ch]
  float v75; // [esp+4Ch] [ebp-58h]
  float v76; // [esp+50h] [ebp-54h]
  float v77; // [esp+54h] [ebp-50h]
  float v78; // [esp+58h] [ebp-4Ch]
  float v79; // [esp+5Ch] [ebp-48h]
  float v80; // [esp+64h] [ebp-40h]
  float v81; // [esp+68h] [ebp-3Ch]
  float v82; // [esp+6Ch] [ebp-38h]
  float v83; // [esp+70h] [ebp-34h]
  float v84; // [esp+74h] [ebp-30h]
  float v85; // [esp+78h] [ebp-2Ch]
  float v86[5]; // [esp+7Ch] [ebp-28h]
  BOOL v87; // [esp+90h] [ebp-14h]
  BOOL v88; // [esp+94h] [ebp-10h]
  BOOL v89; // [esp+98h] [ebp-Ch]
  int v90; // [esp+9Ch] [ebp-8h]
  float v91; // [esp+A0h] [ebp-4h]

  m_data = this->m_quantizedContiguousNodes.m_data;
  v9 = rayTarget->mVec128.m128_f32[2] - raySource->mVec128.m128_f32[2];
  v10 = rayTarget->mVec128.m128_f32[1] - raySource->mVec128.m128_f32[1];
  v69 = rayTarget->mVec128.m128_f32[0] - raySource->mVec128.m128_f32[0];
  v11 = s_bm_current_air_resistance;
  v12 = s_bm_current_air_resistance / fsqrt((float)((float)(v10 * v10) + (float)(v9 * v9)) + (float)(v69 * v69));
  v13 = v9 * v12;
  v14 = v10 * v12;
  v91 = (float)((float)((float)(v9 * v12) * v9) + (float)((float)(v10 * v12) * v10)) + (float)(v69 * (float)(v69 * v12));
  v56 = 0;
  v72 = 0;
  v71 = m_data;
  if ( (float)(v69 * v12) == 0.0 )
    v77 = FLOAT_9_9999998e17;
  else
    v77 = s_bm_current_air_resistance / (float)(v69 * v12);
  if ( v14 == 0.0 )
    v78 = FLOAT_9_9999998e17;
  else
    v78 = s_bm_current_air_resistance / v14;
  if ( v13 == 0.0 )
    v79 = FLOAT_9_9999998e17;
  else
    v79 = s_bm_current_air_resistance / v13;
  v87 = v77 < 0.0;
  v88 = v78 < 0.0;
  v89 = v79 < 0.0;
  v76 = raySource->mVec128.m128_f32[3];
  v15 = raySource->mVec128.m128_f32[0];
  v57 = raySource->mVec128.m128_f32[0];
  v62 = v76;
  if ( raySource->mVec128.m128_f32[0] > rayTarget->mVec128.m128_f32[0] )
    v15 = rayTarget->mVec128.m128_f32[0];
  v16 = raySource->mVec128.m128_f32[1];
  if ( v16 > rayTarget->mVec128.m128_f32[1] )
    v16 = rayTarget->mVec128.m128_f32[1];
  v17 = raySource->mVec128.m128_f32[2];
  if ( v17 > rayTarget->mVec128.m128_f32[2] )
    v17 = rayTarget->mVec128.m128_f32[2];
  if ( v76 > rayTarget->mVec128.m128_f32[3] )
    v76 = rayTarget->mVec128.m128_f32[3];
  if ( rayTarget->mVec128.m128_f32[0] > v57 )
    v57 = rayTarget->mVec128.m128_f32[0];
  v18 = raySource->mVec128.m128_f32[1];
  if ( rayTarget->mVec128.m128_f32[1] > v18 )
    v18 = rayTarget->mVec128.m128_f32[1];
  v19 = raySource->mVec128.m128_f32[2];
  if ( rayTarget->mVec128.m128_f32[2] > v19 )
    v19 = rayTarget->mVec128.m128_f32[2];
  if ( rayTarget->mVec128.m128_f32[3] > v62 )
    v62 = rayTarget->mVec128.m128_f32[3];
  v20 = v18 + aabbMax->mVec128.m128_f32[1];
  v21 = v19 + aabbMax->mVec128.m128_f32[2];
  v73 = aabbMin->mVec128.m128_f32[1] + v16;
  v22 = aabbMin->mVec128.m128_f32[2] + v17;
  v23 = aabbMax->mVec128.m128_f32[0] + v57;
  v80 = aabbMin->mVec128.m128_f32[0] + v15;
  v81 = v73;
  v82 = v22;
  v58 = v20;
  v24 = this->m_bvhAabbMin.mVec128.m128_f32[0];
  v60 = v21;
  v83 = v76;
  if ( v24 <= v80 )
    v24 = v80;
  v25 = v81;
  if ( this->m_bvhAabbMin.mVec128.m128_f32[1] > v81 )
    v25 = this->m_bvhAabbMin.mVec128.m128_f32[1];
  v26 = v82;
  if ( this->m_bvhAabbMin.mVec128.m128_f32[2] > v82 )
    v26 = this->m_bvhAabbMin.mVec128.m128_f32[2];
  if ( v24 > this->m_bvhAabbMax.mVec128.m128_f32[0] )
    v24 = this->m_bvhAabbMax.mVec128.m128_f32[0];
  if ( v25 > this->m_bvhAabbMax.mVec128.m128_f32[1] )
    v25 = this->m_bvhAabbMax.mVec128.m128_f32[1];
  if ( v26 > this->m_bvhAabbMax.mVec128.m128_f32[2] )
    v26 = this->m_bvhAabbMax.mVec128.m128_f32[2];
  v27 = v26 - this->m_bvhAabbMin.mVec128.m128_f32[2];
  v66 = (int)(float)(this->m_bvhQuantization.mVec128.m128_f32[0] * (float)(v24 - this->m_bvhAabbMin.mVec128.m128_f32[0]))
      & 0xFFFE;
  v28 = this->m_bvhAabbMin.mVec128.m128_f32[0];
  v67 = (int)(float)(this->m_bvhQuantization.mVec128.m128_f32[1] * (float)(v25 - this->m_bvhAabbMin.mVec128.m128_f32[1]))
      & 0xFFFE;
  v68 = (int)(float)(this->m_bvhQuantization.mVec128.m128_f32[2] * v27) & 0xFFFE;
  v80 = v23;
  v81 = v58;
  v82 = v60;
  v83 = v62;
  if ( v28 <= v23 )
    v29 = v80;
  else
    v29 = v28;
  v30 = v81;
  if ( this->m_bvhAabbMin.mVec128.m128_f32[1] > v81 )
    v30 = this->m_bvhAabbMin.mVec128.m128_f32[1];
  v31 = v82;
  if ( this->m_bvhAabbMin.mVec128.m128_f32[2] > v82 )
    v31 = this->m_bvhAabbMin.mVec128.m128_f32[2];
  if ( v29 > this->m_bvhAabbMax.mVec128.m128_f32[0] )
    v29 = this->m_bvhAabbMax.mVec128.m128_f32[0];
  if ( v30 > this->m_bvhAabbMax.mVec128.m128_f32[1] )
    v30 = this->m_bvhAabbMax.mVec128.m128_f32[1];
  if ( v31 > this->m_bvhAabbMax.mVec128.m128_f32[2] )
    v31 = this->m_bvhAabbMax.mVec128.m128_f32[2];
  v63 = (int)(float)((float)(this->m_bvhQuantization.mVec128.m128_f32[0]
                           * (float)(v29 - this->m_bvhAabbMin.mVec128.m128_f32[0]))
                   + s_bm_current_air_resistance)
      | 1;
  v64 = (int)(float)((float)(this->m_bvhQuantization.mVec128.m128_f32[1]
                           * (float)(v30 - this->m_bvhAabbMin.mVec128.m128_f32[1]))
                   + s_bm_current_air_resistance)
      | 1;
  v65 = (int)(float)((float)(this->m_bvhQuantization.mVec128.m128_f32[2]
                           * (float)(v31 - this->m_bvhAabbMin.mVec128.m128_f32[2]))
                   + s_bm_current_air_resistance)
      | 1;
  if ( startNodeIndex > 0 )
  {
    do
    {
      ++v72;
      v90 = 0;
      v32 = m_data->m_quantizedAabbMin[2];
      v33 = m_data->m_quantizedAabbMax[0] >= v66
         && v63 >= m_data->m_quantizedAabbMin[0]
         && v65 >= v32
         && v64 >= m_data->m_quantizedAabbMin[1]
         && m_data->m_quantizedAabbMax[1] >= v67
         && m_data->m_quantizedAabbMax[2] >= v68;
      v55 = m_data->m_escapeIndexOrTriangleIndex >= 0;
      if ( (v33 | -((v33 | -v33) >> 31)) >= 0 )
      {
        v53 = v90;
      }
      else
      {
        v34 = m_data->m_quantizedAabbMax[0];
        v70 = v11 / this->m_bvhQuantization.mVec128.m128_f32[2];
        v35 = v11 / this->m_bvhQuantization.mVec128.m128_f32[0];
        v36 = v11 / this->m_bvhQuantization.mVec128.m128_f32[1];
        v74 = this->m_bvhAabbMin.mVec128.m128_f32[1] + (float)((float)m_data->m_quantizedAabbMin[1] * v36);
        v75 = this->m_bvhAabbMin.mVec128.m128_f32[2] + (float)((float)v32 * v70);
        v37 = this->m_bvhAabbMin.mVec128.m128_f32[0];
        v80 = v37 + (float)((float)m_data->m_quantizedAabbMin[0] * v35);
        v81 = v74;
        v82 = v75;
        v38 = (float)v34;
        v39 = m_data->m_quantizedAabbMax[1];
        v83 = 0.0;
        v40 = v80 - aabbMax->mVec128.m128_f32[0];
        v59 = this->m_bvhAabbMin.mVec128.m128_f32[1] + (float)((float)v39 * v36);
        v61 = this->m_bvhAabbMin.mVec128.m128_f32[2] + (float)((float)m_data->m_quantizedAabbMax[2] * v70);
        v84 = v37 + (float)(v38 * v35);
        v85 = v59;
        v86[0] = v61;
        v86[1] = 0.0;
        v80 = v40;
        v81 = v74 - aabbMax->mVec128.m128_f32[1];
        v41 = v84 - aabbMin->mVec128.m128_f32[0];
        v82 = v75 - aabbMax->mVec128.m128_f32[2];
        v85 = v59 - aabbMin->mVec128.m128_f32[1];
        v42 = v61 - aabbMin->mVec128.m128_f32[2];
        v84 = v41;
        v43 = raySource->mVec128.m128_f32[0];
        v86[0] = v42;
        v44 = raySource->mVec128.m128_f32[1];
        v45 = (float)(*(&v80 + 4 * v87) - v43) * v77;
        v46 = (float)(*(&v84 - 4 * v87) - v43) * v77;
        v47 = (float)(v86[-4 * v88 - 1] - v44) * v78;
        v48 = (float)(*(&v81 + 4 * v88) - v44) * v78;
        if ( v45 > v47 || v48 > v46 )
          goto LABEL_68;
        if ( v48 > v45 )
          v45 = (float)(*(&v81 + 4 * v88) - v44) * v78;
        if ( v46 > v47 )
          v46 = (float)(v86[-4 * v88 - 1] - v44) * v78;
        v49 = raySource->mVec128.m128_f32[2];
        v50 = (float)(v86[-4 * v89] - v49) * v79;
        v51 = (float)(*(&v82 + 4 * v89) - v49) * v79;
        if ( v45 > v50 || v51 > v46 )
          goto LABEL_68;
        if ( v51 > v45 )
          v45 = (float)(*(&v82 + 4 * v89) - v49) * v79;
        if ( v46 > v50 )
          v46 = (float)(v86[-4 * v89] - v49) * v79;
        if ( v91 <= v45 || v46 <= 0.0 )
LABEL_68:
          v52 = 0;
        else
          v52 = 1;
        v53 = v52;
      }
      if ( v55 )
      {
        if ( !v53 )
          goto LABEL_75;
        nodeCallback->processNode(
          nodeCallback,
          m_data->m_escapeIndexOrTriangleIndex >> 21,
          ((unsigned int)&loc_1FFFFE + 1) & m_data->m_escapeIndexOrTriangleIndex);
        v11 = s_bm_current_air_resistance;
        m_data = v71;
      }
      if ( v53 )
        goto LABEL_77;
LABEL_75:
      if ( v55 )
      {
LABEL_77:
        ++m_data;
        ++v56;
        goto LABEL_78;
      }
      v54 = -m_data->m_escapeIndexOrTriangleIndex;
      m_data -= m_data->m_escapeIndexOrTriangleIndex;
      v56 += v54;
LABEL_78:
      v71 = m_data;
    }
    while ( v56 < startNodeIndex );
  }
  if ( maxIterations < v72 )
    maxIterations = v72;
}
