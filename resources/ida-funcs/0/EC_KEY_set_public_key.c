BOOL __cdecl EC_KEY_set_public_key(ec_key_st *key, const ec_point_st *pub_key)
{
  ec_point_st *v2; // eax

  if ( key->pub_key )
    EC_POINT_free(key->pub_key);
  v2 = EC_POINT_dup(pub_key, key->group);
  key->pub_key = v2;
  return v2 != 0;
}
