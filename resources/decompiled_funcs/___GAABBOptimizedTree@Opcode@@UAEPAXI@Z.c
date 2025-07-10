Opcode::AABBOptimizedTree *__thiscall Opcode::AABBOptimizedTree::`scalar deleting destructor'(
        Opcode::AABBOptimizedTree *this,
        char a2)
{
  this->__vftable = (Opcode::AABBOptimizedTree_vtbl *)&Opcode::AABBOptimizedTree::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
