ssl_cipher_st *__cdecl OBJ_bsearch_ssl_cipher_id(ssl_cipher_st *key, const ssl_cipher_st *base, int num)
{
  return (ssl_cipher_st *)OBJ_bsearch_(
                            key,
                            (char *)base,
                            num,
                            48,
                            (int (__cdecl *)(const void *, const void *))ssl_cipher_id_cmp_BSEARCH_CMP_FN);
}
