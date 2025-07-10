int __cdecl local_book_besterror(codebook *book, int *a)
{
  codebook *v2; // eax
  int delta; // edx
  int v4; // ecx
  int quantvals; // ebp
  int minval; // esi
  int v7; // edi
  int v8; // ebx
  int v9; // eax
  int *v10; // edi
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  bool v14; // zf
  int v15; // eax
  int *v16; // edx
  int v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // ebx
  int entries; // eax
  int v22; // edx
  int v23; // ebp
  int v24; // eax
  int v25; // ebx
  int v26; // esi
  int *v27; // eax
  int v28; // esi
  unsigned int v29; // edx
  int v30; // ecx
  int v31; // ebp
  int v32; // ecx
  int v33; // eax
  int v34; // eax
  int v35; // ecx
  int *v36; // eax
  int v37; // eax
  int *v38; // ecx
  int *v39; // eax
  int index; // [esp+10h] [ebp-64h]
  int v42; // [esp+14h] [ebp-60h]
  int dim; // [esp+18h] [ebp-5Ch]
  int i; // [esp+1Ch] [ebp-58h]
  int best; // [esp+20h] [ebp-54h]
  int besta; // [esp+20h] [ebp-54h]
  int bestb; // [esp+20h] [ebp-54h]
  int maxval; // [esp+24h] [ebp-50h]
  int j; // [esp+2Ch] [ebp-48h]
  int v50; // [esp+30h] [ebp-44h]
  int e[8]; // [esp+34h] [ebp-40h] BYREF
  int p[8]; // [esp+54h] [ebp-20h] BYREF
  codebook *booka; // [esp+78h] [ebp+4h]
  codebook *bookb; // [esp+78h] [ebp+4h]

  v2 = book;
  delta = book->delta;
  v4 = book->dim;
  quantvals = book->quantvals;
  minval = book->minval;
  v7 = 0;
  v8 = quantvals >> 1;
  dim = book->dim;
  v42 = delta;
  index = 0;
  memset(p, 0, sizeof(p));
  if ( delta == 1 )
  {
    if ( v4 > 0 )
    {
      v15 = (char *)a - (char *)p;
      v16 = &p[v4];
      besta = v4;
      while ( 1 )
      {
        v17 = *(int *)((char *)v16-- + v15 - 4);
        v18 = v17 - minval;
        v19 = v18 >= v8 ? 2 * (v18 - v8) : 2 * (v8 - v18) - 1;
        if ( v19 >= 0 )
        {
          if ( v19 >= quantvals )
            v19 = quantvals - 1;
        }
        else
        {
          v19 = 0;
        }
        v14 = besta-- == 1;
        index = v19 + quantvals * index;
        *v16 = minval + v18;
        if ( v14 )
          break;
        v15 = (char *)a - (char *)p;
      }
      goto LABEL_25;
    }
  }
  else if ( v4 > 0 )
  {
    v9 = (char *)a - (char *)p;
    v10 = &p[v4];
    best = v4;
    while ( 1 )
    {
      v11 = *(int *)((char *)v10-- + v9 - 4);
      v12 = ((delta >> 1) + v11 - minval) / delta;
      v13 = v12 >= v8 ? 2 * (v12 - v8) : 2 * (v8 - v12) - 1;
      if ( v13 >= 0 )
      {
        if ( v13 >= quantvals )
          v13 = quantvals - 1;
      }
      else
      {
        v13 = 0;
      }
      v14 = best-- == 1;
      index = v13 + quantvals * index;
      *v10 = minval + delta * v12;
      if ( v14 )
        break;
      v9 = (char *)a - (char *)p;
    }
LABEL_25:
    v2 = book;
    v4 = dim;
    v7 = 0;
  }
  v20 = index;
  booka = (codebook *)v2->c;
  if ( *(int *)(booka->used_entries + 4 * index) <= 0 )
  {
    entries = v2->entries;
    v22 = minval + v42 * (quantvals - 1);
    v23 = 0;
    bestb = -1;
    memset(e, 0, sizeof(e));
    maxval = v22;
    i = 0;
    v50 = entries;
    if ( entries > 0 )
    {
      bookb = (codebook *)booka->used_entries;
      do
      {
        if ( bookb->dim > 0 )
        {
          v24 = 0;
          v25 = 0;
          v26 = 0;
          if ( v4 >= 2 )
          {
            v27 = a;
            v28 = (char *)&e[1] - (char *)a;
            v29 = ((unsigned int)(v4 - 2) >> 1) + 1;
            j = 2 * v29;
            do
            {
              v30 = *(int *)((char *)v27 + v28 - 4) - *v27;
              v27 += 2;
              v31 = v30 * v30;
              v32 = *(int *)((char *)v27 + v28 - 8) - *(v27 - 1);
              v7 += v31;
              v25 += v32 * v32;
              --v29;
            }
            while ( v29 );
            v23 = i;
            v22 = maxval;
            v24 = 0;
            v26 = j;
            v4 = dim;
          }
          if ( v26 < v4 )
          {
            v33 = e[v26] - a[v26];
            v24 = v33 * v33;
          }
          v34 = v7 + v25 + v24;
          if ( bestb == -1 || v34 < bestb )
          {
            qmemcpy(p, e, sizeof(p));
            bestb = v34;
            index = v23;
          }
        }
        v35 = 0;
        if ( e[0] >= v22 )
        {
          v36 = e;
          do
          {
            ++v35;
            *v36 = 0;
            v36 = &e[v35];
          }
          while ( *v36 >= v22 );
        }
        v37 = e[v35];
        v38 = &e[v35];
        if ( v37 >= 0 )
          *v38 = v42 + v37;
        bookb = (codebook *)((char *)bookb + 4);
        ++v23;
        v7 = 0;
        *v38 = -*v38;
        v4 = dim;
        i = v23;
      }
      while ( v23 < v50 );
      v20 = index;
    }
  }
  v39 = a;
  if ( v20 > -1 && v4 > 0 )
  {
    do
      *v39++ -= p[v7++];
    while ( v7 < v4 );
  }
  return v20;
}
