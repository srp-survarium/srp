BOOL __cdecl asn1_string_canon(asn1_string_st *out)
{
  asn1_string_st *in; // ecx
  asn1_string_st *v2; // edi
  int v4; // eax
  unsigned __int8 *data; // esi
  int i; // ebp
  char *j; // edi
  unsigned __int8 *v8; // edi
  int v9; // ebx
  unsigned __int8 v10; // al
  char v11; // al

  v2 = in;
  if ( (ASN1_tag2bit(in->type) & 0x2956) == 0 )
  {
    out->type = v2->type;
    return ASN1_STRING_set(out, (char *)v2->data, v2->length) != 0;
  }
  out->type = 12;
  v4 = ASN1_STRING_to_UTF8(&out->data, v2);
  out->length = v4;
  if ( v4 == -1 )
    return 0;
  data = out->data;
  for ( i = v4; i > 0; ++data )
  {
    if ( (*data & 0x80u) != 0 )
      break;
    if ( !isspace(*data) )
      break;
    --i;
  }
  for ( j = (char *)&data[i - 1]; i > 0; --j )
  {
    if ( *j < 0 )
      break;
    if ( !isspace((unsigned __int8)*j) )
      break;
    --i;
  }
  v8 = out->data;
  v9 = 0;
  while ( v9 < i )
  {
    v10 = *data;
    if ( (*data & 0x80u) == 0 )
    {
      if ( isspace(v10) )
      {
        *v8++ = 32;
        do
        {
          v11 = *++data;
          ++v9;
        }
        while ( v11 >= 0 && isspace((unsigned __int8)v11) );
        continue;
      }
      v10 = tolower(*data);
    }
    *v8++ = v10;
    ++data;
    ++v9;
  }
  out->length = v8 - out->data;
  return 1;
}
