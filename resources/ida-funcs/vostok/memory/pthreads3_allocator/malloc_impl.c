char *__userpurge vostok::memory::pthreads3_allocator::malloc_impl@<eax>(
        vostok::memory::pthreads3_allocator *this@<ecx>,
        int size,
        const char *const description,
        char *function,
        const char *const file,
        const unsigned int line)
{
  char *result; // eax
  vostok::memory::base_allocator *v7; // [esp-4h] [ebp-4h]

  result = pt3malloc((unsigned int)description);
  if ( result )
    return (char *)vostok::memory::base_allocator::on_malloc(v7, size, result, (unsigned int)description, 0, function);
  return result;
}
