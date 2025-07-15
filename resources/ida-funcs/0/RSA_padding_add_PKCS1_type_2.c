int __usercall RSA_padding_add_PKCS1_type_2@<eax>(
        int a1@<ebx>,
        unsigned __int8 *to,
        int tlen,
        const __m128i *from,
        int flen)
{
  int v6; // edi
  unsigned __int8 *v7; // esi
  int v8; // ebx

  if ( flen <= tlen - 11 )
  {
    *to = 0;
    v6 = tlen - flen - 3;
    to[1] = 2;
    v7 = to + 2;
    if ( RAND_bytes(v6) > 0 )
    {
      v8 = 0;
      if ( v6 <= 0 )
      {
LABEL_10:
        *v7 = 0;
        memcpy((int)(v7 + 1), from, flen);
        return 1;
      }
      else
      {
        while ( *v7 )
        {
LABEL_9:
          ++v8;
          ++v7;
          if ( v8 >= v6 )
            goto LABEL_10;
        }
        while ( RAND_bytes(v6) > 0 )
        {
          if ( *v7 )
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
    ERR_put_error(a1, 4u, 109, 110, ".\\crypto\\rsa\\rsa_pk1.c", 151);
    return 0;
  }
}
