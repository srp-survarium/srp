int __cdecl RSA_padding_add_SSLv23(unsigned __int8 *to, int tlen, unsigned __int8 *from, int flen)
{
  int v5; // edi
  unsigned __int8 *v6; // esi
  int v7; // ebx
  _BYTE *v8; // esi

  if ( flen <= tlen - 11 )
  {
    *to = 0;
    v5 = tlen - flen - 11;
    to[1] = 2;
    v6 = to + 2;
    if ( RAND_bytes() > 0 )
    {
      v7 = 0;
      if ( v5 <= 0 )
      {
LABEL_10:
        *(_DWORD *)v6 = &vostok::memory::s_CRT_arena[39326011];
        *((_DWORD *)v6 + 1) = &vostok::memory::s_CRT_arena[39326011];
        v8 = v6 + 8;
        *v8 = 0;
        memcpy(v8 + 1, from, flen);
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
    ERR_put_error(4u, 110, 110, ".\\crypto\\rsa\\rsa_ssl.c", 73);
    return 0;
  }
}
