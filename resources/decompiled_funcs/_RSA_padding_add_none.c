int __cdecl RSA_padding_add_none(unsigned __int8 *to, int tlen, unsigned __int8 *from, int flen)
{
  if ( flen <= tlen )
  {
    if ( flen >= tlen )
    {
      memcpy(to, from, flen);
      return 1;
    }
    else
    {
      ERR_put_error(4u, 107, 122, ".\\crypto\\rsa\\rsa_none.c", 76);
      return 0;
    }
  }
  else
  {
    ERR_put_error(4u, 107, 110, ".\\crypto\\rsa\\rsa_none.c", 70);
    return 0;
  }
}
