int __cdecl ASN1_STRING_cmp(const asn1_string_st *a, const asn1_string_st *b)
{
  unsigned int length; // ecx
  int result; // eax
  unsigned __int8 *data; // edx
  unsigned __int8 *v5; // esi
  int v6; // eax

  length = a->length;
  result = a->length - b->length;
  if ( a->length == b->length )
  {
    data = b->data;
    v5 = a->data;
    if ( length < 4 )
    {
LABEL_5:
      if ( !length )
        goto LABEL_14;
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
      goto LABEL_13;
    if ( length <= 1 )
      goto LABEL_14;
    v6 = v5[1] - data[1];
    if ( v6 )
      goto LABEL_13;
    if ( length <= 2 )
      goto LABEL_14;
    v6 = v5[2] - data[2];
    if ( v6 )
    {
LABEL_13:
      result = (v6 >> 31) | 1;
      goto LABEL_15;
    }
    if ( length > 3 )
    {
      v6 = v5[3] - data[3];
      goto LABEL_13;
    }
LABEL_14:
    result = 0;
LABEL_15:
    if ( !result )
      return a->type - b->type;
  }
  return result;
}
