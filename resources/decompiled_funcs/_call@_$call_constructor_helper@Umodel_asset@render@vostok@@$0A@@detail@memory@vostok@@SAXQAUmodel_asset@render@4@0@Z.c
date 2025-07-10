void __usercall vostok::memory::detail::call_constructor_helper<vostok::render::model_asset,0>::call(
        vostok::render::model_asset *const begin@<eax>,
        vostok::render::model_asset *const end@<edx>)
{
  char *m_buffer; // eax

  if ( begin != end )
  {
    m_buffer = begin->m_surface_name.m_string.m_buffer;
    do
    {
      if ( m_buffer != (char *)24 )
      {
        *((_DWORD *)m_buffer - 6) = 0;
        *((_DWORD *)m_buffer - 5) = 0;
        *((_DWORD *)m_buffer - 4) = 0;
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 260;
        *m_buffer = 0;
        m_buffer[260] = 47;
      }
      m_buffer += 288;
    }
    while ( m_buffer - 24 != (char *)end );
  }
}
