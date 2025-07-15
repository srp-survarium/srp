void __usercall timeout_LHASH_DOALL_ARG(unsigned int a1@<edi>, ssl_session_st *arg1, timeout_param_st *arg2)
{
  timeout_doall_arg(arg1, arg2, a1);
}
