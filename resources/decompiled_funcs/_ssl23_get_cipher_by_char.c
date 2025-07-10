const ssl_cipher_st *__cdecl ssl23_get_cipher_by_char(const unsigned __int8 *p)
{
  const ssl_cipher_st *result; // eax

  result = ssl3_get_cipher_by_char(p);
  if ( !result )
    return ssl2_get_cipher_by_char(p);
  return result;
}
