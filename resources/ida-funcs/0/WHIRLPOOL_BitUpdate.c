void __cdecl WHIRLPOOL_BitUpdate(WHIRLPOOL_CTX *c, __m128i *_inp, unsigned int bits)
{
  unsigned int v3; // ecx
  __m128i *v4; // ebp
  unsigned int bitoff; // edi
  int v7; // ebx
  unsigned int v8; // edx
  unsigned int *v9; // eax
  unsigned int v11; // eax
  char v12; // bl
  char v13; // dl
  unsigned __int8 *v14; // ebp
  unsigned __int8 v15; // bl
  unsigned int v16; // eax
  unsigned __int8 v17; // bl
  unsigned __int8 *data; // ebp
  unsigned int v19; // eax
  unsigned int v20; // ebx
  unsigned int v21; // ebx
  unsigned int v22; // eax
  unsigned int v23; // ecx
  unsigned int v24; // ebx
  int v25; // [esp+10h] [ebp-Ch]
  unsigned int v26; // [esp+14h] [ebp-8h]
  unsigned int v27; // [esp+18h] [ebp-4h]
  WHIRLPOOL_CTX *ctx; // [esp+20h] [ebp+4h]

  v3 = bits;
  v4 = _inp;
  c->bitlen[0] += bits;
  bitoff = c->bitoff;
  v7 = bitoff & 7;
  v8 = -bits & 7;
  v25 = (unsigned __int8)v7;
  v26 = v8;
  if ( c->bitlen[0] < bits )
  {
    v9 = &c->bitlen[1];
    v27 = 1;
    for ( ctx = (WHIRLPOOL_CTX *)&c->bitlen[1]; (*v9)++ == -1; v9 = (unsigned int *)ctx )
    {
      ++v27;
      ctx = (WHIRLPOOL_CTX *)((char *)ctx + 4);
      if ( v27 >= 8 )
        break;
    }
  }
reconsider:
  if ( v8 || v7 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        if ( !v3 )
          return;
        v11 = bitoff >> 3;
        if ( v7 == v8 )
        {
          v4 = (__m128i *)((char *)v4 + 1);
          _inp = v4;
          c->data[v11] |= v4[-1].m128i_i8[15] & (255 >> v8);
          bits -= 8 - v8;
          bitoff += 8 - v8;
          v25 = 0;
          v26 = 0;
          if ( bitoff == 512 )
          {
            whirlpool_block(c, c->data, 1u);
            bitoff = 0;
          }
          v8 = 0;
          v7 = 0;
          v3 = bits;
          c->bitoff = bitoff;
          goto reconsider;
        }
        if ( v3 >= 8 )
          break;
        v17 = v4->m128i_i8[0] << v8;
        data = c->data;
        if ( v25 )
        {
          data[v11] |= v17 >> v25;
          v8 = v26;
        }
        else
        {
          data[v11] = v17;
        }
        bitoff += bits;
        v19 = v11 + 1;
        if ( bitoff == 512 )
        {
          whirlpool_block(c, c->data, 1u);
          v8 = v26;
          v19 = 0;
          bitoff = 0;
        }
        if ( v25 )
        {
          v8 = v26;
          data[v19] = v17 << (8 - v25);
        }
        bits = 0;
LABEL_26:
        v4 = _inp;
        v7 = v25;
        v3 = bits;
        c->bitoff = bitoff;
      }
      v12 = (unsigned __int8)v4->m128i_i8[1] >> (8 - v8);
      v13 = v4->m128i_i8[0] << v8;
      v14 = c->data;
      v15 = v13 | v12;
      if ( v25 )
        v14[v11] |= v15 >> v25;
      else
        v14[v11] = v15;
      bits -= 8;
      bitoff += 8;
      v16 = v11 + 1;
      _inp = (__m128i *)((char *)_inp + 1);
      if ( bitoff >= 0x200 )
      {
        whirlpool_block(c, c->data, 1u);
        v16 = 0;
        bitoff &= 0x1FFu;
      }
      v8 = v26;
      if ( !v25 )
        goto LABEL_26;
      v3 = bits;
      v14[v16] = v15 << (8 - v25);
      v4 = _inp;
      v7 = v25;
      c->bitoff = bitoff;
    }
  }
  if ( v3 )
  {
    while ( 1 )
    {
      if ( bitoff || (v20 = v3 >> 9) == 0 )
      {
        v21 = 512 - bitoff;
        v22 = bitoff >> 3;
        if ( v3 < 512 - bitoff )
        {
          memcpy((int)&c->data[v22], v4, v3 >> 3);
          bitoff += bits;
          bits = 0;
        }
        else
        {
          v23 = v3 - v21;
          v24 = v21 >> 3;
          bits = v23;
          memcpy((int)&c->data[v22], v4, v24);
          v4 = (__m128i *)((char *)v4 + v24);
          whirlpool_block(c, c->data, 1u);
          bitoff = 0;
        }
        c->bitoff = bitoff;
      }
      else
      {
        whirlpool_block(c, v4, v3 >> 9);
        v4 = (__m128i *)((char *)v4 + ((v20 << 6) & 0x1FFFFFFF));
        bits &= 0x1FFu;
      }
      if ( !bits )
        break;
      v3 = bits;
    }
  }
}
