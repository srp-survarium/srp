int __cdecl XML_StopParser(int a1, char a2)
{
  int v3; // [esp+0h] [ebp-4h]

  v3 = *(_DWORD *)(a1 + 480);
  if ( v3 == 2 )
  {
    *(_DWORD *)(a1 + 284) = 36;
    return 0;
  }
  if ( v3 == 3 )
  {
    if ( a2 )
    {
      *(_DWORD *)(a1 + 284) = 33;
      return 0;
    }
    *(_DWORD *)(a1 + 480) = 2;
  }
  else if ( a2 )
  {
    if ( *(_BYTE *)(a1 + 488) )
    {
      *(_DWORD *)(a1 + 284) = 37;
      return 0;
    }
    *(_DWORD *)(a1 + 480) = 3;
  }
  else
  {
    *(_DWORD *)(a1 + 480) = 2;
  }
  return 1;
}
