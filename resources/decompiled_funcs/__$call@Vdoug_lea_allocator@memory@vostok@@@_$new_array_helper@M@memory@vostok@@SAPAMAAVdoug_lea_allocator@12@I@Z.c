float *__usercall vostok::memory::new_array_helper<float>::call<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        const unsigned int count@<esi>)
{
  char *v2; // eax
  float *result; // eax
  float *v4; // edx
  float *i; // ecx

  v2 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 4 * count + 8);
  *(_DWORD *)v2 = count;
  result = (float *)(v2 + 8);
  *((_DWORD *)result - 1) = 4;
  v4 = &result[count];
  for ( i = result; i != v4; ++i )
  {
    if ( i )
      *i = 0.0;
  }
  return result;
}
