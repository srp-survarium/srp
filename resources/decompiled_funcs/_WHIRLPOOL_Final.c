int __cdecl WHIRLPOOL_Final(unsigned __int8 *md, WHIRLPOOL_CTX *c)
{
  unsigned int v2; // eax
  unsigned int v3; // esi
  unsigned int v4; // eax
  unsigned __int8 *v5; // ecx
  unsigned int *bitlen; // edx
  int v7; // esi
  unsigned int v8; // eax

  v2 = c->bitoff >> 3;
  v3 = c->bitoff & 7;
  if ( v3 )
    c->data[v2] |= 128 >> v3;
  else
    c->data[v2] = 0x80;
  v4 = v2 + 1;
  if ( v4 > 0x20 )
  {
    if ( v4 < 0x40 )
      memset((int)&c->data[v4], 0, 64 - v4);
    whirlpool_block(c, c->data, 1u);
    v4 = 0;
    goto LABEL_9;
  }
  if ( v4 < 0x20 )
LABEL_9:
    memset((int)&c->data[v4], 0, 32 - v4);
  v5 = &c->data[63];
  bitlen = c->bitlen;
  v7 = 8;
  do
  {
    v8 = *bitlen;
    *v5 = *bitlen;
    v8 >>= 8;
    *(v5 - 1) = v8;
    v8 >>= 8;
    *(v5 - 2) = v8;
    *(v5 - 3) = BYTE1(v8);
    v5 -= 4;
    ++bitlen;
    --v7;
  }
  while ( v7 );
  whirlpool_block(c, c->data, 1u);
  if ( !md )
    return 0;
  qmemcpy(md, c, 0x40u);
  memset((int)c, 0, sizeof(WHIRLPOOL_CTX));
  return 1;
}
