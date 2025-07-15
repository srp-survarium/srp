int __cdecl EVP_CIPHER_asn1_to_param(evp_cipher_ctx_st *c)
{
  int (*get_asn1_parameters)(void); // eax

  get_asn1_parameters = (int (*)(void))c->cipher->get_asn1_parameters;
  if ( get_asn1_parameters )
    return get_asn1_parameters();
  else
    return -1;
}
