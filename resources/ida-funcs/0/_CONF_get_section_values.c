stack_st_CONF_VALUE *__cdecl _CONF_get_section_values(const conf_st *conf, const char *section)
{
  lhash_st *data; // ecx
  void ***v3; // eax
  _DWORD v5[3]; // [esp+0h] [ebp-Ch] BYREF

  if ( conf && section && (data = (lhash_st *)conf->data, v5[0] = section, v5[1] = 0, (v3 = lh_retrieve(data, v5)) != 0) )
    return (stack_st_CONF_VALUE *)v3[2];
  else
    return 0;
}
