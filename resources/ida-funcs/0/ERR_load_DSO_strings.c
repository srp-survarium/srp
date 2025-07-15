void __usercall ERR_load_DSO_strings(int a1@<ebx>, int a2@<edi>)
{
  if ( !ERR_func_error_string(a2, a1, DSO_str_functs[0].error) )
  {
    ERR_load_strings(a2, a1, 0, DSO_str_functs);
    ERR_load_strings(a2, a1, 0, DSO_str_reasons);
  }
}
