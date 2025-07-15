int __cdecl def_generate_session_id(const ssl_st *ssl, unsigned __int8 *id, unsigned int *id_len)
{
  int v3; // esi

  v3 = 0;
  while ( 1 )
  {
    if ( RAND_pseudo_bytes() <= 0 )
      return 0;
    if ( !SSL_has_matching_session_id(ssl, id, *id_len) )
      break;
    if ( (unsigned int)++v3 >= 0xA )
      return 0;
  }
  return 1;
}
