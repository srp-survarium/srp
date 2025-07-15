void __thiscall vostok::memory::doug_lea_allocator::finalize_impl(vostok::memory::doug_lea_allocator *this)
{
  destroy_mspace((char *)this->m_arena);
}
