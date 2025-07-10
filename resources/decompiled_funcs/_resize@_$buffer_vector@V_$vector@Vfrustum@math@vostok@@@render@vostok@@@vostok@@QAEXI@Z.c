void __usercall vostok::buffer_vector<vostok::render::vector<vostok::math::frustum>>::resize(
        vostok::buffer_vector<vostok::render::vector<vostok::math::frustum> > *this@<esi>,
        unsigned int size@<eax>,
        vostok::render::vector<vostok::math::frustum> *a3@<ecx>)
{
  vostok::render::vector<vostok::math::frustum> *m_begin; // ecx
  bool v5; // cf
  int v6; // eax
  unsigned int v7; // edi
  vostok::render::vector<vostok::math::frustum> *end; // [esp+0h] [ebp-4h] BYREF

  end = a3;
  m_begin = this->m_begin;
  v5 = size < this->m_end - this->m_begin;
  if ( size != this->m_end - this->m_begin )
  {
    v6 = this->m_end - this->m_begin;
    if ( v5 )
    {
      v7 = size;
      end = &m_begin[this->m_end - this->m_begin];
      vostok::buffer_vector<vostok::render::vector<vostok::math::frustum>>::destroy(&m_begin[v7], &end);
      this->m_end = &this->m_begin[v7];
    }
    else
    {
      end = &m_begin[size];
      vostok::buffer_vector<vostok::render::vector<vostok::render::culling::aab_rect>>::construct(&m_begin[v6], &end);
      this->m_end = &this->m_begin[size];
    }
  }
}
