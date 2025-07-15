void __thiscall vostok::memory::stack_allocator::initialize_impl(
        vostok::memory::stack_allocator *this,
        void *arena,
        unsigned __int64 size,
        const char *arena_id)
{
  this->m_arena_current_position = arena;
}
