int __usercall RSA_padding_check_PKCS1_type_1@<eax>(
        int a1@<ebx>,
        unsigned __int8 *to,
        int tlen,
        const unsigned __int8 *from,
        int flen,
        int num)
{
  const __m128i *v6; // ecx
  int v7; // esi
  int v8; // eax
  signed int v10; // esi

  if ( num == flen + 1 && (v6 = (const __m128i *)(from + 1), *from == 1) )
  {
    v7 = flen - 1;
    v8 = 0;
    if ( flen - 1 > 0 )
    {
      while ( v6->m128i_i8[0] == -1 )
      {
        ++v8;
        v6 = (const __m128i *)((char *)v6 + 1);
        if ( v8 >= v7 )
          goto LABEL_6;
      }
      if ( v6->m128i_i8[0] )
      {
        ERR_put_error(a1, 4u, 112, 102, ".\\crypto\\rsa\\rsa_pk1.c", 113);
        return -1;
      }
      v6 = (const __m128i *)((char *)v6 + 1);
    }
LABEL_6:
    if ( v8 == v7 )
    {
      ERR_put_error(a1, 4u, 112, 113, ".\\crypto\\rsa\\rsa_pk1.c", 122);
      return -1;
    }
    else if ( v8 >= 8 )
    {
      v10 = -1 - v8 + v7;
      if ( v10 <= tlen )
      {
        memcpy((int)to, v6, v10);
        return v10;
      }
      else
      {
        ERR_put_error(a1, 4u, 112, 109, ".\\crypto\\rsa\\rsa_pk1.c", 135);
        return -1;
      }
    }
    else
    {
      ERR_put_error(a1, 4u, 112, 103, ".\\crypto\\rsa\\rsa_pk1.c", 128);
      return -1;
    }
  }
  else
  {
    ERR_put_error(a1, 4u, 112, 106, ".\\crypto\\rsa\\rsa_pk1.c", 100);
    return -1;
  }
}
