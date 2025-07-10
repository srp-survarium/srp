int __usercall btHashMap<btInternalVertexPair,btInternalEdge>::findIndex@<eax>(
        btHashMap<btInternalVertexPair,btInternalEdge> *this@<edx>,
        const btInternalVertexPair *key@<eax>)
{
  __int16 m_v1; // bx
  __int16 m_v0; // di
  unsigned int v4; // eax
  int result; // eax
  btInternalVertexPair *m_data; // esi
  int v7; // ecx

  m_v1 = key->m_v1;
  m_v0 = key->m_v0;
  v4 = (this->m_valueArray.m_capacity - 1) & (key->m_v0 + (m_v1 << 16));
  if ( v4 >= this->m_hashTable.m_size )
    return -1;
  result = this->m_hashTable.m_data[v4];
  if ( result != -1 )
  {
    m_data = this->m_keyArray.m_data;
    do
    {
      v7 = result;
      if ( m_v0 == m_data[result].m_v0 && m_v1 == m_data[v7].m_v1 )
        break;
      result = this->m_next.m_data[v7];
    }
    while ( result != -1 );
  }
  return result;
}
