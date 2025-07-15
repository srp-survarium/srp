void __cdecl btPolyhedralContactClipping::clipFace(
        const btAlignedObjectArray<btVector3> *pVtxIn,
        btAlignedObjectArray<btVector3> *ppVtxOut,
        const btVector3 *planeNormalWS,
        float planeEqWS)
{
  int m_size; // edx
  btVector3 *v5; // esi
  float v6; // xmm3_4
  btVector3 *v7; // esi
  float v8; // xmm4_4
  float v9; // xmm2_4
  float v10; // xmm6_4
  float v11; // xmm4_4
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  __m128 *v15; // ecx
  int v16; // edx
  btVector3 *v17; // esi
  float v18; // xmm3_4
  int v19; // eax
  __m128 *v20; // ecx
  int v21; // edx
  btVector3 *v22; // esi
  btVector3 *v23; // edi
  float *v24; // esi
  int m_capacity; // ecx
  int v26; // eax
  float v27; // xmm3_4
  int v28; // eax
  __m128 *p_mVec128; // ecx
  int v30; // edx
  btVector3 *v31; // esi
  btVector3 *v32; // edi
  int *v33; // edi
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  __m128 *v37; // ecx
  int v38; // edx
  btVector3 *v39; // esi
  int *v40; // edi
  int *v41; // esi
  int v42; // [esp+Ch] [ebp-54h]
  int v43; // [esp+Ch] [ebp-54h]
  int v44; // [esp+Ch] [ebp-54h]
  int v45; // [esp+14h] [ebp-4Ch]
  btVector3 *v46; // [esp+18h] [ebp-48h]
  btVector3 *v47; // [esp+18h] [ebp-48h]
  btVector3 *v48; // [esp+18h] [ebp-48h]
  int v49; // [esp+1Ch] [ebp-44h]
  float v50; // [esp+20h] [ebp-40h]
  float v51; // [esp+24h] [ebp-3Ch]
  float v52; // [esp+28h] [ebp-38h]
  float v53; // [esp+30h] [ebp-30h] BYREF
  float v54; // [esp+34h] [ebp-2Ch]
  float v55; // [esp+38h] [ebp-28h]
  int v56; // [esp+3Ch] [ebp-24h]
  float v57[4]; // [esp+40h] [ebp-20h] BYREF
  float v58; // [esp+50h] [ebp-10h]
  float v59; // [esp+54h] [ebp-Ch]
  float v60; // [esp+58h] [ebp-8h]
  int v61; // [esp+5Ch] [ebp-4h]

  m_size = pVtxIn->m_size;
  v49 = m_size;
  if ( m_size >= 2 )
  {
    v45 = 0;
    v5 = &pVtxIn->m_data[m_size - 1];
    v50 = v5->mVec128.m128_f32[0];
    v5 = (btVector3 *)((char *)v5 + 4);
    v51 = v5->mVec128.m128_f32[0];
    v5 = (btVector3 *)((char *)v5 + 4);
    v52 = v5->mVec128.m128_f32[0];
    v6 = (float)((float)((float)(planeNormalWS->mVec128.m128_f32[1] * v51)
                       + (float)(planeNormalWS->mVec128.m128_f32[2] * v5->mVec128.m128_f32[0]))
               + (float)(planeNormalWS->mVec128.m128_f32[0] * v50))
       + planeEqWS;
    while ( 1 )
    {
      v7 = &pVtxIn->m_data[v45];
      v8 = planeNormalWS->mVec128.m128_f32[0];
      v9 = planeNormalWS->mVec128.m128_f32[1];
      v10 = planeNormalWS->mVec128.m128_f32[2];
      v53 = v7->mVec128.m128_f32[0];
      v7 = (btVector3 *)((char *)v7 + 4);
      v54 = v7->mVec128.m128_f32[0];
      v7 = (btVector3 *)((char *)v7 + 4);
      v55 = v7->mVec128.m128_f32[0];
      v56 = v7->mVec128.m128_i32[1];
      v11 = (float)((float)((float)(v8 * v53) + (float)(v9 * v54)) + (float)(v10 * v55)) + planeEqWS;
      if ( v6 < 0.0 )
        break;
      if ( v11 < 0.0 )
      {
        m_capacity = ppVtxOut->m_capacity;
        v26 = ppVtxOut->m_size;
        v27 = v6 / (float)(v6 - v11);
        v58 = (float)((float)(v53 - v50) * v27) + v50;
        v59 = (float)((float)(v54 - v51) * v27) + v51;
        v60 = (float)((float)(v55 - v52) * v27) + v52;
        v61 = 0;
        if ( v26 == m_capacity )
        {
          v44 = v26 ? 2 * v26 : 1;
          if ( m_capacity < v44 )
          {
            if ( v44 )
              v48 = (btVector3 *)btAlignedAllocInternal(16 * v44);
            else
              v48 = 0;
            v28 = ppVtxOut->m_size;
            if ( v28 > 0 )
            {
              p_mVec128 = &v48->mVec128;
              v30 = 0;
              do
              {
                if ( p_mVec128 )
                {
                  v31 = &ppVtxOut->m_data[v30];
                  p_mVec128->m128_i32[0] = v31->mVec128.m128_i32[0];
                  v31 = (btVector3 *)((char *)v31 + 4);
                  p_mVec128->m128_i32[1] = v31->mVec128.m128_i32[0];
                  v31 = (btVector3 *)((char *)v31 + 4);
                  p_mVec128->m128_i32[2] = v31->mVec128.m128_i32[0];
                  p_mVec128->m128_i32[3] = v31->mVec128.m128_i32[1];
                }
                ++v30;
                ++p_mVec128;
                --v28;
              }
              while ( v28 );
            }
            if ( ppVtxOut->m_data )
            {
              if ( ppVtxOut->m_ownsMemory )
                btAlignedFreeInternal(ppVtxOut->m_data);
              ppVtxOut->m_data = 0;
            }
            ppVtxOut->m_data = v48;
            ppVtxOut->m_ownsMemory = 1;
            ppVtxOut->m_capacity = v44;
          }
        }
        v32 = &ppVtxOut->m_data[ppVtxOut->m_size];
        if ( v32 )
        {
          v32->mVec128.m128_f32[0] = v58;
          v33 = &v32->mVec128.m128_i32[1];
          *(float *)v33++ = v59;
          *(float *)v33 = v60;
          v33[1] = v61;
        }
        v34 = ++ppVtxOut->m_size;
        v35 = ppVtxOut->m_capacity;
        if ( v34 == v35 )
        {
          v42 = v34 ? 2 * v34 : 1;
          if ( v35 < v42 )
          {
            if ( v42 )
              v46 = (btVector3 *)btAlignedAllocInternal(16 * v42);
            else
              v46 = 0;
            v36 = ppVtxOut->m_size;
            if ( v36 > 0 )
            {
              v37 = &v46->mVec128;
              v38 = 0;
              do
              {
                if ( v37 )
                {
                  v39 = &ppVtxOut->m_data[v38];
                  v37->m128_i32[0] = v39->mVec128.m128_i32[0];
                  v39 = (btVector3 *)((char *)v39 + 4);
                  v37->m128_i32[1] = v39->mVec128.m128_i32[0];
                  v39 = (btVector3 *)((char *)v39 + 4);
                  v37->m128_i32[2] = v39->mVec128.m128_i32[0];
                  v37->m128_i32[3] = v39->mVec128.m128_i32[1];
                }
                ++v38;
                ++v37;
                --v36;
              }
              while ( v36 );
            }
LABEL_73:
            if ( ppVtxOut->m_data )
            {
              if ( ppVtxOut->m_ownsMemory )
                btAlignedFreeInternal(ppVtxOut->m_data);
              ppVtxOut->m_data = 0;
            }
            ppVtxOut->m_data = v46;
            ppVtxOut->m_ownsMemory = 1;
            ppVtxOut->m_capacity = v42;
          }
        }
LABEL_78:
        v23 = &ppVtxOut->m_data[ppVtxOut->m_size];
        if ( v23 )
        {
          v24 = &v53;
LABEL_80:
          v23->mVec128.m128_f32[0] = *v24;
          v41 = (int *)(v24 + 1);
          v40 = &v23->mVec128.m128_i32[1];
          *v40 = *v41++;
          *++v40 = *v41;
          v40[1] = v41[1];
        }
LABEL_81:
        ++ppVtxOut->m_size;
      }
      ++v45;
      v50 = v53;
      v51 = v54;
      v52 = v55;
      v6 = v11;
      if ( v45 >= v49 )
        return;
    }
    v12 = ppVtxOut->m_capacity;
    v13 = ppVtxOut->m_size;
    if ( v11 < 0.0 )
    {
      if ( v13 == v12 )
      {
        v42 = v13 ? 2 * v13 : 1;
        if ( v12 < v42 )
        {
          if ( v42 )
            v46 = (btVector3 *)btAlignedAllocInternal(16 * v42);
          else
            v46 = 0;
          v14 = ppVtxOut->m_size;
          if ( v14 > 0 )
          {
            v15 = &v46->mVec128;
            v16 = 0;
            do
            {
              if ( v15 )
              {
                v17 = &ppVtxOut->m_data[v16];
                v15->m128_i32[0] = v17->mVec128.m128_i32[0];
                v17 = (btVector3 *)((char *)v17 + 4);
                v15->m128_i32[1] = v17->mVec128.m128_i32[0];
                v17 = (btVector3 *)((char *)v17 + 4);
                v15->m128_i32[2] = v17->mVec128.m128_i32[0];
                v15->m128_i32[3] = v17->mVec128.m128_i32[1];
              }
              ++v16;
              ++v15;
              --v14;
            }
            while ( v14 );
          }
          goto LABEL_73;
        }
      }
      goto LABEL_78;
    }
    v18 = v6 / (float)(v6 - v11);
    v57[0] = (float)((float)(v53 - v50) * v18) + v50;
    v57[1] = (float)((float)(v54 - v51) * v18) + v51;
    v57[2] = (float)((float)(v55 - v52) * v18) + v52;
    v57[3] = 0.0;
    if ( v13 == v12 )
    {
      v43 = v13 ? 2 * v13 : 1;
      if ( v12 < v43 )
      {
        if ( v43 )
          v47 = (btVector3 *)btAlignedAllocInternal(16 * v43);
        else
          v47 = 0;
        v19 = ppVtxOut->m_size;
        if ( v19 > 0 )
        {
          v20 = &v47->mVec128;
          v21 = 0;
          do
          {
            if ( v20 )
            {
              v22 = &ppVtxOut->m_data[v21];
              v20->m128_i32[0] = v22->mVec128.m128_i32[0];
              v22 = (btVector3 *)((char *)v22 + 4);
              v20->m128_i32[1] = v22->mVec128.m128_i32[0];
              v22 = (btVector3 *)((char *)v22 + 4);
              v20->m128_i32[2] = v22->mVec128.m128_i32[0];
              v20->m128_i32[3] = v22->mVec128.m128_i32[1];
            }
            ++v21;
            ++v20;
            --v19;
          }
          while ( v19 );
        }
        if ( ppVtxOut->m_data )
        {
          if ( ppVtxOut->m_ownsMemory )
            btAlignedFreeInternal(ppVtxOut->m_data);
          ppVtxOut->m_data = 0;
        }
        ppVtxOut->m_data = v47;
        ppVtxOut->m_ownsMemory = 1;
        ppVtxOut->m_capacity = v43;
      }
    }
    v23 = &ppVtxOut->m_data[ppVtxOut->m_size];
    if ( v23 )
    {
      v24 = v57;
      goto LABEL_80;
    }
    goto LABEL_81;
  }
}
