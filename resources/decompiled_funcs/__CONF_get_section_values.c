stack_st_CONF_VALUE *__cdecl _CONF_get_section_values(const conf_st *conf, const char *section)
{
  lhash_st *v2; // ecx
  void **v3; // eax
  _DWORD data[3]; // [esp+0h] [ebp-Ch] BYREF

  if ( conf
    && section
    && (v2 = (lhash_st *)conf->data, data[0] = section, data[1] = 0, (v3 = lh_retrieve(v2, data)) != 0) )
  {
    return (stack_st_CONF_VALUE *)v3[2];
  }
  else
  {
    return 0;
  }
}
