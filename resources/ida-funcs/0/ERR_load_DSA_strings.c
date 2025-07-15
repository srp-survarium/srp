void __usercall ERR_load_DSA_strings(int a1@<ebx>, int a2@<edi>)
{
  if ( !ERR_func_error_string(a2, a1, DSA_str_functs[0].error) )
  {
    ERR_load_strings(a2, a1, 0, DSA_str_functs);
    ERR_load_strings(a2, a1, 0, DSA_str_reasons);
  }
}
