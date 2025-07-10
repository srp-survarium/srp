BOOL __cdecl EC_KEY_set_private_key(ec_key_st *key, const bignum_st *priv_key)
{
  bignum_st *v2; // eax

  if ( key->priv_key )
    BN_clear_free(key->priv_key);
  v2 = BN_dup(priv_key);
  key->priv_key = v2;
  return v2 != 0;
}
