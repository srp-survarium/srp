int __cdecl sub_530640(int a1, _BYTE *a2, int a3, _DWORD *a4)
{
  char v5; // [esp+0h] [ebp-10h]
  int v6; // [esp+Ch] [ebp-4h]
  _BYTE *v7; // [esp+1Ch] [ebp+Ch]

  v6 = 0;
  *a4 = 11;
  if ( a3 - (_DWORD)a2 != 3 )
    return 1;
  if ( *a2 == 88 )
  {
    v6 = 1;
  }
  else if ( *a2 != 120 )
  {
    return 1;
  }
  v7 = a2 + 1;
  if ( *v7 == 77 )
  {
    v6 = 1;
  }
  else if ( *v7 != 109 )
  {
    return 1;
  }
  v5 = v7[1];
  if ( v5 == 76 )
  {
    v6 = 1;
  }
  else if ( v5 != 108 )
  {
    return 1;
  }
  if ( v6 )
    return 0;
  *a4 = 12;
  return 1;
}
