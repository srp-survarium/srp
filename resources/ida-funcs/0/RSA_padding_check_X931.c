unsigned int __usercall RSA_padding_check_X931@<eax>(
        int a1@<ebx>,
        unsigned __int8 *to,
        int tlen,
        const unsigned __int8 *from,
        int flen,
        int num)
{
  char v6; // al
  const __m128i *v7; // edx
  int v8; // esi
  int i; // ecx
  char v10; // al
  unsigned int v11; // esi

  if ( num == flen && ((v6 = *from, *from == 106) || v6 == 107) )
  {
    v7 = (const __m128i *)(from + 1);
    if ( v6 == 107 )
    {
      v8 = flen - 3;
      for ( i = 0; i < v8; ++i )
      {
        v10 = v7->m128i_i8[0];
        v7 = (const __m128i *)((char *)v7 + 1);
        if ( v10 == -70 )
          break;
        if ( v10 != -69 )
        {
          ERR_put_error(a1, 4u, 128, 138, ".\\crypto\\rsa\\rsa_x931.c", 129);
          return -1;
        }
      }
      v11 = v8 - i;
      if ( !i )
      {
        ERR_put_error(a1, 4u, 128, 138, ".\\crypto\\rsa\\rsa_x931.c", 138);
        return -1;
      }
    }
    else
    {
      v11 = flen - 2;
    }
    if ( v7->m128i_i8[v11] == -52 )
    {
      memcpy((int)to, v7, v11);
      return v11;
    }
    else
    {
      ERR_put_error(a1, 4u, 128, 139, ".\\crypto\\rsa\\rsa_x931.c", 147);
      return -1;
    }
  }
  else
  {
    ERR_put_error(a1, 4u, 128, 137, ".\\crypto\\rsa\\rsa_x931.c", 114);
    return -1;
  }
}
