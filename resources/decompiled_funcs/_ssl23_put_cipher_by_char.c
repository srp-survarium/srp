int __cdecl ssl23_put_cipher_by_char(const ssl_cipher_st *c, unsigned __int8 *p)
{
  unsigned int id; // eax

  if ( p )
  {
    id = c->id;
    *p = BYTE2(id);
    p[1] = BYTE1(id);
    p[2] = id;
  }
  return 3;
}
