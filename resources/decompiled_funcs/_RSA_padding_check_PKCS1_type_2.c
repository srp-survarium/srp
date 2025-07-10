int __cdecl RSA_padding_check_PKCS1_type_2(
        unsigned __int8 *to,
        int tlen,
        const unsigned __int8 *from,
        int flen,
        int num)
{
  unsigned __int8 *v5; // edx
  int v6; // esi
  int i; // eax
  signed int v10; // esi

  if ( num == flen + 1 && (v5 = (unsigned __int8 *)(from + 1), *from == 2) )
  {
    v6 = flen - 1;
    for ( i = 0; i < v6; ++i )
    {
      if ( !*v5++ )
        break;
    }
    if ( i == v6 )
    {
      ERR_put_error(4u, 113, 113, ".\\crypto\\rsa\\rsa_pk1.c", 204);
      return -1;
    }
    else if ( i >= 8 )
    {
      v10 = -1 - i + v6;
      if ( v10 <= tlen )
      {
        memcpy(to, v5, v10);
        return v10;
      }
      else
      {
        ERR_put_error(4u, 113, 109, ".\\crypto\\rsa\\rsa_pk1.c", 217);
        return -1;
      }
    }
    else
    {
      ERR_put_error(4u, 113, 103, ".\\crypto\\rsa\\rsa_pk1.c", 210);
      return -1;
    }
  }
  else
  {
    ERR_put_error(4u, 113, 107, ".\\crypto\\rsa\\rsa_pk1.c", 190);
    return -1;
  }
}
