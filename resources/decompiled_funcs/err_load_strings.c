void __usercall err_load_strings(int lib@<ebx>, ERR_string_data_st *str@<ecx>)
{
  ERR_string_data_st *i; // esi

  for ( i = str; i->error; ++i )
  {
    if ( lib )
      i->error |= (unsigned __int8)lib << 24;
    err_fns->cb_err_set_item(i);
  }
}
