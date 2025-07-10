BOOL __cdecl EC_KEY_set_group(ec_key_st *key, const ec_group_st *group)
{
  ec_group_st *v2; // eax

  if ( key->group )
    EC_GROUP_free(key->group);
  v2 = EC_GROUP_dup(group);
  key->group = v2;
  return v2 != 0;
}
