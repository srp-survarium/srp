void __thiscall Opcode::AABBQuantizedNoLeafTree::~AABBQuantizedNoLeafTree(Opcode::AABBQuantizedNoLeafTree *this)
{
  bool v2; // zf
  Opcode::AABBQuantizedNoLeafNode *mNodes; // eax
  vostok::memory::base_allocator *m_allocator; // ecx

  v2 = this->mNodes == 0;
  this->__vftable = (Opcode::AABBQuantizedNoLeafTree_vtbl *)&Opcode::AABBQuantizedNoLeafTree::`vftable';
  if ( !v2 )
  {
    mNodes = this->mNodes;
    m_allocator = this->m_allocator;
    if ( mNodes )
      m_allocator->call_free(
        m_allocator,
        &mNodes[-1].mPosData,
        "Opcode::AABBQuantizedNoLeafTree::~AABBQuantizedNoLeafTree",
        ".\\OPC_OptimizedTree.cpp",
        689u);
    this->mNodes = 0;
  }
  this->__vftable = (Opcode::AABBQuantizedNoLeafTree_vtbl *)&Opcode::AABBOptimizedTree::`vftable';
}
