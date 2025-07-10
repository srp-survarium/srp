int __cdecl EVP_PBE_find(
        int type,
        int pbe_nid,
        int *pcnid,
        int *pmnid,
        int (__cdecl **pkeygen)(evp_cipher_ctx_st *, const char *, int, asn1_type_st *, const evp_cipher_st *, const env_md_st *, int))
{
  int v6; // eax
  char *v7; // eax
  _DWORD data[5]; // [esp+0h] [ebp-14h] BYREF

  if ( !pbe_nid )
    return 0;
  data[1] = pbe_nid;
  data[0] = type;
  if ( !pbe_algs
    || (v6 = sk_find(&pbe_algs->stack, (char *)data), v6 == -1)
    || (v7 = sk_value(&pbe_algs->stack, v6)) == 0 )
  {
    v7 = OBJ_bsearch_(
           data,
           (char *)builtin_pbe,
           20,
           20,
           (int (__cdecl *)(const void *, const void *))pbe2_cmp_BSEARCH_CMP_FN);
    if ( !v7 )
      return 0;
  }
  if ( pcnid )
    *pcnid = *((_DWORD *)v7 + 2);
  if ( pmnid )
    *pmnid = *((_DWORD *)v7 + 3);
  if ( pkeygen )
    *pkeygen = (int (__cdecl *)(evp_cipher_ctx_st *, const char *, int, asn1_type_st *, const evp_cipher_st *, const env_md_st *, int))*((_DWORD *)v7 + 4);
  return 1;
}
