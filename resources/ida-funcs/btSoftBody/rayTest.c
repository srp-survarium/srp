BOOL __userpurge btSoftBody::rayTest@<eax>(
        btSoftBody *this@<edi>,
        btSoftBody::sRayCast *results@<esi>,
        btSoftBody *a3@<ecx>,
        const btVector3 *rayFrom,
        const btVector3 *rayTo)
{
  float v5; // xmm0_4
  char v7; // [esp-4h] [ebp-4h]

  v7 = (char)a3;
  if ( this->m_faces.m_size && !this->m_fdbvt.m_root )
    btSoftBody::initializeFaceTree(a3, (int)this);
  v5 = s_bm_current_air_resistance;
  results->index = -1;
  results->feature = None;
  results->fraction = v5;
  results->body = this;
  return btSoftBody::rayTest(rayTo, this, rayFrom, &results->fraction, &results->feature, &results->index, v7) != 0;
}


int __userpurge btSoftBody::rayTest@<eax>(
        const btVector3 *rayTo@<eax>,
        btSoftBody *this,
        const btVector3 *rayFrom,
        float *mint,
        btSoftBody::eFeature::_ *feature,
        int *index,
        bool bcountonly)
{
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  btSoftBody *v10; // ebx
  btDbvtNode *m_root; // edx
  float v12; // xmm0_4
  btSoftBody::Face *m_face; // eax
  float v14; // xmm0_4
  btSoftBody::Tetra *v15; // ebx
  int *v16; // eax
  int v17; // edx
  int *p_m_x; // esi
  int v19; // eax
  int v20; // esi
  int v21; // esi
  double v22; // st7
  float v23; // xmm0_4
  float v25; // [esp+0h] [ebp-A4h]
  int v26; // [esp+10h] [ebp-94h]
  int v27; // [esp+10h] [ebp-94h]
  int v28; // [esp+14h] [ebp-90h]
  int *v29; // [esp+14h] [ebp-90h]
  int v30; // [esp+18h] [ebp-8Ch]
  int m_size; // [esp+1Ch] [ebp-88h]
  int v32; // [esp+1Ch] [ebp-88h]
  int v33; // [esp+20h] [ebp-84h]
  btVector3 v34; // [esp+24h] [ebp-80h] BYREF
  btVector3 v35; // [esp+34h] [ebp-70h] BYREF
  btSoftBody::RayFromToCaster policy; // [esp+44h] [ebp-60h] BYREF
  btVector3 v37; // [esp+84h] [ebp-20h] BYREF
  btVector3 v38; // [esp+94h] [ebp-10h] BYREF

  v7 = rayTo->mVec128.m128_f32[0] - rayFrom->mVec128.m128_f32[0];
  v8 = rayTo->mVec128.m128_f32[1] - rayFrom->mVec128.m128_f32[1];
  v9 = rayTo->mVec128.m128_f32[2] - rayFrom->mVec128.m128_f32[2];
  v10 = this;
  m_root = this->m_fdbvt.m_root;
  v30 = 0;
  v35.mVec128.m128_f32[0] = v7;
  *(unsigned __int64 *)((char *)v35.mVec128.m128_u64 + 4) = __PAIR64__(LODWORD(v9), LODWORD(v8));
  v35.mVec128.m128_i32[3] = 0;
  if ( m_root )
  {
    policy.m_rayFrom = (btVector3)rayFrom->mVec128;
    v34.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v8), LODWORD(v7));
    v34.mVec128.m128_u64[1] = LODWORD(v9);
    policy.m_rayNormalizedDirection.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v8), LODWORD(v7));
    policy.m_rayNormalizedDirection.mVec128.m128_u64[1] = LODWORD(v9);
    policy.m_rayTo = (btVector3)rayTo->mVec128;
    v12 = *mint;
    policy.m_face = 0;
    policy.m_tests = 0;
    policy.m_mint = v12;
    btDbvt::rayTest<btSoftBody::RayFromToCaster>(rayTo, m_root, rayFrom, &policy);
    m_face = policy.m_face;
    if ( policy.m_face )
    {
      *mint = policy.m_mint;
      *feature = 3;
      *index = m_face - this->m_faces.m_data;
      v30 = 1;
    }
  }
  else
  {
    v26 = 0;
    m_size = this->m_faces.m_size;
    if ( m_size > 0 )
    {
      v28 = 0;
      do
      {
        v14 = btSoftBody::RayFromToCaster::rayFromToTriangle(
                rayFrom,
                &v35,
                &this->m_faces.m_data[v28].m_n[1]->m_x,
                &this->m_faces.m_data[v28].m_n[2]->m_x,
                &this->m_faces.m_data[v28].m_n[0]->m_x,
                COERCE_CONST_BTVECTOR3_(*mint));
        if ( v14 > 0.0 )
        {
          ++v30;
          *feature = 3;
          *index = v26;
          *mint = v14;
        }
        ++v26;
        ++v28;
      }
      while ( v26 < m_size );
    }
  }
  v27 = 0;
  if ( this->m_tetras.m_size > 0 )
  {
    v33 = 0;
    while ( 1 )
    {
      v15 = &v10->m_tetras.m_data[v33];
      v16 = &policy.m_rayFrom.mVec128.m128_i32[1];
      policy.m_rayFrom.mVec128.m128_i32[0] = 0;
      *(unsigned __int64 *)((char *)policy.m_rayFrom.mVec128.m128_u64 + 4) = 0x200000001LL;
      policy.m_rayFrom.mVec128.m128_i32[3] = 0;
      policy.m_rayTo.mVec128.m128_u64[0] = 0x300000001LL;
      policy.m_rayTo.mVec128.m128_u64[1] = 0x200000001LL;
      policy.m_rayNormalizedDirection.mVec128.m128_i32[0] = 3;
      *(unsigned __int64 *)((char *)policy.m_rayNormalizedDirection.mVec128.m128_u64 + 4) = 0x200000000LL;
      policy.m_rayNormalizedDirection.mVec128.m128_i32[3] = 3;
      v29 = &policy.m_rayFrom.mVec128.m128_i32[1];
      v32 = 4;
      while ( 1 )
      {
        v17 = *v16;
        p_m_x = (int *)&v15->m_n[*(v16 - 1)]->m_x;
        v34.mVec128.m128_i32[0] = *p_m_x++;
        v34.mVec128.m128_i32[1] = *p_m_x++;
        v34.mVec128.m128_i32[2] = *p_m_x;
        v19 = v16[1];
        v34.mVec128.m128_i32[3] = p_m_x[1];
        v20 = (int)&v15->m_n[v17]->m_x;
        v38.mVec128.m128_i32[0] = *(_DWORD *)v20;
        v20 += 4;
        v38.mVec128.m128_i32[1] = *(_DWORD *)v20;
        v38.mVec128.m128_u64[1] = *(_QWORD *)(v20 + 4);
        v21 = (int)&v15->m_n[v19]->m_x;
        v22 = *mint;
        v37.mVec128.m128_i32[0] = *(_DWORD *)v21;
        v21 += 4;
        v37.mVec128.m128_i32[1] = *(_DWORD *)v21;
        v37.mVec128.m128_u64[1] = *(_QWORD *)(v21 + 4);
        v25 = v22;
        v23 = btSoftBody::RayFromToCaster::rayFromToTriangle(
                rayFrom,
                &v35,
                &v38,
                &v37,
                &v34,
                (const btVector3 *)LODWORD(v25));
        if ( v23 > 0.0 )
        {
          ++v30;
          *feature = 4;
          *index = v27;
          *mint = v23;
        }
        v29 += 3;
        if ( !--v32 )
          break;
        v16 = v29;
      }
      ++v27;
      ++v33;
      if ( v27 >= this->m_tetras.m_size )
        break;
      v10 = this;
    }
  }
  return v30;
}
