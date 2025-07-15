void __thiscall vostok::collision::colliders::aabb_geometry::query(
        vostok::collision::colliders::aabb_geometry *this,
        const Opcode::AABBNoLeafNode *node)
{
  float x; // xmm5_4
  const vostok::math::aabb *m_aabb; // eax
  float v6; // xmm2_4
  float y; // xmm4_4
  float v8; // xmm1_4
  float z; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  unsigned int mPosData; // eax
  unsigned int mNegData; // eax

  while ( 1 )
  {
    x = node->mAABB.mCenter.x;
    m_aabb = this->m_aabb;
    v6 = node->mAABB.mExtents.x;
    if ( (float)(node->mAABB.mCenter.x - v6) > this->m_aabb->max.x )
      break;
    y = node->mAABB.mCenter.y;
    v8 = node->mAABB.mExtents.y;
    if ( (float)(y - v8) > m_aabb->max.y )
      break;
    z = node->mAABB.mCenter.z;
    v10 = node->mAABB.mExtents.z;
    if ( (float)(z - v10) > m_aabb->max.z
      || m_aabb->min.x > (float)(v6 + x)
      || m_aabb->min.y > (float)(v8 + y)
      || m_aabb->min.z > (float)(v10 + z) )
    {
      break;
    }
    v11 = node->mAABB.mExtents.x;
    if ( (float)(x - v11) >= m_aabb->min.x )
    {
      v12 = node->mAABB.mExtents.y;
      if ( (float)(y - v12) >= m_aabb->min.y )
      {
        v13 = node->mAABB.mExtents.z;
        if ( (float)(z - v13) >= m_aabb->min.z
          && m_aabb->max.x >= (float)(v11 + x)
          && m_aabb->max.y >= (float)(v12 + y)
          && m_aabb->max.z >= (float)(v13 + z) )
        {
          vostok::collision::colliders::aabb_geometry::add_triangles(this, node);
          return;
        }
      }
    }
    mPosData = node->mPosData;
    if ( (mPosData & 1) != 0 )
      vostok::collision::colliders::aabb_geometry::test_primitive(this, (float **)this, mPosData >> 1);
    else
      vostok::collision::colliders::aabb_geometry::query(this, (const Opcode::AABBNoLeafNode *)node->mPosData);
    mNegData = node->mNegData;
    if ( (mNegData & 1) != 0 )
    {
      vostok::collision::colliders::aabb_geometry::test_primitive(this, (float **)this, mNegData >> 1);
      return;
    }
    node = (const Opcode::AABBNoLeafNode *)node->mNegData;
  }
}
