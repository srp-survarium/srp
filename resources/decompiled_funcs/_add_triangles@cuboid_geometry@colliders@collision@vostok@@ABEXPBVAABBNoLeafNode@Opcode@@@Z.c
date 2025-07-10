void __thiscall vostok::collision::colliders::cuboid_geometry::add_triangles(
        vostok::collision::colliders::cuboid_geometry *this,
        const Opcode::AABBNoLeafNode *node)
{
  const Opcode::AABBNoLeafNode *v2; // esi
  unsigned int mPosData; // edx
  unsigned int mNegData; // eax

  v2 = node;
  if ( node )
  {
    while ( 1 )
    {
      mPosData = v2->mPosData;
      if ( (mPosData & 1) != 0 )
        vostok::collision::colliders::cuboid_geometry::add_triangle(this, mPosData >> 1);
      else
        vostok::collision::colliders::cuboid_geometry::add_triangles(this, (const Opcode::AABBNoLeafNode *)v2->mPosData);
      mNegData = v2->mNegData;
      if ( (mNegData & 1) != 0 )
        break;
      v2 = (const Opcode::AABBNoLeafNode *)v2->mNegData;
      if ( !mNegData )
        return;
    }
    vostok::collision::colliders::cuboid_geometry::add_triangle(this, mNegData >> 1);
  }
}
