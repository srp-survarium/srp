int __cdecl SHA256_Init(SHA256state_st *c)
{
  memset((int)c, 0, sizeof(SHA256state_st));
  c->h[0] = 1779033703;
  c->h[1] = -1150833019;
  c->h[2] = 1013904242;
  c->h[3] = -1521486534;
  c->h[4] = 1359893119;
  c->h[5] = -1694144372;
  c->h[6] = 528734635;
  c->h[7] = 1541459225;
  c->md_len = 32;
  return 1;
}
