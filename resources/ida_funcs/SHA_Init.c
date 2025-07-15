int __cdecl SHA_Init(RIPEMD160state_st *c)
{
  memset((int)c, 0, sizeof(RIPEMD160state_st));
  c->A = 1732584193;
  c->B = -271733879;
  c->C = -1732584194;
  c->D = 271733878;
  c->E = -1009589776;
  return 1;
}
