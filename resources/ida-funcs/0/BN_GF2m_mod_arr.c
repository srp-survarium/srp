int __usercall BN_GF2m_mod_arr@<eax>(int a1@<ebx>, bignum_st *r, const bignum_st *a, const int *p)
{
  const int *v4; // esi
  int result; // eax
  bignum_st *v6; // ebp
  int i; // eax
  unsigned int *d; // edi
  int v9; // ecx
  int v10; // ebx
  bool v11; // zf
  unsigned int *v12; // eax
  unsigned int v13; // ebp
  const int *v14; // ecx
  int v15; // eax
  int v16; // esi
  unsigned int *v17; // eax
  int v18; // edx
  int top; // eax
  unsigned int *v20; // ecx
  int v22; // edx
  unsigned int v23; // ebx
  const int *v24; // eax
  int v25; // ebp
  int v26; // edx
  int v27; // eax
  unsigned int v28; // esi
  int v29; // [esp+4h] [ebp-Ch]
  int v30; // [esp+8h] [ebp-8h]
  unsigned int *v31; // [esp+Ch] [ebp-4h]

  v4 = p;
  if ( !*p )
  {
    BN_set_word(a1, r, 0);
    return 1;
  }
  v6 = r;
  if ( a != r )
  {
    if ( a->top > r->dmax )
      result = (int)bn_expand2(r, a->top);
    else
      result = (int)r;
    if ( !result )
      return result;
    for ( i = 0; i < a->top; ++i )
      r->d[i] = a->d[i];
    r->top = a->top;
  }
  d = r->d;
  v9 = *p / 32;
  v10 = r->top - 1;
  v11 = v10 == v9;
  v29 = v9;
  if ( v10 > v9 )
  {
    v12 = &d[v10 - v9];
    v31 = v12;
    do
    {
      v13 = d[v10];
      if ( v13 )
      {
        v14 = v4 + 1;
        d[v10] = 0;
        v30 = 1;
        if ( v4[1] )
        {
          do
          {
            v15 = *v4 - *v14;
            v16 = v15 % 32;
            v17 = &d[v10 - v15 / 32];
            *v17 ^= v13 >> v16;
            if ( v16 )
              *(v17 - 1) ^= v13 << (32 - v16);
            v4 = p;
            v11 = p[v30 + 1] == 0;
            v14 = &p[++v30];
          }
          while ( !v11 );
        }
        v18 = *v4 % 32;
        v12 = v31;
        *v31 ^= v13 >> v18;
        if ( v18 )
          *(v31 - 1) ^= v13 << (32 - v18);
        v9 = v29;
      }
      else
      {
        --v10;
        v31 = --v12;
      }
      v11 = v10 == v9;
    }
    while ( v10 > v9 );
    v6 = r;
  }
  if ( v11 )
  {
    while ( 1 )
    {
      v22 = *v4 % 32;
      v23 = d[v9] >> v22;
      if ( !v23 )
        break;
      if ( v22 )
        d[v29] = d[v9] << (32 - v22) >> (32 - v22);
      else
        d[v29] = 0;
      *d ^= v23;
      v24 = v4 + 1;
      v25 = 1;
      if ( v4[1] )
      {
        do
        {
          v26 = *v24;
          v27 = *v24 / 32;
          v26 %= 32;
          d[v27] ^= v23 << v26;
          v28 = v23 >> (32 - v26);
          if ( v26 && v28 )
            d[v27 + 1] ^= v28;
          v24 = &p[++v25];
        }
        while ( *v24 );
        v4 = p;
      }
      v6 = r;
      v9 = v29;
    }
  }
  top = v6->top;
  if ( top > 0 )
  {
    v20 = &v6->d[top - 1];
    do
    {
      if ( *v20-- )
        break;
      --top;
    }
    while ( top > 0 );
    v6->top = top;
  }
  return 1;
}
