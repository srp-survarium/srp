void __thiscall vostok::collision::colliders::convex_geometry::calculate_triangles(
        vostok::collision::colliders::convex_geometry *this,
        const Opcode::AABBNoLeafNode *node)
{
  const Opcode::AABBNoLeafNode *v2; // esi
  unsigned int mNegData; // eax

  v2 = node;
  if ( node )
  {
    while ( 1 )
    {
      if ( (v2->mPosData & 1) != 0 )
        ++this->m_result;
      else
        vostok::collision::colliders::convex_geometry::calculate_triangles(
          this,
          (const Opcode::AABBNoLeafNode *)v2->mPosData);
      mNegData = v2->mNegData;
      if ( (mNegData & 1) != 0 )
        break;
      v2 = (const Opcode::AABBNoLeafNode *)v2->mNegData;
      if ( !mNegData )
        return;
    }
    ++this->m_result;
  }
}
