lhash_st *__cdecl lh_new(
        int (__cdecl *h)(const char *c),
        void (__cdecl *c)(unsigned __int8 *str1, unsigned __int8 *str2))
{
  _DWORD *v2; // esi
  void *v3; // eax
  int i; // eax
  void (__cdecl *v6)(unsigned __int8 *, unsigned __int8 *); // eax
  int (__cdecl *v7)(const char *); // eax

  v2 = CRYPTO_malloc(96, ".\\crypto\\lhash\\lhash.c", 119);
  if ( !v2 )
    return 0;
  v3 = CRYPTO_malloc(64, ".\\crypto\\lhash\\lhash.c", 121);
  *v2 = v3;
  if ( !v3 )
  {
    CRYPTO_free(v2);
    return 0;
  }
  for ( i = 0; i < 64; i += 4 )
    *(_DWORD *)(i + *v2) = 0;
  v6 = c;
  if ( !c )
    v6 = strcmp;
  v2[1] = v6;
  v7 = h;
  if ( !h )
    v7 = lh_strhash;
  v2[2] = v7;
  v2[5] = 0;
  v2[9] = 0;
  v2[10] = 0;
  v2[11] = 0;
  v2[12] = 0;
  v2[13] = 0;
  v2[14] = 0;
  v2[15] = 0;
  v2[16] = 0;
  v2[17] = 0;
  v2[18] = 0;
  v2[19] = 0;
  v2[20] = 0;
  v2[21] = 0;
  v2[22] = 0;
  v2[23] = 0;
  v2[3] = 8;
  v2[6] = 8;
  v2[4] = 16;
  v2[7] = 512;
  v2[8] = 256;
  return (lhash_st *)v2;
}
