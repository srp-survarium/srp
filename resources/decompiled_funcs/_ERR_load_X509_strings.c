void __usercall ERR_load_X509_strings(unsigned int a1@<edi>)
{
  if ( !ERR_func_error_string(a1, X509_str_functs[0].error) )
  {
    ERR_load_strings(a1, 0, X509_str_functs);
    ERR_load_strings(a1, 0, X509_str_reasons);
  }
}
