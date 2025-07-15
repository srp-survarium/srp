SXNET_st *__cdecl sxnet_v2i(v3_ext_method *method, v3_ext_ctx *ctx, stack_st_CONF_VALUE *nval)
{
  int v3; // esi
  char *v4; // eax
  const __m128i *v5; // edi
  asn1_string_st *v6; // eax
  asn1_string_st **v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  v3 = 0;
  if ( sk_num(&nval->stack) <= 0 )
    return (SXNET_st *)v8;
  while ( 1 )
  {
    v4 = sk_value(&nval->stack, v3);
    v5 = (const __m128i *)*((_DWORD *)v4 + 2);
    v6 = s2i_ASN1_INTEGER((int)nval, 0, *((char **)v4 + 1));
    if ( !v6 )
      break;
    if ( !SXNET_add_id_INTEGER(&v8, v6, v5, -1) )
      return 0;
    if ( ++v3 >= sk_num(&nval->stack) )
      return (SXNET_st *)v8;
  }
  ERR_put_error((int)nval, 0x22u, 125, 131, ".\\crypto\\x509v3\\v3_sxnet.c", 157);
  return 0;
}
