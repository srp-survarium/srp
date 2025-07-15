BOOL __usercall probable_prime@<eax>(bignum_st *rnd@<edi>, int bits@<ebx>)
{
  int i; // esi
  unsigned int v3; // esi
  int j; // ecx
  _WORD v6[2047]; // [esp+Ah] [ebp-1002h]

  while ( BN_rand(rnd, bits, 1, 1) )
  {
    for ( i = 0; i < 2047; ++i )
      v6[i] = BN_mod_word(rnd, primes[i + 1]);
    v3 = 0;
    while ( 2 )
    {
      for ( j = 0; ; ++j )
      {
        if ( j >= 2047 )
          return BN_add_word(rnd, v3) != 0;
        if ( (v3 + (unsigned __int16)v6[j]) % primes[j + 1] <= 1 )
          break;
      }
      v3 += 2;
      if ( v3 <= 0xFFFFBA38 )
        continue;
      break;
    }
  }
  return 0;
}
