BOOL __usercall do_othername@<eax>(GENERAL_NAME_st *gen@<ebx>, char *value, v3_ext_ctx *ctx)
{
  int v3; // eax
  int v4; // esi
  otherName_st *v6; // eax
  unsigned int v7; // esi
  unsigned __int8 *v8; // edi

  strchr(value, 0x3Bu);
  v4 = v3;
  if ( !v3 )
    return 0;
  v6 = OTHERNAME_new();
  gen->d.ptr = (char *)v6;
  if ( !v6 )
    return 0;
  ASN1_TYPE_free(v6->value);
  *((_DWORD *)gen->d.ptr + 1) = ASN1_generate_v3((char *)(v4 + 1), ctx);
  if ( !*((_DWORD *)gen->d.ptr + 1) )
    return 0;
  v7 = v4 - (_DWORD)value;
  v8 = (unsigned __int8 *)CRYPTO_malloc(v7 + 1, ".\\crypto\\x509v3\\v3_alt.c", 581);
  strncpy(v8, (unsigned __int8 *)value, v7);
  v8[v7] = 0;
  *(_DWORD *)gen->d.ptr = OBJ_txt2obj((int)gen, (char *)v8, 0);
  CRYPTO_free(v8);
  return *(_DWORD *)gen->d.ptr != 0;
}
