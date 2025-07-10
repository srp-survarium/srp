int __cdecl ASN1_TYPE_get_int_octetstring(asn1_type_st *a, int *num, unsigned __int8 *data, int max_len)
{
  int v4; // edi
  asn1_string_st *v5; // ebx
  asn1_string_st *v6; // esi
  int *ptr; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int *v12; // edi
  unsigned int v13; // eax
  int length; // [esp+Ch] [ebp-30h] BYREF
  asn1_const_ctx_st c; // [esp+10h] [ebp-2Ch] BYREF

  v4 = -1;
  v5 = 0;
  v6 = 0;
  if ( a->type != 16 || !a->value.boolean )
    goto err_64;
  ptr = (int *)a->value.ptr;
  a = (asn1_type_st *)ptr[2];
  length = *ptr;
  c.max = (const unsigned __int8 *)a + length;
  c.p = (const unsigned __int8 *)a;
  c.pp = (const unsigned __int8 **)&a;
  c.error = 109;
  if ( !asn1_GetSequence(&c, (unsigned __int8 **)&length) )
  {
    c.line = 160;
err_64:
    ERR_put_error(0xDu, 134, 109, ".\\crypto\\asn1\\evp_asn1.c", 183);
    goto LABEL_6;
  }
  c.q = c.p;
  v5 = d2i_ASN1_INTEGER(0, &c.p, c.slen);
  if ( !v5 )
    goto err_64;
  v9 = c.q - c.p + c.slen;
  c.q = c.p;
  c.slen = v9;
  v6 = d2i_ASN1_OCTET_STRING(0, &c.p, v9);
  if ( !v6 )
    goto err_64;
  v10 = c.q - c.p + c.slen;
  c.slen = v10;
  if ( (c.inf & 1) != 0 )
  {
    v11 = ASN1_const_check_infinite_end(&c.p, v10);
    c.eos = v11;
  }
  else
  {
    v11 = v10 <= 0;
  }
  if ( !v11 )
    goto err_64;
  v12 = num;
  if ( num )
    *v12 = ASN1_INTEGER_get(v5);
  v4 = v6->length;
  v13 = max_len;
  if ( max_len > v6->length )
    v13 = v6->length;
  if ( data )
    memcpy(data, v6->data, v13);
LABEL_6:
  if ( v6 )
    ASN1_STRING_free(v6);
  if ( v5 )
    ASN1_STRING_free(v5);
  return v4;
}
