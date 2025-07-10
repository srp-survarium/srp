void __thiscall vostok::collision::colliders::cuboid_geometry::query(
        vostok::collision::colliders::cuboid_geometry *this,
        const Opcode::AABBNoLeafNode *node)
{
  __int32 v4; // eax
  unsigned int mPosData; // edx
  unsigned int mNegData; // eax

  while ( 1 )
  {
    v4 = vostok::collision::colliders::cuboid_geometry::intersects_aabb(node, this) - 1;
    if ( !v4 )
      break;
    if ( v4 == 1 )
      return;
    mPosData = node->mPosData;
    if ( (mPosData & 1) != 0 )
      vostok::collision::colliders::cuboid_geometry::add_triangle(this, mPosData >> 1);
    else
      vostok::collision::colliders::cuboid_geometry::query(this, (const Opcode::AABBNoLeafNode *)node->mPosData);
    mNegData = node->mNegData;
    if ( (mNegData & 1) != 0 )
    {
      vostok::collision::colliders::cuboid_geometry::add_triangle(this, mNegData >> 1);
      return;
    }
    node = (const Opcode::AABBNoLeafNode *)node->mNegData;
  }
  vostok::collision::colliders::cuboid_geometry::add_triangles(this, node);
}
