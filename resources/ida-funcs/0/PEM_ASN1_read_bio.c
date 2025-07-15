void *__cdecl PEM_ASN1_read_bio(
        void *(__cdecl *d2i)(void **, const unsigned __int8 **, int),
        char *name,
        bio_st *bp,
        void **x,
        int (__cdecl *cb)(char *, int, int, void *),
        void *u)
{
  void *result; // eax
  void *v7; // esi
  unsigned __int8 *pdata; // [esp+0h] [ebp-Ch] BYREF
  unsigned __int8 *v9; // [esp+4h] [ebp-8h] BYREF
  int plen; // [esp+8h] [ebp-4h] BYREF

  v9 = 0;
  pdata = 0;
  result = (void *)PEM_bytes_read_bio(&pdata, &plen, 0, name, bp, cb, u);
  if ( result )
  {
    v9 = pdata;
    v7 = d2i(x, (const unsigned __int8 **)&v9, plen);
    if ( !v7 )
      ERR_put_error(9u, 103, 13, ".\\crypto\\pem\\pem_oth.c", 83);
    CRYPTO_free(pdata);
    return v7;
  }
  return result;
}
