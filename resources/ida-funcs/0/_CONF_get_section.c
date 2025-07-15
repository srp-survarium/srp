void ***__cdecl _CONF_get_section(const conf_st *conf, const char *section)
{
  lhash_st *data; // ecx
  _DWORD v4[3]; // [esp+0h] [ebp-Ch] BYREF

  if ( !conf || !section )
    return 0;
  data = (lhash_st *)conf->data;
  v4[0] = section;
  v4[1] = 0;
  return lh_retrieve(data, v4);
}
