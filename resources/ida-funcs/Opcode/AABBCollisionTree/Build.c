char __thiscall Opcode::AABBCollisionTree::Build(Opcode::AABBCollisionTree *this, Opcode::AABBTree *tree)
{
  Opcode::AABBTree *v4; // ecx
  unsigned int mTotalNbNodes; // eax
  bool v7; // zf
  Opcode::AABBCollisionNode *mNodes; // eax
  Opcode::AABBCollisionNode *v9; // eax
  Opcode::AABBCollisionNode *v10; // [esp-10h] [ebp-18h]
  unsigned int v11; // [esp+4h] [ebp-4h] BYREF

  v4 = tree;
  if ( !tree )
    return 0;
  mTotalNbNodes = tree->mTotalNbNodes;
  if ( mTotalNbNodes != 2 * tree->mNbPrimitives - 1 )
    return 0;
  if ( this->mNbNodes != mTotalNbNodes )
  {
    v7 = this->mNodes == 0;
    this->mNbNodes = mTotalNbNodes;
    if ( !v7 )
    {
      mNodes = this->mNodes;
      if ( mNodes )
        this->m_allocator->call_free(
          this->m_allocator,
          &mNodes[-1].mAABB.mExtents.z,
          "Opcode::AABBCollisionTree::Build",
          ".\\OPC_OptimizedTree.cpp",
          243u);
      this->mNodes = 0;
    }
    v9 = vostok::memory::new_array_helper<Opcode::AABBCollisionNode>::call<vostok::memory::base_allocator>(
           this->mNbNodes,
           this->m_allocator,
           "Opcode::AABBCollisionTree::Build",
           (const char *const)0xF4);
    this->mNodes = v9;
    if ( v9 )
    {
      v4 = tree;
      goto LABEL_11;
    }
    return 0;
  }
LABEL_11:
  v10 = this->mNodes;
  v11 = 1;
  BuildCollisionTree(v10, 0, &v11, v4);
  return 1;
}
