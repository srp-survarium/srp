unsigned int __cdecl BN_div_word(bignum_st *a, unsigned int w)
{
  int v4; // eax
  char v5; // si
  unsigned int v6; // ebp
  int v7; // edi
  unsigned int v8; // esi
  unsigned int v9; // eax
  int top; // eax
  unsigned int v11; // [esp+4h] [ebp-4h]
  char l; // [esp+10h] [ebp+8h]

  v11 = 0;
  if ( !w )
    return -1;
  if ( !a->top )
    return 0;
  v4 = BN_num_bits_word(w);
  v5 = 32 - v4;
  l = 32 - v4;
  v6 = w << (32 - v4);
  if ( !BN_lshift(a, a, 32 - v4) )
    return -1;
  v7 = a->top - 1;
  if ( v7 >= 0 )
  {
    do
    {
      v8 = a->d[v7];
      v9 = bn_div_words(v11, v8, v6);
      a->d[v7--] = v9;
      v11 = v8 - v6 * v9;
    }
    while ( v7 >= 0 );
    v5 = l;
  }
  top = a->top;
  if ( top > 0 && !a->d[top - 1] )
    a->top = top - 1;
  return v11 >> v5;
}
