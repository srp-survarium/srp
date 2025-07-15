int __cdecl inflate_table(
        codetype type,
        unsigned __int16 *lens,
        unsigned int codes,
        code **table,
        unsigned int *bits,
        unsigned __int16 *work)
{
  unsigned int i; // eax
  unsigned int v7; // ebx
  unsigned int v9; // esi
  int v10; // edx
  unsigned int j; // eax
  unsigned int k; // eax
  unsigned __int16 v13; // cx
  unsigned int m; // eax
  const unsigned __int16 *v15; // eax
  unsigned int v16; // ebp
  unsigned int v17; // ebx
  int v18; // eax
  int v19; // eax
  int v20; // edx
  code *v21; // ecx
  unsigned int v22; // edx
  unsigned int n; // eax
  int v24; // esi
  unsigned __int8 v25; // cl
  unsigned int v26; // edx
  int v27; // eax
  unsigned __int16 *v28; // esi
  int v29; // eax
  code *v30; // esi
  unsigned int ii; // eax
  code this; // [esp+Ch] [ebp-7Ch]
  code thisa; // [esp+Ch] [ebp-7Ch]
  unsigned int root; // [esp+10h] [ebp-78h]
  unsigned int len; // [esp+14h] [ebp-74h]
  unsigned int max; // [esp+18h] [ebp-70h]
  code *next; // [esp+1Ch] [ebp-6Ch]
  unsigned __int16 *v38; // [esp+20h] [ebp-68h]
  unsigned int used; // [esp+24h] [ebp-64h]
  int end; // [esp+28h] [ebp-60h]
  const unsigned __int16 *extra; // [esp+2Ch] [ebp-5Ch]
  const unsigned __int16 *base; // [esp+30h] [ebp-58h]
  unsigned int low; // [esp+34h] [ebp-54h]
  int v44; // [esp+38h] [ebp-50h]
  unsigned int mask; // [esp+3Ch] [ebp-4Ch]
  unsigned __int16 count[16]; // [esp+48h] [ebp-40h] BYREF
  unsigned __int16 offs[16]; // [esp+68h] [ebp-20h]

  memset(count, 0, sizeof(count));
  for ( i = 0; i < codes; ++i )
    ++count[lens[i]];
  root = *bits;
  v7 = 15;
  do
  {
    if ( count[v7] )
      break;
    --v7;
  }
  while ( v7 );
  max = v7;
  if ( *bits > v7 )
    root = v7;
  if ( !v7 )
  {
    *(*table)++ = (code)320;
    *(*table)++ = (code)320;
    *bits = 1;
    return 0;
  }
  v9 = 1;
  while ( !count[v9] )
  {
    if ( count[v9 + 1] )
    {
      ++v9;
      break;
    }
    if ( count[v9 + 2] )
    {
      v9 += 2;
      break;
    }
    if ( count[v9 + 3] )
    {
      v9 += 3;
      break;
    }
    if ( count[v9 + 4] )
    {
      v9 += 4;
      break;
    }
    v9 += 5;
    if ( v9 > 0xF )
      break;
  }
  if ( root < v9 )
    root = v9;
  v10 = 1;
  for ( j = 1; j <= 0xF; ++j )
  {
    v10 = 2 * v10 - count[j];
    if ( v10 < 0 )
      return -1;
  }
  if ( v10 > 0 && (type == CODES || v7 != 1) )
    return -1;
  offs[1] = 0;
  for ( k = 1; k < 15; offs[k] = v13 )
  {
    v13 = count[k] + offs[k];
    ++k;
  }
  for ( m = 0; m < codes; ++m )
  {
    if ( lens[m] )
      work[offs[lens[m]]++] = m;
  }
  if ( type )
  {
    if ( type != LENS )
    {
      base = dbase;
      extra = dext;
      end = -1;
      goto LABEL_44;
    }
    base = &lbase[-257];
    v15 = &lext[-257];
    end = 256;
  }
  else
  {
    v15 = work;
    base = work;
    end = 19;
  }
  extra = v15;
LABEL_44:
  next = *table;
  low = -1;
  v16 = 0;
  v17 = 0;
  len = v9;
  v44 = 1 << root;
  used = 1 << root;
  mask = (1 << root) - 1;
  if ( type == LENS && (unsigned int)(1 << root) >= 0x5B0 )
    return 1;
  v38 = work;
  while ( 1 )
  {
    if ( *v38 >= end )
    {
      if ( *v38 <= end )
      {
        this.op = 96;
        this.val = 0;
      }
      else
      {
        v18 = *v38;
        this.op = extra[v18];
        this.val = base[v18];
      }
    }
    else
    {
      this.op = 0;
      this.val = *v38;
    }
    v19 = v44;
    v20 = 1 << (len - v17);
    v21 = &next[v44 + (v16 >> v17)];
    do
    {
      v19 -= v20;
      v21 -= v20;
      this.bits = len - v17;
      *v21 = this;
    }
    while ( v19 );
    v22 = len;
    for ( n = 1 << (len - 1); (n & v16) != 0; n >>= 1 )
      ;
    if ( n )
      v16 = n + (v16 & (n - 1));
    else
      v16 = 0;
    ++v38;
    if ( --count[len] )
      goto LABEL_62;
    if ( len == max )
      break;
    len = lens[*v38];
    v22 = len;
LABEL_62:
    if ( v22 > root )
    {
      v24 = v16 & mask;
      if ( (v16 & mask) != low )
      {
        if ( !v17 )
          v17 = root;
        next += v44;
        v25 = len - v17;
        v26 = len;
        v27 = 1 << (len - v17);
        if ( len < max )
        {
          v28 = &count[len];
          do
          {
            v29 = v27 - *v28;
            if ( v29 <= 0 )
              break;
            ++v26;
            ++v25;
            ++v28;
            v27 = 2 * v29;
          }
          while ( v26 < max );
          v24 = v16 & mask;
        }
        used += 1 << v25;
        v44 = 1 << v25;
        if ( type == LENS && used >= 0x5B0 )
          return 1;
        (*table)[v24].op = v25;
        (*table)[v24].bits = root;
        low = v24;
        (*table)[v24].val = next - *table;
      }
    }
  }
  thisa.op = 64;
  thisa.bits = len - v17;
  thisa.val = 0;
  if ( v16 )
  {
    v30 = next;
    do
    {
      if ( v17 && (v16 & mask) != low )
      {
        v30 = *table;
        v17 = 0;
        thisa.bits = root;
        LOBYTE(v22) = root;
      }
      v30[v16 >> v17] = thisa;
      for ( ii = 1 << (v22 - 1); (ii & v16) != 0; ii >>= 1 )
        ;
      if ( !ii )
        break;
      v16 = ii + (v16 & (ii - 1));
    }
    while ( v16 );
  }
  *table += used;
  *bits = root;
  return 0;
}
