void __usercall vostok::memory::delete_helper<vostok::memory::base_allocator,Opcode::AABBTree>(
        Opcode::AABBTree **pointer@<edi>,
        Opcode::AABBTree *a2@<ecx>,
        vostok::memory::base_allocator *allocator)
{
  void *v3; // esi

  v3 = *pointer;
  if ( *pointer )
  {
    Opcode::AABBTree::Release(a2);
    allocator->call_free(allocator, v3);
    *pointer = 0;
  }
}
