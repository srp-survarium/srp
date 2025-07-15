void __usercall ERR_load_SSL_strings(int a1@<edi>, int a2@<ebx>)
{
  if ( !ERR_func_error_string(a1, a2, SSL_str_functs[0].error) )
  {
    ERR_load_strings(a1, a2, 0, SSL_str_functs);
    ERR_load_strings(a1, a2, 0, SSL_str_reasons);
  }
}
