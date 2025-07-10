int __cdecl RSA_padding_add_X931(unsigned __int8 *to, int tlen, unsigned __int8 *from, unsigned int flen)
{
  int v4; // edi
  unsigned __int8 *v6; // esi

  v4 = tlen - flen - 2;
  if ( v4 >= 0 )
  {
    v6 = to + 1;
    if ( tlen - flen == 2 )
    {
      *to = 106;
    }
    else
    {
      *to = 107;
      if ( v4 > 1 )
      {
        memset((int)v6, (unsigned __int8 *)0xBB, tlen - flen - 3);
        v6 = &to[v4];
      }
      *v6++ = -70;
    }
    memcpy(v6, from, flen);
    v6[flen] = -52;
    return 1;
  }
  else
  {
    ERR_put_error(4u, 127, 110, ".\\crypto\\rsa\\rsa_x931.c", 80);
    return -1;
  }
}
