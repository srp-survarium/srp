int __cdecl ssl2_pending(const ssl_st *s)
{
  if ( (SSL_state(s) & 0x3000) != 0 )
    return 0;
  else
    return s->s2->ract_data_length;
}
