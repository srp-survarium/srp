int __cdecl int_ec_size(ec_key_st *pkey)
{
  return ECDSA_size((const ec_key_st *)pkey->conv_form);
}
