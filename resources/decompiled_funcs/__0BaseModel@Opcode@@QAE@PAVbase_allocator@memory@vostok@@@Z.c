void __userpurge Opcode::BaseModel::BaseModel(
        Opcode::BaseModel *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::memory::base_allocator *allocator)
{
  a2[1] = 0;
  a2[2] = 0;
  a2[3] = 0;
  a2[4] = 0;
  *a2 = &Opcode::BaseModel::`vftable';
  a2[5] = allocator;
}
