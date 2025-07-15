void __cdecl sub_3760B0(int a1)
{
  int v1; // esi

  v1 = *(_DWORD *)(a1 + 408);
  if ( *(_DWORD *)(v1 + 16) )
  {
    if ( *(_BYTE *)(a1 + 73) && sub_375920(a1) )
    {
      *(_DWORD *)(v1 + 12) = sub_375A80;
      *(_DWORD *)(a1 + 136) = 0;
      return;
    }
    *(_DWORD *)(v1 + 12) = sub_375790;
  }
  *(_DWORD *)(a1 + 136) = 0;
}
