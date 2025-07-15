void __thiscall vostok::logging::memory_base_allocator_wrapper::deallocate(
        vostok::logging::memory_base_allocator_wrapper *this,
        void *pointer)
{
  vostok::memory::base_allocator *m_allocator; // ecx

  m_allocator = this->m_allocator;
  if ( pointer )
    m_allocator->call_free(
      m_allocator,
      pointer,
      "vostok::logging::memory_base_allocator_wrapper::deallocate",
      "c:\\survarium.deploy\\sources\\vostok/logging/memory_base_allocator_wrapper.h",
      35u);
}
