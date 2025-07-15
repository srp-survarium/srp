void __usercall ssl2_return_error(int a1@<ebx>, ssl_st *s, int err)
{
  if ( !s->error )
  {
    s->error = 3;
    s->error_code = err;
    ssl2_write_error(a1, s);
  }
}
