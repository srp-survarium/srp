void __usercall ERR_load_EVP_strings(unsigned int a1@<edi>)
{
  if ( !ERR_func_error_string(a1, EVP_str_functs[0].error) )
  {
    ERR_load_strings(a1, 0, EVP_str_functs);
    ERR_load_strings(a1, 0, EVP_str_reasons);
  }
}
