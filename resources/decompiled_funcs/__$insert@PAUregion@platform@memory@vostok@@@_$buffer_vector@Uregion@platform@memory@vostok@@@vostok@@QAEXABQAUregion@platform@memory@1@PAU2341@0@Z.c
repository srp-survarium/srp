void __userpurge vostok::buffer_vector<vostok::memory::platform::region>::insert<vostok::memory::platform::region *>(
        vostok::memory::platform::region *begin@<ecx>,
        vostok::memory::platform::region *const *end@<eax>,
        vostok::buffer_vector<vostok::memory::platform::region> *this,
        vostok::memory::platform::region **where)
{
  vostok::memory::platform::region *m_end; // ecx
  unsigned int v6; // eax
  vostok::memory::platform::region *v7; // edx
  vostok::memory::platform::region *v8; // esi
  vostok::memory::platform::region *i; // ecx
  vostok::memory::platform::region *v10; // ecx
  vostok::memory::platform::region *v11; // eax

  m_end = this->m_end;
  v6 = *end - begin;
  v7 = m_end - 1;
  v8 = &m_end[v6 - 1];
  for ( i = *where - 1; v7 != i; --v8 )
  {
    if ( v8 )
    {
      v8->size = v7->size;
      *(_QWORD *)&v8->address = *(_QWORD *)&v7->address;
    }
    --v7;
  }
  this->m_end = (vostok::memory::platform::region *)((char *)this->m_end + v6 * 16);
  v10 = *where;
  v11 = &(*where)[v6];
  if ( *where != v11 )
  {
    do
    {
      if ( v10 )
      {
        v10->size = begin->size;
        *(_QWORD *)&v10->address = *(_QWORD *)&begin->address;
      }
      ++v10;
      ++begin;
    }
    while ( v10 != v11 );
  }
}
