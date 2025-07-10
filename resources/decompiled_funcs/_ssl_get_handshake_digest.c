int __cdecl ssl_get_handshake_digest(unsigned int idx, int *mask, const env_md_st **md)
{
  int v3; // eax

  if ( idx > 3 )
    return 0;
  v3 = ssl_handshake_digest_flag[idx];
  if ( !v3 )
    return 0;
  *mask = v3;
  *md = ssl_digest_methods[idx];
  return 1;
}
