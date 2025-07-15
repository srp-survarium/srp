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


void __userpurge vostok::buffer_vector<vostok::math::float3>::insert<vostok::math::float3 const *>(
        const vostok::math::float3 *begin@<ecx>,
        const vostok::math::float3 *const *end@<eax>,
        vostok::buffer_vector<vostok::math::float3> *this,
        vostok::math::float3 **where)
{
  const vostok::math::float3 *v4; // edi
  vostok::math::float3 *m_end; // edx
  unsigned int v6; // ecx
  int v7; // esi
  vostok::math::float3 *v8; // edx
  vostok::math::float3 *i; // eax
  vostok::math::float3 *v10; // eax
  vostok::math::float3 *v11; // ecx

  v4 = begin;
  m_end = this->m_end;
  v6 = *end - begin;
  v7 = (int)&m_end[v6 - 1];
  v8 = m_end - 1;
  for ( i = *where - 1; v8 != i; v7 -= 12 )
  {
    if ( v7 )
    {
      *(_QWORD *)v7 = *(_QWORD *)&v8->x;
      *(float *)(v7 + 8) = v8->z;
    }
    --v8;
  }
  this->m_end = (vostok::math::float3 *)((char *)this->m_end + v6 * 12);
  v10 = *where;
  v11 = &(*where)[v6];
  if ( *where != v11 )
  {
    do
    {
      if ( v10 )
      {
        *(_QWORD *)&v10->x = *(_QWORD *)&v4->x;
        v10->z = v4->z;
      }
      ++v10;
      ++v4;
    }
    while ( v10 != v11 );
  }
}
