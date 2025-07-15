int __cdecl BN_from_montgomery_word(bignum_st *ret, bignum_st *r, bn_mont_ctx_st *mont)
{
  int top; // edi
  int v4; // esi
  bignum_st *v5; // eax
  int v6; // eax
  unsigned int *d; // ebx
  int v8; // ecx
  unsigned int *i; // edi
  int v10; // eax
  unsigned int v11; // eax
  bool v12; // zf
  _DWORD *j; // eax
  int v14; // eax
  unsigned int *v15; // ecx
  int v17; // eax
  int v19; // ebx
  int v21; // ebx
  unsigned int v22; // ebp
  int v23; // eax
  unsigned int *v24; // ecx
  int v25; // eax
  int v26; // edi
  int v27; // esi
  int v28; // edx
  int *v29; // eax
  _DWORD *v30; // ecx
  int v31; // edi
  int v32; // ebx
  int v33; // esi
  int v34; // edi
  char *v35; // ebp
  unsigned int *v36; // eax
  int v37; // esi
  int v38; // eax
  unsigned int *v39; // ecx
  int v41; // eax
  unsigned int *v42; // ecx
  int v44; // [esp+Ch] [ebp-1Ch]
  int v45; // [esp+Ch] [ebp-1Ch]
  int v46; // [esp+Ch] [ebp-1Ch]
  unsigned int *v47; // [esp+10h] [ebp-18h]
  char *v48; // [esp+10h] [ebp-18h]
  unsigned int v49; // [esp+14h] [ebp-14h]
  char *v50; // [esp+1Ch] [ebp-Ch]
  int v51; // [esp+20h] [ebp-8h]
  int v52; // [esp+24h] [ebp-4h]
  int v53; // [esp+34h] [ebp+Ch]
  unsigned int *v54; // [esp+34h] [ebp+Ch]

  top = mont->N.top;
  v4 = mont->ri / 32;
  v44 = top;
  if ( v4 && top )
  {
    if ( top + v4 + 1 > r->dmax )
      v5 = bn_expand2(r, top + v4 + 1);
    else
      v5 = r;
    if ( !v5 )
      return 0;
    r->neg ^= mont->N.neg;
    v6 = r->top;
    d = r->d;
    v47 = mont->N.d;
    v8 = top + v4 + 1;
    for ( i = &r->d[top]; v6 < v8; ++v6 )
      r->d[v6] = 0;
    r->top = v8;
    v10 = v44;
    v49 = mont->n0[0];
    if ( v44 > 0 )
    {
      v53 = v44;
      while ( 1 )
      {
        v11 = bn_mul_add_words(d, v47, v10, v49 * *d);
        *i++ += v11;
        ++d;
        if ( *(i - 1) < v11 )
        {
          v12 = (*i)++ == -1;
          if ( v12 )
          {
            v12 = i[1]++ == -1;
            if ( v12 )
            {
              v12 = i[2]++ == -1;
              for ( j = i + 2; v12; ++*j )
                v12 = *++j == -1;
            }
          }
        }
        if ( !--v53 )
          break;
        v10 = v44;
      }
    }
    v14 = r->top;
    if ( v14 > 0 )
    {
      v15 = &r->d[v14 - 1];
      do
      {
        if ( *v15-- )
          break;
        --v14;
      }
      while ( v14 > 0 );
      r->top = v14;
    }
    v17 = r->top;
    if ( v17 <= v4 )
    {
      ret->top = 0;
      return 1;
    }
    v19 = v17 - v4;
    v45 = v17 - v4;
    if ( v4 > ret->dmax ? bn_expand2(ret, v4) : ret )
    {
      v21 = -(((v19 - v4) >> 31) & 1);
      ret->top = v45 & v21 | v4 & ~v21;
      ret->neg = r->neg;
      v22 = (unsigned int)&r->d[v4];
      v54 = ret->d;
      v23 = bn_sub_words(ret->d, v22, v47, v4);
      v24 = v54;
      v25 = ((((v4 - v45) >> 31) & 1) - 1) & (-(((v4 - v45) >> 31) & 1) | v21 | -v23);
      v26 = v22 & v25 | (unsigned int)v54 & ~v25;
      v27 = v4 - 4;
      v28 = 0;
      v52 = v26;
      if ( v27 > 0 )
      {
        v48 = (char *)(v22 - v26);
        v29 = (int *)(v26 + 8);
        v30 = v54 + 1;
        v50 = (char *)v54 - v26;
        do
        {
          v31 = *(v29 - 2);
          v46 = *(v29 - 1);
          v32 = *v29;
          *(_DWORD *)(v22 + 4 * v28) = 0;
          v51 = v29[1];
          *(_DWORD *)((char *)v30 + v22 - (_DWORD)v54) = 0;
          *(v30 - 1) = v31;
          *(int *)((char *)v29 + (_DWORD)v48) = 0;
          *v30 = v46;
          *(_DWORD *)(v22 + 4 * v28 + 12) = 0;
          *(int *)((char *)v29 + (_DWORD)v50) = v32;
          v30[2] = v51;
          v28 += 4;
          v30 += 4;
          v29 += 4;
        }
        while ( v28 < v27 );
        v24 = v54;
        v26 = v52;
      }
      v33 = v27 + 4;
      if ( v28 < v33 )
      {
        v34 = v26 - (_DWORD)v24;
        v35 = (char *)(v22 - (_DWORD)v24);
        v36 = &v24[v28];
        v37 = v33 - v28;
        do
        {
          *v36 = *(unsigned int *)((char *)v36 + v34);
          *(_DWORD *)&v35[(_DWORD)v36++] = 0;
          --v37;
        }
        while ( v37 );
      }
      v38 = r->top;
      if ( v38 > 0 )
      {
        v39 = &r->d[v38 - 1];
        do
        {
          if ( *v39-- )
            break;
          --v38;
        }
        while ( v38 > 0 );
        r->top = v38;
      }
      v41 = ret->top;
      if ( v41 <= 0 )
        return 1;
      v42 = &ret->d[v41 - 1];
      do
      {
        if ( *v42-- )
          break;
        --v41;
      }
      while ( v41 > 0 );
      ret->top = v41;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    ret->top = 0;
    return 1;
  }
}
