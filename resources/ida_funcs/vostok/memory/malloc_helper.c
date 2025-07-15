void *__fastcall vostok::memory::malloc_helper<vostok::memory::base_allocator>(
        vostok::memory::base_allocator *allocator,
        unsigned int size)
{
  return allocator->call_malloc(allocator, size);
}


void *__usercall vostok::memory::malloc_helper<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        unsigned int size@<eax>)
{
  return vostok::memory::doug_lea_allocator::malloc_impl(allocator, size);
}


// attributes: thunk
void *__usercall vostok::memory::malloc_helper<vostok::memory::pthreads3_allocator>@<eax>(unsigned int size@<eax>)
{
  return pt3malloc(size);
}
