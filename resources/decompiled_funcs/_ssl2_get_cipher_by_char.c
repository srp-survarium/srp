const ssl_cipher_st *__cdecl ssl2_get_cipher_by_char(const unsigned __int8 *p)
{
  const ssl_cipher_st *result; // eax
  ssl_cipher_st key; // [esp+0h] [ebp-30h] BYREF

  key.id = p[2] | ((p[1] | ((*p | 0x200) << 8)) << 8);
  result = OBJ_bsearch_ssl_cipher_id(&key, ssl2_ciphers, 7);
  if ( !result || !result->valid )
    return 0;
  return result;
}
