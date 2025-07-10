void __thiscall btCompoundShape::recalculateLocalAabb(btCompoundShape *this)
{
  int v2; // edi
  bool v3; // cc
  int v4; // [esp+54h] [ebp-24h]
  unsigned __int64 v5; // [esp+58h] [ebp-20h] BYREF
  float v6; // [esp+60h] [ebp-18h]
  int v7; // [esp+64h] [ebp-14h]
  float v8; // [esp+68h] [ebp-10h] BYREF
  float v9; // [esp+6Ch] [ebp-Ch]
  float v10; // [esp+70h] [ebp-8h]

  v6 = 9.9999998e17;
  this->m_localAabbMin.mVec128.m128_u64[0] = 0x5D5E0B6B5D5E0B6BLL;
  v7 = 0;
  this->m_localAabbMin.mVec128.m128_u64[1] = LODWORD(v6);
  v5 = 0xDD5E0B6BDD5E0B6BuLL;
  v6 = -9.9999998e17;
  v2 = 0;
  v3 = this->m_children.m_size <= 0;
  this->m_localAabbMax.mVec128.m128_u64[0] = 0xDD5E0B6BDD5E0B6BuLL;
  v7 = 0;
  this->m_localAabbMax.mVec128.m128_u64[1] = LODWORD(v6);
  v4 = 0;
  if ( !v3 )
  {
    do
    {
      this->m_children.m_data[v2].m_childShape->getAabb(
        this->m_children.m_data[v2].m_childShape,
        (const btTransform *)&this->m_children.m_data[v2],
        (btVector3 *)&v5,
        (btVector3 *)&v8);
      if ( this->m_localAabbMin.mVec128.m128_f32[0] > *(float *)&v5 )
        this->m_localAabbMin.mVec128.m128_i32[0] = v5;
      if ( v8 > this->m_localAabbMax.mVec128.m128_f32[0] )
        this->m_localAabbMax.mVec128.m128_f32[0] = v8;
      if ( this->m_localAabbMin.mVec128.m128_f32[1] > *((float *)&v5 + 1) )
        this->m_localAabbMin.mVec128.m128_i32[1] = HIDWORD(v5);
      if ( v9 > this->m_localAabbMax.mVec128.m128_f32[1] )
        this->m_localAabbMax.mVec128.m128_f32[1] = v9;
      if ( this->m_localAabbMin.mVec128.m128_f32[2] > v6 )
        this->m_localAabbMin.mVec128.m128_f32[2] = v6;
      if ( v10 > this->m_localAabbMax.mVec128.m128_f32[2] )
        this->m_localAabbMax.mVec128.m128_f32[2] = v10;
      ++v2;
      ++v4;
    }
    while ( v4 < this->m_children.m_size );
  }
}
