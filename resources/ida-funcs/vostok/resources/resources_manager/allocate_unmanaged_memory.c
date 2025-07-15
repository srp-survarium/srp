int *__usercall vostok::resources::resources_manager::allocate_unmanaged_memory@<eax>(
        unsigned int size@<eax>,
        vostok::resources::resources_manager *this)
{
  return vostok::memory::doug_lea_allocator::malloc_impl(&vostok::memory::g_resources_unmanaged_allocator, size);
}
