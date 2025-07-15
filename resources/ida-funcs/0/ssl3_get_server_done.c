int __cdecl ssl3_get_server_done(ssl_st *s)
{
  ssl_st *v1; // esi
  int result; // eax

  v1 = s;
  result = s->method->ssl_get_message(s, 4448, 4449, 14, 30, (int *)&s);
  if ( s )
  {
    if ( result <= 0 )
    {
      return 1;
    }
    else
    {
      ssl3_send_alert(v1, 2, 50);
      ERR_put_error(0x14u, 145, 159, ".\\ssl\\s3_clnt.c", 1984);
      return -1;
    }
  }
  return result;
}
