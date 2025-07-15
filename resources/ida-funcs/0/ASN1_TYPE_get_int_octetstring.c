int __cdecl ASN1_TYPE_get_int_octetstring(asn1_type_st *a, int *num, unsigned __int8 *data, int max_len)
{
  int length; // edi
  asn1_string_st *v5; // ebx
  asn1_string_st *v6; // esi
  char *ptr; // eax
  const unsigned __int8 *v9; // ecx
  int v10; // eax
  int v11; // eax
  int *v12; // edi
  unsigned int v13; // eax
  const unsigned __int8 *v14; // [esp+Ch] [ebp-30h] BYREF
  asn1_const_ctx_st p; // [esp+10h] [ebp-2Ch] BYREF

  length = -1;
  v5 = 0;
  v6 = 0;
  if ( a->type != 16 || !a->value.boolean )
    goto err_66;
  ptr = a->value.ptr;
  a = (asn1_type_st *)*((_DWORD *)ptr + 2);
  v14 = *(const unsigned __int8 **)ptr;
  p.max = &v14[(_DWORD)a];
  p.p = (const unsigned __int8 *)a;
  p.pp = (const unsigned __int8 **)&a;
  p.error = 109;
  if ( !asn1_GetSequence(&p, &v14) )
  {
    p.line = 160;
err_66:
    ERR_put_error((int)v5, 0xDu, 134, 109, ".\\crypto\\asn1\\evp_asn1.c", 183);
    goto LABEL_6;
  }
  p.q = p.p;
  v5 = d2i_ASN1_INTEGER(0, (unsigned __int8 **)&p, (const unsigned __int8 *)p.slen);
  if ( !v5 )
    goto err_66;
  v9 = (const unsigned __int8 *)(p.q - p.p + p.slen);
  p.q = p.p;
  p.slen = (int)v9;
  v6 = d2i_ASN1_OCTET_STRING(0, (unsigned __int8 **)&p, v9);
  if ( !v6 )
    goto err_66;
  v10 = p.q - p.p + p.slen;
  p.slen = v10;
  if ( (p.inf & 1) != 0 )
  {
    v11 = ASN1_const_check_infinite_end(&p.p, v10);
    p.eos = v11;
  }
  else
  {
    v11 = v10 <= 0;
  }
  if ( !v11 )
    goto err_66;
  v12 = num;
  if ( num )
    *v12 = ASN1_INTEGER_get(v5);
  length = v6->length;
  v13 = max_len;
  if ( max_len > v6->length )
    v13 = v6->length;
  if ( data )
    memcpy((int)data, (const __m128i *)v6->data, v13);
LABEL_6:
  if ( v6 )
    ASN1_STRING_free(v6);
  if ( v5 )
    ASN1_STRING_free(v5);
  return length;
}
