void __thiscall Opcode::AABBNoLeafTree::~AABBNoLeafTree(Opcode::AABBNoLeafTree *this)
{
  bool v2; // zf

  v2 = this->mNodes == 0;
  this->__vftable = (Opcode::AABBNoLeafTree_vtbl *)&Opcode::AABBNoLeafTree::`vftable';
  if ( !v2 )
  {
    this->m_allocator->call_free(this->m_allocator, &this->mNodes[-1].mPosData);
    this->mNodes = 0;
  }
  this->__vftable = (Opcode::AABBNoLeafTree_vtbl *)&Opcode::AABBOptimizedTree::`vftable';
}
