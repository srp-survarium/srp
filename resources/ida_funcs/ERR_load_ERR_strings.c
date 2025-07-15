void __usercall ERR_load_ERR_strings(unsigned int a1@<edi>)
{
  ERR_string_data_st *i; // esi
  ERR_string_data_st *j; // esi
  ERR_string_data_st *k; // esi
  const st_ERR_FNS *v4; // ecx
  ERR_string_data_st *m; // esi
  const st_ERR_FNS *v6; // eax

  if ( !err_fns )
  {
    CRYPTO_lock(a1, 9, 1, ".\\crypto\\err\\err.c", 295);
    if ( !err_fns )
      err_fns = &err_defaults;
    CRYPTO_lock(a1, 10, 1, ".\\crypto\\err\\err.c", 298);
  }
  for ( i = ERR_str_libraries; i->error; ++i )
    err_fns->cb_err_set_item(i);
  for ( j = ERR_str_reasons; j->error; ++j )
    err_fns->cb_err_set_item(j);
  for ( k = ERR_str_functs; k->error; ++k )
  {
    v4 = err_fns;
    k->error |= (unsigned int)&vostok::memory::s_CRT_arena[22351416];
    v4->cb_err_set_item(k);
  }
  build_SYS_str_reasons(a1);
  for ( m = SYS_str_reasons; m->error; ++m )
  {
    v6 = err_fns;
    m->error |= (unsigned int)&vostok::memory::s_CRT_arena[22351416];
    v6->cb_err_set_item(m);
  }
}
