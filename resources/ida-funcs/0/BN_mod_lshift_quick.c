int __cdecl BN_mod_lshift_quick(bignum_st *r, const bignum_st *a, int n, const bignum_st *m)
{
  int result; // eax
  int v6; // ebx
  int v7; // esi
  bignum_st *aa; // [esp+8h] [ebp+4h]

  if ( r == a || (result = (int)BN_copy(r, a)) != 0 )
  {
    v6 = n;
    if ( n <= 0 )
    {
      return 1;
    }
    else
    {
      while ( 1 )
      {
        aa = (bignum_st *)BN_num_bits(r);
        v7 = BN_num_bits(m) - (_DWORD)aa;
        if ( v7 < 0 )
          break;
        if ( v7 > v6 )
          v7 = v6;
        if ( v7 )
        {
          if ( !BN_lshift(r, r, v7) )
            return 0;
          v6 -= v7;
        }
        else
        {
          if ( !BN_lshift1(r, r) )
            return 0;
          --v6;
        }
        if ( BN_cmp(r, m) >= 0 && !BN_sub(r, r, m) )
          return 0;
        if ( v6 <= 0 )
          return 1;
      }
      ERR_put_error(v6, 3u, 119, 110, ".\\crypto\\bn\\bn_mod.c", 273);
      return 0;
    }
  }
  return result;
}
