void __userpurge btSoftColliders::CollideVF_SS::Process(
        const btDbvtNode *lnode@<eax>,
        const btDbvtNode *lface@<ecx>,
        btSoftColliders::CollideVF_SS *this)
{
  btDbvtNode *v3; // ebx
  btDbvtNode *v4; // eax
  float *v5; // ecx
  float v6; // xmm4_4
  const btVector3 *v7; // esi
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm4_4
  float *v13; // eax
  float v14; // xmm4_4
  float v15; // xmm0_4
  long double v16; // st7
  long double v17; // st7
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm5_4
  float v22; // xmm0_4
  long double v23; // st7
  btSoftBody *v24; // ebx
  btSoftBody *v25; // eax
  btSoftBody *p_kDF; // ecx
  btSoftBody_vtbl *v27; // xmm0_4
  float kSHR; // xmm1_4
  int m_capacity; // ecx
  float v30; // xmm1_4
  int m_size; // eax
  int v32; // esi
  __m128 *v33; // eax
  int v34; // edx
  btSoftBody::SContact *m_data; // eax
  btSoftBody::SContact *v36; // edx
  btSoftBody::SContact *v37; // edi
  const btVector3 *v38; // [esp+534h] [ebp-B0h]
  float v39; // [esp+534h] [ebp-B0h]
  int v40; // [esp+534h] [ebp-B0h]
  int sqd; // [esp+538h] [ebp-ACh] BYREF
  __m128 *p_mVec128; // [esp+53Ch] [ebp-A8h]
  float v43; // [esp+540h] [ebp-A4h]
  btVector3 a; // [esp+544h] [ebp-A0h] BYREF
  unsigned __int64 v45; // [esp+554h] [ebp-90h]
  unsigned __int64 v46; // [esp+55Ch] [ebp-88h]
  btVector3 b; // [esp+564h] [ebp-80h] BYREF
  float v48; // [esp+57Ch] [ebp-68h]
  float v49; // [esp+580h] [ebp-64h]
  btVector3 prj; // [esp+584h] [ebp-60h] BYREF
  btVector3 v51; // [esp+594h] [ebp-50h] BYREF
  _OWORD v52[4]; // [esp+5A4h] [ebp-40h] BYREF

  v3 = lnode->childs[0];
  v4 = lface->childs[0];
  v5 = (float *)v4->volume.mi.mVec128.m128_i32[3];
  v6 = v5[4];
  v45 = v3->volume.mx.mVec128.m128_u64[0];
  v46 = v3->volume.mx.mVec128.m128_u64[1];
  v7 = (const btVector3 *)v4->volume.mx.mVec128.m128_i32[0];
  v8 = v7[1].mVec128.m128_f32[0];
  v9 = v7[1].mVec128.m128_f32[1];
  v10 = v7[1].mVec128.m128_f32[2];
  *(float *)&sqd = 3.4028235e38;
  b.mVec128.m128_f32[0] = v6 - *(float *)&v45;
  v11 = v5[5];
  v51.mVec128.m128_f32[0] = v8 - *(float *)&v45;
  b.mVec128.m128_f32[1] = v11 - *((float *)&v45 + 1);
  v12 = v5[6];
  p_mVec128 = &v4->volume.mi.mVec128;
  v13 = (float *)v4->volume.mi.mVec128.m128_i32[2];
  v51.mVec128.m128_f32[1] = v9 - *((float *)&v45 + 1);
  b.mVec128.m128_f32[2] = v12 - *(float *)&v46;
  v14 = v13[4] - *(float *)&v45;
  a.mVec128.m128_f32[1] = v13[5] - *((float *)&v45 + 1);
  v15 = v13[6];
  v43 = *(float *)&v13;
  v38 = (const btVector3 *)v5;
  v51.mVec128.m128_f32[2] = v10 - *(float *)&v46;
  v51.mVec128.m128_i32[3] = 0;
  b.mVec128.m128_i32[3] = 0;
  a.mVec128.m128_f32[0] = v14;
  a.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v15 - *(float *)&v46);
  ProjectOrigin_0(&a, &b, &v51, &prj, (float *)&sqd);
  v16 = sqrtf(
          (float)((float)((float)(*(float *)&v46 - *(float *)&v3->childs[1])
                        * (float)(*(float *)&v46 - *(float *)&v3->childs[1]))
                + (float)((float)(*((float *)&v45 + 1) - *(float *)v3->childs)
                        * (float)(*((float *)&v45 + 1) - *(float *)v3->childs)))
        + (float)((float)(*(float *)&v45 - *(float *)&v3->parent) * (float)(*(float *)&v45 - *(float *)&v3->parent)));
  v17 = v16 + v16 + this->mrg;
  v49 = v17;
  if ( v17 * v17 > *(float *)&sqd )
  {
    a.mVec128.m128_f32[0] = prj.mVec128.m128_f32[0] + *(float *)&v45;
    a.mVec128.m128_f32[1] = prj.mVec128.m128_f32[1] + *((float *)&v45 + 1);
    a.mVec128.m128_f32[2] = prj.mVec128.m128_f32[2] + *(float *)&v46;
    a.mVec128.m128_i32[3] = 0;
    BaryCoord((const btVector3 *)(LODWORD(v43) + 16), v38 + 1, v7 + 1, &a);
    v18 = *(float *)(p_mVec128->m128_i32[3] + 96);
    v19 = *(float *)(p_mVec128[1].m128_i32[0] + 96);
    v20 = *(float *)(p_mVec128->m128_i32[2] + 96);
    v21 = v3[2].volume.mi.mVec128.m128_f32[0];
    v22 = (float)((float)(v19 * b.mVec128.m128_f32[2]) + (float)(v18 * b.mVec128.m128_f32[1]))
        + (float)(v20 * b.mVec128.m128_f32[0]);
    v48 = v21;
    v39 = v22;
    if ( v20 <= 0.0 || v18 <= 0.0 || v19 <= 0.0 )
    {
      v22 = 0.0;
      v39 = 0.0;
    }
    v43 = v22 + v21;
    if ( (float)(v22 + v21) > 0.0 )
    {
      v23 = 1.0 / -sqrtf(*(float *)&sqd);
      a.mVec128.m128_i32[3] = 0;
      *(_QWORD *)&v52[0] = __PAIR64__((unsigned int)p_mVec128, (unsigned int)v3);
      v24 = this->psb[0];
      v25 = this->psb[1];
      p_kDF = (btSoftBody *)&v25->m_cfg.kDF;
      a.mVec128.m128_f32[0] = prj.mVec128.m128_f32[0] * v23;
      a.mVec128.m128_f32[1] = prj.mVec128.m128_f32[1] * v23;
      a.mVec128.m128_f32[2] = v23 * prj.mVec128.m128_f32[2];
      v52[2] = _mm_load_si128((const __m128i *)&a);
      *(float *)&v52[3] = v49;
      v52[1] = _mm_load_si128((const __m128i *)&b);
      if ( v24->m_cfg.kDF > v25->m_cfg.kDF )
        p_kDF = (btSoftBody *)&v24->m_cfg.kDF;
      v27 = p_kDF->__vftable;
      kSHR = v24->m_cfg.kSHR;
      m_capacity = v24->m_scontacts.m_capacity;
      DWORD1(v52[3]) = v27;
      *((float *)&v52[3] + 2) = (float)(kSHR * (float)(*(float *)&clear_value / v43)) * v48;
      v30 = v25->m_cfg.kSHR;
      m_size = v24->m_scontacts.m_size;
      *((float *)&v52[3] + 3) = (float)(v30 * (float)(*(float *)&clear_value / v43)) * v39;
      if ( m_size == m_capacity )
      {
        if ( m_size )
        {
          v32 = 2 * m_size;
          sqd = 2 * m_size;
        }
        else
        {
          sqd = 1;
          v32 = 1;
        }
        if ( m_capacity < v32 )
        {
          if ( v32 )
          {
            ++gNumAlignedAllocs;
            p_mVec128 = (__m128 *)sAlignedAllocFunc(v32 << 6, 16);
          }
          else
          {
            p_mVec128 = 0;
          }
          if ( v24->m_scontacts.m_size > 0 )
          {
            v33 = p_mVec128;
            v34 = 0;
            v40 = v24->m_scontacts.m_size;
            do
            {
              if ( v33 )
              {
                qmemcpy(v33, &v24->m_scontacts.m_data[v34], 0x40u);
                v32 = sqd;
              }
              ++v34;
              v33 += 4;
              --v40;
            }
            while ( v40 );
          }
          m_data = v24->m_scontacts.m_data;
          if ( m_data )
          {
            if ( v24->m_scontacts.m_ownsMemory )
            {
              ++gNumAlignedFree;
              sAlignedFreeFunc(m_data);
            }
            v24->m_scontacts.m_data = 0;
          }
          v36 = (btSoftBody::SContact *)p_mVec128;
          v24->m_scontacts.m_ownsMemory = 1;
          v24->m_scontacts.m_data = v36;
          v24->m_scontacts.m_capacity = v32;
        }
      }
      v37 = &v24->m_scontacts.m_data[v24->m_scontacts.m_size];
      if ( v37 )
        qmemcpy(v37, v52, sizeof(btSoftBody::SContact));
      ++v24->m_scontacts.m_size;
    }
  }
}
