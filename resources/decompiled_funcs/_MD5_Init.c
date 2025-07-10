int __cdecl MD5_Init(MD5state_st *c)
{
  memset((int)c, 0, sizeof(MD5state_st));
  c->A = 1732584193;
  c->B = -271733879;
  c->C = -1732584194;
  c->D = 271733878;
  return 1;
}
