char __thiscall Opcode::AABBNoLeafTree::Build(Opcode::AABBNoLeafTree *this, Opcode::AABBTree *tree)
{
  Opcode::AABBTree *v4; // ecx
  unsigned int mNbPrimitives; // eax
  unsigned int v7; // eax
  bool v8; // zf
  Opcode::AABBNoLeafNode *mNodes; // eax
  Opcode::AABBNoLeafNode *v10; // eax
  Opcode::AABBNoLeafNode *v11; // [esp-10h] [ebp-18h]
  unsigned int v12; // [esp+4h] [ebp-4h] BYREF

  v4 = tree;
  if ( !tree )
    return 0;
  mNbPrimitives = tree->mNbPrimitives;
  if ( tree->mTotalNbNodes != 2 * mNbPrimitives - 1 )
    return 0;
  v7 = mNbPrimitives - 1;
  if ( this->mNbNodes != v7 )
  {
    v8 = this->mNodes == 0;
    this->mNbNodes = v7;
    if ( !v8 )
    {
      mNodes = this->mNodes;
      if ( mNodes )
        this->m_allocator->call_free(
          this->m_allocator,
          &mNodes[-1].mPosData,
          "Opcode::AABBNoLeafTree::Build",
          ".\\OPC_OptimizedTree.cpp",
          338u);
      this->mNodes = 0;
    }
    v10 = vostok::memory::new_array_helper<Opcode::AABBNoLeafNode>::call<vostok::memory::base_allocator>(
            this->mNbNodes,
            this->m_allocator,
            "Opcode::AABBNoLeafTree::Build",
            (const char *const)0x153);
    this->mNodes = v10;
    if ( v10 )
    {
      v4 = tree;
      goto LABEL_11;
    }
    return 0;
  }
LABEL_11:
  v11 = this->mNodes;
  v12 = 1;
  BuildNoLeafTree(v11, 0, &v12, v4);
  return 1;
}
