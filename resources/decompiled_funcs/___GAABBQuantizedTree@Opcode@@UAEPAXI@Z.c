Opcode::AABBQuantizedTree *__thiscall Opcode::AABBQuantizedTree::`scalar deleting destructor'(
        Opcode::AABBQuantizedTree *this,
        char a2)
{
  bool v3; // zf

  v3 = this->mNodes == 0;
  this->__vftable = (Opcode::AABBQuantizedTree_vtbl *)&Opcode::AABBQuantizedTree::`vftable';
  if ( !v3 )
  {
    this->m_allocator->call_free(this->m_allocator, &this->mNodes[-1].mAABB.mExtents[1]);
    this->mNodes = 0;
  }
  this->__vftable = (Opcode::AABBQuantizedTree_vtbl *)&Opcode::AABBOptimizedTree::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
