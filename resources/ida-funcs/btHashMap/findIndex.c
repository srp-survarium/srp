int __usercall btHashMap<btInternalVertexPair,btInternalEdge>::findIndex@<eax>(
        btHashMap<btInternalVertexPair,btInternalEdge> *this@<ecx>,
        const btInternalVertexPair *key@<eax>)
{
  __int16 m_v1; // bx
  __int16 m_v0; // si
  unsigned int v4; // eax
  int result; // eax
  btInternalVertexPair *v6; // edi

  m_v1 = key->m_v1;
  m_v0 = key->m_v0;
  v4 = (this->m_valueArray.m_capacity - 1) & (key->m_v0 + (m_v1 << 16));
  if ( v4 >= this->m_hashTable.m_size )
    return -1;
  for ( result = this->m_hashTable.m_data[v4]; result != -1; result = this->m_next.m_data[result] )
  {
    v6 = &this->m_keyArray.m_data[result];
    if ( m_v0 == v6->m_v0 && m_v1 == v6->m_v1 )
      break;
  }
  return result;
}


int __usercall btHashMap<btHashPtr,btCollisionShape *>::findIndex@<eax>(
        btHashMap<btHashPtr,btCollisionShape *> *this@<edx>,
        const btHashPtr *key@<eax>)
{
  int v2; // esi
  int v3; // eax
  int v4; // eax
  unsigned int v5; // ecx
  int result; // eax

  v2 = key->m_hashValues[0];
  v3 = 9
     * ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0])
      ^ ((~(key->m_hashValues[0] << 15) + key->m_hashValues[0]) >> 10));
  v4 = ~(((v3 >> 6) ^ v3) << 11) + ((v3 >> 6) ^ v3);
  v5 = (this->m_valueArray.m_capacity - 1) & (v4 ^ (v4 >> 16));
  if ( v5 >= this->m_hashTable.m_size )
    return -1;
  for ( result = this->m_hashTable.m_data[v5]; result != -1; result = this->m_next.m_data[result] )
  {
    if ( v2 == this->m_keyArray.m_data[result].m_hashValues[0] )
      break;
  }
  return result;
}


int __usercall btHashMap<btHashKey<btTriIndex>,btTriIndex>::findIndex@<eax>(
        btHashMap<btHashKey<btTriIndex>,btTriIndex> *this@<edx>,
        const btHashKey<btTriIndex> *key@<eax>)
{
  int m_uid; // esi
  int v3; // eax
  int v4; // eax
  unsigned int v5; // ecx
  int result; // eax

  m_uid = key->m_uid;
  v3 = 9 * ((~(key->m_uid << 15) + key->m_uid) ^ ((~(key->m_uid << 15) + key->m_uid) >> 10));
  v4 = ~(((v3 >> 6) ^ v3) << 11) + ((v3 >> 6) ^ v3);
  v5 = (this->m_valueArray.m_capacity - 1) & (v4 ^ (v4 >> 16));
  if ( v5 >= this->m_hashTable.m_size )
    return -1;
  for ( result = this->m_hashTable.m_data[v5]; result != -1; result = this->m_next.m_data[result] )
  {
    if ( m_uid == this->m_keyArray.m_data[result].m_uid )
      break;
  }
  return result;
}
