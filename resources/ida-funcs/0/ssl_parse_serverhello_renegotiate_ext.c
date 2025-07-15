int __usercall ssl_parse_serverhello_renegotiate_ext@<eax>(
        int a1@<edi>,
        int a2@<ebx>,
        ssl_st *s,
        unsigned __int8 *d,
        int len,
        int *al)
{
  int v6; // esi
  int v8; // eax
  ssl3_state_st *s3; // ecx
  unsigned int previous_client_finished_len; // eax
  unsigned __int8 *previous_client_finished; // ecx
  unsigned __int8 *v12; // esi
  ssl3_state_st *v13; // eax
  unsigned int previous_server_finished_len; // ecx
  unsigned __int8 *previous_server_finished; // esi
  unsigned __int8 *v16; // eax

  v6 = s->s3->previous_client_finished_len + s->s3->previous_server_finished_len;
  if ( v6 )
  {
    if ( !s->s3->previous_client_finished_len )
      OpenSSLDie(a1, v6, a2, ".\\ssl\\t1_reneg.c", 240, "!expected_len || s->s3->previous_client_finished_len");
    if ( !s->s3->previous_server_finished_len )
      OpenSSLDie(a1, v6, a2, ".\\ssl\\t1_reneg.c", 241, "!expected_len || s->s3->previous_server_finished_len");
  }
  if ( len < 1 )
  {
    ERR_put_error(a2, 0x14u, 301, 336, ".\\ssl\\t1_reneg.c", 246);
    *al = 47;
    return 0;
  }
  v8 = *d;
  if ( v8 + 1 != len )
  {
    ERR_put_error(a2, 0x14u, 301, 336, ".\\ssl\\t1_reneg.c", 256);
    *al = 47;
    return 0;
  }
  if ( v8 != v6 )
  {
    ERR_put_error(a2, 0x14u, 301, 337, ".\\ssl\\t1_reneg.c", 264);
LABEL_22:
    *al = 40;
    return 0;
  }
  s3 = s->s3;
  previous_client_finished_len = s3->previous_client_finished_len;
  previous_client_finished = s3->previous_client_finished;
  v12 = d + 1;
  if ( previous_client_finished_len >= 4 )
  {
    while ( *(_DWORD *)v12 == *(_DWORD *)previous_client_finished )
    {
      previous_client_finished_len -= 4;
      previous_client_finished += 4;
      v12 += 4;
      if ( previous_client_finished_len < 4 )
        goto LABEL_15;
    }
    goto LABEL_21;
  }
LABEL_15:
  if ( previous_client_finished_len
    && (*previous_client_finished != *v12
     || previous_client_finished_len > 1
     && (previous_client_finished[1] != v12[1]
      || previous_client_finished_len > 2 && previous_client_finished[2] != v12[2])) )
  {
LABEL_21:
    ERR_put_error(a2, 0x14u, 301, 337, ".\\ssl\\t1_reneg.c", 272);
    goto LABEL_22;
  }
  v13 = s->s3;
  previous_server_finished_len = v13->previous_server_finished_len;
  previous_server_finished = v13->previous_server_finished;
  v16 = &d[v13->previous_client_finished_len + 1];
  if ( previous_server_finished_len >= 4 )
  {
    while ( *(_DWORD *)v16 == *(_DWORD *)previous_server_finished )
    {
      previous_server_finished_len -= 4;
      previous_server_finished += 4;
      v16 += 4;
      if ( previous_server_finished_len < 4 )
        goto LABEL_26;
    }
    goto LABEL_32;
  }
LABEL_26:
  if ( previous_server_finished_len
    && (*previous_server_finished != *v16
     || previous_server_finished_len > 1
     && (previous_server_finished[1] != v16[1]
      || previous_server_finished_len > 2 && previous_server_finished[2] != v16[2])) )
  {
LABEL_32:
    ERR_put_error(a2, 0x14u, 301, 337, ".\\ssl\\t1_reneg.c", 281);
    *al = 47;
    return 0;
  }
  s->s3->send_connection_binding = 1;
  return 1;
}
