int __cdecl SHA512_Init(SHA512state_st *c)
{
  c->h[0] = 0x6A09E667F3BCC908LL;
  c->h[1] = 0xBB67AE8584CAA73BuLL;
  c->h[2] = 0x3C6EF372FE94F82BLL;
  c->h[3] = 0xA54FF53A5F1D36F1uLL;
  c->h[4] = 0x510E527FADE682D1LL;
  c->h[5] = 0x9B05688C2B3E6C1FuLL;
  c->h[6] = 0x1F83D9ABFB41BD6BLL;
  c->h[7] = 0x5BE0CD19137E2179LL;
  c->Nl = 0;
  c->Nh = 0;
  c->num = 0;
  c->md_len = 64;
  return 1;
}
