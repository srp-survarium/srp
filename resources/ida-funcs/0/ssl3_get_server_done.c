int __usercall ssl3_get_server_done@<eax>(int a1@<ebx>, ssl_st *s)
{
  ssl_st *v2; // esi
  int result; // eax

  v2 = s;
  result = s->method->ssl_get_message(s, 4448, 4449, 14, 30, (int *)&s);
  if ( s )
  {
    if ( result <= 0 )
    {
      return 1;
    }
    else
    {
      ssl3_send_alert(v2, 2, 50);
      ERR_put_error(a1, 0x14u, 145, 159, ".\\ssl\\s3_clnt.c", 1984);
      return -1;
    }
  }
  return result;
}
