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
