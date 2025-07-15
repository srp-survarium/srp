int __usercall EC_GROUP_get_pentanomial_basis@<eax>(
        int a1@<ebx>,
        ssl_st *group,
        unsigned int *k1,
        void (__cdecl **k2)(int, int, int, const void *, unsigned int, ssl_st *, void *),
        unsigned int *k3)
{
  void *msg_callback_arg; // eax

  if ( !group )
    return 0;
  if ( *(int (__cdecl **)(ec_group_st *, const bignum_st *, const bignum_st *, const bignum_st *))(EVP_CIPHER_CTX_cipher(group)
                                                                                                 + 20) != ec_GF2m_simple_group_set_curve
    || !group->d1
    || !group->read_ahead
    || !group->msg_callback
    || (msg_callback_arg = group->msg_callback_arg) == 0
    || group->hit )
  {
    ERR_put_error(a1, 0x10u, 193, 66, ".\\crypto\\ec\\ec_asn1.c", 114);
    return 0;
  }
  if ( k1 )
    *k1 = (unsigned int)msg_callback_arg;
  if ( k2 )
    *k2 = group->msg_callback;
  if ( k3 )
    *k3 = group->read_ahead;
  return 1;
}
