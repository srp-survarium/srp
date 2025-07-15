int __cdecl i2c_ASN1_INTEGER(asn1_string_st *a, unsigned __int8 **pp)
{
  int v3; // esi
  char v4; // bl
  unsigned __int8 *data; // edx
  int length; // ecx
  int v7; // ebp
  int v8; // eax
  int result; // eax
  unsigned __int8 *v10; // ecx
  int v11; // esi
  unsigned __int8 *v12; // eax
  bool v13; // zf
  unsigned __int8 *v14; // eax
  unsigned __int8 *v15; // ecx
  int v16; // esi
  unsigned __int8 *v17; // ecx
  unsigned __int8 *i; // eax
  int ret; // [esp+10h] [ebp+4h]

  v3 = 0;
  v4 = 0;
  if ( !a )
    return 0;
  data = a->data;
  if ( !data )
    return 0;
  length = a->length;
  v7 = a->type & 0x100;
  if ( !a->length )
  {
    ret = 1;
    goto LABEL_17;
  }
  if ( v7 )
  {
    if ( *data <= 0x80u )
    {
      if ( *data != 128 )
        goto LABEL_16;
      v8 = 1;
      if ( length <= 1 )
        goto LABEL_16;
      while ( !data[v8] )
      {
        if ( ++v8 >= length )
          goto LABEL_16;
      }
    }
    v4 = -1;
    goto LABEL_15;
  }
  if ( *data > 0x7Fu )
  {
    v4 = 0;
LABEL_15:
    v3 = 1;
  }
LABEL_16:
  ret = v3 + length;
LABEL_17:
  if ( !pp )
    return ret;
  v10 = *pp;
  if ( v3 )
    *v10++ = v4;
  v11 = a->length;
  if ( a->length )
  {
    v12 = a->data;
    if ( v7 )
    {
      v13 = v12[v11 - 1] == 0;
      v14 = &v12[v11 - 1];
      v15 = &v10[v11 - 1];
      if ( v13 )
      {
        do
        {
          *v15 = 0;
          --v14;
          --v15;
          --v11;
        }
        while ( !*v14 );
      }
      *v15 = -*v14;
      v16 = v11 - 1;
      v17 = v15 - 1;
      for ( i = v14 - 1; v16 > 0; --i )
      {
        *v17 = ~*i;
        --v16;
        --v17;
      }
      result = ret;
      *pp += ret;
    }
    else
    {
      memcpy(v10, v12, a->length);
      result = ret;
      *pp += ret;
    }
  }
  else
  {
    result = ret;
    *v10 = 0;
    *pp += ret;
  }
  return result;
}
