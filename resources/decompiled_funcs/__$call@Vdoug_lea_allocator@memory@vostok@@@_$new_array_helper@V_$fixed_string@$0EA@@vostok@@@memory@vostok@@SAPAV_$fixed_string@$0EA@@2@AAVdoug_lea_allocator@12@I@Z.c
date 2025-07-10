vostok::fixed_string<64> *__usercall vostok::memory::new_array_helper<vostok::fixed_string<64>>::call<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        const unsigned int count@<edi>)
{
  char *v2; // eax
  vostok::fixed_string<64> *result; // eax
  char *m_buffer; // ecx

  v2 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 76 * count + 8);
  *(_DWORD *)v2 = count;
  v2 += 4;
  *(_DWORD *)v2 = 76;
  result = (vostok::fixed_string<64> *)(v2 + 4);
  if ( result != &result[count] )
  {
    m_buffer = result->m_buffer;
    do
    {
      if ( m_buffer != (char *)12 )
      {
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 64;
        *m_buffer = 0;
        *m_buffer = 0;
      }
      m_buffer += 76;
    }
    while ( m_buffer - 12 != (char *)&result[count] );
  }
  return result;
}
