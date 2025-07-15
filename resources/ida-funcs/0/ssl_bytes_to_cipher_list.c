stack_st_SSL_CIPHER *__cdecl ssl_bytes_to_cipher_list(ssl_st *s, unsigned __int8 *p, int num, stack_st **skp)
{
  ssl3_state_st *s3; // eax
  int v6; // ebx
  int v7; // edi
  stack_st **v9; // esi
  ssl3_state_st *v11; // eax
  char *v12; // eax
  stack_st *sa; // [esp+10h] [ebp+4h]

  s3 = s->s3;
  v6 = 0;
  if ( s3 )
    s3->send_connection_binding = 0;
  v7 = s->method->put_cipher_by_char(0, 0);
  if ( num % v7 )
  {
    ERR_put_error(0, 0x14u, 161, 151, ".\\ssl\\ssl_lib.c", 1408);
    return 0;
  }
  v9 = skp;
  if ( skp && *skp )
  {
    sa = *skp;
    sk_zero(*skp);
  }
  else
  {
    sa = sk_new_null();
  }
  if ( num <= 0 )
  {
LABEL_21:
    if ( v9 )
      *v9 = sa;
    return (stack_st_SSL_CIPHER *)sa;
  }
  while ( 1 )
  {
    v11 = s->s3;
    if ( !v11 || v7 == 3 && *p )
      break;
    if ( p[v7 - 2] || p[v7 - 1] != 0xFF )
      break;
    if ( s->new_session )
    {
      ERR_put_error(v6, 0x14u, 161, 345, ".\\ssl\\ssl_lib.c", 1429);
      ssl3_send_alert(s, 2, 40);
      goto err_213;
    }
    v11->send_connection_binding = 1;
    p += v7;
LABEL_19:
    v6 += v7;
    if ( v6 >= num )
    {
      v9 = skp;
      goto LABEL_21;
    }
  }
  v12 = (char *)s->method->get_cipher_by_char(p);
  p += v7;
  if ( !v12 || sk_push(sa, v12) )
    goto LABEL_19;
  ERR_put_error(v6, 0x14u, 161, 65, ".\\ssl\\ssl_lib.c", 1447);
err_213:
  if ( !skp || !*skp )
    sk_free(sa);
  return 0;
}
