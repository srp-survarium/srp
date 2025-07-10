void __usercall vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc>::construct(
        vostok::render::grass_layer_desc::model_desc *begin@<edx>,
        vostok::render::grass_layer_desc::model_desc *const *end@<esi>)
{
  vostok::render::grass_layer_desc::model_desc *v2; // ecx
  char *m_buffer; // eax

  if ( begin != *end )
  {
    v2 = begin + 1;
    do
    {
      if ( begin != v2 )
      {
        m_buffer = v2[-1].name.m_buffer;
        do
        {
          if ( m_buffer != (char *)12 )
          {
            *((_DWORD *)m_buffer - 3) = m_buffer;
            *((_DWORD *)m_buffer - 2) = m_buffer;
            *((_DWORD *)m_buffer - 1) = m_buffer + 260;
            *m_buffer = 0;
            *m_buffer = 0;
          }
          m_buffer += 280;
        }
        while ( m_buffer - 12 != (char *)v2 );
      }
      ++begin;
      ++v2;
    }
    while ( begin != *end );
  }
}
