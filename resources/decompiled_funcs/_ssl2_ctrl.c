int __cdecl ssl2_ctrl(ssl_st *s, int cmd)
{
  int result; // eax

  result = 0;
  if ( cmd == 8 )
    return s->hit;
  return result;
}
