int __cdecl pkey_ec_copy(evp_pkey_ctx_st *dst, evp_pkey_ctx_st *src)
{
  _DWORD *v2; // esi
  const ec_group_st **data; // edi
  int result; // eax

  v2 = CRYPTO_malloc(8, ".\\crypto\\ec\\ec_pmeth.c", 80);
  if ( !v2 )
    return 0;
  *v2 = 0;
  v2[1] = 0;
  dst->data = v2;
  data = (const ec_group_st **)src->data;
  if ( !*data || (result = (int)EC_GROUP_dup(*data), (*v2 = result) != 0) )
  {
    v2[1] = data[1];
    return 1;
  }
  return result;
}
