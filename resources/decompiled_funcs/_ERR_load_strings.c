void __usercall ERR_load_strings(unsigned int a1@<edi>, int lib, ERR_string_data_st *str)
{
  ERR_load_ERR_strings(a1);
  err_load_strings(lib, str);
}
