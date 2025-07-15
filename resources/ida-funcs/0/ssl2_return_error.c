void __cdecl ssl2_return_error(ssl_st *s, int err)
{
  if ( !s->error )
  {
    s->error = 3;
    s->error_code = err;
    ssl2_write_error(s);
  }
}
