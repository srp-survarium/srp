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
