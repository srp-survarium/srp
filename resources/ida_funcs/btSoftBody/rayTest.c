BOOL __userpurge btSoftBody::rayTest@<eax>(
        btSoftBody *this@<edi>,
        btSoftBody::sRayCast *results@<esi>,
        btSoftBody *a3@<ecx>,
        const btVector3 *rayFrom,
        const btVector3 *rayTo)
{
  bool v6; // [esp-4h] [ebp-4h]

  v6 = (char)a3;
  if ( this->m_faces.m_size && !this->m_fdbvt.m_root )
    btSoftBody::initializeFaceTree(a3, this);
  LODWORD(results->fraction) = clear_value;
  results->feature = Linear;
  results->body = this;
  results->index = -1;
  return btSoftBody::rayTest(rayFrom, rayTo, this, &results->fraction, &results->feature, &results->index, v6) != 0;
}


int __userpurge btSoftBody::rayTest@<eax>(
        const btVector3 *rayFrom@<ecx>,
        const btVector3 *rayTo@<eax>,
        btSoftBody *this,
        float *mint,
        btSoftBody::eFeature::_ *feature,
        int *index,
        bool bcountonly)
{
  btDbvtNode *m_root; // ebx
  btSoftBody::Face *m_face; // eax
  int v11; // ebx
  float v12; // xmm0_4
  btSoftBody::Tetra *v13; // ebx
  int *v14; // eax
  int v15; // edx
  int v16; // esi
  unsigned __int64 v17; // xmm0_8
  int p_m_x; // eax
  unsigned __int64 v19; // xmm0_8
  btSoftBody::Node *v20; // eax
  double v21; // st7
  unsigned __int64 v22; // xmm0_8
  __m128 *v23; // eax
  float v24; // xmm0_4
  float mxt; // [esp+360h] [ebp-A4h]
  int v27; // [esp+370h] [ebp-94h]
  int v28; // [esp+374h] [ebp-90h]
  int *v29; // [esp+374h] [ebp-90h]
  int m_size; // [esp+378h] [ebp-8Ch]
  int v31; // [esp+378h] [ebp-8Ch]
  int v32; // [esp+37Ch] [ebp-88h]
  int v33; // [esp+380h] [ebp-84h]
  btVector3 v34; // [esp+384h] [ebp-80h] BYREF
  btSoftBody::RayFromToCaster policy; // [esp+394h] [ebp-70h] BYREF
  btVector3 c; // [esp+3D4h] [ebp-30h] BYREF
  btVector3 a; // [esp+3E4h] [ebp-20h] BYREF
  btVector3 b; // [esp+3F4h] [ebp-10h] BYREF

  m_root = this->m_fdbvt.m_root;
  v34.mVec128.m128_f32[0] = rayTo->mVec128.m128_f32[0] - rayFrom->mVec128.m128_f32[0];
  v34.mVec128.m128_f32[1] = rayTo->mVec128.m128_f32[1] - rayFrom->mVec128.m128_f32[1];
  v34.mVec128.m128_f32[2] = rayTo->mVec128.m128_f32[2] - rayFrom->mVec128.m128_f32[2];
  v27 = 0;
  v34.mVec128.m128_i32[3] = 0;
  if ( m_root )
  {
    btSoftBody::RayFromToCaster::RayFromToCaster(rayTo, rayFrom, &policy, *mint);
    btDbvt::rayTest<btSoftBody::RayFromToCaster>(rayTo, m_root, rayFrom, &policy);
    m_face = policy.m_face;
    if ( policy.m_face )
    {
      *mint = policy.m_mint;
      *feature = SContacts;
      *index = m_face - this->m_faces.m_data;
      v27 = 1;
    }
  }
  else
  {
    v11 = 0;
    m_size = this->m_faces.m_size;
    if ( m_size > 0 )
    {
      v28 = 0;
      do
      {
        v12 = btSoftBody::RayFromToCaster::rayFromToTriangle(
                rayFrom,
                &this->m_faces.m_data[v28].m_n[0]->m_x,
                &this->m_faces.m_data[v28].m_n[1]->m_x,
                &this->m_faces.m_data[v28].m_n[2]->m_x,
                &v34,
                COERCE_CONST_BTVECTOR3_(*mint));
        if ( v12 > 0.0 )
        {
          ++v27;
          *feature = SContacts;
          *index = v11;
          *mint = v12;
        }
        ++v28;
        ++v11;
      }
      while ( v11 < m_size );
    }
  }
  v32 = 0;
  if ( this->m_tetras.m_size > 0 )
  {
    v33 = 0;
    do
    {
      v13 = &this->m_tetras.m_data[v33];
      policy.m_rayTo.mVec128.m128_i32[0] = 1;
      v14 = &policy.m_rayFrom.mVec128.m128_i32[1];
      policy.m_rayFrom.mVec128.m128_u64[0] = 0x100000000LL;
      policy.m_rayFrom.mVec128.m128_u64[1] = 2;
      *(unsigned __int64 *)((char *)policy.m_rayTo.mVec128.m128_u64 + 4) = 0x100000003LL;
      policy.m_rayTo.mVec128.m128_i32[3] = 2;
      policy.m_rayNormalizedDirection.mVec128.m128_u64[0] = 3;
      policy.m_rayNormalizedDirection.mVec128.m128_u64[1] = 0x300000002LL;
      v29 = &policy.m_rayFrom.mVec128.m128_i32[1];
      v31 = 4;
      while ( 1 )
      {
        v15 = *v14;
        v16 = v14[1];
        v17 = v13->m_n[*(v14 - 1)]->m_x.mVec128.m128_u64[0];
        p_m_x = (int)&v13->m_n[*(v14 - 1)]->m_x;
        a.mVec128.m128_u64[0] = v17;
        v19 = *(_QWORD *)(p_m_x + 8);
        v20 = v13->m_n[v15];
        v21 = *mint;
        a.mVec128.m128_u64[1] = v19;
        b.mVec128.m128_u64[0] = v20->m_x.mVec128.m128_u64[0];
        v22 = v20->m_x.mVec128.m128_u64[1];
        v23 = (__m128 *)v13->m_n[v16];
        b.mVec128.m128_u64[1] = v22;
        c.mVec128 = v23[1];
        mxt = v21;
        v24 = btSoftBody::RayFromToCaster::rayFromToTriangle(rayFrom, &a, &b, &c, &v34, (const btVector3 *)LODWORD(mxt));
        if ( v24 > 0.0 )
        {
          ++v27;
          *feature = END;
          *index = v32;
          *mint = v24;
        }
        v29 += 3;
        if ( !--v31 )
          break;
        v14 = v29;
      }
      ++v33;
      ++v32;
    }
    while ( v32 < this->m_tetras.m_size );
  }
  return v27;
}
