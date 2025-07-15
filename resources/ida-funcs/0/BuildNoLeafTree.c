void __cdecl BuildNoLeafTree(
        Opcode::AABBNoLeafNode *linear,
        unsigned int box_id,
        unsigned int *current_id,
        const Opcode::AABBTreeNode *current_node)
{
  const Opcode::AABBTreeNode *v5; // ecx
  const Opcode::AABBTreeNode *v6; // ebx
  Opcode::AABBNoLeafNode *v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // ecx

  while ( 1 )
  {
    v5 = (const Opcode::AABBTreeNode *)(current_node->mPos & 0xFFFFFFFE);
    v6 = v5 != 0 ? &v5[1] : 0;
    v7 = &linear[box_id];
    v7->mAABB.mCenter.x = current_node->mBV.mCenter.x;
    v7->mAABB.mCenter.y = current_node->mBV.mCenter.y;
    v7->mAABB.mCenter.z = current_node->mBV.mCenter.z;
    v7->mAABB.mExtents.x = current_node->mBV.mExtents.x;
    v7->mAABB.mExtents.y = current_node->mBV.mExtents.y;
    v7->mAABB.mExtents.z = current_node->mBV.mExtents.z;
    if ( (v5->mPos & 0xFFFFFFFE) != 0 )
    {
      v8 = (*current_id)++;
      v7->mPosData = (unsigned int)&linear[v8];
      BuildNoLeafTree(linear, v8, current_id, v5);
      v7 = &linear[box_id];
    }
    else
    {
      v7->mPosData = (2 * *v5->mNodePrimitives) | 1;
    }
    if ( (v6->mPos & 0xFFFFFFFE) == 0 )
      break;
    v9 = (*current_id)++;
    box_id = v9;
    v7->mNegData = (unsigned int)&linear[v9];
    current_node = v6;
  }
  linear[box_id].mNegData = (2 * *v6->mNodePrimitives) | 1;
}
