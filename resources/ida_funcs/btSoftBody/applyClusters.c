void __thiscall btSoftBody::applyClusters(btSoftBody *this, btSoftBody *drift, bool drifta)
{
  CProfileNode *v3; // esi
  int RecursionCounter; // eax
  btSoftBody *v5; // ebx
  int m_size; // esi
  _QWORD *v7; // eax
  int v8; // ecx
  int v9; // edi
  _DWORD *v10; // eax
  bool v11; // dl
  const vostok::math::float4x4 *v12; // xmm3_4
  int i; // ecx
  btSoftBody::Cluster *v14; // eax
  float v15; // xmm0_4
  float v16; // xmm0_4
  int p_m_x; // ecx
  btSoftBody::Cluster *v18; // esi
  int m_ndimpulses; // eax
  float *m128_f32; // eax
  float sdt; // xmm0_4
  float *v22; // eax
  float v23; // xmm0_4
  int v24; // edi
  float v25; // xmm6_4
  float v26; // xmm4_4
  float v27; // xmm7_4
  int v28; // ebx
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm5_4
  float v32; // xmm3_4
  int v33; // ecx
  float v34; // xmm1_4
  float *v35; // eax
  float v36; // xmm2_4
  int v37; // edi
  int v38; // edx
  float *v39; // eax
  unsigned int v40; // esi
  float v41; // xmm1_4
  float *v42; // ecx
  float v43; // xmm0_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  btSoftBody::Node *m_data; // ecx
  float v48; // xmm4_4
  float *v49; // ecx
  float v50; // xmm0_4
  float v51; // xmm2_4
  float v52; // xmm1_4
  float v53; // xmm0_4
  float v54; // xmm1_4
  float *v55; // ecx
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  float v59; // xmm1_4
  float v60; // xmm0_4
  float v61; // xmm1_4
  float v62; // xmm2_4
  int v63; // edx
  float v64; // xmm1_4
  float *v65; // eax
  float v66; // xmm0_4
  float v67; // xmm1_4
  float v68; // xmm2_4
  CProfileNode *v69; // esi
  bool v70; // zf
  int *p_RecursionCounter; // edi
  int v72; // [esp+13Ch] [ebp-58h]
  float *v73; // [esp+13Ch] [ebp-58h]
  int v74; // [esp+140h] [ebp-54h]
  float v75; // [esp+144h] [ebp-50h]
  float v76; // [esp+148h] [ebp-4Ch]
  float v77; // [esp+14Ch] [ebp-48h]
  float v78; // [esp+158h] [ebp-3Ch]
  char *ptr; // [esp+178h] [ebp-1Ch]
  char *v80; // [esp+18Ch] [ebp-8h]

  v3 = CProfileManager::CurrentNode;
  if ( CProfileManager::CurrentNode->Name != "ApplyClusters" )
  {
    CProfileManager::CurrentNode = CProfileNode::Get_Sub_Node((const char *)this);
    v3 = CProfileManager::CurrentNode;
  }
  RecursionCounter = v3->RecursionCounter;
  ++v3->TotalCalls;
  v3->RecursionCounter = RecursionCounter + 1;
  if ( !RecursionCounter )
    v3->StartTime = btClock::getTimeMicroseconds((btClock *)1);
  v80 = 0;
  ptr = 0;
  v5 = drift;
  m_size = drift->m_nodes.m_size;
  v74 = m_size;
  if ( m_size > 0 )
  {
    ++gNumAlignedAllocs;
    v80 = (char *)sAlignedAllocFunc(16 * m_size, 16);
    v7 = v80;
    v8 = m_size;
    do
    {
      if ( v7 )
      {
        *v7 = 0;
        v7[1] = 0;
      }
      v7 += 2;
      --v8;
    }
    while ( v8 );
  }
  v9 = drift->m_nodes.m_size;
  if ( v9 > 0 )
  {
    ++gNumAlignedAllocs;
    ptr = (char *)sAlignedAllocFunc(4 * v9, 16);
    v10 = ptr;
    do
    {
      if ( v10 )
        *v10 = 0;
      ++v10;
      --v9;
    }
    while ( v9 );
  }
  v11 = drifta;
  v12 = clear_value;
  if ( drifta )
  {
    for ( i = 0; i < drift->m_clusters.m_size; ++i )
    {
      v14 = drift->m_clusters.m_data[i];
      if ( v14->m_ndimpulses )
      {
        v15 = *(float *)&v12 / (float)v14->m_ndimpulses;
        v14->m_dimpulses[0].mVec128.m128_f32[0] = v14->m_dimpulses[0].mVec128.m128_f32[0] * v15;
        v14->m_dimpulses[0].mVec128.m128_f32[1] = v14->m_dimpulses[0].mVec128.m128_f32[1] * v15;
        v14->m_dimpulses[0].mVec128.m128_f32[2] = v14->m_dimpulses[0].mVec128.m128_f32[2] * v15;
        v16 = *(float *)&v12 / (float)v14->m_ndimpulses;
        v14->m_dimpulses[1].mVec128.m128_f32[0] = v14->m_dimpulses[1].mVec128.m128_f32[0] * v16;
        v14->m_dimpulses[1].mVec128.m128_f32[1] = v14->m_dimpulses[1].mVec128.m128_f32[1] * v16;
        v14->m_dimpulses[1].mVec128.m128_f32[2] = v14->m_dimpulses[1].mVec128.m128_f32[2] * v16;
      }
    }
  }
  p_m_x = 0;
  v72 = 0;
  if ( drift->m_clusters.m_size > 0 )
  {
    do
    {
      v18 = v5->m_clusters.m_data[p_m_x];
      if ( v11 )
        m_ndimpulses = v18->m_ndimpulses;
      else
        m_ndimpulses = v18->m_nvimpulses;
      if ( m_ndimpulses > 0 )
      {
        m128_f32 = v18->m_dimpulses[0].mVec128.m128_f32;
        if ( !v11 )
          m128_f32 = v18->m_vimpulses[0].mVec128.m128_f32;
        sdt = v5->m_sst.sdt;
        v75 = sdt * *m128_f32;
        v76 = m128_f32[1] * sdt;
        v77 = m128_f32[2] * sdt;
        v22 = v18->m_dimpulses[1].mVec128.m128_f32;
        if ( !v11 )
          v22 = v18->m_vimpulses[1].mVec128.m128_f32;
        v23 = v5->m_sst.sdt;
        v24 = 0;
        v25 = v23 * *v22;
        v26 = v22[1] * v23;
        v78 = v26;
        v27 = v22[2] * v23;
        if ( v18->m_nodes.m_size > 0 )
        {
          while ( 1 )
          {
            v28 = (int)&v18->m_nodes.m_data[v24];
            v29 = *(float *)(*(_DWORD *)v28 + 24) - v18->m_com.mVec128.m128_f32[2];
            v30 = *(float *)(*(_DWORD *)v28 + 20) - v18->m_com.mVec128.m128_f32[1];
            v31 = *(float *)(*(_DWORD *)v28 + 16) - v18->m_com.mVec128.m128_f32[0];
            v32 = (float)((float)(v29 * v26) - (float)(v30 * v27)) + v75;
            v33 = (signed int)(*(_DWORD *)v28 - (unsigned int)drift->m_nodes.m_data) / 112;
            v34 = v18->m_masses.m_data[v24];
            v35 = (float *)&v80[16 * v33];
            v35[1] = v35[1] + (float)((float)((float)((float)(v27 * v31) - (float)(v29 * v25)) + v76) * v34);
            v36 = v35[2];
            *v35 = (float)(v32 * v34) + *v35;
            v35[2] = v36 + (float)((float)((float)((float)(v30 * v25) - (float)(v78 * v31)) + v77) * v34);
            ++v24;
            *(float *)&ptr[4 * v33] = v34 + *(float *)&ptr[4 * v33];
            if ( v24 >= v18->m_nodes.m_size )
              break;
            v26 = v78;
          }
          v12 = clear_value;
          v5 = drift;
          p_m_x = v72;
          v11 = drifta;
        }
      }
      v72 = ++p_m_x;
    }
    while ( p_m_x < v5->m_clusters.m_size );
    m_size = v74;
  }
  v37 = 0;
  if ( m_size >= 4 )
  {
    v73 = (float *)(ptr + 8);
    v38 = 0;
    v39 = (float *)(v80 + 24);
    v40 = ((unsigned int)(m_size - 4) >> 2) + 1;
    v37 = 4 * v40;
    do
    {
      v41 = *(v73 - 2);
      if ( v41 > 0.0 )
      {
        v42 = v5->m_nodes.m_data[v38].m_x.mVec128.m128_f32;
        v43 = *(float *)&v12 / v41;
        v44 = *(v39 - 5) * (float)(*(float *)&v12 / v41);
        v45 = *(v39 - 4) * v43;
        *v42 = *v42 + (float)(*(v39 - 6) * v43);
        v42[1] = v44 + v42[1];
        v42[2] = v45 + v42[2];
      }
      v46 = *(v73 - 1);
      if ( v46 > 0.0 )
      {
        m_data = v5->m_nodes.m_data;
        v48 = m_data[v38 + 1].m_x.mVec128.m128_f32[0];
        v49 = m_data[v38 + 1].m_x.mVec128.m128_f32;
        v50 = *(float *)&v12 / v46;
        v51 = *(v39 - 2) * (float)(*(float *)&v12 / v46);
        v52 = *(v39 - 1) * (float)(*(float *)&v12 / v46);
        v53 = v50 * *v39;
        *v49 = v48 + v51;
        v49[1] = v52 + v49[1];
        v49[2] = v53 + v49[2];
      }
      v54 = *v73;
      if ( *v73 > 0.0 )
      {
        v55 = v5->m_nodes.m_data[v38 + 2].m_x.mVec128.m128_f32;
        v56 = *(float *)&v12 / v54;
        v57 = v39[3] * (float)(*(float *)&v12 / v54);
        v58 = v39[4] * v56;
        *v55 = *v55 + (float)(v39[2] * v56);
        v55[1] = v57 + v55[1];
        v55[2] = v58 + v55[2];
      }
      p_m_x = (int)v73;
      v59 = v73[1];
      if ( v59 > 0.0 )
      {
        p_m_x = (int)&v5->m_nodes.m_data[v38 + 3].m_x;
        v60 = *(float *)&v12 / v59;
        v61 = v39[7] * (float)(*(float *)&v12 / v59);
        v62 = v39[8] * v60;
        *(float *)p_m_x = *(float *)p_m_x + (float)(v39[6] * v60);
        *(float *)(p_m_x + 4) = v61 + *(float *)(p_m_x + 4);
        *(float *)(p_m_x + 8) = v62 + *(float *)(p_m_x + 8);
      }
      v73 += 4;
      v39 += 16;
      v38 += 4;
      --v40;
    }
    while ( v40 );
    m_size = v74;
  }
  if ( v37 < m_size )
  {
    v63 = v37;
    p_m_x = (int)&v80[16 * v37 + 8];
    do
    {
      v64 = *(float *)&ptr[4 * v37];
      if ( v64 > 0.0 )
      {
        v65 = v5->m_nodes.m_data[v63].m_x.mVec128.m128_f32;
        v66 = *(float *)&v12 / v64;
        v67 = (float)(*(float *)(p_m_x - 4) * (float)(*(float *)&v12 / v64))
            + v5->m_nodes.m_data[v63].m_x.mVec128.m128_f32[1];
        v68 = (float)(*(float *)p_m_x * v66) + v5->m_nodes.m_data[v63].m_x.mVec128.m128_f32[2];
        *v65 = *v65 + (float)(*(float *)(p_m_x - 8) * v66);
        v65[1] = v67;
        v65[2] = v68;
      }
      ++v37;
      p_m_x += 16;
      ++v63;
    }
    while ( v37 < m_size );
  }
  if ( ptr )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(ptr);
  }
  if ( v80 )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(v80);
  }
  v69 = CProfileManager::CurrentNode;
  v70 = CProfileManager::CurrentNode->RecursionCounter-- == 1;
  p_RecursionCounter = &v69->RecursionCounter;
  if ( v70 && v69->TotalCalls )
  {
    v69->TotalTime = (double)(btClock::getTimeMicroseconds((btClock *)p_m_x) - v69->StartTime) * 0.001 + v69->TotalTime;
    v69 = CProfileManager::CurrentNode;
  }
  if ( !*p_RecursionCounter )
    CProfileManager::CurrentNode = v69->Parent;
}
