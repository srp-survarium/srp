int __usercall RSA_padding_add_none@<eax>(int a1@<ebx>, unsigned __int8 *to, int tlen, const __m128i *from, int flen)
{
  if ( flen <= tlen )
  {
    if ( flen >= tlen )
    {
      memcpy((int)to, from, flen);
      return 1;
    }
    else
    {
      ERR_put_error(a1, 4u, 107, 122, ".\\crypto\\rsa\\rsa_none.c", 76);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 4u, 107, 110, ".\\crypto\\rsa\\rsa_none.c", 70);
    return 0;
  }
}
