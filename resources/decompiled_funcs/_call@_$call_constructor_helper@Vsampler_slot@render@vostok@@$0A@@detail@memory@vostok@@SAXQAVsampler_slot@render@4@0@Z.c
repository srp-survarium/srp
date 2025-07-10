void __usercall vostok::memory::detail::call_constructor_helper<vostok::render::sampler_slot,0>::call(
        vostok::render::texture_slot *const begin@<eax>,
        vostok::render::texture_slot *const end@<ecx>)
{
  char *m_buffer; // eax

  if ( begin != end )
  {
    m_buffer = begin->name.m_buffer;
    do
    {
      if ( m_buffer != (char *)12 )
      {
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 64;
        *m_buffer = 0;
        *m_buffer = 0;
        *((_DWORD *)m_buffer + 16) = -1;
        *((_DWORD *)m_buffer + 17) = 0;
      }
      m_buffer += 84;
    }
    while ( m_buffer - 12 != (char *)end );
  }
}
