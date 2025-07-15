ecdsa_data_st *__usercall ECDSA_sign_setup@<eax>(
        int a1@<edi>,
        ec_key_st *eckey,
        bignum_ctx *ctx_in,
        bignum_st **kinvp,
        bignum_st **rp)
{
  ecdsa_data_st *result; // eax

  result = ecdsa_check(a1, eckey);
  if ( result )
    return (ecdsa_data_st *)result->meth->ecdsa_sign_setup(eckey, ctx_in, kinvp, rp);
  return result;
}
