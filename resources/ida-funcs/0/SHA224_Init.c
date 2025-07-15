int __cdecl SHA224_Init(SHA256state_st *c)
{
  memset((int)c, 0, sizeof(SHA256state_st));
  c->h[0] = -1056596264;
  c->h[1] = 914150663;
  c->h[2] = 812702999;
  c->h[3] = -150054599;
  c->h[4] = -4191439;
  c->h[5] = 1750603025;
  c->h[6] = 1694076839;
  c->h[7] = -1090891868;
  c->md_len = 28;
  return 1;
}
