void __thiscall vostok::collision::colliders::aabb_geometry::add_triangles(
        vostok::collision::colliders::aabb_geometry *this,
        const Opcode::AABBNoLeafNode *node)
{
  unsigned int mPosData; // eax
  unsigned int mNegData; // eax

  while ( node )
  {
    mPosData = node->mPosData;
    if ( (mPosData & 1) != 0 )
      vostok::collision::colliders::aabb_geometry::add_triangle(this, (int)this, mPosData >> 1);
    else
      vostok::collision::colliders::aabb_geometry::add_triangles(this, (const Opcode::AABBNoLeafNode *)node->mPosData);
    mNegData = node->mNegData;
    if ( (mNegData & 1) != 0 )
    {
      vostok::collision::colliders::aabb_geometry::add_triangle(this, (int)this, mNegData >> 1);
      return;
    }
    node = (const Opcode::AABBNoLeafNode *)node->mNegData;
  }
}
