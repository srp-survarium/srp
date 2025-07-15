int __cdecl XML_ParseBuffer(int a1, int a2, int a3)
{
  int v4; // [esp+0h] [ebp-10h]
  int v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h]

  v6 = 1;
  v5 = *(_DWORD *)(a1 + 480);
  if ( v5 )
  {
    if ( v5 == 2 )
    {
      *(_DWORD *)(a1 + 284) = 36;
      return 0;
    }
    if ( v5 == 3 )
    {
      *(_DWORD *)(a1 + 284) = 33;
      return 0;
    }
  }
  else if ( !*(_DWORD *)(a1 + 476) && !sub_640730(a1) )
  {
    *(_DWORD *)(a1 + 284) = 1;
    return 0;
  }
  *(_DWORD *)(a1 + 480) = 1;
  v7 = *(_DWORD *)(a1 + 24);
  *(_DWORD *)(a1 + 296) = v7;
  *(_DWORD *)(a1 + 28) += a2;
  *(_DWORD *)(a1 + 40) = *(_DWORD *)(a1 + 28);
  *(_DWORD *)(a1 + 36) += a2;
  *(_BYTE *)(a1 + 484) = a3;
  *(_DWORD *)(a1 + 284) = (*(int (__cdecl **)(int, int, _DWORD, int))(a1 + 280))(a1, v7, *(_DWORD *)(a1 + 40), a1 + 24);
  if ( *(_DWORD *)(a1 + 284) )
  {
    *(_DWORD *)(a1 + 292) = *(_DWORD *)(a1 + 288);
    *(_DWORD *)(a1 + 280) = XML_GetErrorCode;
    return 0;
  }
  v4 = *(_DWORD *)(a1 + 480);
  if ( v4 >= 0 )
  {
    if ( v4 <= 1 )
    {
      if ( a3 )
      {
        *(_DWORD *)(a1 + 480) = 2;
        return 1;
      }
    }
    else if ( v4 == 3 )
    {
      v6 = 2;
    }
  }
  (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD, int))(*(_DWORD *)(a1 + 144) + 52))(
    *(_DWORD *)(a1 + 144),
    *(_DWORD *)(a1 + 296),
    *(_DWORD *)(a1 + 24),
    a1 + 408);
  *(_DWORD *)(a1 + 296) = *(_DWORD *)(a1 + 24);
  return v6;
}
