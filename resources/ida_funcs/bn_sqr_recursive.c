void __cdecl bn_sqr_recursive(unsigned int *r, unsigned int *a, int n2, unsigned int *t)
{
  int v5; // esi
  int v6; // eax
  unsigned int *v7; // edi
  unsigned int *v8; // edi
  unsigned int v9; // ecx
  unsigned int *v10; // ebp
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int *v13; // [esp-Ch] [ebp-1Ch]
  unsigned int *ta; // [esp+8h] [ebp-8h]
  int n; // [esp+1Ch] [ebp+Ch]
  int na; // [esp+1Ch] [ebp+Ch]
  int nb; // [esp+1Ch] [ebp+Ch]

  v5 = n2 / 2;
  if ( n2 == 4 )
  {
    bn_sqr_comba4(r, a);
  }
  else if ( n2 == 8 )
  {
    bn_sqr_comba8(r, a);
  }
  else if ( n2 >= 16 )
  {
    v6 = bn_cmp_words((char *)a, (char *)&a[n2 / 2], n2 / 2);
    n = 0;
    if ( v6 <= 0 )
    {
      if ( v6 >= 0 )
        n = 1;
      else
        bn_sub_words(t, &a[v5], a, v5);
      v7 = t;
    }
    else
    {
      v7 = t;
      bn_sub_words(t, a, &a[v5], v5);
    }
    ta = &v7[2 * n2];
    if ( n )
    {
      v8 = &v7[n2];
      memset((int)v8, 0, 4 * n2);
    }
    else
    {
      v13 = &v7[2 * n2];
      v8 = &v7[n2];
      bn_sqr_recursive(v8, t, v5, v13);
    }
    bn_sqr_recursive(r, a, v5, ta);
    bn_sqr_recursive(&r[n2], &a[v5], v5, &t[2 * n2]);
    na = bn_add_words(t, r, &r[n2], n2);
    nb = na - bn_sub_words(v8, t, v8, n2);
    v9 = bn_add_words(&r[v5], &r[v5], v8, n2) + nb;
    if ( v9 )
    {
      v10 = &r[n2 + v5];
      v11 = v9 + *v10;
      *v10 = v11;
      if ( v11 < v9 )
      {
        do
        {
          v12 = v10[1];
          *++v10 = v12 + 1;
        }
        while ( v12 == -1 );
      }
    }
  }
  else
  {
    bn_sqr_normal(r, a, n2, t);
  }
}
