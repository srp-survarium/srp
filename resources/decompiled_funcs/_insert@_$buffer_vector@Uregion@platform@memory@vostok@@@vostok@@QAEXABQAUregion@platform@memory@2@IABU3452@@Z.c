void __userpurge vostok::buffer_vector<vostok::memory::platform::region>::insert(
        vostok::buffer_vector<vostok::memory::platform::region> *this@<esi>,
        vostok::memory::platform::region **where@<edi>,
        const vostok::memory::platform::region *count,
        const vostok::memory::platform::region *value)
{
  vostok::memory::platform::region *m_end; // ecx
  vostok::memory::platform::region *v5; // eax
  vostok::memory::platform::region *v6; // edx
  vostok::memory::platform::region *v7; // eax
  vostok::memory::platform::region *v8; // ecx

  m_end = this->m_end;
  v5 = m_end - 1;
  v6 = *where - 1;
  if ( &m_end[-1] != v6 )
  {
    do
    {
      if ( m_end )
      {
        m_end->size = v5->size;
        *(_QWORD *)&m_end->address = *(_QWORD *)&v5->address;
      }
      --v5;
      --m_end;
    }
    while ( v5 != v6 );
  }
  ++this->m_end;
  v7 = *where;
  v8 = *where + 1;
  if ( *where != v8 )
  {
    do
    {
      if ( v7 )
      {
        v7->size = count->size;
        *(_QWORD *)&v7->address = *(_QWORD *)&count->address;
      }
      ++v7;
    }
    while ( v7 != v8 );
  }
}
