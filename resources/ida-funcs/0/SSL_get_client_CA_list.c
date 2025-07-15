stack_st_X509_NAME *__cdecl SSL_get_client_CA_list(const ssl_st *s)
{
  ssl3_state_st *s3; // ecx
  stack_st_X509_NAME *result; // eax

  if ( s->type == 4096 )
  {
    if ( (s->version & 0xFFFFFF00) == 0x300 && (s3 = s->s3) != 0 )
      return s3->tmp.ca_names;
    else
      return 0;
  }
  else
  {
    result = s->client_CA;
    if ( !result )
      return s->ctx->client_CA;
  }
  return result;
}
