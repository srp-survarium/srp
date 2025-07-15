void __cdecl bn_mul_part_recursive(
        unsigned int *r,
        unsigned int *a,
        unsigned int *b,
        int n,
        int tna,
        int tnb,
        unsigned int *t)
{
  int v8; // ebp
  unsigned int *v9; // eax
  unsigned int *v10; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  int v14; // ecx
  int v15; // eax
  int v16; // edi
  int v17; // edi
  unsigned int v18; // edi
  unsigned int *v19; // eax
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  int v22; // [esp-10h] [ebp-30h]
  unsigned int *v23; // [esp+4h] [ebp-1Ch]
  unsigned int *v24; // [esp+8h] [ebp-18h]
  unsigned int *ta; // [esp+Ch] [ebp-14h]
  int v26; // [esp+10h] [ebp-10h]
  int v27; // [esp+10h] [ebp-10h]
  int v28; // [esp+14h] [ebp-Ch]
  unsigned int *v29; // [esp+14h] [ebp-Ch]
  int v30; // [esp+18h] [ebp-8h]
  int v31; // [esp+1Ch] [ebp-4h]
  unsigned int *n2; // [esp+30h] [ebp+10h]

  if ( n >= 8 )
  {
    v28 = n - tna;
    v23 = &a[n];
    v8 = bn_cmp_part_words((char *)a, (char *)v23, tna, n - tna);
    v30 = 0;
    v26 = tnb - n;
    n2 = &b[n];
    switch ( bn_cmp_part_words((char *)&b[n], (char *)b, tnb, tnb - n) + 3 * v8 )
    {
      case -4:
        bn_sub_part_words(t, v23, a, tna, tna - n);
        v9 = n2;
        v10 = b;
        v11 = n - tnb;
        goto LABEL_8;
      case -3:
      case -2:
        bn_sub_part_words(t, v23, a, tna, tna - n);
        bn_sub_part_words(&t[n], n2, b, tnb, v26);
        v30 = 1;
        break;
      case -1:
      case 0:
      case 1:
      case 2:
        bn_sub_part_words(t, a, v23, tna, v28);
        bn_sub_part_words(&t[n], b, n2, tnb, n - tnb);
        v30 = 1;
        break;
      case 3:
      case 4:
        bn_sub_part_words(t, a, v23, tna, v28);
        v11 = v26;
        v9 = b;
        v10 = n2;
LABEL_8:
        bn_sub_part_words(&t[n], v10, v9, tnb, v11);
        break;
      default:
        break;
    }
    if ( n == 8 )
    {
      v29 = t + 16;
      bn_mul_comba8(t + 16, t, t + 8);
      bn_mul_comba8(r, a, b);
      v24 = r + 16;
      bn_mul_normal(r + 16, a + 8, tna, b + 8, tnb);
      memset((int)&r[tnb + 16 + tna], 0, 4 * (16 - tna - tnb));
    }
    else
    {
      ta = &t[4 * n];
      v27 = 2 * n;
      v29 = &t[2 * n];
      bn_mul_recursive(v29, t, &t[n], n, 0, 0, ta);
      bn_mul_recursive(r, a, b, n, 0, 0, ta);
      v12 = n / 2;
      v31 = n / 2;
      v13 = tna;
      if ( tna <= tnb )
        v13 = tnb;
      v14 = v13 - v12;
      if ( v14 )
      {
        if ( v14 <= 0 )
        {
          v24 = &r[v27];
          memset((int)&r[v27], 0, v27 * 4);
          if ( tna >= 16 || tnb >= 16 )
          {
            v15 = v31 / 2;
            if ( v31 / 2 >= tna )
            {
              while ( v15 >= tnb )
              {
                if ( v15 == tna || v15 == tnb )
                {
                  bn_mul_recursive(v24, v23, n2, v15, tna - v15, tnb - v15, ta);
                  goto LABEL_26;
                }
                v15 /= 2;
                if ( v15 < tna )
                  break;
              }
            }
            bn_mul_part_recursive(v24, v23, n2, v15, tna - v15, tnb - v15, ta);
          }
          else
          {
            bn_mul_normal(v24, v23, tna, n2, tnb);
          }
        }
        else
        {
          v24 = &r[v27];
          bn_mul_part_recursive(&r[v27], v23, n2, n / 2, tna - v12, tnb - v12, ta);
          memset((int)&r[2 * n + tnb + tna], 0, 4 * (2 * n - tna - tnb));
        }
      }
      else
      {
        v24 = &r[v27];
        bn_mul_recursive(&r[v27], v23, n2, n / 2, tna - v12, tnb - v12, ta);
        memset((int)&r[2 * n + 2 * v31], 0, v27 * 4 - 8 * v31);
      }
    }
LABEL_26:
    v16 = bn_add_words(t, r, v24, 2 * n);
    v22 = 2 * n;
    if ( v30 )
      v17 = v16 - bn_sub_words(v29, t, v29, v22);
    else
      v17 = bn_add_words(v29, v29, t, v22) + v16;
    v18 = bn_add_words(&r[n], &r[n], v29, 2 * n) + v17;
    if ( v18 )
    {
      v19 = &r[3 * n];
      v20 = v18 + *v19;
      *v19 = v20;
      if ( v20 < v18 )
      {
        do
        {
          v21 = v19[1];
          *++v19 = v21 + 1;
        }
        while ( v21 == -1 );
      }
    }
  }
  else
  {
    bn_mul_normal(r, a, tna + n, b, n + tnb);
  }
}
