void __usercall Opcode::AABBCollisionTree::AABBCollisionTree(
        Opcode::AABBCollisionTree *this@<eax>,
        vostok::memory::base_allocator *allocator@<edx>)
{
  this->mNbNodes = 0;
  this->m_allocator = allocator;
  this->__vftable = (Opcode::AABBCollisionTree_vtbl *)&Opcode::AABBCollisionTree::`vftable';
  this->mNodes = 0;
}
