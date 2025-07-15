int __cdecl ssl_session_cmp(const ssl_session_st *b)
{
  const ssl_session_st *a; // ecx
  const ssl_session_st *v2; // esi
  unsigned int session_id_length; // ecx
  unsigned __int8 *session_id; // esi
  unsigned __int8 *v6; // edx
  int v7; // eax

  v2 = a;
  if ( a->ssl_version != b->ssl_version )
    return 1;
  session_id_length = a->session_id_length;
  if ( session_id_length != b->session_id_length )
    return 1;
  session_id = v2->session_id;
  v6 = b->session_id;
  if ( session_id_length < 4 )
  {
LABEL_7:
    if ( !session_id_length )
      return 0;
  }
  else
  {
    while ( *(_DWORD *)session_id == *(_DWORD *)v6 )
    {
      session_id_length -= 4;
      v6 += 4;
      session_id += 4;
      if ( session_id_length < 4 )
        goto LABEL_7;
    }
  }
  v7 = *session_id - *v6;
  if ( v7 )
    return (v7 >> 31) | 1;
  if ( session_id_length <= 1 )
    return 0;
  v7 = session_id[1] - v6[1];
  if ( v7 )
    return (v7 >> 31) | 1;
  if ( session_id_length <= 2 )
    return 0;
  v7 = session_id[2] - v6[2];
  if ( v7 )
    return (v7 >> 31) | 1;
  if ( session_id_length > 3 )
  {
    v7 = session_id[3] - v6[3];
    return (v7 >> 31) | 1;
  }
  return 0;
}
