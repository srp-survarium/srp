BOOL __cdecl _CONF_new_data(conf_st *conf)
{
  BOOL result; // eax
  lhash_st *v2; // eax

  result = 0;
  if ( conf )
  {
    if ( conf->data )
      return 1;
    v2 = lh_new(
           (int (__cdecl *)(const char *))conf_value_LHASH_HASH,
           (void (__cdecl *)(unsigned __int8 *, unsigned __int8 *))conf_value_LHASH_COMP);
    conf->data = (lhash_st_CONF_VALUE *)v2;
    if ( v2 )
      return 1;
  }
  return result;
}
