void __thiscall vostok::collision::colliders::cuboid_geometry::query(
        vostok::collision::colliders::cuboid_geometry *this,
        const Opcode::AABBNoLeafNode *node)
{
  int v4; // eax
  vostok::collision::colliders::cuboid_geometry *v5; // ecx
  unsigned int mPosData; // eax
  vostok::collision::colliders::cuboid_geometry *v7; // ecx
  unsigned int mNegData; // eax
  vostok::math::cuboid *v9; // [esp-4h] [ebp-3Ch]
  IceMaths::Point mExtents; // [esp+8h] [ebp-30h] BYREF
  IceMaths::Point mCenter; // [esp+14h] [ebp-24h] BYREF
  vostok::math::aabb aabb; // [esp+20h] [ebp-18h] BYREF

  while ( 1 )
  {
    mCenter = node->mAABB.mCenter;
    mExtents = node->mAABB.mExtents;
    vostok::math::create_aabb_center_radius(
      (const vostok::math::float3 *)&mExtents,
      (const vostok::math::float3 *)&mCenter,
      &aabb);
    v4 = vostok::math::cuboid::test_inexact(v9, (int)this->m_cuboid, (vostok::math::aabb_plane *)&aabb) - 1;
    if ( !v4 )
      break;
    if ( v4 == 1 )
      return;
    mPosData = node->mPosData;
    if ( (mPosData & 1) != 0 )
      vostok::collision::colliders::cuboid_geometry::add_triangle(v5, (int)this, mPosData >> 1);
    else
      vostok::collision::colliders::cuboid_geometry::query(this, (const Opcode::AABBNoLeafNode *)node->mPosData);
    mNegData = node->mNegData;
    if ( (mNegData & 1) != 0 )
    {
      vostok::collision::colliders::cuboid_geometry::add_triangle(v7, (int)this, mNegData >> 1);
      return;
    }
    node = (const Opcode::AABBNoLeafNode *)node->mNegData;
  }
  vostok::collision::colliders::cuboid_geometry::add_triangles(this, node);
}
