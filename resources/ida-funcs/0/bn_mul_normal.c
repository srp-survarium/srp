void __cdecl bn_mul_normal(unsigned int *r, unsigned int *a, int na, unsigned int *b, int nb)
{
  int v5; // esi
  int v6; // edi
  unsigned int *v7; // ecx
  unsigned int *v8; // eax
  int v9; // esi
  unsigned int *v10; // ebx
  unsigned int *v11; // ebp
  int v12; // esi
  int v13; // esi
  int v14; // esi
  int v15; // eax
  unsigned int *v16; // [esp+18h] [ebp+Ch]

  v5 = nb;
  v6 = na;
  if ( na >= nb )
  {
    v8 = a;
  }
  else
  {
    v7 = a;
    v6 = nb;
    v5 = na;
    v8 = b;
    a = b;
    b = v7;
  }
  if ( v5 > 0 )
  {
    v9 = v5 - 1;
    r[v6] = bn_mul_words(r, v8, v6, *b);
    if ( v9 > 0 )
    {
      v10 = &r[v6 + 2];
      v11 = r + 2;
      v16 = b + 2;
      do
      {
        v12 = v9 - 1;
        *(v10 - 1) = bn_mul_add_words(v11 - 1, a, v6, *(v16 - 1));
        if ( v12 <= 0 )
          break;
        v13 = v12 - 1;
        *v10 = bn_mul_add_words(v11, a, v6, *v16);
        if ( v13 <= 0 )
          break;
        v14 = v13 - 1;
        v10[1] = bn_mul_add_words(v11 + 1, a, v6, v16[1]);
        if ( v14 <= 0 )
          break;
        v15 = bn_mul_add_words(v11 + 2, a, v6, v16[2]);
        v16 += 4;
        v10[2] = v15;
        v9 = v14 - 1;
        v10 += 4;
        v11 += 4;
      }
      while ( v9 > 0 );
    }
  }
  else
  {
    bn_mul_words(r, v8, v6, 0);
  }
}
