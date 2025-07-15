CONF_VALUE *__cdecl _CONF_get_section(const conf_st *conf, const char *section)
{
  lhash_st *v2; // ecx
  _DWORD data[3]; // [esp+0h] [ebp-Ch] BYREF

  if ( !conf || !section )
    return 0;
  v2 = (lhash_st *)conf->data;
  data[0] = section;
  data[1] = 0;
  return (CONF_VALUE *)lh_retrieve(v2, data);
}
