void __userpurge btDbvt::update(btDbvtNode *leaf@<edi>, btDbvt *this, btDbvtAabbMm *volume)
{
  btDbvtNode *m_root; // eax
  int m_lkhd; // esi
  int i; // edx

  m_root = removeleaf(leaf, this);
  if ( m_root )
  {
    m_lkhd = this->m_lkhd;
    if ( m_lkhd < 0 )
    {
      m_root = this->m_root;
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
  leaf->volume = *volume;
  insertleaf(m_root, this, leaf);
}


void __usercall btDbvt::update(btDbvt *this@<esi>, btDbvtNode *leaf@<edi>)
{
  btDbvtNode *m_root; // eax
  btDbvt *v3; // [esp+0h] [ebp-8h]

  m_root = removeleaf(leaf, v3);
  if ( m_root )
    m_root = this->m_root;
  insertleaf(m_root, this, leaf);
}


char __userpurge btDbvt::update@<al>(
        btDbvtAabbMm *volume@<eax>,
        const btVector3 *velocity@<ecx>,
        btDbvt *this,
        btDbvtNode *leaf,
        float margin)
{
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4

  if ( volume->mi.mVec128.m128_f32[0] >= leaf->volume.mi.mVec128.m128_f32[0]
    && volume->mi.mVec128.m128_f32[1] >= leaf->volume.mi.mVec128.m128_f32[1]
    && volume->mi.mVec128.m128_f32[2] >= leaf->volume.mi.mVec128.m128_f32[2]
    && leaf->volume.mx.mVec128.m128_f32[0] >= volume->mx.mVec128.m128_f32[0]
    && leaf->volume.mx.mVec128.m128_f32[1] >= volume->mx.mVec128.m128_f32[1]
    && leaf->volume.mx.mVec128.m128_f32[2] >= volume->mx.mVec128.m128_f32[2] )
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
  btDbvt::update(leaf, this, volume);
  return 1;
}
