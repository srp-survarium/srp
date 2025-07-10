stack_st_CONF_VALUE *__cdecl CONF_get_section(lhash_st_CONF_VALUE *conf, char *section)
{
  conf_method_st *v3; // eax
  conf_st confa; // [esp+4h] [ebp-Ch] BYREF

  if ( !conf )
    return 0;
  v3 = default_CONF_method;
  if ( !default_CONF_method )
  {
    v3 = (conf_method_st *)NCONF_default();
    default_CONF_method = v3;
  }
  v3->init(&confa);
  confa.data = conf;
  return NCONF_get_section(&confa, section);
}
