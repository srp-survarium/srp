void __userpurge vostok::buffer_vector<vostok::render::ray>::assign<vostok::render::ray const *>(
        const vostok::render::ray *begin@<ecx>,
        const vostok::render::ray *const *end@<edi>,
        vostok::buffer_vector<vostok::render::ray> *this)
{
  vostok::render::ray *m_begin; // esi
  vostok::render::ray *i; // eax

  m_begin = this->m_begin;
  this->m_end = &this->m_begin[*end - begin];
  for ( i = m_begin; begin != *end; ++i )
  {
    if ( i )
      *i = *begin;
    ++begin;
  }
}
