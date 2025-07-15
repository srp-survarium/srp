int __cdecl sub_656180(int a1, int a2, int a3, _DWORD *a4)
{
  int v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-4h]
  int i; // [esp+1Ch] [ebp+Ch]

  if ( a2 != a3 )
  {
    if ( !*(_BYTE *)a2 && *(_BYTE *)(a2 + 1) == 120 )
      return sub_6562B0(a1, a2 + 2, a3, a4);
    if ( *(_BYTE *)a2 )
      v6 = sub_64FDE0(*(_BYTE *)a2, *(_BYTE *)(a2 + 1));
    else
      v6 = *(unsigned __int8 *)(a1 + *(unsigned __int8 *)(a2 + 1) + 76);
    if ( v6 != 25 )
    {
      *a4 = a2;
      return 0;
    }
    for ( i = a2 + 2; i != a3; i += 2 )
    {
      if ( *(_BYTE *)i )
        v5 = sub_64FDE0(*(_BYTE *)i, *(_BYTE *)(i + 1));
      else
        v5 = *(unsigned __int8 *)(a1 + *(unsigned __int8 *)(i + 1) + 76);
      if ( v5 == 18 )
      {
        *a4 = i + 2;
        return 10;
      }
      if ( v5 != 25 )
      {
        *a4 = i;
        return 0;
      }
    }
  }
  return -1;
}
