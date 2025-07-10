void __usercall vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::light const>(
        vostok::memory::doug_lea_allocator *allocator@<eax>,
        vostok::render::light *a2@<ecx>,
        const vostok::render::light **pointer)
{
  void *v3; // edi

  v3 = (void *)*pointer;
  if ( *pointer )
  {
    vostok::render::light::~light(a2);
    allocator->m_out_of_memory = 0;
    vostok_mspace_free(allocator->m_arena, v3);
    *pointer = 0;
  }
}
