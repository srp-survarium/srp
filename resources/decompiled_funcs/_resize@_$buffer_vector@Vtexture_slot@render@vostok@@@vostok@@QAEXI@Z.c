void __usercall vostok::buffer_vector<vostok::render::texture_slot>::resize(
        vostok::buffer_vector<vostok::render::texture_slot> *this@<edi>,
        unsigned int size@<eax>,
        vostok::render::texture_slot *a3@<ecx>)
{
  vostok::render::texture_slot *m_begin; // ecx
  unsigned int v5; // eax
  unsigned int v6; // esi
  unsigned int v7; // esi
  vostok::render::texture_slot *v8; // ebp
  vostok::render::texture_slot *v9; // eax
  vostok::render::texture_slot *v10; // ebx
  vostok::render::texture_slot *end; // [esp+0h] [ebp-4h] BYREF

  end = a3;
  m_begin = this->m_begin;
  v5 = this->m_end - this->m_begin;
  if ( size != v5 )
  {
    if ( size >= v5 )
    {
      v7 = size;
      v8 = &m_begin[v7];
      v9 = &m_begin[v5];
      if ( v9 != &m_begin[v7] )
      {
        do
        {
          v10 = v9 + 1;
          vostok::memory::detail::call_constructor_helper<vostok::render::sampler_slot,0>::call(v9, v9 + 1);
          v9 = v10;
        }
        while ( v10 != v8 );
      }
      this->m_end = &this->m_begin[v7];
    }
    else
    {
      v6 = size;
      end = &m_begin[v5];
      vostok::buffer_vector<vostok::render::texture_slot>::destroy(&m_begin[v6], &end);
      this->m_end = &this->m_begin[v6];
    }
  }
}
