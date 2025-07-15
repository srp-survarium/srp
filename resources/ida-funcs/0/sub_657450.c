int __cdecl sub_657450(int a1, _BYTE *a2, int a3, _DWORD *a4)
{
  int v5; // [esp+4h] [ebp-18h]
  int v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+14h] [ebp-8h]
  int v8; // [esp+18h] [ebp-4h]
  _BYTE *v9; // [esp+28h] [ebp+Ch]
  _BYTE *v10; // [esp+28h] [ebp+Ch]

  v8 = 0;
  *a4 = 11;
  if ( a3 - (_DWORD)a2 != 6 )
    return 1;
  if ( *a2 )
    v7 = -1;
  else
    v7 = (char)a2[1];
  if ( v7 == 88 )
  {
    v8 = 1;
  }
  else if ( v7 != 120 )
  {
    return 1;
  }
  v9 = a2 + 2;
  if ( *v9 )
    v6 = -1;
  else
    v6 = (char)v9[1];
  if ( v6 == 77 )
  {
    v8 = 1;
  }
  else if ( v6 != 109 )
  {
    return 1;
  }
  v10 = v9 + 2;
  if ( *v10 )
    v5 = -1;
  else
    v5 = (char)v10[1];
  if ( v5 == 76 )
  {
    v8 = 1;
  }
  else if ( v5 != 108 )
  {
    return 1;
  }
  if ( v8 )
    return 0;
  *a4 = 12;
  return 1;
}
