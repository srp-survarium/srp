void __cdecl BuildNoLeafTree(
        Opcode::AABBNoLeafNode *linear,
        unsigned int box_id,
        unsigned int *current_id,
        const Opcode::AABBTreeNode *current_node)
{
  const Opcode::AABBTreeNode *v7; // ecx
  Opcode::AABBNoLeafNode *v8; // esi
  float z; // edx
  IceMaths::Point *p_mExtents; // eax
  unsigned int v11; // eax
  unsigned int v12; // ecx
  const Opcode::AABBTreeNode *N; // [esp+14h] [ebp+4h]

  while ( 1 )
  {
    v7 = (const Opcode::AABBTreeNode *)(current_node->mPos & 0xFFFFFFFE);
    N = v7 ? &v7[1] : 0;
    v8 = &linear[box_id];
    v8->mAABB.mCenter.x = current_node->mBV.mCenter.x;
    v8->mAABB.mCenter.y = current_node->mBV.mCenter.y;
    z = current_node->mBV.mCenter.z;
    p_mExtents = &current_node->mBV.mExtents;
    v8->mAABB.mCenter.z = z;
    v8->mAABB.mExtents.x = p_mExtents->x;
    v8->mAABB.mExtents.y = p_mExtents->y;
    v8->mAABB.mExtents.z = p_mExtents->z;
    if ( (v7->mPos & 0xFFFFFFFE) != 0 )
    {
      v11 = (*current_id)++;
      v8->mPosData = (unsigned int)&linear[v11];
      BuildNoLeafTree(linear, v11, current_id, v7);
    }
    else
    {
      v8->mPosData = (2 * *v7->mNodePrimitives) | 1;
    }
    current_node = N;
    if ( (N->mPos & 0xFFFFFFFE) == 0 )
      break;
    v12 = (*current_id)++;
    v8->mNegData = (unsigned int)&linear[v12];
    box_id = v12;
  }
  linear[box_id].mNegData = (2 * *N->mNodePrimitives) | 1;
}
