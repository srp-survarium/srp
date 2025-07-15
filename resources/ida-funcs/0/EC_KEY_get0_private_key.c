bio_st *__cdecl EC_KEY_get0_private_key(const ssl_st *s)
{
  return s->rbio;
}
