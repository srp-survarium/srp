ecdh_data_st *__cdecl ECDH_compute_key(
        void *out,
        unsigned int outlen,
        const ec_point_st *pub_key,
        ec_key_st *eckey,
        void *(__cdecl *KDF)(const void *, unsigned int, void *, unsigned int *))
{
  ecdh_data_st *result; // eax

  result = ecdh_check(eckey);
  if ( result )
    return (ecdh_data_st *)result->meth->compute_key(out, outlen, pub_key, eckey, KDF);
  return result;
}
