void __thiscall vostok::buffer_vector<vostok::render::sampler_slot>::resize(
        vostok::buffer_vector<vostok::render::sampler_slot> *this,
        vostok::buffer_vector<vostok::render::sampler_slot> *size)
{
  vostok::render::sampler_slot *m_begin; // esi
  unsigned int v3; // eax
  int v4; // edi
  vostok::render::texture_slot *v5; // ebx
  vostok::render::texture_slot *v6; // eax
  vostok::render::texture_slot *v7; // esi

  m_begin = size->m_begin;
  v3 = size->m_end - size->m_begin;
  if ( this != (vostok::buffer_vector<vostok::render::sampler_slot> *)v3 )
  {
    if ( (unsigned int)this >= v3 )
    {
      v4 = (int)this;
      v5 = (vostok::render::texture_slot *)&m_begin[(_DWORD)this];
      v6 = (vostok::render::texture_slot *)&m_begin[v3];
      if ( v6 != v5 )
      {
        do
        {
          v7 = v6 + 1;
          vostok::memory::detail::call_constructor_helper<vostok::render::sampler_slot,0>::call(v6, v6 + 1);
          v6 = v7;
        }
        while ( v7 != v5 );
      }
      size->m_end = &size->m_begin[v4];
    }
    else
    {
      size->m_end = &m_begin[(_DWORD)this];
    }
  }
}
