int __cdecl sub_523460(int a1, unsigned __int8 *a2, int a3, _DWORD *a4, int a5)
{
  int v6; // eax
  int v7; // eax
  int v8; // edx
  int v9; // ecx
  int v10; // ecx
  int v11; // eax
  unsigned __int8 *v12; // [esp+0h] [ebp-8h]
  unsigned __int8 *v13; // [esp+4h] [ebp-4h]

  v12 = a2;
  v13 = (unsigned __int8 *)(*(_DWORD *)(a4[3] + 4 * a1) + a4[28]);
  if ( a3 < 0 )
    return -1;
  if ( a5 )
  {
    if ( (unsigned int)&a2[a3] > a4[29] )
      return -1;
    while ( 1 )
    {
      v6 = a3--;
      if ( v6 <= 0 )
        break;
      v7 = *(unsigned __int8 *)(a4[12] + *a2);
      v8 = *(unsigned __int8 *)(a4[12] + *v13);
      ++a2;
      ++v13;
      if ( v8 != v7 )
        return -1;
    }
  }
  else
  {
    if ( (unsigned int)&a2[a3] > a4[29] )
      return -1;
    while ( 1 )
    {
      v9 = a3--;
      if ( v9 <= 0 )
        break;
      v10 = *a2;
      v11 = *v13;
      ++a2;
      ++v13;
      if ( v11 != v10 )
        return -1;
    }
  }
  return a2 - v12;
}
