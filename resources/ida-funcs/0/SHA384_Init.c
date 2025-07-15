int __cdecl SHA384_Init(SHA512state_st *c)
{
  c->h[0] = 0xCBBB9D5DC1059ED8uLL;
  c->h[1] = 0x629A292A367CD507LL;
  c->h[2] = 0x9159015A3070DD17uLL;
  c->h[3] = 0x152FECD8F70E5939LL;
  c->h[4] = 0x67332667FFC00B31LL;
  c->h[5] = 0x8EB44A8768581511uLL;
  c->h[6] = 0xDB0C2E0D64F98FA7uLL;
  c->h[7] = 0x47B5481DBEFA4FA4LL;
  c->Nl = 0;
  c->Nh = 0;
  c->num = 0;
  c->md_len = 48;
  return 1;
}
