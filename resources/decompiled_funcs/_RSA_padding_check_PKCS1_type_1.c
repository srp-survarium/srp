int __cdecl RSA_padding_check_PKCS1_type_1(
        unsigned __int8 *to,
        int tlen,
        const unsigned __int8 *from,
        int flen,
        int num)
{
  unsigned __int8 *v5; // ecx
  int v6; // esi
  int v7; // eax
  signed int v9; // esi

  if ( num == flen + 1 && (v5 = (unsigned __int8 *)(from + 1), *from == 1) )
  {
    v6 = flen - 1;
    v7 = 0;
    if ( flen - 1 > 0 )
    {
      while ( *v5 == 0xFF )
      {
        ++v7;
        ++v5;
        if ( v7 >= v6 )
          goto LABEL_6;
      }
      if ( *v5 )
      {
        ERR_put_error(4u, 112, 102, ".\\crypto\\rsa\\rsa_pk1.c", 113);
        return -1;
      }
      ++v5;
    }
LABEL_6:
    if ( v7 == v6 )
    {
      ERR_put_error(4u, 112, 113, ".\\crypto\\rsa\\rsa_pk1.c", 122);
      return -1;
    }
    else if ( v7 >= 8 )
    {
      v9 = -1 - v7 + v6;
      if ( v9 <= tlen )
      {
        memcpy(to, v5, v9);
        return v9;
      }
      else
      {
        ERR_put_error(4u, 112, 109, ".\\crypto\\rsa\\rsa_pk1.c", 135);
        return -1;
      }
    }
    else
    {
      ERR_put_error(4u, 112, 103, ".\\crypto\\rsa\\rsa_pk1.c", 128);
      return -1;
    }
  }
  else
  {
    ERR_put_error(4u, 112, 106, ".\\crypto\\rsa\\rsa_pk1.c", 100);
    return -1;
  }
}
