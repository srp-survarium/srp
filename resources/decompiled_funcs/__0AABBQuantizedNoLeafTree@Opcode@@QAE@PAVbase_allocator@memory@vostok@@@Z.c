void __usercall Opcode::AABBQuantizedNoLeafTree::AABBQuantizedNoLeafTree(
        Opcode::AABBQuantizedNoLeafTree *this@<eax>,
        vostok::memory::base_allocator *allocator@<edx>)
{
  this->mNbNodes = 0;
  this->m_allocator = allocator;
  this->__vftable = (Opcode::AABBQuantizedNoLeafTree_vtbl *)&Opcode::AABBQuantizedNoLeafTree::`vftable';
  this->mNodes = 0;
}
