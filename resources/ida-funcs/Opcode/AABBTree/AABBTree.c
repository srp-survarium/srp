void __userpurge Opcode::AABBTree::AABBTree(
        Opcode::AABBTree *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::memory::base_allocator *allocator)
{
  a2[6] = 0;
  a2[7] = 0;
  a2[8] = 0;
  a2[9] = 0;
  a2[10] = 0;
  a2[12] = 0;
  a2[13] = allocator;
}
