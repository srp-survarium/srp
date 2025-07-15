void __usercall int_cleanup(unsigned int a1@<edi>)
{
  if ( ex_data || ex_data_check(a1) )
  {
    lh_doall((lhash_st *)ex_data, (void (__cdecl *)(void *))def_cleanup_cb);
    lh_free((lhash_st *)ex_data);
    ex_data = 0;
    impl = 0;
  }
}
