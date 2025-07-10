unsigned int *__usercall vostok::memory::new_array_helper<unsigned int>::call<vostok::memory::base_allocator>@<eax>(
        vostok::memory::base_allocator *allocator@<ecx>,
        const unsigned int count@<esi>)
{
  _DWORD *v2; // eax
  unsigned int *result; // eax
  unsigned int *v4; // edx
  unsigned int *i; // ecx

  v2 = allocator->call_malloc(allocator, 4 * count + 8);
  *v2 = count;
  result = v2 + 2;
  *(result - 1) = 4;
  v4 = &result[count];
  for ( i = result; i != v4; ++i )
  {
    if ( i )
      *i = 0;
  }
  return result;
}
