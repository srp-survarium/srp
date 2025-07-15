void __cdecl bn_mul_recursive(
        unsigned int *r,
        unsigned int *a,
        unsigned int *b,
        int n2,
        int dna,
        int dnb,
        unsigned int *t)
{
  int v7; // esi
  int v8; // ebx
  int v9; // ebp
  int v10; // edi
  unsigned int *v11; // ecx
  unsigned int *v12; // edx
  int v13; // eax
  unsigned int *v14; // ebx
  unsigned int *v15; // ebp
  int v16; // edi
  unsigned int v17; // edi
  int v18; // esi
  unsigned int v19; // eax
  unsigned int *v20; // ebp
  unsigned int v21; // eax
  unsigned int v22; // eax
  int v23; // [esp+10h] [ebp-18h]
  unsigned int *v24; // [esp+10h] [ebp-18h]
  int v25; // [esp+10h] [ebp-18h]
  unsigned int *v26; // [esp+14h] [ebp-14h]
  unsigned int *v27; // [esp+18h] [ebp-10h]
  int v28; // [esp+1Ch] [ebp-Ch]
  int v29; // [esp+20h] [ebp-8h]
  int dnba; // [esp+40h] [ebp+18h]

  v7 = n2 / 2;
  v8 = n2 / 2 + dna;
  v9 = n2 / 2 + dnb;
  if ( n2 == 8 )
  {
    if ( !dna && !dnb )
    {
      bn_mul_comba8(r, a, b);
      return;
    }
    goto LABEL_6;
  }
  if ( n2 < 16 )
  {
LABEL_6:
    bn_mul_normal(r, a, n2 + dna, b, n2 + dnb);
    if ( dna + dnb < 0 )
      memset((int)&r[2 * n2 + dnb + dna], 0, -4 * (dna + dnb));
    return;
  }
  v29 = -dna;
  v27 = &a[v7];
  v10 = bn_cmp_part_words((char *)a, (char *)v27, v7 + dna, -dna);
  v28 = 0;
  v23 = 0;
  v26 = &b[v7];
  switch ( bn_cmp_part_words((char *)v26, (char *)b, v9, v9 - v7) + 3 * v10 )
  {
    case -4:
      bn_sub_part_words(t, v27, a, v8, v8 - v7);
      v11 = &b[v7];
      v12 = b;
      v13 = v7 - v9;
      goto LABEL_14;
    case -3:
    case -1:
    case 0:
    case 1:
    case 3:
      v23 = 1;
      break;
    case -2:
      bn_sub_part_words(t, v27, a, v8, v8 - v7);
      bn_sub_part_words(&t[v7], v26, b, v9, v9 - v7);
      v28 = 1;
      break;
    case 2:
      bn_sub_part_words(t, a, v27, v8, v29);
      bn_sub_part_words(&t[v7], b, v26, v9, v7 - v9);
      v28 = 1;
      break;
    case 4:
      bn_sub_part_words(t, a, v27, v8, v29);
      v13 = v9 - v7;
      v11 = b;
      v12 = &b[v7];
LABEL_14:
      bn_sub_part_words(&t[v7], v12, v11, v9, v13);
      break;
    default:
      break;
  }
  if ( v7 != 4 )
  {
    if ( v7 == 8 && !dna && !dnb )
    {
      v14 = &t[n2];
      if ( v23 )
        memset((int)v14, 0, 64);
      else
        bn_mul_comba8(v14, t, t + 8);
      v15 = r;
      bn_mul_comba8(r, a, b);
      v24 = &r[n2];
      bn_mul_comba8(v24, a + 8, b + 8);
      goto LABEL_33;
    }
    goto LABEL_29;
  }
  if ( dna || dnb )
  {
LABEL_29:
    if ( v23 )
    {
      v14 = &t[n2];
      v25 = n2;
      memset((int)v14, 0, 4 * n2);
    }
    else
    {
      v25 = n2;
      v14 = &t[n2];
      bn_mul_recursive(v14, t, &t[v7], v7, 0, 0, &t[2 * n2]);
    }
    v15 = r;
    bn_mul_recursive(r, a, b, v7, 0, 0, &t[2 * n2]);
    v24 = &r[v25];
    bn_mul_recursive(v24, v27, v26, v7, dna, dnb, &t[2 * n2]);
    goto LABEL_33;
  }
  v14 = &t[n2];
  if ( v23 )
  {
    *v14 = 0;
    v14[1] = 0;
    v14[2] = 0;
    v14[3] = 0;
    v14[4] = 0;
    v14[5] = 0;
    v14[6] = 0;
    v14[7] = 0;
  }
  else
  {
    bn_mul_comba4(v14, t, t + 4);
  }
  v15 = r;
  bn_mul_comba4(r, a, b);
  v24 = &r[n2];
  bn_mul_comba4(v24, a + 4, b + 4);
LABEL_33:
  dnba = bn_add_words(t, v15, v24, n2);
  if ( v28 )
    v16 = dnba - bn_sub_words(v14, t, v14, n2);
  else
    v16 = bn_add_words(v14, v14, t, n2) + dnba;
  v17 = bn_add_words(&v15[v7], &v15[v7], v14, n2) + v16;
  if ( v17 )
  {
    v18 = n2 + v7;
    v19 = v15[v18];
    v20 = &v15[v18];
    v21 = v17 + v19;
    *v20 = v21;
    if ( v21 < v17 )
    {
      do
      {
        v22 = v20[1];
        *++v20 = v22 + 1;
      }
      while ( v22 == -1 );
    }
  }
}
