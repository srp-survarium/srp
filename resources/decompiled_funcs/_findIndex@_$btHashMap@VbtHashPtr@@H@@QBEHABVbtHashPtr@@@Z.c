int __usercall btHashMap<btHashPtr,int>::findIndex@<eax>(
        btHashMap<btHashPtr,int> *this@<edx>,
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
