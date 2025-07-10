int __cdecl BN_usub(bignum_st *r, const bignum_st *a, const bignum_st *b)
{
  unsigned int *top; // eax
  int v4; // edi
  char *v5; // esi
  bignum_st *v7; // ecx
  bignum_st *v8; // eax
  unsigned int *d; // eax
  unsigned int *v10; // ebp
  unsigned int *v11; // ecx
  BOOL v12; // edx
  unsigned int v13; // ebx
  unsigned int v14; // edi
  unsigned int v15; // edi
  unsigned int v16; // edx
  char *v17; // edx
  char *v18; // esi
  char *v19; // edx
  char *v20; // esi
  char *v21; // edx
  int v22; // eax
  unsigned int *v23; // ecx
  int v25; // [esp+10h] [ebp-4h]
  int v26; // [esp+1Ch] [ebp+8h]

  top = (unsigned int *)a->top;
  v4 = b->top;
  v5 = (char *)top - v4;
  v25 = (int)top;
  if ( (int)top - v4 < 0 )
  {
    ERR_put_error(3u, 115, 100, ".\\crypto\\bn\\bn_add.c", 184);
    return 0;
  }
  v7 = r;
  if ( (int)top > r->dmax )
  {
    v8 = bn_expand2(r, top);
    v7 = r;
  }
  else
  {
    v8 = r;
  }
  if ( !v8 )
    return 0;
  d = a->d;
  v10 = b->d;
  v11 = v7->d;
  v12 = 0;
  v26 = v4;
  if ( v4 )
  {
    do
    {
      v13 = *v10;
      v14 = *d++;
      ++v10;
      if ( v12 )
      {
        v12 = v13 >= v14;
        v15 = -1 - v13 + v14;
      }
      else
      {
        v12 = v14 < v13;
        v15 = v14 - v13;
      }
      *v11++ = v15;
      --v26;
    }
    while ( v26 );
    if ( v12 )
    {
      if ( !v5 )
        return 0;
      do
      {
        v16 = *d;
        *v11 = *d - 1;
        --v5;
        ++d;
        ++v11;
      }
      while ( !v16 && v5 );
    }
  }
  if ( v11 != d && v5 )
  {
    do
    {
      *v11 = *d;
      v17 = v5 - 1;
      v18 = v5 - 2;
      if ( !v17 )
        break;
      v11[1] = d[1];
      v19 = v18;
      v20 = v18 - 1;
      if ( !v19 )
        break;
      v11[2] = d[2];
      v21 = v20;
      v5 = v20 - 1;
      if ( !v21 )
        break;
      v11[3] = d[3];
      v11 += 4;
      d += 4;
    }
    while ( v5 );
  }
  v22 = v25;
  r->top = v25;
  r->neg = 0;
  if ( v25 > 0 )
  {
    v23 = &r->d[v25 - 1];
    do
    {
      if ( *v23-- )
        break;
      --v22;
    }
    while ( v22 > 0 );
    r->top = v22;
  }
  return 1;
}
