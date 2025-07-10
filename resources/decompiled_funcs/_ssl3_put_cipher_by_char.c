int __cdecl ssl3_put_cipher_by_char(const ssl_cipher_st *c, unsigned __int8 *p)
{
  unsigned int id; // eax

  if ( p )
  {
    id = c->id;
    if ( (unsigned __int8 *)(id & 0xFF000000) != &vostok::memory::s_CRT_arena[39128632] )
      return 0;
    *p = BYTE1(id);
    p[1] = id;
  }
  return 2;
}
