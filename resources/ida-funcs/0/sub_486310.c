int __cdecl sub_486310(int *a1, int a2)
{
  int result; // eax
  int v3; // esi

  result = (int)a1;
  v3 = a1[101];
  if ( a2 )
  {
    if ( a2 == 2 )
    {
      *(_DWORD *)(v3 + 4) = sub_4862E0;
    }
    else
    {
      *(_DWORD *)(*a1 + 20) = 3;
      return (*(int (__cdecl **)(int *))*a1)(a1);
    }
  }
  else if ( *(_BYTE *)(a1[108] + 8) )
  {
    *(_DWORD *)(v3 + 4) = sub_4861A0;
    result = sub_485E70(a1);
    *(_DWORD *)(v3 + 64) = 0;
    *(_DWORD *)(v3 + 68) = 0;
    *(_DWORD *)(v3 + 76) = 0;
    *(_BYTE *)(v3 + 48) = 0;
    *(_DWORD *)(v3 + 52) = 0;
  }
  else
  {
    *(_BYTE *)(v3 + 48) = 0;
    *(_DWORD *)(v3 + 52) = 0;
    *(_DWORD *)(v3 + 4) = sub_486130;
  }
  return result;
}
