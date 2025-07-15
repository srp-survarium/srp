int __cdecl sub_6479B0(int a1, int a2, int a3, int a4)
{
  int v5; // [esp+0h] [ebp-20h]
  int v6; // [esp+4h] [ebp-1Ch]
  int v7; // [esp+8h] [ebp-18h]
  int j; // [esp+Ch] [ebp-14h]
  int i; // [esp+10h] [ebp-10h]
  int v10; // [esp+14h] [ebp-Ch]
  _BYTE *v11; // [esp+14h] [ebp-Ch]
  _DWORD *v12; // [esp+18h] [ebp-8h]
  int v13; // [esp+1Ch] [ebp-4h]

  v12 = *(_DWORD **)(a1 + 356);
  if ( v12[23] != v12[22] || (unsigned __int8)sub_649210(v12 + 20) )
  {
    *(_BYTE *)v12[23]++ = 0;
    v7 = 1;
  }
  else
  {
    v7 = 0;
  }
  if ( !v7 )
    return 0;
  v10 = sub_6491A0(v12 + 20, a2, a3, a4);
  if ( !v10 )
    return 0;
  v11 = (_BYTE *)(v10 + 1);
  v13 = sub_648950(a1, v12 + 10, v11, 12);
  if ( !v13 )
    return 0;
  if ( *(_BYTE **)v13 == v11 )
  {
    v12[24] = v12[23];
    if ( *(_BYTE *)(a1 + 236) )
    {
      if ( *v11 == 120 && v11[1] == 109 && v11[2] == 108 && v11[3] == 110 && v11[4] == 115 && (!v11[5] || v11[5] == 58) )
      {
        if ( v11[5] )
          *(_DWORD *)(v13 + 4) = sub_648950(a1, v12 + 15, v11 + 6, 8);
        else
          *(_DWORD *)(v13 + 4) = v12 + 38;
        *(_BYTE *)(v13 + 9) = 1;
      }
      else
      {
        for ( i = 0; v11[i]; ++i )
        {
          if ( v11[i] == 58 )
          {
            for ( j = 0; j < i; ++j )
            {
              if ( v12[23] != v12[22] || (unsigned __int8)sub_649210(v12 + 20) )
              {
                *(_BYTE *)v12[23]++ = v11[j];
                v6 = 1;
              }
              else
              {
                v6 = 0;
              }
              if ( !v6 )
                return 0;
            }
            if ( v12[23] != v12[22] || (unsigned __int8)sub_649210(v12 + 20) )
            {
              *(_BYTE *)v12[23]++ = 0;
              v5 = 1;
            }
            else
            {
              v5 = 0;
            }
            if ( !v5 )
              return 0;
            *(_DWORD *)(v13 + 4) = sub_648950(a1, v12 + 15, v12[24], 8);
            if ( **(_DWORD **)(v13 + 4) == v12[24] )
              v12[24] = v12[23];
            else
              v12[23] = v12[24];
            return v13;
          }
        }
      }
    }
  }
  else
  {
    v12[23] = v12[24];
  }
  return v13;
}
