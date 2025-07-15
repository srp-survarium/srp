int __cdecl ssl_session_cmp(const ssl_session_st *b)
{
  _DWORD *v1; // ecx
  _DWORD *v2; // esi
  unsigned int v4; // ecx
  unsigned __int8 *v5; // esi
  unsigned __int8 *session_id; // edx
  int v7; // eax

  v2 = v1;
  if ( *v1 != b->ssl_version )
    return 1;
  v4 = v1[17];
  if ( v4 != b->session_id_length )
    return 1;
  v5 = (unsigned __int8 *)(v2 + 18);
  session_id = b->session_id;
  if ( v4 < 4 )
  {
LABEL_7:
    if ( !v4 )
      return 0;
  }
  else
  {
    while ( *(_DWORD *)v5 == *(_DWORD *)session_id )
    {
      v4 -= 4;
      session_id += 4;
      v5 += 4;
      if ( v4 < 4 )
        goto LABEL_7;
    }
  }
  v7 = *v5 - *session_id;
  if ( v7 )
    return (v7 >> 31) | 1;
  if ( v4 <= 1 )
    return 0;
  v7 = v5[1] - session_id[1];
  if ( v7 )
    return (v7 >> 31) | 1;
  if ( v4 <= 2 )
    return 0;
  v7 = v5[2] - session_id[2];
  if ( v7 )
    return (v7 >> 31) | 1;
  if ( v4 > 3 )
  {
    v7 = v5[3] - session_id[3];
    return (v7 >> 31) | 1;
  }
  return 0;
}
