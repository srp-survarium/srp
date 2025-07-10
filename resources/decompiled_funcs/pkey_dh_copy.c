int __cdecl pkey_dh_copy(evp_pkey_ctx_st *dst, evp_pkey_ctx_st *src)
{
  int *v2; // eax
  int *data; // ecx

  v2 = (int *)CRYPTO_malloc(20, ".\\crypto\\dh\\dh_pmeth.c", 83);
  if ( !v2 )
    return 0;
  *v2 = 1024;
  v2[2] = 0;
  v2[1] = 2;
  dst->data = v2;
  dst->keygen_info_count = 2;
  dst->keygen_info = v2 + 3;
  data = (int *)src->data;
  *v2 = *data;
  v2[1] = data[1];
  v2[2] = data[2];
  return 1;
}
