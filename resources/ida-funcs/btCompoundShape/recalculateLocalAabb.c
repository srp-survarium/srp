void __thiscall btCompoundShape::recalculateLocalAabb(btCompoundShape *this)
{
  int v2; // esi
  btVector3 *p_m_localAabbMax; // eax
  int j; // ecx
  float v5; // xmm0_4
  float v6; // xmm0_4
  int i; // [esp+Ch] [ebp-24h]
  float v8; // [esp+10h] [ebp-20h] BYREF
  unsigned __int64 v9; // [esp+14h] [ebp-1Ch]
  int v10; // [esp+1Ch] [ebp-14h]
  _BYTE v11[16]; // [esp+20h] [ebp-10h] BYREF

  *(float *)&v9 = FLOAT_9_9999998e17;
  *((float *)&v9 + 1) = FLOAT_9_9999998e17;
  v10 = 0;
  this->m_localAabbMin.mVec128.m128_f32[0] = FLOAT_9_9999998e17;
  *(unsigned __int64 *)((char *)this->m_localAabbMin.mVec128.m128_u64 + 4) = v9;
  this->m_localAabbMin.mVec128.m128_i32[3] = v10;
  v8 = FLOAT_N9_9999998e17;
  *(float *)&v9 = FLOAT_N9_9999998e17;
  *((float *)&v9 + 1) = FLOAT_N9_9999998e17;
  v10 = 0;
  this->m_localAabbMax.mVec128.m128_f32[0] = FLOAT_N9_9999998e17;
  *(unsigned __int64 *)((char *)this->m_localAabbMax.mVec128.m128_u64 + 4) = v9;
  this->m_localAabbMax.mVec128.m128_i32[3] = v10;
  v2 = 0;
  for ( i = 0; i < this->m_children.m_size; ++v2 )
  {
    this->m_children.m_data[v2].m_childShape->getAabb(
      this->m_children.m_data[v2].m_childShape,
      (const btTransform *)&this->m_children.m_data[v2],
      (btVector3 *)&v8,
      (btVector3 *)v11);
    p_m_localAabbMax = &this->m_localAabbMax;
    for ( j = 0; j < 12; j += 4 )
    {
      v5 = *(float *)((char *)&v8 + j);
      if ( p_m_localAabbMax[-1].mVec128.m128_f32[0] > v5 )
        p_m_localAabbMax[-1].mVec128.m128_f32[0] = v5;
      v6 = *(float *)&v11[j];
      if ( v6 > p_m_localAabbMax->mVec128.m128_f32[0] )
        p_m_localAabbMax->mVec128.m128_f32[0] = v6;
      p_m_localAabbMax = (btVector3 *)((char *)p_m_localAabbMax + 4);
    }
    ++i;
  }
}
