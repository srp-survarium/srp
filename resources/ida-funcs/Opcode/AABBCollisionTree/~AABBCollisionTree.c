void __thiscall Opcode::AABBCollisionTree::~AABBCollisionTree(Opcode::AABBCollisionTree *this)
{
  bool v2; // zf
  Opcode::AABBCollisionNode *mNodes; // eax
  vostok::memory::base_allocator *m_allocator; // ecx

  v2 = this->mNodes == 0;
  this->__vftable = (Opcode::AABBCollisionTree_vtbl *)&Opcode::AABBCollisionTree::`vftable';
  if ( !v2 )
  {
    mNodes = this->mNodes;
    m_allocator = this->m_allocator;
    if ( mNodes )
      m_allocator->call_free(
        m_allocator,
        &mNodes[-1].mAABB.mExtents.z,
        "Opcode::AABBCollisionTree::~AABBCollisionTree",
        ".\\OPC_OptimizedTree.cpp",
        220u);
    this->mNodes = 0;
  }
  this->__vftable = (Opcode::AABBCollisionTree_vtbl *)&Opcode::AABBOptimizedTree::`vftable';
}
