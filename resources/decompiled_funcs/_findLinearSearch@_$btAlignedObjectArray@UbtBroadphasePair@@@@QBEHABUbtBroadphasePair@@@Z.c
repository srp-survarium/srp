int __usercall btAlignedObjectArray<btBroadphasePair>::findLinearSearch@<eax>(
        btAlignedObjectArray<btBroadphasePair> *this@<ecx>,
        const btBroadphasePair *key@<edi>)
{
  int result; // eax
  int v3; // edx
  btBroadphasePair *i; // ecx

  result = this->m_size;
  v3 = 0;
  if ( result > 0 )
  {
    for ( i = this->m_data; i->m_pProxy0 != key->m_pProxy0 || i->m_pProxy1 != key->m_pProxy1; ++i )
    {
      if ( ++v3 >= result )
        return result;
    }
    return v3;
  }
  return result;
}
