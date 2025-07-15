int __cdecl EVP_CIPHER_param_to_asn1(evp_cipher_ctx_st *c)
{
  int (*set_asn1_parameters)(void); // eax

  set_asn1_parameters = (int (*)(void))c->cipher->set_asn1_parameters;
  if ( set_asn1_parameters )
    return set_asn1_parameters();
  else
    return -1;
}
