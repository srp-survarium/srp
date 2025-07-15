void __usercall ERR_load_UI_strings(unsigned int a1@<edi>)
{
  if ( !ERR_func_error_string(a1, UI_str_functs[0].error) )
  {
    ERR_load_strings(a1, 0, UI_str_functs);
    ERR_load_strings(a1, 0, UI_str_reasons);
  }
}
