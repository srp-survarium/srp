void __thiscall btDbvt::update(btDbvt *this, btDbvt *leaf, btDbvtNode *volume, const void *a4)
{
  btDbvtNode *m_root; // eax
  int m_lkhd; // edx
  int i; // esi

  m_root = removeleaf(volume, leaf);
  if ( m_root )
  {
    m_lkhd = leaf->m_lkhd;
    if ( m_lkhd < 0 )
    {
      m_root = leaf->m_root;
    }
    else
    {
      for ( i = 0; i < m_lkhd; m_root = m_root->parent )
      {
        if ( !m_root->parent )
          break;
        ++i;
      }
    }
  }
  qmemcpy(volume, a4, 0x20u);
  insertleaf(m_root, leaf, volume);
}


char __userpurge btDbvt::update@<al>(
        btDbvtAabbMm *volume@<eax>,
        const btVector3 *velocity@<edx>,
        btDbvt *this,
        btDbvt *leaf,
        float margin)
{
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4

  if ( volume->mi.mVec128.m128_f32[0] >= *(float *)&leaf->m_root
    && volume->mi.mVec128.m128_f32[1] >= *(float *)&leaf->m_free
    && volume->mi.mVec128.m128_f32[2] >= *(float *)&leaf->m_lkhd
    && *(float *)&leaf->m_opath >= volume->mx.mVec128.m128_f32[0]
    && *(float *)&leaf->m_stkStack.m_allocator >= volume->mx.mVec128.m128_f32[1]
    && *(float *)&leaf->m_stkStack.m_size >= volume->mx.mVec128.m128_f32[2] )
  {
    return 0;
  }
  volume->mi.mVec128.m128_f32[0] = volume->mi.mVec128.m128_f32[0] - margin;
  volume->mi.mVec128.m128_f32[1] = volume->mi.mVec128.m128_f32[1] - margin;
  volume->mi.mVec128.m128_f32[2] = volume->mi.mVec128.m128_f32[2] - margin;
  volume->mx.mVec128.m128_f32[0] = margin + volume->mx.mVec128.m128_f32[0];
  volume->mx.mVec128.m128_f32[1] = volume->mx.mVec128.m128_f32[1] + margin;
  volume->mx.mVec128.m128_f32[2] = volume->mx.mVec128.m128_f32[2] + margin;
  v6 = velocity->mVec128.m128_f32[0];
  if ( velocity->mVec128.m128_f32[0] <= 0.0 )
    volume->mi.mVec128.m128_f32[0] = volume->mi.mVec128.m128_f32[0] + v6;
  else
    volume->mx.mVec128.m128_f32[0] = v6 + volume->mx.mVec128.m128_f32[0];
  v7 = velocity->mVec128.m128_f32[1];
  if ( v7 <= 0.0 )
    volume->mi.mVec128.m128_f32[1] = volume->mi.mVec128.m128_f32[1] + v7;
  else
    volume->mx.mVec128.m128_f32[1] = volume->mx.mVec128.m128_f32[1] + v7;
  v8 = velocity->mVec128.m128_f32[2];
  if ( v8 <= 0.0 )
    volume->mi.mVec128.m128_f32[2] = v8 + volume->mi.mVec128.m128_f32[2];
  else
    volume->mx.mVec128.m128_f32[2] = volume->mx.mVec128.m128_f32[2] + v8;
  btDbvt::update(leaf, this, (btDbvtNode *)leaf, volume);
  return 1;
}
