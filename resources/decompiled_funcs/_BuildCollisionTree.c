void __cdecl BuildCollisionTree(
        Opcode::AABBCollisionNode *linear,
        unsigned int box_id,
        unsigned int *current_id,
        const Opcode::AABBTreeNode *current_node)
{
  unsigned int v4; // ecx
  const Opcode::AABBTreeNode *v5; // esi
  Opcode::AABBCollisionNode *v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // esi
  unsigned int v10; // eax
  Opcode::AABBCollisionNode *v11; // eax

  v4 = box_id;
  v5 = current_node;
  linear[box_id].mAABB.mCenter.x = current_node->mBV.mCenter.x;
  v6 = &linear[box_id];
  v6->mAABB.mCenter.y = current_node->mBV.mCenter.y;
  v6->mAABB.mCenter.z = current_node->mBV.mCenter.z;
  for ( v6->mAABB.mExtents = current_node->mBV.mExtents; (v5->mPos & 0xFFFFFFFE) != 0; box_id = v8 )
  {
    v7 = *current_id;
    v8 = *current_id + 1;
    *current_id += 2;
    *(&linear->mData + 8 * v4 - box_id) = (unsigned int)&linear[v7];
    BuildCollisionTree(linear, v7, current_id, (const Opcode::AABBTreeNode *)(v5->mPos & 0xFFFFFFFE));
    v9 = v5->mPos & 0xFFFFFFFE;
    if ( v9 )
      v5 = (const Opcode::AABBTreeNode *)(v9 + 36);
    else
      v5 = 0;
    v10 = v8;
    linear[v10].mAABB.mCenter.x = v5->mBV.mCenter.x;
    linear[v10].mAABB.mCenter.y = v5->mBV.mCenter.y;
    v11 = &linear[v8];
    v11->mAABB.mCenter.z = v5->mBV.mCenter.z;
    v11 = (Opcode::AABBCollisionNode *)((char *)v11 + 12);
    v11->mAABB.mCenter.x = v5->mBV.mExtents.x;
    v11->mAABB.mCenter.y = v5->mBV.mExtents.y;
    v4 = v8;
    v11->mAABB.mCenter.z = v5->mBV.mExtents.z;
  }
  linear[v4].mData = (2 * *v5->mNodePrimitives) | 1;
}
