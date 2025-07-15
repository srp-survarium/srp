void __cdecl _CONF_free_data(conf_st *conf)
{
  if ( conf )
  {
    if ( conf->data )
    {
      conf->data[8].dummy = 0;
      lh_doall_arg(
        (lhash_st *)conf->data,
        (void (__cdecl *)(void *, void *))value_free_hash_LHASH_DOALL_ARG,
        conf->data);
      lh_doall((lhash_st *)conf->data, (void (__cdecl *)(void *))value_free_stack_LHASH_DOALL);
      lh_free((lhash_st *)conf->data);
    }
  }
}
