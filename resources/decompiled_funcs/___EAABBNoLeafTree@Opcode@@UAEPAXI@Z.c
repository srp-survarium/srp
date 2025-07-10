Opcode::AABBNoLeafTree *__thiscall Opcode::AABBNoLeafTree::`vector deleting destructor'(
        Opcode::AABBNoLeafTree *this,
        char a2)
{
  bool v3; // zf

  v3 = this->mNodes == 0;
  this->__vftable = (Opcode::AABBNoLeafTree_vtbl *)&Opcode::AABBNoLeafTree::`vftable';
  if ( !v3 )
  {
    this->m_allocator->call_free(this->m_allocator, &this->mNodes[-1].mPosData);
    this->mNodes = 0;
  }
  this->__vftable = (Opcode::AABBNoLeafTree_vtbl *)&Opcode::AABBOptimizedTree::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
