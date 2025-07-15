int __cdecl DH_check_pub_key(const dh_st *dh, const bignum_st *pub_key, int *ret)
{
  bignum_st *v3; // eax
  bignum_st *v4; // esi

  *ret = 0;
  v3 = BN_new(0);
  v4 = v3;
  if ( !v3 )
    return 0;
  BN_set_word(0, v3, 1u);
  if ( BN_cmp(pub_key, v4) <= 0 )
    *ret |= 1u;
  BN_copy(v4, dh->p);
  BN_sub_word((int)pub_key, v4, 1u);
  if ( BN_cmp(pub_key, v4) >= 0 )
    *ret |= 2u;
  BN_free(v4);
  return 1;
}
