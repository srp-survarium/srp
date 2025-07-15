int __cdecl asn1_bio_new(bio_st *b)
{
  _DWORD *v1; // esi
  void *v3; // eax

  v1 = CRYPTO_malloc(64, ".\\crypto\\asn1\\bio_asn1.c", 153);
  if ( !v1 )
    return 0;
  v3 = CRYPTO_malloc(20, ".\\crypto\\asn1\\bio_asn1.c", 166);
  v1[1] = v3;
  if ( !v3 )
    return 0;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[12] = 0;
  v1[14] = 0;
  v1[13] = 0;
  *v1 = 0;
  v1[2] = 20;
  v1[7] = 4;
  b->flags = 0;
  b->ptr = v1;
  b->init = 1;
  return 1;
}
