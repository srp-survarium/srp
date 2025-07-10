void __thiscall Opcode::AABBQuantizedNoLeafTree::~AABBQuantizedNoLeafTree(Opcode::AABBQuantizedNoLeafTree *this)
{
  bool v2; // zf

  v2 = this->mNodes == 0;
  this->__vftable = (Opcode::AABBQuantizedNoLeafTree_vtbl *)&Opcode::AABBQuantizedNoLeafTree::`vftable';
  if ( !v2 )
  {
    this->m_allocator->call_free(this->m_allocator, &this->mNodes[-1].mPosData);
    this->mNodes = 0;
  }
  this->__vftable = (Opcode::AABBQuantizedNoLeafTree_vtbl *)&Opcode::AABBOptimizedTree::`vftable';
}
