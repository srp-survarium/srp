void __userpurge vostok::buffer_vector<vostok::memory::tester_pinned_resource>::erase(
        vostok::memory::tester_pinned_resource **end@<edi>,
        vostok::buffer_vector<vostok::memory::tester_pinned_resource> *this,
        vostok::memory::tester_pinned_resource *const *begin)
{
  vostok::memory::tester_pinned_resource *v3; // ecx
  vostok::memory::tester_pinned_resource *m_begin; // edx
  vostok::memory::tester_pinned_resource *i; // eax

  v3 = *end;
  m_begin = this->m_begin;
  if ( this->m_begin != *end )
  {
    for ( i = vostok::memory::s_pinned.m_end; v3 != i; ++m_begin )
    {
      if ( m_begin )
      {
        *(_QWORD *)&m_begin->res = *(_QWORD *)&v3->res;
        m_begin->unpin_time = v3->unpin_time;
        i = vostok::memory::s_pinned.m_end;
      }
      ++v3;
    }
    vostok::memory::s_pinned.m_end = &vostok::memory::s_pinned.m_begin[i
                                                                     - vostok::memory::s_pinned.m_begin
                                                                     - (*end
                                                                      - this->m_begin)];
  }
}
