int __cdecl sub_64E820(int a1, _BYTE *a2, int a3)
{
  int v4; // [esp+8h] [ebp-4h]
  _BYTE *v5; // [esp+18h] [ebp+Ch]
  _BYTE *v6; // [esp+18h] [ebp+Ch]
  _BYTE *v7; // [esp+18h] [ebp+Ch]
  _BYTE *v8; // [esp+18h] [ebp+Ch]
  _BYTE *v9; // [esp+18h] [ebp+Ch]

  v4 = a3 - (_DWORD)a2;
  if ( a3 - (_DWORD)a2 == 2 )
  {
    if ( a2[1] == 116 )
    {
      if ( *a2 == 103 )
        return 62;
      if ( *a2 == 108 )
        return 60;
    }
  }
  else if ( v4 == 3 )
  {
    if ( *a2 == 97 )
    {
      v5 = a2 + 1;
      if ( *v5 == 109 && v5[1] == 112 )
        return 38;
    }
  }
  else if ( v4 == 4 )
  {
    if ( *a2 == 97 )
    {
      v8 = a2 + 1;
      if ( *v8 == 112 )
      {
        v9 = v8 + 1;
        if ( *v9 == 111 && v9[1] == 115 )
          return 39;
      }
    }
    else if ( *a2 == 113 )
    {
      v6 = a2 + 1;
      if ( *v6 == 117 )
      {
        v7 = v6 + 1;
        if ( *v7 == 111 && v7[1] == 116 )
          return 34;
      }
    }
  }
  return 0;
}
