int __usercall bnrand@<eax>(int bits@<ecx>, int pseudorand@<edx>, int a3@<ebx>, bignum_st *rnd, int top, int bottom)
{
  int v8; // ebp
  int v9; // ebx
  unsigned __int8 *v10; // esi
  void *v11; // esp
  int i; // edi
  unsigned __int8 v13; // [esp+1Bh] [ebp-11h]
  int v14; // [esp+1Ch] [ebp-10h]
  __int64 timeptr; // [esp+24h] [ebp-8h] BYREF

  v14 = 0;
  if ( !bits )
  {
    BN_set_word(a3, rnd, 0);
    return 1;
  }
  v8 = (bits + 7) / 8;
  v9 = (bits - 1) % 8;
  v10 = (unsigned __int8 *)CRYPTO_malloc(v8, ".\\crypto\\bn\\bn_rand.c", 134);
  if ( !v10 )
  {
    ERR_put_error(v9, 3u, 127, 65, ".\\crypto\\bn\\bn_rand.c", 137);
    return 0;
  }
  _time64(&timeptr);
  v11 = alloca(8);
  RAND_add(pseudorand, &timeptr, 8, 0.0);
  if ( pseudorand )
  {
    if ( RAND_pseudo_bytes(pseudorand) != -1 )
    {
      if ( pseudorand == 2 )
      {
        for ( i = 0; i < v8; ++i )
        {
          RAND_pseudo_bytes(i);
          if ( v13 < 0x80u || i <= 0 )
          {
            if ( v13 >= 0x2Au )
            {
              if ( v13 < 0x54u )
                v10[i] = -1;
            }
            else
            {
              v10[i] = 0;
            }
          }
          else
          {
            v10[i] = v10[i - 1];
          }
        }
      }
      goto LABEL_19;
    }
  }
  else if ( RAND_bytes(0) > 0 )
  {
LABEL_19:
    if ( top != -1 )
    {
      if ( top )
      {
        if ( v9 )
        {
          *v10 |= 3 << (v9 - 1);
        }
        else
        {
          v10[1] |= 0x80u;
          *v10 = 1;
        }
      }
      else
      {
        *v10 |= 1 << v9;
      }
    }
    *v10 &= ~(unsigned __int8)(255 << (v9 + 1));
    if ( bottom )
      v10[v8 - 1] |= 1u;
    if ( BN_bin2bn(v10, v8, rnd) )
      v14 = 1;
  }
  OPENSSL_cleanse(v10, v8);
  CRYPTO_free(v10);
  return v14;
}
