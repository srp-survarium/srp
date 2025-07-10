int __cdecl MDC2_Init(mdc2_ctx_st *c)
{
  c->num = 0;
  c->pad_type = 1;
  qmemcpy(c->h, "RRRRRRRR%%%%%%%%", 16);
  return 1;
}
