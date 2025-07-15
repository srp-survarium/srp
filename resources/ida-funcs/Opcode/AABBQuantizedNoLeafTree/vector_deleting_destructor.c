Opcode::AABBQuantizedNoLeafTree *__thiscall Opcode::AABBQuantizedNoLeafTree::`vector deleting destructor'(
        Opcode::AABBQuantizedNoLeafTree *this,
        char a2)
{
  bool v3; // zf

  v3 = this->mNodes == 0;
  this->__vftable = (Opcode::AABBQuantizedNoLeafTree_vtbl *)&Opcode::AABBQuantizedNoLeafTree::`vftable';
  if ( !v3 )
  {
    this->m_allocator->call_free(this->m_allocator, &this->mNodes[-1].mPosData);
    this->mNodes = 0;
  }
  this->__vftable = (Opcode::AABBQuantizedNoLeafTree_vtbl *)&Opcode::AABBOptimizedTree::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
