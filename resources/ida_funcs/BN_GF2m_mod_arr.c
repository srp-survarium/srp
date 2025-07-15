int __cdecl BN_GF2m_mod_arr(bignum_st *r, const bignum_st *a, const int *p)
{
  const int *v3; // esi
  int result; // eax
  bignum_st *v5; // ebp
  int i; // eax
  unsigned int *d; // edi
  int v8; // ecx
  int v9; // ebx
  bool v10; // zf
  unsigned int *v11; // eax
  unsigned int v12; // ebp
  const int *v13; // ecx
  int v14; // eax
  int v15; // esi
  unsigned int *v16; // eax
  int v17; // edx
  int top; // eax
  unsigned int *v19; // ecx
  int v21; // edx
  unsigned int v22; // ebx
  const int *v23; // eax
  int v24; // ebp
  int v25; // edx
  int v26; // eax
  unsigned int v27; // esi
  int v28; // [esp+4h] [ebp-Ch]
  int v29; // [esp+8h] [ebp-8h]
  unsigned int *v30; // [esp+Ch] [ebp-4h]

  v3 = p;
  if ( !*p )
  {
    BN_set_word(r, 0);
    return 1;
  }
  v5 = r;
  if ( a != r )
  {
    if ( a->top > r->dmax )
      result = (int)bn_expand2(r, (unsigned int *)a->top);
    else
      result = (int)r;
    if ( !result )
      return result;
    for ( i = 0; i < a->top; ++i )
      r->d[i] = a->d[i];
    r->top = a->top;
  }
  d = r->d;
  v8 = *p / 32;
  v9 = r->top - 1;
  v10 = v9 == v8;
  v28 = v8;
  if ( v9 > v8 )
  {
    v11 = &d[v9 - v8];
    v30 = v11;
    do
    {
      v12 = d[v9];
      if ( v12 )
      {
        v13 = v3 + 1;
        d[v9] = 0;
        v29 = 1;
        if ( v3[1] )
        {
          do
          {
            v14 = *v3 - *v13;
            v15 = v14 % 32;
            v16 = &d[v9 - v14 / 32];
            *v16 ^= v12 >> v15;
            if ( v15 )
              *(v16 - 1) ^= v12 << (32 - v15);
            v3 = p;
            v10 = p[v29 + 1] == 0;
            v13 = &p[++v29];
          }
          while ( !v10 );
        }
        v17 = *v3 % 32;
        v11 = v30;
        *v30 ^= v12 >> v17;
        if ( v17 )
          *(v30 - 1) ^= v12 << (32 - v17);
        v8 = v28;
      }
      else
      {
        --v9;
        v30 = --v11;
      }
      v10 = v9 == v8;
    }
    while ( v9 > v8 );
    v5 = r;
  }
  if ( v10 )
  {
    while ( 1 )
    {
      v21 = *v3 % 32;
      v22 = d[v8] >> v21;
      if ( !v22 )
        break;
      if ( v21 )
        d[v28] = d[v8] << (32 - v21) >> (32 - v21);
      else
        d[v28] = 0;
      *d ^= v22;
      v23 = v3 + 1;
      v24 = 1;
      if ( v3[1] )
      {
        do
        {
          v25 = *v23;
          v26 = *v23 / 32;
          v25 %= 32;
          d[v26] ^= v22 << v25;
          v27 = v22 >> (32 - v25);
          if ( v25 && v27 )
            d[v26 + 1] ^= v27;
          v23 = &p[++v24];
        }
        while ( *v23 );
        v3 = p;
      }
      v5 = r;
      v8 = v28;
    }
  }
  top = v5->top;
  if ( top > 0 )
  {
    v19 = &v5->d[top - 1];
    do
    {
      if ( *v19-- )
        break;
      --top;
    }
    while ( top > 0 );
    v5->top = top;
  }
  return 1;
}
