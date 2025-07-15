stack_st_CONF_VALUE *__usercall CONF_get_section@<eax>(int a1@<ebx>, lhash_st_CONF_VALUE *conf, char *section)
{
  conf_method_st *v4; // eax
  conf_st v5; // [esp+4h] [ebp-Ch] BYREF

  if ( !conf )
    return 0;
  v4 = default_CONF_method;
  if ( !default_CONF_method )
  {
    v4 = NCONF_default();
    default_CONF_method = v4;
  }
  v4->init(&v5);
  v5.data = conf;
  return NCONF_get_section(a1, &v5, section);
}
