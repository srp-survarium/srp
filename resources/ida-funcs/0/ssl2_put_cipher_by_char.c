int __cdecl ssl2_put_cipher_by_char(const ssl_cipher_st *c, unsigned __int8 *p)
{
  unsigned int id; // eax

  if ( p )
  {
    id = c->id;
    if ( (id & 0xFF000000) != 0x2000000 )
      return 0;
    *p = BYTE2(id);
    p[1] = BYTE1(id);
    p[2] = id;
  }
  return 3;
}
