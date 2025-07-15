void __thiscall btDbvtBroadphase::getBroadphaseAabb(btDbvtBroadphase *this, btVector3 *aabbMin, btVector3 *aabbMax)
{
  btDbvtNode *m_root; // esi
  btDbvtNode *v4; // ecx
  __m128 mVec128; // xmm1
  _OWORD v6[2]; // [esp+10h] [ebp-40h] BYREF
  _BYTE v7[32]; // [esp+30h] [ebp-20h] BYREF

  m_root = this->m_sets[0].m_root;
  if ( !m_root )
  {
    m_root = this->m_sets[1].m_root;
    if ( !m_root )
    {
      memset(v6, 0, 16);
      m_root = (btDbvtNode *)btDbvtAabbMm::FromCR((int)v7, (float *)v6, 0.0);
    }
    goto LABEL_6;
  }
  v4 = this->m_sets[1].m_root;
  if ( !v4 )
  {
LABEL_6:
    qmemcpy(v6, m_root, sizeof(v6));
    goto LABEL_7;
  }
  mVec128 = v4->volume.mx.mVec128;
  v6[0] = _mm_min_ps(m_root->volume.mi.mVec128, v4->volume.mi.mVec128);
  v6[1] = _mm_max_ps(m_root->volume.mx.mVec128, mVec128);
LABEL_7:
  *aabbMin = (btVector3)v6[0];
  *aabbMax = (btVector3)v6[1];
}
