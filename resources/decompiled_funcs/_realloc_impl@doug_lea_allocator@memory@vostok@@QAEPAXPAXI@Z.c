int *__thiscall vostok::memory::doug_lea_allocator::realloc_impl(
        vostok::memory::doug_lea_allocator *this,
        char *pointer,
        unsigned int new_size)
{
  bool v4; // al
  malloc_state *m_arena; // eax

  v4 = this->m_out_of_memory && new_size;
  this->m_out_of_memory = v4;
  if ( new_size )
  {
    if ( pointer )
      vostok::memory::doug_lea_allocator::usable_size(this, pointer);
    m_arena = (malloc_state *)this->m_arena;
    if ( pointer )
      return (int *)internal_realloc(m_arena, (unsigned __int8 *)pointer, new_size);
    else
      return vostok_mspace_malloc(m_arena, new_size);
  }
  else
  {
    if ( pointer )
    {
      this->m_out_of_memory = 0;
      vostok_mspace_free((malloc_state *)this->m_arena, pointer);
    }
    return 0;
  }
}
