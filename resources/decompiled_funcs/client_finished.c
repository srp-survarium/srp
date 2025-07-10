int __usercall client_finished@<eax>(ssl_st *s@<esi>)
{
  char *data; // eax
  ssl2_state_st *s2; // ecx
  ssl2_state_st *v4; // ecx

  if ( s->state == 4160 )
  {
    data = s->init_buf->data;
    *data = 3;
    s2 = s->s2;
    if ( s2->conn_id_length > 0x10 )
    {
      ERR_put_error(0x14u, 167, 68, ".\\ssl\\s2_clnt.c", 733);
      return -1;
    }
    memcpy((unsigned __int8 *)data + 1, s2->conn_id, s2->conn_id_length);
    v4 = s->s2;
    s->state = 4161;
    s->init_num = v4->conn_id_length + 1;
    s->init_off = 0;
  }
  return ssl2_do_write(s);
}
