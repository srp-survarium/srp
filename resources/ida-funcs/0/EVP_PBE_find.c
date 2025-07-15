int __usercall EVP_PBE_find@<eax>(
        int a1@<edi>,
        int type,
        int pbe_nid,
        int *pcnid,
        int *pmnid,
        int (__cdecl **pkeygen)(evp_cipher_ctx_st *, const char *, int, asn1_type_st *, const evp_cipher_st *, const env_md_st *, int))
{
  int v7; // eax
  char *v8; // eax
  _DWORD v9[5]; // [esp+0h] [ebp-14h] BYREF

  if ( !pbe_nid )
    return 0;
  v9[1] = pbe_nid;
  v9[0] = type;
  if ( !pbe_algs
    || (v7 = sk_find(a1, &pbe_algs->stack, (char *)v9), v7 == -1)
    || (v8 = sk_value(&pbe_algs->stack, v7)) == 0 )
  {
    v8 = OBJ_bsearch_(
           v9,
           (char *)builtin_pbe,
           20,
           20,
           (int (__cdecl *)(const void *, const void *))pbe2_cmp_BSEARCH_CMP_FN);
    if ( !v8 )
      return 0;
  }
  if ( pcnid )
    *pcnid = *((_DWORD *)v8 + 2);
  if ( pmnid )
    *pmnid = *((_DWORD *)v8 + 3);
  if ( pkeygen )
    *pkeygen = (int (__cdecl *)(evp_cipher_ctx_st *, const char *, int, asn1_type_st *, const evp_cipher_st *, const env_md_st *, int))*((_DWORD *)v8 + 4);
  return 1;
}
