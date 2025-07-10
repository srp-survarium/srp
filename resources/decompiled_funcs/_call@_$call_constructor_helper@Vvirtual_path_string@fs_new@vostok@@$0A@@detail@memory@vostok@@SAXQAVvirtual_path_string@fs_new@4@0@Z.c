void __usercall vostok::memory::detail::call_constructor_helper<vostok::fs_new::virtual_path_string,0>::call(
        vostok::fs_new::virtual_path_string *const begin@<eax>,
        vostok::fs_new::virtual_path_string *const end@<ecx>)
{
  char *m_buffer; // eax

  if ( begin != end )
  {
    m_buffer = begin->m_string.m_buffer;
    do
    {
      if ( m_buffer != (char *)12 )
      {
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 260;
        *m_buffer = 0;
        *m_buffer = 0;
        m_buffer[260] = 47;
      }
      m_buffer += 276;
    }
    while ( m_buffer - 12 != (char *)end );
  }
}
