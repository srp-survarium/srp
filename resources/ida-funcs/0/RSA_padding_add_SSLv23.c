int __usercall RSA_padding_add_SSLv23@<eax>(int a1@<ebx>, unsigned __int8 *to, int tlen, const __m128i *from, int flen)
{
  int v6; // edi
  unsigned __int8 *v7; // esi
  int v8; // ebx
  _BYTE *v9; // esi

  if ( flen <= tlen - 11 )
  {
    *to = 0;
    v6 = tlen - flen - 11;
    to[1] = 2;
    v7 = to + 2;
    if ( RAND_bytes(v6) > 0 )
    {
      v8 = 0;
      if ( v6 <= 0 )
      {
LABEL_10:
        *(_DWORD *)v7 = 50529027;
        *((_DWORD *)v7 + 1) = 50529027;
        v9 = v7 + 8;
        *v9 = 0;
        memcpy((int)(v9 + 1), from, flen);
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
    ERR_put_error(a1, 4u, 110, 110, ".\\crypto\\rsa\\rsa_ssl.c", 73);
    return 0;
  }
}
