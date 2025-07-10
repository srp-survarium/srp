void __usercall Opcode::MeshInterface::MeshInterface(
        Opcode::MeshInterface *this@<eax>,
        vostok::memory::base_allocator *allocator@<edx>)
{
  this->mNbTris = 0;
  this->mNbVerts = 0;
  this->m_allocator = allocator;
  this->mTris = 0;
  this->mVerts = 0;
}
