int __cdecl RSA_padding_check_none(unsigned __int8 *to, int tlen, unsigned __int8 *from, int flen)
{
  if ( flen <= tlen )
  {
    memset((int)to, 0, tlen - flen);
    memcpy(&to[tlen - flen], from, flen);
    return tlen;
  }
  else
  {
    ERR_put_error(4u, 111, 109, ".\\crypto\\rsa\\rsa_none.c", 90);
    return -1;
  }
}
