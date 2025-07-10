int __cdecl WHIRLPOOL_Init(WHIRLPOOL_CTX *c)
{
  memset((int)c, 0, sizeof(WHIRLPOOL_CTX));
  return 1;
}
