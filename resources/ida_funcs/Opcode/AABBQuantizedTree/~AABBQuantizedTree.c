void __thiscall Opcode::AABBQuantizedTree::~AABBQuantizedTree(Opcode::AABBQuantizedTree *this)
{
  bool v2; // zf

  v2 = this->mNodes == 0;
  this->__vftable = (Opcode::AABBQuantizedTree_vtbl *)&Opcode::AABBQuantizedTree::`vftable';
  if ( !v2 )
  {
    this->m_allocator->call_free(this->m_allocator, &this->mNodes[-1].mAABB.mExtents[1]);
    this->mNodes = 0;
  }
  this->__vftable = (Opcode::AABBQuantizedTree_vtbl *)&Opcode::AABBOptimizedTree::`vftable';
}
