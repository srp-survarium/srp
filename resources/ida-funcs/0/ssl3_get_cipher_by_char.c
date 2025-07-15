const ssl_cipher_st *__cdecl ssl3_get_cipher_by_char(const unsigned __int8 *p)
{
  const ssl_cipher_st *result; // eax
  ssl_cipher_st key; // [esp+0h] [ebp-30h] BYREF

  key.id = p[1] | (((unsigned int)&loc_30000 | *p) << 8);
  result = OBJ_bsearch_ssl_cipher_id(&key, ssl3_ciphers, 90);
  if ( !result || !result->valid )
    return 0;
  return result;
}
