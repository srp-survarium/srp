int __cdecl RSA_padding_add_PKCS1_type_1(unsigned __int8 *to, int tlen, unsigned __int8 *from, int flen)
{
  unsigned __int8 *v5; // esi

  if ( flen <= tlen - 11 )
  {
    *to = 0;
    to[1] = 1;
    memset((int)(to + 2), (unsigned __int8 *)0xFF, tlen - flen - 3);
    v5 = &to[tlen - flen - 1];
    *v5 = 0;
    memcpy(v5 + 1, from, flen);
    return 1;
  }
  else
  {
    ERR_put_error(4u, 108, 110, ".\\crypto\\rsa\\rsa_pk1.c", 73);
    return 0;
  }
}
