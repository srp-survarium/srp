void __thiscall btDbvtBroadphase::getBroadphaseAabb(btDbvtBroadphase *this, btVector3 *aabbMin, btVector3 *aabbMax)
{
  btDbvtNode *m_root; // eax
  btDbvtNode *v4; // ecx
  __m128 mVec128; // xmm1
  __m128 v6; // xmm0
  unsigned __int64 v7; // xmm1_8
  unsigned __int64 v8; // xmm3_8
  unsigned __int64 v9; // xmm2_8
  unsigned __int64 v10; // xmm0_8
  struct btVector3 *v11[4]; // [esp+40h] [ebp-40h] BYREF
  __m128 v12; // [esp+50h] [ebp-30h]
  struct btDbvtAabbMm v13; // [esp+60h] [ebp-20h] BYREF

  m_root = this->m_sets[0].m_root;
  v4 = this->m_sets[1].m_root;
  if ( !m_root )
  {
    if ( v4 )
    {
      v10 = v4->volume.mi.mVec128.m128_u64[0];
      v7 = v4->volume.mi.mVec128.m128_u64[1];
      v9 = v4->volume.mx.mVec128.m128_u64[0];
      v8 = v4->volume.mx.mVec128.m128_u64[1];
      goto LABEL_8;
    }
    memset(v11, 0, sizeof(v11));
    m_root = (btDbvtNode *)btDbvtAabbMm::FromCR(&v13, (float *)v11, 0.0);
LABEL_7:
    v8 = m_root->volume.mx.mVec128.m128_u64[1];
    v9 = m_root->volume.mx.mVec128.m128_u64[0];
    v7 = m_root->volume.mi.mVec128.m128_u64[1];
    v10 = m_root->volume.mi.mVec128.m128_u64[0];
    goto LABEL_8;
  }
  if ( !v4 )
    goto LABEL_7;
  mVec128 = v4->volume.mx.mVec128;
  *(__m128 *)v11 = _mm_min_ps(m_root->volume.mi.mVec128, v4->volume.mi.mVec128);
  v6 = _mm_max_ps(m_root->volume.mx.mVec128, mVec128);
  v7 = *(_QWORD *)&v11[2];
  v12 = v6;
  v8 = v6.m128_u64[1];
  v9 = v6.m128_u64[0];
  v10 = *(_QWORD *)v11;
LABEL_8:
  aabbMin->mVec128.m128_u64[0] = v10;
  aabbMin->mVec128.m128_u64[1] = v7;
  aabbMax->mVec128.m128_u64[0] = v9;
  aabbMax->mVec128.m128_u64[1] = v8;
}
