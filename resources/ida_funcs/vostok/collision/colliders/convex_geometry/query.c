void __thiscall vostok::collision::colliders::convex_geometry::query(
        vostok::collision::colliders::convex_geometry *this,
        const Opcode::AABBNoLeafNode *node)
{
  __int32 v4; // eax

  while ( 1 )
  {
    v4 = vostok::collision::colliders::convex_geometry::intersects_aabb(node, this) - 1;
    if ( !v4 )
      break;
    if ( v4 == 1 )
      return;
    if ( (node->mPosData & 1) != 0 )
      ++this->m_result;
    else
      vostok::collision::colliders::convex_geometry::query(this, (const Opcode::AABBNoLeafNode *)node->mPosData);
    if ( (node->mNegData & 1) != 0 )
    {
      ++this->m_result;
      return;
    }
    node = (const Opcode::AABBNoLeafNode *)node->mNegData;
  }
  vostok::collision::colliders::convex_geometry::calculate_triangles(this, node);
}
