unsigned __int8 *__usercall vostok::memory::new_array_helper<unsigned char>::call<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        const unsigned int count@<esi>)
{
  char *v2; // eax
  unsigned __int8 *result; // eax
  unsigned __int8 *i; // ecx

  v2 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, count + 8);
  *(_DWORD *)v2 = count;
  result = (unsigned __int8 *)(v2 + 8);
  *((_DWORD *)result - 1) = 1;
  for ( i = result; i != &result[count]; ++i )
  {
    if ( i )
      *i = 0;
  }
  return result;
}
