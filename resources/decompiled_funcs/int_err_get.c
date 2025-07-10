lhash_st_ERR_STRING_DATA *__usercall int_err_get@<eax>(unsigned int a1@<edi>, int create)
{
  lhash_st_ERR_STRING_DATA *v2; // esi
  lhash_st_ERR_STRING_DATA *v3; // eax

  v2 = 0;
  CRYPTO_lock(a1, 9, 1, ".\\crypto\\err\\err.c", 354);
  v3 = int_error_hash;
  if ( int_error_hash
    || create
    && (CRYPTO_push_info_("int_err_get (err.c)", ".\\crypto\\err\\err.c", 357),
        int_error_hash = (lhash_st_ERR_STRING_DATA *)lh_new(
                                                       (unsigned int (__cdecl *)(const void *))err_string_data_LHASH_HASH,
                                                       nid_cmp_BSEARCH_CMP_FN),
        CRYPTO_pop_info(),
        (v3 = int_error_hash) != 0) )
  {
    v2 = v3;
  }
  CRYPTO_lock(a1, 10, 1, ".\\crypto\\err\\err.c", 363);
  return v2;
}
