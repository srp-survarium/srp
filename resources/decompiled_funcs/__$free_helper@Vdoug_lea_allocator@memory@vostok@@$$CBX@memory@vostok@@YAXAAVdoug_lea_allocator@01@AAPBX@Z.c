void __usercall ___free_helper_Vdoug_lea_allocator_memory_vostok____CBX_memory_vostok__YAXAAVdoug_lea_allocator_01_AAPBX_Z(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        void **pointer@<edi>)
{
  void *v2; // eax
  void *m_arena; // esi

  v2 = *pointer;
  if ( *pointer )
  {
    m_arena = allocator->m_arena;
    allocator->m_out_of_memory = 0;
    vostok_mspace_free(m_arena, v2);
    *pointer = 0;
  }
}
