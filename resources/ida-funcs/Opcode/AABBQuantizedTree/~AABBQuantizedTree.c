void __thiscall Opcode::AABBQuantizedTree::~AABBQuantizedTree(Opcode::AABBQuantizedTree *this)
{
  bool v2; // zf
  Opcode::AABBQuantizedNode *mNodes; // eax
  vostok::memory::base_allocator *m_allocator; // ecx

  v2 = this->mNodes == 0;
  this->__vftable = (Opcode::AABBQuantizedTree_vtbl *)&Opcode::AABBQuantizedTree::`vftable';
  if ( !v2 )
  {
    mNodes = this->mNodes;
    m_allocator = this->m_allocator;
    if ( mNodes )
      m_allocator->call_free(
        m_allocator,
        &mNodes[-1].mAABB.mExtents[1],
        "Opcode::AABBQuantizedTree::~AABBQuantizedTree",
        ".\\OPC_OptimizedTree.cpp",
        575u);
    this->mNodes = 0;
  }
  this->__vftable = (Opcode::AABBQuantizedTree_vtbl *)&Opcode::AABBOptimizedTree::`vftable';
}
