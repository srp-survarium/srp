void *__thiscall vostok::logging::memory_base_allocator_wrapper::allocate(
        vostok::logging::memory_base_allocator_wrapper *this,
        unsigned int size)
{
  return this->m_allocator->call_malloc(
           this->m_allocator,
           size,
           "logging::memory_base_allocator_wrapper",
           "vostok::logging::memory_base_allocator_wrapper::allocate",
           "c:\\survarium.deploy\\sources\\vostok/logging/memory_base_allocator_wrapper.h",
           30);
}
