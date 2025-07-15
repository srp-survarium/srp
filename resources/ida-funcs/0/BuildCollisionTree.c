void __cdecl BuildCollisionTree(
        Opcode::AABBCollisionNode *linear,
        unsigned int box_id,
        unsigned int *current_id,
        const Opcode::AABBTreeNode *current_node)
{
  unsigned int v4; // edx
  Opcode::AABBCollisionNode *v5; // ecx
  Opcode::AABBCollisionNode *i; // eax
  unsigned int v8; // eax
  unsigned int v9; // esi

  v4 = box_id;
  v5 = linear;
  for ( i = &linear[box_id]; ; i = &linear[v9] )
  {
    i->mAABB.mCenter.x = current_node->mBV.mCenter.x;
    i->mAABB.mCenter.y = current_node->mBV.mCenter.y;
    i->mAABB.mCenter.z = current_node->mBV.mCenter.z;
    i->mAABB.mExtents.x = current_node->mBV.mExtents.x;
    i->mAABB.mExtents.y = current_node->mBV.mExtents.y;
    i->mAABB.mExtents.z = current_node->mBV.mExtents.z;
    if ( (current_node->mPos & 0xFFFFFFFE) == 0 )
      break;
    v8 = *current_id;
    v9 = *current_id + 1;
    *current_id += 2;
    v5[box_id].mData = (unsigned int)&v5[v8];
    BuildCollisionTree(v5, v8, current_id, (const Opcode::AABBTreeNode *)(current_node->mPos & 0xFFFFFFFE));
    v5 = linear;
    v4 = v9;
    current_node = (current_node->mPos & 0xFFFFFFFE) != 0
                 ? (const Opcode::AABBTreeNode *)((current_node->mPos & 0xFFFFFFFE) + 36)
                 : 0;
    box_id = v9;
  }
  v5[v4].mData = (2 * *current_node->mNodePrimitives) | 1;
}
