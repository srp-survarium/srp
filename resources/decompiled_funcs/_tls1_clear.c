void __cdecl tls1_clear(ssl_st *s)
{
  ssl3_clear(s);
  s->version = 769;
}
