int __usercall bn_rand_range@<eax>(bignum_st *r@<esi>, const bignum_st *range@<edi>, int pseudo)
{
  int (__cdecl *v3)(bignum_st *, int, int, int); // ebp
  int v4; // ebx
  int v6; // ebx
  int count; // [esp+8h] [ebp+4h]

  v3 = BN_pseudo_rand;
  if ( !pseudo )
    v3 = BN_rand;
  count = 100;
  if ( range->neg || !range->top )
  {
    ERR_put_error(3u, 122, 115, ".\\crypto\\bn\\bn_rand.c", 238);
    return 0;
  }
  else
  {
    v4 = BN_num_bits(range);
    if ( v4 == 1 )
    {
      BN_set_word(r, 0);
      return 1;
    }
    else
    {
      if ( BN_is_bit_set(range, v4 - 2) || BN_is_bit_set(range, v4 - 3) )
      {
        while ( v3(r, v4, -1, 0) )
        {
          if ( !--count )
          {
            ERR_put_error(3u, 122, 113, ".\\crypto\\bn\\bn_rand.c", 285);
            return 0;
          }
          if ( BN_cmp(r, range) < 0 )
            return 1;
        }
      }
      else
      {
        v6 = v4 + 1;
        while ( v3(r, v6, -1, 0)
             && (BN_cmp(r, range) < 0 || BN_sub(r, r, range) && (BN_cmp(r, range) < 0 || BN_sub(r, r, range))) )
        {
          if ( !--count )
          {
            ERR_put_error(3u, 122, 113, ".\\crypto\\bn\\bn_rand.c", 269);
            return 0;
          }
          if ( BN_cmp(r, range) < 0 )
            return 1;
        }
      }
      return 0;
    }
  }
}
