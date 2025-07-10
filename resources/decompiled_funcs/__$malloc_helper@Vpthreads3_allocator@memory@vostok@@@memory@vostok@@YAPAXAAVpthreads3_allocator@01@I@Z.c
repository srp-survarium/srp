// attributes: thunk
void *__usercall vostok::memory::malloc_helper<vostok::memory::pthreads3_allocator>@<eax>(unsigned int size@<eax>)
{
  return pt3malloc(size);
}
