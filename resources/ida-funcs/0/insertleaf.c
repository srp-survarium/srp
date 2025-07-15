void __usercall insertleaf(btDbvtNode *root@<eax>, btDbvt *pdbvt, btDbvtNode *leaf)
{
  btDbvt *v3; // ecx
  btDbvtNode *v4; // esi
  __m128 v5; // xmm3
  __m128 v6; // xmm0
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  btDbvtNode *m_free; // eax
  btDbvtNode *parent; // edi
  __m128 v12; // xmm0
  __m128 *p_mVec128; // eax
  __m128 *v14; // ecx
  __m128 v15; // xmm0

  v3 = pdbvt;
  v4 = root;
  if ( pdbvt->m_root )
  {
    if ( root->childs[1] )
    {
      v5 = _mm_add_ps(leaf->volume.mx.mVec128, leaf->volume.mi.mVec128);
      do
      {
        v6 = _mm_and_ps(
               _mm_sub_ps(_mm_add_ps(*(__m128 *)(v4->dataAsInt + 16), v4->childs[0]->volume.mi.mVec128), v5),
               (__m128)_mask__AbsFloat_);
        v7 = _mm_add_ps(_mm_movehl_ps(v6, v6), v6);
        v8 = _mm_and_ps(
               _mm_sub_ps(_mm_add_ps(v4->childs[1]->volume.mx.mVec128, v4->childs[1]->volume.mi.mVec128), v5),
               (__m128)_mask__AbsFloat_);
        v9 = _mm_add_ps(_mm_movehl_ps(v8, v8), v8);
        v9.m128_f32[0] = v9.m128_f32[0] + _mm_shuffle_ps(v9, v9, 1).m128_f32[0];
        v7.m128_f32[0] = v7.m128_f32[0] + _mm_shuffle_ps(v7, v7, 1).m128_f32[0];
        v4 = v4->childs[_mm_cmple_ss(v9, v7).m128_u8[0] & 1];
      }
      while ( v4->childs[1] );
    }
    m_free = pdbvt->m_free;
    parent = v4->parent;
    if ( m_free )
    {
      pdbvt->m_free = 0;
    }
    else
    {
      m_free = (btDbvtNode *)btAlignedAllocInternal(0x30u);
      v3 = pdbvt;
    }
    m_free->parent = parent;
    m_free->dataAsInt = 0;
    m_free->childs[1] = 0;
    v12 = _mm_max_ps(leaf->volume.mx.mVec128, v4->volume.mx.mVec128);
    m_free->volume.mi.mVec128 = _mm_min_ps(leaf->volume.mi.mVec128, v4->volume.mi.mVec128);
    m_free->volume.mx.mVec128 = v12;
    if ( parent )
    {
      *(&parent->dataAsInt + (v4->parent->childs[1] == v4)) = (int)m_free;
      m_free->dataAsInt = (int)v4;
      v4->parent = m_free;
      m_free->childs[1] = leaf;
      leaf->parent = m_free;
      do
      {
        if ( m_free->volume.mi.mVec128.m128_f32[0] >= parent->volume.mi.mVec128.m128_f32[0]
          && m_free->volume.mi.mVec128.m128_f32[1] >= parent->volume.mi.mVec128.m128_f32[1]
          && m_free->volume.mi.mVec128.m128_f32[2] >= parent->volume.mi.mVec128.m128_f32[2]
          && parent->volume.mx.mVec128.m128_f32[0] >= m_free->volume.mx.mVec128.m128_f32[0]
          && parent->volume.mx.mVec128.m128_f32[1] >= m_free->volume.mx.mVec128.m128_f32[1]
          && parent->volume.mx.mVec128.m128_f32[2] >= m_free->volume.mx.mVec128.m128_f32[2] )
        {
          break;
        }
        p_mVec128 = &parent->childs[1]->volume.mi.mVec128;
        v14 = &parent->childs[0]->volume.mi.mVec128;
        v15 = _mm_max_ps(v14[1], p_mVec128[1]);
        parent->volume.mi.mVec128 = _mm_min_ps(*v14, *p_mVec128);
        parent->volume.mx.mVec128 = v15;
        m_free = parent;
        parent = parent->parent;
      }
      while ( parent );
    }
    else
    {
      m_free->dataAsInt = (int)v4;
      v4->parent = m_free;
      m_free->childs[1] = leaf;
      leaf->parent = m_free;
      v3->m_root = m_free;
    }
  }
  else
  {
    pdbvt->m_root = leaf;
    leaf->parent = 0;
  }
}
