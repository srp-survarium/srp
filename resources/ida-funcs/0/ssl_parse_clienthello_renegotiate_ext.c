int __usercall ssl_parse_clienthello_renegotiate_ext@<eax>(
        int a1@<ebx>,
        ssl_st *s,
        unsigned __int8 *d,
        int len,
        int *al)
{
  int v6; // ecx
  ssl3_state_st *s3; // edi
  unsigned int previous_client_finished_len; // eax
  unsigned __int8 *previous_client_finished; // ecx
  unsigned __int8 *v10; // esi

  if ( len < 1 )
  {
    ERR_put_error(a1, 0x14u, 300, 336, ".\\ssl\\t1_reneg.c", 155);
    *al = 47;
    return 0;
  }
  v6 = *d;
  if ( v6 + 1 != len )
  {
    ERR_put_error(a1, 0x14u, 300, 336, ".\\ssl\\t1_reneg.c", 165);
    *al = 47;
    return 0;
  }
  s3 = s->s3;
  if ( v6 != s3->previous_client_finished_len )
  {
    ERR_put_error(a1, 0x14u, 300, 337, ".\\ssl\\t1_reneg.c", 173);
    *al = 40;
    return 0;
  }
  previous_client_finished_len = s3->previous_client_finished_len;
  previous_client_finished = s3->previous_client_finished;
  v10 = d + 1;
  if ( previous_client_finished_len >= 4 )
  {
    while ( *(_DWORD *)v10 == *(_DWORD *)previous_client_finished )
    {
      previous_client_finished_len -= 4;
      previous_client_finished += 4;
      v10 += 4;
      if ( previous_client_finished_len < 4 )
        goto LABEL_10;
    }
    goto LABEL_16;
  }
LABEL_10:
  if ( previous_client_finished_len
    && (*previous_client_finished != *v10
     || previous_client_finished_len > 1
     && (previous_client_finished[1] != v10[1]
      || previous_client_finished_len > 2 && previous_client_finished[2] != v10[2])) )
  {
LABEL_16:
    ERR_put_error(a1, 0x14u, 300, 337, ".\\ssl\\t1_reneg.c", 181);
    *al = 40;
    return 0;
  }
  s3->send_connection_binding = 1;
  return 1;
}
