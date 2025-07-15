BOOL __usercall EC_KEY_set_private_key@<eax>(int a1@<ebx>, ec_key_st *key, const bignum_st *priv_key)
{
  bignum_st *v3; // eax

  if ( key->priv_key )
    BN_clear_free(key->priv_key);
  v3 = BN_dup(a1, priv_key);
  key->priv_key = v3;
  return v3 != 0;
}
