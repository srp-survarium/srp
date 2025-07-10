void __cdecl EC_KEY_set_enc_flags(ec_key_st *key, unsigned int flags)
{
  key->enc_flag = flags;
}
