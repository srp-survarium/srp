char __cdecl sub_52DE70(int *a1)
{
  int v2; // [esp+0h] [ebp-14h]
  int v3; // [esp+0h] [ebp-14h]
  int v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]

  if ( a1[1] )
  {
    if ( !a1[4] )
    {
      *a1 = a1[1];
      a1[1] = *(_DWORD *)a1[1];
      *(_DWORD *)*a1 = 0;
      a1[4] = *a1 + 8;
      a1[2] = *(_DWORD *)(*a1 + 4) + a1[4];
      a1[3] = a1[4];
      return 1;
    }
    if ( a1[2] - a1[4] < *(_DWORD *)(a1[1] + 4) )
    {
      v7 = *(_DWORD *)a1[1];
      *(_DWORD *)a1[1] = *a1;
      *a1 = a1[1];
      a1[1] = v7;
      memcpy((unsigned __int8 *)(*a1 + 8), (unsigned __int8 *)a1[4], a1[2] - a1[4]);
      a1[3] = *a1 + a1[3] - a1[4] + 8;
      a1[4] = *a1 + 8;
      a1[2] = *(_DWORD *)(*a1 + 4) + a1[4];
      return 1;
    }
  }
  if ( *a1 && a1[4] == *a1 + 8 )
  {
    v5 = 2 * (a1[2] - a1[4]);
    v6 = (*(int (__cdecl **)(int, int))(a1[5] + 4))(*a1, v5 + 8);
    if ( !v6 )
      return 0;
    *a1 = v6;
    *(_DWORD *)(*a1 + 4) = v5;
    a1[3] = *a1 + a1[3] - a1[4] + 8;
    a1[4] = *a1 + 8;
    a1[2] = v5 + a1[4];
  }
  else
  {
    v2 = a1[2] - a1[4];
    if ( v2 >= 1024 )
      v3 = 2 * v2;
    else
      v3 = 1024;
    v4 = (*(int (__cdecl **)(int))a1[5])(v3 + 8);
    if ( !v4 )
      return 0;
    *(_DWORD *)(v4 + 4) = v3;
    *(_DWORD *)v4 = *a1;
    *a1 = v4;
    if ( a1[3] != a1[4] )
      memcpy((unsigned __int8 *)(v4 + 8), (unsigned __int8 *)a1[4], a1[3] - a1[4]);
    a1[3] = v4 + a1[3] - a1[4] + 8;
    a1[4] = v4 + 8;
    a1[2] = v4 + v3 + 8;
  }
  return 1;
}
