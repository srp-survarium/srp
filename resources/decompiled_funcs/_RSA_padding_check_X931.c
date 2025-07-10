unsigned int __cdecl RSA_padding_check_X931(
        unsigned __int8 *to,
        int tlen,
        const unsigned __int8 *from,
        int flen,
        int num)
{
  char v5; // al
  unsigned __int8 *v6; // edx
  int v7; // esi
  int i; // ecx
  char v9; // al
  unsigned int v10; // esi

  if ( num == flen && ((v5 = *from, *from == 106) || v5 == 107) )
  {
    v6 = (unsigned __int8 *)(from + 1);
    if ( v5 == 107 )
    {
      v7 = flen - 3;
      for ( i = 0; i < v7; ++i )
      {
        v9 = *v6++;
        if ( v9 == -70 )
          break;
        if ( v9 != -69 )
        {
          ERR_put_error(4u, 128, 138, ".\\crypto\\rsa\\rsa_x931.c", 129);
          return -1;
        }
      }
      v10 = v7 - i;
      if ( !i )
      {
        ERR_put_error(4u, 128, 138, ".\\crypto\\rsa\\rsa_x931.c", 138);
        return -1;
      }
    }
    else
    {
      v10 = flen - 2;
    }
    if ( v6[v10] == 0xCC )
    {
      memcpy(to, v6, v10);
      return v10;
    }
    else
    {
      ERR_put_error(4u, 128, 139, ".\\crypto\\rsa\\rsa_x931.c", 147);
      return -1;
    }
  }
  else
  {
    ERR_put_error(4u, 128, 137, ".\\crypto\\rsa\\rsa_x931.c", 114);
    return -1;
  }
}
