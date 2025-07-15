void __usercall int_cleanup(int a1@<edi>, int a2@<ebx>)
{
  if ( ex_data || ex_data_check(a1, a2) )
  {
    lh_doall((lhash_st *)ex_data, (void (__cdecl *)(void *))def_cleanup_cb);
    lh_free((lhash_st *)ex_data);
    ex_data = 0;
    impl = 0;
  }
}
