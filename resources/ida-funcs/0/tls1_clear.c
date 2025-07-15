void __usercall tls1_clear(int a1@<ebx>, ssl_st *s)
{
  ssl3_clear(a1, s);
  s->version = 769;
}
