asn1_object_st *__cdecl c2i_ASN1_OBJECT(asn1_object_st **a, unsigned __int8 **pp, int len)
{
  unsigned __int8 *v3; // edx
  int v4; // eax
  char *v5; // ecx
  asn1_object_st *v6; // esi
  asn1_object_st *v7; // eax
  unsigned __int8 *data; // edi
  unsigned __int8 *v10; // ebx
  int v11; // eax
  const unsigned __int8 *v12; // ebx

  v3 = *pp;
  v4 = 0;
  if ( len <= 0 )
  {
LABEL_7:
    if ( !a || (v6 = *a) == 0 || (v6->flags & 1) == 0 )
    {
      v7 = (asn1_object_st *)CRYPTO_malloc(24, ".\\crypto\\asn1\\a_object.c", 351);
      if ( !v7 )
      {
        ERR_put_error(0xDu, 123, 65, ".\\crypto\\asn1\\a_object.c", 354);
        return 0;
      }
      v7->length = 0;
      v7->data = 0;
      v7->nid = 0;
      v7->sn = 0;
      v7->ln = 0;
      v7->flags = 1;
      v6 = v7;
    }
    data = (unsigned __int8 *)v6->data;
    v10 = *pp;
    v6->data = 0;
    if ( !data || v6->length < len )
    {
      v6->length = 0;
      if ( data )
        CRYPTO_free(data);
      v11 = len;
      if ( !len )
        v11 = 1;
      data = (unsigned __int8 *)CRYPTO_malloc(v11, ".\\crypto\\asn1\\a_object.c", 323);
      if ( !data )
      {
        ERR_put_error(0xDu, 196, 65, ".\\crypto\\asn1\\a_object.c", 341);
        if ( !a || *a != v6 )
          ASN1_OBJECT_free(v6);
        return 0;
      }
      v6->flags |= 8u;
    }
    memcpy(data, v10, len);
    v12 = &v10[len];
    v6->data = data;
    v6->length = len;
    v6->sn = 0;
    v6->ln = 0;
    if ( a )
      *a = v6;
    *pp = (unsigned __int8 *)v12;
    return v6;
  }
  else
  {
    v5 = (char *)(v3 - 1);
    while ( v3[v4] != 0x80 || v4 && *v5 < 0 )
    {
      ++v4;
      ++v5;
      if ( v4 >= len )
        goto LABEL_7;
    }
    ERR_put_error(0xDu, 196, 216, ".\\crypto\\asn1\\a_object.c", 300);
    return 0;
  }
}
