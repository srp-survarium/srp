void __usercall ERR_load_EVP_strings(int a1@<ebx>, int a2@<edi>)
{
  if ( !ERR_func_error_string(a2, a1, EVP_str_functs[0].error) )
  {
    ERR_load_strings(a2, a1, 0, EVP_str_functs);
    ERR_load_strings(a2, a1, 0, EVP_str_reasons);
  }
}
