Opcode::AABBCollisionTree *__thiscall Opcode::AABBCollisionTree::`vector deleting destructor'(
        Opcode::AABBCollisionTree *this,
        char a2)
{
  bool v3; // zf

  v3 = this->mNodes == 0;
  this->__vftable = (Opcode::AABBCollisionTree_vtbl *)&Opcode::AABBCollisionTree::`vftable';
  if ( !v3 )
  {
    this->m_allocator->call_free(this->m_allocator, &this->mNodes[-1].mAABB.mExtents.z);
    this->mNodes = 0;
  }
  this->__vftable = (Opcode::AABBCollisionTree_vtbl *)&Opcode::AABBOptimizedTree::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
