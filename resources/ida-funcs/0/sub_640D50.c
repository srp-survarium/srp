char __cdecl sub_640D50(int a1)
{
  int v2; // [esp+0h] [ebp-14h]
  int v3; // [esp+4h] [ebp-10h]
  int v4; // [esp+8h] [ebp-Ch]
  unsigned __int8 *dst; // [esp+Ch] [ebp-8h]
  int **i; // [esp+10h] [ebp-4h]

  for ( i = *(int ***)(a1 + 364); i; i = (int **)*i )
  {
    v4 = (int)i[6] + 1;
    dst = (unsigned __int8 *)i[9] + v4;
    if ( i[1] == (int *)dst )
      break;
    v3 = (int)i[2] + v4;
    if ( v3 > (char *)i[10] - (char *)i[9] )
    {
      v2 = (*(int (__cdecl **)(int *, int))(a1 + 16))(i[9], v3);
      if ( !v2 )
        return 0;
      if ( i[3] == i[9] )
        i[3] = (int *)v2;
      if ( i[4] )
        i[4] = (int *)(v2 + (char *)i[4] - (char *)i[9]);
      i[9] = (int *)v2;
      i[10] = (int *)(v3 + v2);
      dst = (unsigned __int8 *)(v4 + v2);
    }
    memcpy((int)dst, (const __m128i *)i[1], (unsigned int)i[2]);
    i[1] = (int *)dst;
  }
  return 1;
}
