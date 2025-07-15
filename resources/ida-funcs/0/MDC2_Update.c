int __cdecl MDC2_Update(mdc2_ctx_st *c, const __m128i *in, unsigned int len)
{
  unsigned int v3; // ebx
  unsigned int num; // eax
  unsigned int v6; // edi
  unsigned __int8 *v7; // ebp
  unsigned int v8; // edi
  unsigned int v9; // ebx

  v3 = len;
  num = c->num;
  if ( c->num )
  {
    if ( num + len < 8 )
    {
      memcpy((int)&c->data[num], in, len);
      c->num += len;
      return 1;
    }
    v6 = 8 - num;
    memcpy((int)&c->data[num], in, 8 - num);
    v3 = len - v6;
    v7 = &in->m128i_u8[v6];
    c->num = 0;
    mdc2_body(c, 8u);
  }
  else
  {
    v7 = (unsigned __int8 *)in;
  }
  v8 = v3 & 0xFFFFFFF8;
  if ( (v3 & 0xFFFFFFF8) != 0 )
    mdc2_body(c, v3 & 0xFFFFFFF8);
  v9 = v3 - v8;
  if ( v9 )
  {
    memcpy((int)c->data, (const __m128i *)&v7[v8], v9);
    c->num = v9;
  }
  return 1;
}
