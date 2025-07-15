BOOL __cdecl sub_6467E0(int a1, int a2, char a3, int a4, int a5, _DWORD *a6)
{
  int v7; // [esp+0h] [ebp-8h]
  int v8; // [esp+4h] [ebp-4h]

  v8 = sub_6468B0(a1, a2, a3, a4, a5, a6);
  if ( v8 )
    return v8;
  if ( !a3 && a6[3] != a6[4] && *(_BYTE *)(a6[3] - 1) == 32 )
    --a6[3];
  if ( a6[3] != a6[2] || (unsigned __int8)sub_649210(a6) )
  {
    *(_BYTE *)a6[3]++ = 0;
    v7 = 1;
  }
  else
  {
    v7 = 0;
  }
  return v7 == 0;
}
