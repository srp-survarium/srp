int __cdecl MDC2_Update(mdc2_ctx_st *c, unsigned __int8 *in, unsigned int len)
{
  unsigned int v3; // ebx
  unsigned int num; // eax
  unsigned int v6; // edi
  const unsigned __int8 *v7; // ebp
  unsigned int v8; // edi
  unsigned int v9; // ebx

  v3 = len;
  num = c->num;
  if ( c->num )
  {
    if ( num + len < 8 )
    {
      memcpy(&c->data[num], in, len);
      c->num += len;
      return 1;
    }
    v6 = 8 - num;
    memcpy(&c->data[num], in, 8 - num);
    v3 = len - v6;
    v7 = &in[v6];
    c->num = 0;
    mdc2_body(c, 8u);
  }
  else
  {
    v7 = in;
  }
  v8 = v3 & 0xFFFFFFF8;
  if ( (v3 & 0xFFFFFFF8) != 0 )
    mdc2_body(c, v3 & 0xFFFFFFF8);
  v9 = v3 - v8;
  if ( v9 )
  {
    memcpy(c->data, (unsigned __int8 *)&v7[v8], v9);
    c->num = v9;
  }
  return 1;
}
