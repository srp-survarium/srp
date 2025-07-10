void __usercall Opcode::AABBQuantizedTree::AABBQuantizedTree(
        Opcode::AABBQuantizedTree *this@<eax>,
        vostok::memory::base_allocator *allocator@<edx>)
{
  this->mNbNodes = 0;
  this->m_allocator = allocator;
  this->__vftable = (Opcode::AABBQuantizedTree_vtbl *)&Opcode::AABBQuantizedTree::`vftable';
  this->mNodes = 0;
}
