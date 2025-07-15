int __fastcall btAlignedObjectArray<int>::findLinearSearch(btAlignedObjectArray<int> *this, int *key)
{
  int result; // eax
  int v3; // esi
  int v4; // edx
  int *i; // ecx

  result = this->m_size;
  v3 = 0;
  if ( result > 0 )
  {
    v4 = *key;
    for ( i = this->m_data; *i != v4; ++i )
    {
      if ( ++v3 >= result )
        return result;
    }
    return v3;
  }
  return result;
}
