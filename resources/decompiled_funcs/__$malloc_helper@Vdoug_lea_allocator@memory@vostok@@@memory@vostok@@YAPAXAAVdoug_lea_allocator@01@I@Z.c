void *__usercall vostok::memory::malloc_helper<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        unsigned int size@<eax>)
{
  return vostok::memory::doug_lea_allocator::malloc_impl(allocator, size);
}
