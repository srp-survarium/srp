stack_st_SSL_COMP *__usercall SSL_COMP_get_compression_methods@<eax>(unsigned int a1@<edi>)
{
  load_builtin_compressions(a1);
  return ssl_comp_methods;
}
