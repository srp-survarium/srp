char __thiscall Opcode::AABBCollisionTree::Build(Opcode::AABBCollisionTree *this, unsigned int tree)
{
  Opcode::AABBTree *v2; // ebx
  unsigned int v5; // eax
  bool v6; // zf
  Opcode::AABBCollisionNode *v7; // eax
  Opcode::AABBCollisionNode *mNodes; // [esp-10h] [ebp-18h]

  v2 = (Opcode::AABBTree *)tree;
  if ( !tree )
    return 0;
  v5 = *(_DWORD *)(tree + 48);
  if ( v5 != 2 * *(_DWORD *)(tree + 32) - 1 )
    return 0;
  if ( this->mNbNodes != v5 )
  {
    v6 = this->mNodes == 0;
    this->mNbNodes = v5;
    if ( !v6 )
    {
      this->m_allocator->call_free(this->m_allocator, &this->mNodes[-1].mAABB.mExtents.z);
      this->mNodes = 0;
    }
    v7 = vostok::memory::new_array_helper<Opcode::AABBCollisionNode>::call<vostok::memory::base_allocator>(
           this->m_allocator,
           this->mNbNodes);
    this->mNodes = v7;
    if ( !v7 )
      return 0;
  }
  mNodes = this->mNodes;
  tree = 1;
  BuildCollisionTree(mNodes, 0, &tree, v2);
  return 1;
}
