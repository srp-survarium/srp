void __thiscall Opcode::AABBNoLeafTree::~AABBNoLeafTree(Opcode::AABBNoLeafTree *this)
{
  bool v2; // zf
  Opcode::AABBNoLeafNode *mNodes; // eax
  vostok::memory::base_allocator *m_allocator; // ecx

  v2 = this->mNodes == 0;
  this->__vftable = (Opcode::AABBNoLeafTree_vtbl *)&Opcode::AABBNoLeafTree::`vftable';
  if ( !v2 )
  {
    mNodes = this->mNodes;
    m_allocator = this->m_allocator;
    if ( mNodes )
      m_allocator->call_free(
        m_allocator,
        &mNodes[-1].mPosData,
        "Opcode::AABBNoLeafTree::~AABBNoLeafTree",
        ".\\OPC_OptimizedTree.cpp",
        315u);
    this->mNodes = 0;
  }
  this->__vftable = (Opcode::AABBNoLeafTree_vtbl *)&Opcode::AABBOptimizedTree::`vftable';
}
