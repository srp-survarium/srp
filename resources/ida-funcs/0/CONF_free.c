void __cdecl CONF_free(lhash_st_CONF_VALUE *conf)
{
  conf_method_st *v1; // eax
  _DWORD v2[3]; // [esp+0h] [ebp-Ch] BYREF

  v1 = default_CONF_method;
  if ( !default_CONF_method )
  {
    v1 = NCONF_default();
    default_CONF_method = v1;
  }
  v1->init((conf_st *)v2);
  v2[2] = conf;
  (*(void (__cdecl **)(_DWORD *))(v2[0] + 16))(v2);
}
