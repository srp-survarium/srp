void __usercall Opcode::AABBNoLeafTree::AABBNoLeafTree(
        Opcode::AABBNoLeafTree *this@<eax>,
        vostok::memory::base_allocator *allocator@<edx>)
{
  this->mNbNodes = 0;
  this->m_allocator = allocator;
  this->__vftable = (Opcode::AABBNoLeafTree_vtbl *)&Opcode::AABBNoLeafTree::`vftable';
  this->mNodes = 0;
}
