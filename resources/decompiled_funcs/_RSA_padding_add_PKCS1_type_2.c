int __cdecl RSA_padding_add_PKCS1_type_2(unsigned __int8 *to, int tlen, unsigned __int8 *from, int flen)
{
  int v5; // edi
  unsigned __int8 *v6; // esi
  int v7; // ebx

  if ( flen <= tlen - 11 )
  {
    *to = 0;
    v5 = tlen - flen - 3;
    to[1] = 2;
    v6 = to + 2;
    if ( RAND_bytes() > 0 )
    {
      v7 = 0;
      if ( v5 <= 0 )
      {
LABEL_10:
        *v6 = 0;
        memcpy(v6 + 1, from, flen);
        return 1;
      }
      else
      {
        while ( *v6 )
        {
LABEL_9:
          ++v7;
          ++v6;
          if ( v7 >= v5 )
            goto LABEL_10;
        }
        while ( RAND_bytes() > 0 )
        {
          if ( *v6 )
            goto LABEL_9;
        }
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    ERR_put_error(4u, 109, 110, ".\\crypto\\rsa\\rsa_pk1.c", 151);
    return 0;
  }
}
