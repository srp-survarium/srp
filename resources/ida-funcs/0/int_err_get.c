lhash_st_ERR_STRING_DATA *__usercall int_err_get@<eax>(int a1@<edi>, int a2@<ebx>, int create)
{
  lhash_st_ERR_STRING_DATA *v3; // esi
  lhash_st_ERR_STRING_DATA *v4; // eax

  v3 = 0;
  CRYPTO_lock(a1, a2, 9, 1, ".\\crypto\\err\\err.c", 354);
  v4 = int_error_hash;
  if ( int_error_hash
    || create
    && (CRYPTO_push_info_(a1, "int_err_get (err.c)", ".\\crypto\\err\\err.c", 0x165u),
        int_error_hash = (lhash_st_ERR_STRING_DATA *)lh_new(
                                                       (int (__cdecl *)(const char *))err_string_data_LHASH_HASH,
                                                       (void (__cdecl *)(unsigned __int8 *, unsigned __int8 *))nid_cmp_BSEARCH_CMP_FN),
        CRYPTO_pop_info(a1),
        (v4 = int_error_hash) != 0) )
  {
    v3 = v4;
  }
  CRYPTO_lock(a1, a2, 10, 1, ".\\crypto\\err\\err.c", 363);
  return v3;
}
