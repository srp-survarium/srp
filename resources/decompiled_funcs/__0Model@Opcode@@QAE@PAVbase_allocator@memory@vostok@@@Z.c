void __userpurge Opcode::Model::Model(
        Opcode::Model *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::memory::base_allocator *allocator)
{
  a2[1] = 0;
  a2[2] = 0;
  a2[3] = 0;
  a2[4] = 0;
  a2[5] = allocator;
  *a2 = &Opcode::Model::`vftable';
}
