void __thiscall vostok::collision::colliders::convex_geometry::calculate_triangles(
        vostok::collision::colliders::convex_geometry *this,
        const Opcode::AABBNoLeafNode *node)
{
  while ( node )
  {
    if ( (node->mPosData & 1) != 0 )
      ++this->m_result;
    else
      vostok::collision::colliders::convex_geometry::calculate_triangles(
        this,
        (const Opcode::AABBNoLeafNode *)node->mPosData);
    if ( (node->mNegData & 1) != 0 )
    {
      ++this->m_result;
      return;
    }
    node = (const Opcode::AABBNoLeafNode *)node->mNegData;
  }
}
