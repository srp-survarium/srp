void __cdecl sub_482D70(int a1)
{
  int v1; // esi

  v1 = *(_DWORD *)(a1 + 408);
  if ( *(_DWORD *)(v1 + 16) )
  {
    if ( *(_BYTE *)(a1 + 73) && sub_4825E0(a1) )
    {
      *(_DWORD *)(v1 + 12) = sub_482740;
      *(_DWORD *)(a1 + 136) = 0;
      return;
    }
    *(_DWORD *)(v1 + 12) = sub_482450;
  }
  *(_DWORD *)(a1 + 136) = 0;
}
