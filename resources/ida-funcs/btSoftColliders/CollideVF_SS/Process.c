void __userpurge btSoftColliders::CollideVF_SS::Process(
        const btDbvtNode *lnode@<eax>,
        btSoftColliders::CollideVF_SS *this,
        const btDbvtNode *lface)
{
  btDbvtNode *v3; // ebx
  btDbvtNode *v4; // eax
  const btVector3 *v5; // edi
  const btVector3 *v6; // esi
  unsigned int v7; // xmm1_4
  float *v8; // eax
  float v9; // xmm1_4
  float v10; // xmm0_4
  unsigned int v11; // xmm1_4
  int v12; // eax
  float v13; // xmm6_4
  float v14; // xmm0_4
  float v15; // xmm5_4
  float v16; // xmm3_4
  btSoftBody *v17; // eax
  btSoftBody *v18; // ebx
  btSoftBody *p_kDF; // ecx
  btSoftBody_vtbl *v20; // xmm1_4
  int m_capacity; // ecx
  float kSHR; // xmm1_4
  int m_size; // eax
  int v24; // eax
  btSoftBody::SContact *v25; // edx
  int v26; // eax
  btSoftBody::SContact *v27; // edi
  float v28; // [esp+14h] [ebp-ACh] BYREF
  btSoftBody::SContact *v29; // [esp+18h] [ebp-A8h]
  const btVector3 *v30; // [esp+1Ch] [ebp-A4h]
  float v31; // [esp+20h] [ebp-A0h]
  float v32; // [esp+24h] [ebp-9Ch]
  float v33; // [esp+28h] [ebp-98h]
  int v34; // [esp+2Ch] [ebp-94h]
  btVector3 v35; // [esp+30h] [ebp-90h] BYREF
  btVector3 v36; // [esp+40h] [ebp-80h] BYREF
  float v37; // [esp+5Ch] [ebp-64h]
  btVector3 v38; // [esp+60h] [ebp-60h] BYREF
  btVector3 v39; // [esp+70h] [ebp-50h] BYREF
  _QWORD v40[8]; // [esp+80h] [ebp-40h] BYREF

  v3 = lnode->childs[0];
  v4 = lface->childs[0];
  v31 = v3->volume.mx.mVec128.m128_f32[0];
  v32 = v3->volume.mx.mVec128.m128_f32[1];
  v33 = v3->volume.mx.mVec128.m128_f32[2];
  v34 = v3->volume.mx.mVec128.m128_i32[3];
  v5 = (const btVector3 *)v4->volume.mi.mVec128.m128_i32[3];
  v6 = (const btVector3 *)v4->volume.mx.mVec128.m128_i32[0];
  v35.mVec128.m128_f32[0] = v5[1].mVec128.m128_f32[0] - v31;
  v35.mVec128.m128_f32[1] = v5[1].mVec128.m128_f32[1] - v32;
  *(float *)&v7 = v5[1].mVec128.m128_f32[2] - v33;
  v29 = (btSoftBody::SContact *)v4;
  v8 = (float *)v4->volume.mi.mVec128.m128_i32[2];
  v35.mVec128.m128_u64[1] = v7;
  v36.mVec128.m128_f32[0] = v8[4] - v31;
  v9 = v8[5] - v32;
  v28 = FLOAT_3_4028235e38;
  v10 = v6[1].mVec128.m128_f32[0] - v31;
  v30 = (const btVector3 *)v8;
  v36.mVec128.m128_f32[1] = v9;
  *(float *)&v11 = v8[6] - v33;
  v39.mVec128.m128_f32[0] = v10;
  v39.mVec128.m128_f32[1] = v6[1].mVec128.m128_f32[1] - v32;
  v39.mVec128.m128_f32[2] = v6[1].mVec128.m128_f32[2] - v33;
  v39.mVec128.m128_i32[3] = 0;
  v36.mVec128.m128_u64[1] = v11;
  ProjectOrigin_0(&v35, &v28, &v36, &v39, &v38);
  v37 = (float)(fsqrt(
                  (float)((float)((float)(v33 - *(float *)&v3->childs[1]) * (float)(v33 - *(float *)&v3->childs[1]))
                        + (float)((float)(v32 - *(float *)v3->childs) * (float)(v32 - *(float *)v3->childs)))
                + (float)((float)(v31 - *(float *)&v3->parent) * (float)(v31 - *(float *)&v3->parent)))
              * 2.0)
      + this->mrg;
  if ( (float)(v37 * v37) > v28 )
  {
    v35.mVec128.m128_f32[0] = v38.mVec128.m128_f32[0] + v31;
    v35.mVec128.m128_f32[1] = v38.mVec128.m128_f32[1] + v32;
    v35.mVec128.m128_f32[2] = v38.mVec128.m128_f32[2] + v33;
    v35.mVec128.m128_i32[3] = 0;
    BaryCoord(v30 + 1, v5 + 1, v6 + 1, &v35, &v36);
    v12 = *((_DWORD *)&v29->m_face + 1);
    v13 = v3[2].volume.mi.mVec128.m128_f32[0];
    v14 = (float)((float)(*(float *)(v29->m_weights.mVec128.m128_i32[0] + 96) * v36.mVec128.m128_f32[2])
                + (float)(*(float *)(*((_DWORD *)&v29->m_face + 2) + 96) * v36.mVec128.m128_f32[1]))
        + (float)(*(float *)(v12 + 96) * v36.mVec128.m128_f32[0]);
    if ( *(float *)(v12 + 96) <= 0.0
      || *(float *)(*((_DWORD *)&v29->m_face + 2) + 96) <= 0.0
      || *(float *)(v29->m_weights.mVec128.m128_i32[0] + 96) <= 0.0 )
    {
      v14 = 0.0;
    }
    v15 = v14 + v13;
    if ( (float)(v14 + v13) > 0.0 )
    {
      v35.mVec128.m128_i32[3] = 0;
      v16 = s_bm_current_air_resistance / COERCE_FLOAT(COERCE_UNSIGNED_INT(fsqrt(v28)) ^ _mask__NegFloat_);
      v35.mVec128.m128_f32[0] = v16 * v38.mVec128.m128_f32[0];
      v35.mVec128.m128_f32[1] = v38.mVec128.m128_f32[1] * v16;
      v35.mVec128.m128_f32[2] = v38.mVec128.m128_f32[2] * v16;
      *(float *)&v40[4] = v16 * v38.mVec128.m128_f32[0];
      *((float *)&v40[4] + 1) = v38.mVec128.m128_f32[1] * v16;
      *(float *)&v40[5] = v38.mVec128.m128_f32[2] * v16;
      HIDWORD(v40[5]) = 0;
      *(float *)&v40[6] = v37;
      v17 = this->psb[1];
      v40[0] = __PAIR64__((unsigned int)v29, (unsigned int)v3);
      v18 = this->psb[0];
      v40[2] = v36.mVec128.m128_u64[0];
      LODWORD(v40[3]) = v36.mVec128.m128_i32[2];
      p_kDF = (btSoftBody *)&v17->m_cfg.kDF;
      if ( v18->m_cfg.kDF > v17->m_cfg.kDF )
        p_kDF = (btSoftBody *)&v18->m_cfg.kDF;
      v20 = p_kDF->__vftable;
      m_capacity = v18->m_scontacts.m_capacity;
      HIDWORD(v40[3]) = v36.mVec128.m128_i32[3];
      HIDWORD(v40[6]) = v20;
      *(float *)&v40[7] = (float)(v18->m_cfg.kSHR * (float)(s_bm_current_air_resistance / v15)) * v13;
      kSHR = v17->m_cfg.kSHR;
      m_size = v18->m_scontacts.m_size;
      *((float *)&v40[7] + 1) = (float)(kSHR * (float)(s_bm_current_air_resistance / v15)) * v14;
      if ( m_size == m_capacity )
      {
        LODWORD(v28) = m_size ? 2 * m_size : 1;
        if ( m_capacity < SLODWORD(v28) )
        {
          if ( v28 == 0.0 )
            v29 = 0;
          else
            v29 = (btSoftBody::SContact *)btAlignedAllocInternal(LODWORD(v28) << 6);
          v24 = v18->m_scontacts.m_size;
          if ( v24 > 0 )
          {
            v25 = v29;
            v30 = 0;
            do
            {
              if ( v25 )
                qmemcpy(v25, (char *)v30 + (unsigned int)v18->m_scontacts.m_data, sizeof(btSoftBody::SContact));
              v30 += 4;
              ++v25;
              --v24;
            }
            while ( v24 );
          }
          if ( v18->m_scontacts.m_data )
          {
            if ( v18->m_scontacts.m_ownsMemory )
              btAlignedFreeInternal(v18->m_scontacts.m_data);
            v18->m_scontacts.m_data = 0;
          }
          v18->m_scontacts.m_data = v29;
          v26 = LODWORD(v28);
          v18->m_scontacts.m_ownsMemory = 1;
          v18->m_scontacts.m_capacity = v26;
        }
      }
      v27 = &v18->m_scontacts.m_data[v18->m_scontacts.m_size];
      if ( v27 )
        qmemcpy(v27, v40, sizeof(btSoftBody::SContact));
      ++v18->m_scontacts.m_size;
    }
  }
}
