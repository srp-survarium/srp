int __usercall ssl_parse_serverhello_renegotiate_ext@<eax>(
        unsigned int a1@<edi>,
        ssl_st *s,
        unsigned __int8 *d,
        int len,
        int *al)
{
  unsigned int v5; // esi
  int v7; // eax
  ssl3_state_st *s3; // ecx
  unsigned int previous_client_finished_len; // eax
  unsigned __int8 *previous_client_finished; // ecx
  unsigned __int8 *v11; // esi
  ssl3_state_st *v12; // eax
  unsigned int previous_server_finished_len; // ecx
  unsigned __int8 *previous_server_finished; // esi
  unsigned __int8 *v15; // eax

  v5 = s->s3->previous_client_finished_len + s->s3->previous_server_finished_len;
  if ( v5 )
  {
    if ( !s->s3->previous_client_finished_len )
      OpenSSLDie(a1, v5, ".\\ssl\\t1_reneg.c", 240, "!expected_len || s->s3->previous_client_finished_len");
    if ( !s->s3->previous_server_finished_len )
      OpenSSLDie(a1, v5, ".\\ssl\\t1_reneg.c", 241, "!expected_len || s->s3->previous_server_finished_len");
  }
  if ( len < 1 )
  {
    ERR_put_error(0x14u, 301, 336, ".\\ssl\\t1_reneg.c", 246);
    *al = 47;
    return 0;
  }
  v7 = *d;
  if ( v7 + 1 != len )
  {
    ERR_put_error(0x14u, 301, 336, ".\\ssl\\t1_reneg.c", 256);
    *al = 47;
    return 0;
  }
  if ( v7 != v5 )
  {
    ERR_put_error(0x14u, 301, 337, ".\\ssl\\t1_reneg.c", 264);
LABEL_22:
    *al = 40;
    return 0;
  }
  s3 = s->s3;
  previous_client_finished_len = s3->previous_client_finished_len;
  previous_client_finished = s3->previous_client_finished;
  v11 = d + 1;
  if ( previous_client_finished_len >= 4 )
  {
    while ( *(_DWORD *)v11 == *(_DWORD *)previous_client_finished )
    {
      previous_client_finished_len -= 4;
      previous_client_finished += 4;
      v11 += 4;
      if ( previous_client_finished_len < 4 )
        goto LABEL_15;
    }
    goto LABEL_21;
  }
LABEL_15:
  if ( previous_client_finished_len
    && (*previous_client_finished != *v11
     || previous_client_finished_len > 1
     && (previous_client_finished[1] != v11[1]
      || previous_client_finished_len > 2 && previous_client_finished[2] != v11[2])) )
  {
LABEL_21:
    ERR_put_error(0x14u, 301, 337, ".\\ssl\\t1_reneg.c", 272);
    goto LABEL_22;
  }
  v12 = s->s3;
  previous_server_finished_len = v12->previous_server_finished_len;
  previous_server_finished = v12->previous_server_finished;
  v15 = &d[v12->previous_client_finished_len + 1];
  if ( previous_server_finished_len >= 4 )
  {
    while ( *(_DWORD *)v15 == *(_DWORD *)previous_server_finished )
    {
      previous_server_finished_len -= 4;
      previous_server_finished += 4;
      v15 += 4;
      if ( previous_server_finished_len < 4 )
        goto LABEL_26;
    }
    goto LABEL_32;
  }
LABEL_26:
  if ( previous_server_finished_len
    && (*previous_server_finished != *v15
     || previous_server_finished_len > 1
     && (previous_server_finished[1] != v15[1]
      || previous_server_finished_len > 2 && previous_server_finished[2] != v15[2])) )
  {
LABEL_32:
    ERR_put_error(0x14u, 301, 337, ".\\ssl\\t1_reneg.c", 281);
    *al = 47;
    return 0;
  }
  s->s3->send_connection_binding = 1;
  return 1;
}
