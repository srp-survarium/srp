int __usercall ssl3_check_client_hello@<eax>(int a1@<edi>, int a2@<ebx>, ssl_st *s)
{
  ssl_st *v3; // esi
  int result; // eax
  ssl3_state_st *s3; // ecx
  ssl3_state_st *v6; // ecx

  v3 = s;
  if ( (s->s3->flags & 0x40) != 0 )
  {
    ERR_put_error(a2, 0x14u, 304, 346, ".\\ssl\\s3_srvr.c", 763);
    return -1;
  }
  else
  {
    result = s->method->ssl_get_message(s, 8576, 8577, -1, s->max_cert_list, (int *)&s);
    if ( s )
    {
      result = 1;
      v3->s3->tmp.reuse_message = 1;
      s3 = v3->s3;
      if ( s3->tmp.message_type == 1 )
      {
        if ( s3->tmp.dh )
        {
          DH_free(a1, a2, s3->tmp.dh);
          v3->s3->tmp.dh = 0;
        }
        v6 = v3->s3;
        if ( v6->tmp.ecdh )
        {
          EC_KEY_free(v6->tmp.ecdh);
          v3->s3->tmp.ecdh = 0;
        }
        v3->s3->flags |= 0x40u;
        return 2;
      }
    }
  }
  return result;
}
