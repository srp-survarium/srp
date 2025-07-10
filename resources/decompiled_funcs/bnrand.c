int __fastcall bnrand(int bits, int pseudorand, bignum_st *rnd, int top, int bottom)
{
  int v7; // ebp
  int v8; // ebx
  unsigned __int8 *v9; // esi
  void *v10; // esp
  int i; // edi
  unsigned __int8 buf; // [esp+1Bh] [ebp-11h]
  int v13; // [esp+1Ch] [ebp-10h]
  __int64 timeptr; // [esp+24h] [ebp-8h] BYREF

  v13 = 0;
  if ( !bits )
  {
    BN_set_word(rnd, 0);
    return 1;
  }
  v7 = (bits + 7) / 8;
  v8 = (bits - 1) % 8;
  v9 = (unsigned __int8 *)CRYPTO_malloc(v7, ".\\crypto\\bn\\bn_rand.c", 134);
  if ( !v9 )
  {
    ERR_put_error(3u, 127, 65, ".\\crypto\\bn\\bn_rand.c", 137);
    return 0;
  }
  _time64(&timeptr);
  v10 = alloca(8);
  RAND_add(&timeptr, 8, 0.0);
  if ( pseudorand )
  {
    if ( RAND_pseudo_bytes() != -1 )
    {
      if ( pseudorand == 2 )
      {
        for ( i = 0; i < v7; ++i )
        {
          RAND_pseudo_bytes();
          if ( buf < 0x80u || i <= 0 )
          {
            if ( buf >= 0x2Au )
            {
              if ( buf < 0x54u )
                v9[i] = -1;
            }
            else
            {
              v9[i] = 0;
            }
          }
          else
          {
            v9[i] = v9[i - 1];
          }
        }
      }
      goto LABEL_19;
    }
  }
  else if ( RAND_bytes() > 0 )
  {
LABEL_19:
    if ( top != -1 )
    {
      if ( top )
      {
        if ( v8 )
        {
          *v9 |= 3 << (v8 - 1);
        }
        else
        {
          v9[1] |= 0x80u;
          *v9 = 1;
        }
      }
      else
      {
        *v9 |= 1 << v8;
      }
    }
    *v9 &= ~(unsigned __int8)(255 << (v8 + 1));
    if ( bottom )
      v9[v7 - 1] |= 1u;
    if ( BN_bin2bn(v9, v7, rnd) )
      v13 = 1;
  }
  OPENSSL_cleanse(v9, v7);
  CRYPTO_free(v9);
  return v13;
}
