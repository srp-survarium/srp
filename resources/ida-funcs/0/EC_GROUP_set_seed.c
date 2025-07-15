int __cdecl EC_GROUP_set_seed(ec_group_st *group, const __m128i *p, unsigned int len)
{
  int result; // eax

  if ( group->seed )
  {
    CRYPTO_free(group->seed);
    group->seed = 0;
    group->seed_len = 0;
  }
  if ( !len || !p )
    return 1;
  result = (int)CRYPTO_malloc(len, ".\\crypto\\ec\\ec_lib.c", 386);
  group->seed = (unsigned __int8 *)result;
  if ( result )
  {
    memcpy(result, p, len);
    group->seed_len = len;
    return len;
  }
  return result;
}
