const ssl_cipher_st *__cdecl ssl23_get_cipher(unsigned int u)
{
  unsigned int v1; // eax

  v1 = ssl3_num_ciphers();
  if ( u >= v1 )
    return ssl2_get_cipher(u - v1);
  else
    return ssl3_get_cipher(u);
}
