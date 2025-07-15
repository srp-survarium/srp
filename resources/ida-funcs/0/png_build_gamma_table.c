int __cdecl png_build_gamma_table(int a1, int a2)
{
  int result; // eax
  int v3; // eax
  int v4; // eax
  int v5; // [esp+0h] [ebp-18h]
  int v6; // [esp+4h] [ebp-14h]
  int v7; // [esp+8h] [ebp-10h]
  int v8; // [esp+Ch] [ebp-Ch]
  int v9; // [esp+10h] [ebp-8h]
  unsigned __int8 v10; // [esp+16h] [ebp-2h]
  unsigned __int8 v11; // [esp+17h] [ebp-1h]

  if ( *(_DWORD *)(a1 + 384) || *(_DWORD *)(a1 + 388) )
  {
    png_warning(a1, "gamma table being rebuilt");
    png_destroy_gamma_table(a1);
  }
  if ( a2 > 8 )
  {
    if ( (*(_BYTE *)(a1 + 315) & 2) != 0 )
    {
      v11 = *(_BYTE *)(a1 + 408);
      if ( *(unsigned __int8 *)(a1 + 409) > (int)v11 )
        v11 = *(_BYTE *)(a1 + 409);
      if ( *(unsigned __int8 *)(a1 + 410) > (int)v11 )
        v11 = *(_BYTE *)(a1 + 410);
    }
    else
    {
      v11 = *(_BYTE *)(a1 + 411);
    }
    if ( v11 && v11 < 0x10u )
      v10 = 16 - v11;
    else
      v10 = 0;
    if ( (*(_DWORD *)(a1 + 116) & 0x4000400) != 0 && v10 < 5u )
      v10 = 5;
    if ( v10 > 8u )
      v10 = 8;
    *(_DWORD *)(a1 + 372) = v10;
    if ( (*(_DWORD *)(a1 + 116) & 0x4000400) != 0 )
    {
      if ( *(int *)(a1 + 380) <= 0 )
      {
        sub_464F00(a1, a1 + 388, v10, 100000);
      }
      else
      {
        v7 = sub_464CB0(*(_DWORD *)(a1 + 376), *(_DWORD *)(a1 + 380));
        sub_464F00(a1, a1 + 388, v10, v7);
      }
    }
    else if ( *(int *)(a1 + 380) <= 0 )
    {
      sub_464D20(a1, a1 + 388, v10, 100000);
    }
    else
    {
      v6 = png_reciprocal2(*(_DWORD *)(a1 + 376), *(_DWORD *)(a1 + 380));
      sub_464D20(a1, a1 + 388, v10, v6);
    }
    result = a1;
    if ( ((unsigned int)&loc_600080 & *(_DWORD *)(a1 + 116)) != 0 )
    {
      v4 = png_reciprocal(*(_DWORD *)(a1 + 376));
      sub_464D20(a1, a1 + 404, v10, v4);
      if ( *(int *)(a1 + 380) <= 0 )
      {
        return sub_464D20(a1, a1 + 400, v10, *(_DWORD *)(a1 + 376));
      }
      else
      {
        v5 = png_reciprocal(*(_DWORD *)(a1 + 380));
        return sub_464D20(a1, a1 + 400, v10, v5);
      }
    }
  }
  else
  {
    if ( *(int *)(a1 + 380) <= 0 )
    {
      sub_465080(a1, a1 + 384, 100000);
    }
    else
    {
      v9 = png_reciprocal2(*(_DWORD *)(a1 + 376), *(_DWORD *)(a1 + 380));
      sub_465080(a1, a1 + 384, v9);
    }
    result = a1;
    if ( ((unsigned int)&loc_600080 & *(_DWORD *)(a1 + 116)) != 0 )
    {
      v3 = png_reciprocal(*(_DWORD *)(a1 + 376));
      sub_465080(a1, a1 + 396, v3);
      if ( *(int *)(a1 + 380) <= 0 )
      {
        return sub_465080(a1, a1 + 392, *(_DWORD *)(a1 + 376));
      }
      else
      {
        v8 = png_reciprocal(*(_DWORD *)(a1 + 380));
        return sub_465080(a1, a1 + 392, v8);
      }
    }
  }
  return result;
}
