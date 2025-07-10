void __thiscall vostok::buffer_vector<vostok::render::vertex_colored>::resize(
        vostok::buffer_vector<vostok::render::vertex_colored> *this,
        vostok::buffer_vector<vostok::render::vertex_colored> *size)
{
  vostok::render::vertex_colored *m_begin; // edx
  unsigned int v3; // eax
  int v4; // ecx
  vostok::render::vertex_colored *v5; // eax
  vostok::render::vertex_colored *v6; // edi
  vostok::render::vertex_colored *v7; // edx
  vostok::render::vertex_colored *v8; // esi
  vostok::render::vertex_colored *i; // eax

  m_begin = size->m_begin;
  v3 = size->m_end - size->m_begin;
  if ( this != (vostok::buffer_vector<vostok::render::vertex_colored> *)v3 )
  {
    if ( (unsigned int)this >= v3 )
    {
      v4 = (int)this;
      v5 = &m_begin[v3];
      v6 = &m_begin[v4];
      v7 = v5;
      if ( v5 != v6 )
      {
        v8 = v5 + 1;
        do
        {
          for ( i = v7; i != v8; ++i )
          {
            if ( i )
              i->color.m_value = -1;
          }
          ++v7;
          ++v8;
        }
        while ( v7 != v6 );
      }
      size->m_end = &size->m_begin[v4];
    }
    else
    {
      size->m_end = &m_begin[(_DWORD)this];
    }
  }
}
