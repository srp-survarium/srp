int __cdecl RSA_padding_check_SSLv23(unsigned __int8 *to, int tlen, const unsigned __int8 *from, int flen, int num)
{
  unsigned __int8 *v6; // edx
  int v7; // esi
  int i; // ecx
  int v10; // eax
  signed int v11; // esi

  if ( flen >= 10 )
  {
    if ( num == flen + 1 && (v6 = (unsigned __int8 *)(from + 1), *from == 2) )
    {
      v7 = flen - 1;
      for ( i = 0; i < v7; ++i )
      {
        if ( !*v6++ )
          break;
      }
      if ( i == v7 || i < 8 )
      {
        ERR_put_error(4u, 114, 113, ".\\crypto\\rsa\\rsa_ssl.c", 130);
        return -1;
      }
      else
      {
        v10 = -9;
        do
        {
          if ( v6[v10] != 3 )
            break;
          ++v10;
        }
        while ( v10 < -1 );
        if ( v10 == -1 )
        {
          ERR_put_error(4u, 114, 115, ".\\crypto\\rsa\\rsa_ssl.c", 139);
          return -1;
        }
        else
        {
          v11 = -1 - i + v7;
          if ( v11 <= tlen )
          {
            memcpy(to, v6, v11);
            return v11;
          }
          else
          {
            ERR_put_error(4u, 114, 109, ".\\crypto\\rsa\\rsa_ssl.c", 147);
            return -1;
          }
        }
      }
    }
    else
    {
      ERR_put_error(4u, 114, 107, ".\\crypto\\rsa\\rsa_ssl.c", 119);
      return -1;
    }
  }
  else
  {
    ERR_put_error(4u, 114, 111, ".\\crypto\\rsa\\rsa_ssl.c", 114);
    return -1;
  }
}
