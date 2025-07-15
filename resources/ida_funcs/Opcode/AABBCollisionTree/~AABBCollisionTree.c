void __thiscall Opcode::AABBCollisionTree::~AABBCollisionTree(Opcode::AABBCollisionTree *this)
{
  bool v2; // zf

  v2 = this->mNodes == 0;
  this->__vftable = (Opcode::AABBCollisionTree_vtbl *)&Opcode::AABBCollisionTree::`vftable';
  if ( !v2 )
  {
    this->m_allocator->call_free(this->m_allocator, &this->mNodes[-1].mAABB.mExtents.z);
    this->mNodes = 0;
  }
  this->__vftable = (Opcode::AABBCollisionTree_vtbl *)&Opcode::AABBOptimizedTree::`vftable';
}
