SXNET_st *__cdecl sxnet_v2i(v3_ext_method *method, v3_ext_ctx *ctx, stack_st_CONF_VALUE *nval)
{
  int v3; // esi
  char *v4; // eax
  char *v5; // edi
  asn1_string_st *v6; // eax
  SXNET_st *psx; // [esp+Ch] [ebp-4h] BYREF

  psx = 0;
  v3 = 0;
  if ( sk_num(&nval->stack) <= 0 )
    return psx;
  while ( 1 )
  {
    v4 = sk_value(&nval->stack, v3);
    v5 = (char *)*((_DWORD *)v4 + 2);
    v6 = s2i_ASN1_INTEGER(0, *((char **)v4 + 1));
    if ( !v6 )
      break;
    if ( !SXNET_add_id_INTEGER((asn1_string_st ***)&psx, v6, v5, -1) )
      return 0;
    if ( ++v3 >= sk_num(&nval->stack) )
      return psx;
  }
  ERR_put_error(0x22u, 125, 131, ".\\crypto\\x509v3\\v3_sxnet.c", 157);
  return 0;
}
