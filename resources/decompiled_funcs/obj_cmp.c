unsigned int __cdecl obj_cmp(const asn1_object_st *const *ap)
{
  const unsigned int *bp; // ecx
  int v2; // eax
  unsigned int length; // ecx
  const asn1_object_st *v4; // edx
  unsigned int result; // eax
  const unsigned __int8 *data; // edx
  const unsigned __int8 *v7; // esi
  int v8; // eax

  v2 = *bp;
  length = (*ap)->length;
  v4 = &nid_objs[v2];
  result = length - v4->length;
  if ( !result )
  {
    data = v4->data;
    v7 = (*ap)->data;
    if ( length < 4 )
    {
LABEL_5:
      if ( !length )
        return 0;
    }
    else
    {
      while ( *(_DWORD *)v7 == *(_DWORD *)data )
      {
        length -= 4;
        data += 4;
        v7 += 4;
        if ( length < 4 )
          goto LABEL_5;
      }
    }
    v8 = *v7 - *data;
    if ( v8 )
      return (v8 >> 31) | 1;
    if ( length > 1 )
    {
      v8 = v7[1] - data[1];
      if ( v8 )
        return (v8 >> 31) | 1;
      if ( length > 2 )
      {
        v8 = v7[2] - data[2];
        if ( !v8 )
        {
          if ( length > 3 )
          {
            v8 = v7[3] - data[3];
            return (v8 >> 31) | 1;
          }
          return 0;
        }
        return (v8 >> 31) | 1;
      }
    }
    return 0;
  }
  return result;
}
