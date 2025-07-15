void __usercall btPolyhedralContactClipping::clipFace(
        btAlignedObjectArray<btVector3> *ppVtxOut@<esi>,
        const btAlignedObjectArray<btVector3> *pVtxIn,
        const btVector3 *planeNormalWS,
        float planeEqWS)
{
  int m_size; // ecx
  btVector3 *m_data; // eax
  float v6; // xmm6_4
  float v7; // xmm5_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm4_4
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  btVector3 *v14; // ebx
  int v15; // edx
  btVector3 *v16; // ecx
  int v17; // edi
  btVector3 *v18; // eax
  btVector3 *v19; // eax
  float v20; // xmm3_4
  int v21; // eax
  btVector3 *v22; // ebx
  int v23; // edx
  btVector3 *v24; // ecx
  int v25; // edi
  btVector3 *v26; // eax
  btVector3 *v27; // eax
  btVector3 *v28; // eax
  unsigned __int64 v29; // xmm0_8
  int m_capacity; // ecx
  int v31; // eax
  float v32; // xmm3_4
  int v33; // eax
  btVector3 *v34; // ebx
  int v35; // edx
  btVector3 *v36; // ecx
  int v37; // edi
  btVector3 *v38; // eax
  btVector3 *v39; // eax
  btVector3 *v40; // eax
  int v41; // eax
  int v42; // ecx
  int v43; // eax
  int v44; // edx
  btVector3 *v45; // ecx
  int v46; // edi
  btVector3 *v47; // eax
  btVector3 *v48; // eax
  bool v49; // cc
  int v50; // [esp+11Ch] [ebp-4Ch]
  int v51; // [esp+11Ch] [ebp-4Ch]
  int v52; // [esp+11Ch] [ebp-4Ch]
  int v53; // [esp+11Ch] [ebp-4Ch]
  int v54; // [esp+120h] [ebp-48h]
  int v55; // [esp+124h] [ebp-44h]
  btVector3 v56; // [esp+128h] [ebp-40h]
  unsigned __int64 v57; // [esp+138h] [ebp-30h]
  unsigned __int64 v58; // [esp+148h] [ebp-20h]
  unsigned __int64 v59; // [esp+158h] [ebp-10h]

  m_size = pVtxIn->m_size;
  v55 = m_size;
  if ( m_size >= 2 )
  {
    m_data = pVtxIn->m_data;
    v57 = m_data[m_size - 1].mVec128.m128_u64[0];
    v6 = *((float *)&v57 + 1);
    v7 = m_data[m_size - 1].mVec128.m128_f32[2];
    v8 = (float)((float)((float)(planeNormalWS->mVec128.m128_f32[1] * *((float *)&v57 + 1))
                       + (float)(planeNormalWS->mVec128.m128_f32[2] * v7))
               + (float)(planeNormalWS->mVec128.m128_f32[0] * *(float *)&v57))
       + planeEqWS;
    v54 = 0;
    while ( 1 )
    {
      v56.mVec128 = (__m128)pVtxIn->m_data[v54];
      v9 = pVtxIn->m_data[v54].mVec128.m128_f32[1];
      v10 = (float)((float)((float)(planeNormalWS->mVec128.m128_f32[0] * v56.mVec128.m128_f32[0])
                          + (float)(planeNormalWS->mVec128.m128_f32[1] * v56.mVec128.m128_f32[1]))
                  + (float)(planeNormalWS->mVec128.m128_f32[2] * v56.mVec128.m128_f32[2]))
          + planeEqWS;
      if ( v8 >= 0.0 )
      {
        if ( v10 >= 0.0 )
          goto LABEL_89;
        m_capacity = ppVtxOut->m_capacity;
        v31 = ppVtxOut->m_size;
        v32 = v8 / (float)(v8 - v10);
        if ( v31 == m_capacity )
        {
          v33 = v31 ? 2 * v31 : 1;
          v52 = v33;
          if ( m_capacity < v33 )
          {
            if ( v33 )
            {
              ++gNumAlignedAllocs;
              v34 = (btVector3 *)sAlignedAllocFunc(16 * v33, 16);
            }
            else
            {
              v34 = 0;
            }
            if ( ppVtxOut->m_size > 0 )
            {
              v35 = 0;
              v36 = v34;
              v37 = ppVtxOut->m_size;
              do
              {
                if ( v36 )
                {
                  v38 = ppVtxOut->m_data;
                  v36->mVec128.m128_u64[0] = v38[v35].mVec128.m128_u64[0];
                  v36->mVec128.m128_u64[1] = v38[v35].mVec128.m128_u64[1];
                }
                ++v35;
                ++v36;
                --v37;
              }
              while ( v37 );
            }
            v39 = ppVtxOut->m_data;
            if ( v39 )
            {
              if ( ppVtxOut->m_ownsMemory )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(v39);
              }
              ppVtxOut->m_data = 0;
            }
            ppVtxOut->m_ownsMemory = 1;
            ppVtxOut->m_data = v34;
            ppVtxOut->m_capacity = v52;
          }
        }
        v40 = &ppVtxOut->m_data[ppVtxOut->m_size];
        if ( v40 )
        {
          *((float *)&v59 + 1) = (float)((float)(v9 - v6) * v32) + v6;
          *(float *)&v59 = (float)((float)(v56.mVec128.m128_f32[0] - *(float *)&v57) * v32) + *(float *)&v57;
          v40->mVec128.m128_u64[0] = v59;
          v40->mVec128.m128_u64[1] = COERCE_UNSIGNED_INT((float)((float)(v56.mVec128.m128_f32[2] - v7) * v32) + v7);
        }
        v41 = ++ppVtxOut->m_size;
        v42 = ppVtxOut->m_capacity;
        if ( v41 == v42 )
        {
          v43 = v41 ? 2 * v41 : 1;
          v53 = v43;
          if ( v42 < v43 )
          {
            if ( v43 )
            {
              ++gNumAlignedAllocs;
              v14 = (btVector3 *)sAlignedAllocFunc(16 * v43, 16);
            }
            else
            {
              v14 = 0;
            }
            if ( ppVtxOut->m_size > 0 )
            {
              v44 = 0;
              v45 = v14;
              v46 = ppVtxOut->m_size;
              do
              {
                if ( v45 )
                {
                  v47 = ppVtxOut->m_data;
                  v45->mVec128.m128_u64[0] = v47[v44].mVec128.m128_u64[0];
                  v45->mVec128.m128_u64[1] = v47[v44].mVec128.m128_u64[1];
                }
                ++v44;
                ++v45;
                --v46;
              }
              while ( v46 );
            }
            v48 = ppVtxOut->m_data;
            if ( v48 )
            {
              if ( ppVtxOut->m_ownsMemory )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(v48);
              }
              ppVtxOut->m_data = 0;
            }
            ppVtxOut->m_capacity = v53;
            goto LABEL_84;
          }
        }
      }
      else
      {
        v11 = ppVtxOut->m_capacity;
        v12 = ppVtxOut->m_size;
        if ( v10 >= 0.0 )
        {
          v20 = v8 / (float)(v8 - v10);
          if ( v12 == v11 )
          {
            v21 = v12 ? 2 * v12 : 1;
            v51 = v21;
            if ( v11 < v21 )
            {
              if ( v21 )
              {
                ++gNumAlignedAllocs;
                v22 = (btVector3 *)sAlignedAllocFunc(16 * v21, 16);
              }
              else
              {
                v22 = 0;
              }
              if ( ppVtxOut->m_size > 0 )
              {
                v23 = 0;
                v24 = v22;
                v25 = ppVtxOut->m_size;
                do
                {
                  if ( v24 )
                  {
                    v26 = ppVtxOut->m_data;
                    v24->mVec128.m128_u64[0] = v26[v23].mVec128.m128_u64[0];
                    v24->mVec128.m128_u64[1] = v26[v23].mVec128.m128_u64[1];
                  }
                  ++v23;
                  ++v24;
                  --v25;
                }
                while ( v25 );
              }
              v27 = ppVtxOut->m_data;
              if ( v27 )
              {
                if ( ppVtxOut->m_ownsMemory )
                {
                  ++gNumAlignedFree;
                  sAlignedFreeFunc(v27);
                }
                ppVtxOut->m_data = 0;
              }
              ppVtxOut->m_ownsMemory = 1;
              ppVtxOut->m_data = v22;
              ppVtxOut->m_capacity = v51;
            }
          }
          v28 = &ppVtxOut->m_data[ppVtxOut->m_size];
          if ( !v28 )
            goto LABEL_88;
          *((float *)&v58 + 1) = (float)((float)(v9 - v6) * v20) + v6;
          *(float *)&v58 = (float)((float)(v56.mVec128.m128_f32[0] - *(float *)&v57) * v20) + *(float *)&v57;
          v28->mVec128.m128_u64[0] = v58;
          v29 = COERCE_UNSIGNED_INT((float)((float)(v56.mVec128.m128_f32[2] - v7) * v20) + v7);
          goto LABEL_87;
        }
        if ( v12 == v11 )
        {
          v13 = 2 * v12;
          if ( !v12 )
            v13 = 1;
          v50 = v13;
          if ( v11 < v13 )
          {
            if ( v13 )
            {
              ++gNumAlignedAllocs;
              v14 = (btVector3 *)sAlignedAllocFunc(16 * v13, 16);
            }
            else
            {
              v14 = 0;
            }
            if ( ppVtxOut->m_size > 0 )
            {
              v15 = 0;
              v16 = v14;
              v17 = ppVtxOut->m_size;
              do
              {
                if ( v16 )
                {
                  v18 = ppVtxOut->m_data;
                  v16->mVec128.m128_u64[0] = v18[v15].mVec128.m128_u64[0];
                  v16->mVec128.m128_u64[1] = v18[v15].mVec128.m128_u64[1];
                }
                ++v15;
                ++v16;
                --v17;
              }
              while ( v17 );
              v13 = v50;
            }
            v19 = ppVtxOut->m_data;
            if ( v19 )
            {
              if ( ppVtxOut->m_ownsMemory )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(v19);
              }
              ppVtxOut->m_data = 0;
            }
            ppVtxOut->m_capacity = v13;
LABEL_84:
            ppVtxOut->m_ownsMemory = 1;
            ppVtxOut->m_data = v14;
          }
        }
      }
      v28 = &ppVtxOut->m_data[ppVtxOut->m_size];
      if ( v28 )
      {
        v28->mVec128.m128_u64[0] = v56.mVec128.m128_u64[0];
        v29 = v56.mVec128.m128_u64[1];
LABEL_87:
        v28->mVec128.m128_u64[1] = v29;
      }
LABEL_88:
      ++ppVtxOut->m_size;
LABEL_89:
      v49 = v54 + 1 < v55;
      LODWORD(v57) = v56.mVec128.m128_i32[0];
      v8 = v10;
      ++v54;
      if ( !v49 )
        return;
      v7 = v56.mVec128.m128_f32[2];
      v6 = v56.mVec128.m128_f32[1];
    }
  }
}
