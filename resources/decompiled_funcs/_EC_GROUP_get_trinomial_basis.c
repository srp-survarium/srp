int __cdecl EC_GROUP_get_trinomial_basis(const ssl_st *group, unsigned int *k)
{
  unsigned int read_ahead; // eax

  if ( !group )
    return 0;
  if ( *(int (__cdecl **)(ec_group_st *, const bignum_st *, const bignum_st *, const bignum_st *, bignum_ctx *))(EVP_CIPHER_CTX_cipher(group) + 20) != ec_GF2m_simple_group_set_curve
    || !group->d1
    || (read_ahead = group->read_ahead) == 0
    || group->msg_callback )
  {
    ERR_put_error(0x10u, 194, 66, ".\\crypto\\ec\\ec_asn1.c", 95);
    return 0;
  }
  if ( k )
    *k = read_ahead;
  return 1;
}
