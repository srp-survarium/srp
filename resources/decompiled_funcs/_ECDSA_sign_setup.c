ecdsa_data_st *__cdecl ECDSA_sign_setup(ec_key_st *eckey, bignum_ctx *ctx_in, bignum_st **kinvp, bignum_st **rp)
{
  ecdsa_data_st *result; // eax

  result = ecdsa_check(eckey);
  if ( result )
    return (ecdsa_data_st *)result->meth->ecdsa_sign_setup(eckey, ctx_in, kinvp, rp);
  return result;
}
