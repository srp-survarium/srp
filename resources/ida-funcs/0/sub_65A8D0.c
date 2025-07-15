int __cdecl sub_65A8D0(int a1, _BYTE *a2, int a3)
{
  int v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+Ch] [ebp-8h]
  int v6; // [esp+10h] [ebp-4h]
  _BYTE *v7; // [esp+20h] [ebp+Ch]
  _BYTE *v8; // [esp+20h] [ebp+Ch]
  _BYTE *v9; // [esp+20h] [ebp+Ch]
  _BYTE *v10; // [esp+20h] [ebp+Ch]
  _BYTE *v11; // [esp+20h] [ebp+Ch]
  _BYTE *v12; // [esp+20h] [ebp+Ch]
  _BYTE *v13; // [esp+20h] [ebp+Ch]
  _BYTE *v14; // [esp+20h] [ebp+Ch]

  v6 = (a3 - (int)a2) / 2;
  switch ( v6 )
  {
    case 2:
      if ( !a2[2] && a2[3] == 116 )
      {
        if ( *a2 )
          v5 = -1;
        else
          v5 = (char)a2[1];
        if ( v5 == 103 )
          return 62;
        if ( v5 == 108 )
          return 60;
      }
      break;
    case 3:
      if ( !*a2 && a2[1] == 97 )
      {
        v7 = a2 + 2;
        if ( !*v7 && v7[1] == 109 )
        {
          v8 = v7 + 2;
          if ( !*v8 && v8[1] == 112 )
            return 38;
        }
      }
      break;
    case 4:
      if ( *a2 )
        v4 = -1;
      else
        v4 = (char)a2[1];
      if ( v4 == 97 )
      {
        v12 = a2 + 2;
        if ( !*v12 && v12[1] == 112 )
        {
          v13 = v12 + 2;
          if ( !*v13 && v13[1] == 111 )
          {
            v14 = v13 + 2;
            if ( !*v14 && v14[1] == 115 )
              return 39;
          }
        }
      }
      else if ( v4 == 113 )
      {
        v9 = a2 + 2;
        if ( !*v9 && v9[1] == 117 )
        {
          v10 = v9 + 2;
          if ( !*v10 && v10[1] == 111 )
          {
            v11 = v10 + 2;
            if ( !*v11 && v11[1] == 116 )
              return 34;
          }
        }
      }
      break;
  }
  return 0;
}
