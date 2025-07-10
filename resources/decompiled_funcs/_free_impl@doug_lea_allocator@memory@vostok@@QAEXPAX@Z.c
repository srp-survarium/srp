void __thiscall vostok::memory::doug_lea_allocator::free_impl(vostok::memory::doug_lea_allocator *this, char *pointer)
{
  malloc_state *m_arena; // esi

  if ( pointer )
  {
    m_arena = (malloc_state *)this->m_arena;
    this->m_out_of_memory = 0;
    vostok_mspace_free(m_arena, pointer);
  }
}
