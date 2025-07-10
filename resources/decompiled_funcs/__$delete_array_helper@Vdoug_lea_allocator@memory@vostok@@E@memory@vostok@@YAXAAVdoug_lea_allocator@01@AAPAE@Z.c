void __usercall vostok::memory::delete_array_helper<vostok::memory::doug_lea_allocator,unsigned char>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        unsigned __int8 **pointer@<eax>)
{
  void *m_arena; // esi
  unsigned __int8 *v3; // eax

  m_arena = allocator->m_arena;
  v3 = *pointer - 8;
  allocator->m_out_of_memory = 0;
  vostok_mspace_free(m_arena, v3);
}
