unsigned int __cdecl OBJ_cmp(const asn1_object_st *a, const asn1_object_st *b)
{
  unsigned int length; // ecx
  unsigned int result; // eax
  const unsigned __int8 *data; // edx
  const unsigned __int8 *v5; // esi
  int v6; // eax

  length = a->length;
  result = length - b->length;
  if ( !result )
  {
    data = b->data;
    v5 = a->data;
    if ( length < 4 )
    {
LABEL_5:
      if ( !length )
        return 0;
    }
    else
    {
      while ( *(_DWORD *)v5 == *(_DWORD *)data )
      {
        length -= 4;
        data += 4;
        v5 += 4;
        if ( length < 4 )
          goto LABEL_5;
      }
    }
    v6 = *v5 - *data;
    if ( v6 )
      return (v6 >> 31) | 1;
    if ( length > 1 )
    {
      v6 = v5[1] - data[1];
      if ( v6 )
        return (v6 >> 31) | 1;
      if ( length > 2 )
      {
        v6 = v5[2] - data[2];
        if ( !v6 )
        {
          if ( length > 3 )
          {
            v6 = v5[3] - data[3];
            return (v6 >> 31) | 1;
          }
          return 0;
        }
        return (v6 >> 31) | 1;
      }
    }
    return 0;
  }
  return result;
}
