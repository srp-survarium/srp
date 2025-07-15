int __usercall RSA_padding_check_PKCS1_type_2@<eax>(
        int a1@<ebx>,
        unsigned __int8 *to,
        int tlen,
        const unsigned __int8 *from,
        int flen,
        int num)
{
  const __m128i *v6; // edx
  int v7; // esi
  int i; // eax
  char v9; // cl
  signed int v11; // esi

  if ( num == flen + 1 && (v6 = (const __m128i *)(from + 1), *from == 2) )
  {
    v7 = flen - 1;
    for ( i = 0; i < v7; ++i )
    {
      v9 = v6->m128i_i8[0];
      v6 = (const __m128i *)((char *)v6 + 1);
      if ( !v9 )
        break;
    }
    if ( i == v7 )
    {
      ERR_put_error(a1, 4u, 113, 113, ".\\crypto\\rsa\\rsa_pk1.c", 204);
      return -1;
    }
    else if ( i >= 8 )
    {
      v11 = -1 - i + v7;
      if ( v11 <= tlen )
      {
        memcpy((int)to, v6, v11);
        return v11;
      }
      else
      {
        ERR_put_error(a1, 4u, 113, 109, ".\\crypto\\rsa\\rsa_pk1.c", 217);
        return -1;
      }
    }
    else
    {
      ERR_put_error(a1, 4u, 113, 103, ".\\crypto\\rsa\\rsa_pk1.c", 210);
      return -1;
    }
  }
  else
  {
    ERR_put_error(a1, 4u, 113, 107, ".\\crypto\\rsa\\rsa_pk1.c", 190);
    return -1;
  }
}
