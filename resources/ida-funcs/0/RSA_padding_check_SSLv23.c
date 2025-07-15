int __usercall RSA_padding_check_SSLv23@<eax>(
        int a1@<ebx>,
        unsigned __int8 *to,
        int tlen,
        const unsigned __int8 *from,
        int flen,
        int num)
{
  const __m128i *v7; // edx
  int v8; // esi
  int i; // ecx
  char v10; // al
  int v11; // eax
  signed int v12; // esi

  if ( flen >= 10 )
  {
    if ( num == flen + 1 && (v7 = (const __m128i *)(from + 1), *from == 2) )
    {
      v8 = flen - 1;
      for ( i = 0; i < v8; ++i )
      {
        v10 = v7->m128i_i8[0];
        v7 = (const __m128i *)((char *)v7 + 1);
        if ( !v10 )
          break;
      }
      if ( i == v8 || i < 8 )
      {
        ERR_put_error(a1, 4u, 114, 113, ".\\crypto\\rsa\\rsa_ssl.c", 130);
        return -1;
      }
      else
      {
        v11 = -9;
        do
        {
          if ( v7->m128i_i8[v11] != 3 )
            break;
          ++v11;
        }
        while ( v11 < -1 );
        if ( v11 == -1 )
        {
          ERR_put_error(a1, 4u, 114, 115, ".\\crypto\\rsa\\rsa_ssl.c", 139);
          return -1;
        }
        else
        {
          v12 = -1 - i + v8;
          if ( v12 <= tlen )
          {
            memcpy((int)to, v7, v12);
            return v12;
          }
          else
          {
            ERR_put_error(a1, 4u, 114, 109, ".\\crypto\\rsa\\rsa_ssl.c", 147);
            return -1;
          }
        }
      }
    }
    else
    {
      ERR_put_error(a1, 4u, 114, 107, ".\\crypto\\rsa\\rsa_ssl.c", 119);
      return -1;
    }
  }
  else
  {
    ERR_put_error(a1, 4u, 114, 111, ".\\crypto\\rsa\\rsa_ssl.c", 114);
    return -1;
  }
}
