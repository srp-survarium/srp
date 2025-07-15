char __thiscall Opcode::AABBNoLeafTree::Build(Opcode::AABBNoLeafTree *this, unsigned int tree)
{
  Opcode::AABBTree *v2; // ebx
  unsigned int v5; // eax
  unsigned int v6; // eax
  bool v7; // zf
  Opcode::AABBNoLeafNode *v8; // eax
  Opcode::AABBNoLeafNode *mNodes; // [esp-10h] [ebp-18h]

  v2 = (Opcode::AABBTree *)tree;
  if ( !tree )
    return 0;
  v5 = *(_DWORD *)(tree + 32);
  if ( *(_DWORD *)(tree + 48) != 2 * v5 - 1 )
    return 0;
  v6 = v5 - 1;
  if ( this->mNbNodes != v6 )
  {
    v7 = this->mNodes == 0;
    this->mNbNodes = v6;
    if ( !v7 )
    {
      this->m_allocator->call_free(this->m_allocator, &this->mNodes[-1].mPosData);
      this->mNodes = 0;
    }
    v8 = vostok::memory::new_array_helper<Opcode::AABBNoLeafNode>::call<vostok::memory::base_allocator>(
           this->m_allocator,
           this->mNbNodes);
    this->mNodes = v8;
    if ( !v8 )
      return 0;
  }
  mNodes = this->mNodes;
  tree = 1;
  BuildNoLeafTree(mNodes, 0, &tree, v2);
  return 1;
}
