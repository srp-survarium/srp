void __usercall vostok::memory::stack_allocator::swap(
        vostok::memory::stack_allocator *this@<ecx>,
        vostok::memory::stack_allocator *other@<eax>)
{
  void *m_arena_start; // edx
  void *m_arena_end; // edx
  void *m_arena_current_position; // edx
  const char *m_arena_id; // edx

  m_arena_start = this->m_arena_start;
  this->m_arena_start = other->m_arena_start;
  other->m_arena_start = m_arena_start;
  m_arena_end = this->m_arena_end;
  this->m_arena_end = other->m_arena_end;
  other->m_arena_end = m_arena_end;
  m_arena_current_position = this->m_arena_current_position;
  this->m_arena_current_position = other->m_arena_current_position;
  other->m_arena_current_position = m_arena_current_position;
  m_arena_id = this->m_arena_id;
  this->m_arena_id = other->m_arena_id;
  other->m_arena_id = m_arena_id;
}
