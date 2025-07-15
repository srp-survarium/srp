int __cdecl sub_646E80(int a1, int a2, int a3, int a4)
{
  _BYTE v5[4]; // [esp+4h] [ebp-2Ch] BYREF
  int i; // [esp+8h] [ebp-28h]
  int v7; // [esp+Ch] [ebp-24h]
  int v8; // [esp+10h] [ebp-20h]
  int v9; // [esp+14h] [ebp-1Ch]
  int v10; // [esp+18h] [ebp-18h] BYREF
  int v11; // [esp+1Ch] [ebp-14h]
  _DWORD *v12; // [esp+20h] [ebp-10h]
  int v13; // [esp+24h] [ebp-Ch]
  int v14; // [esp+28h] [ebp-8h]
  _BYTE *v15; // [esp+2Ch] [ebp-4h]

  v15 = *(_BYTE **)(a1 + 356);
  v12 = v15 + 104;
  v13 = 0;
  v14 = *(_DWORD *)(a1 + 276);
  *(_DWORD *)(a1 + 276) = 1;
  if ( !*v12 && !(unsigned __int8)sub_649210(v12) )
    return 1;
  while ( 2 )
  {
    v11 = ((__int64 (__cdecl *)(int, int, int, int *))*(_DWORD *)(a2 + 20))(a2, a3, a4, &v10);
    switch ( v11 )
    {
      case -4:
        v13 = 0;
        goto LABEL_60;
      case -3:
        v10 = *(_DWORD *)(a2 + 68) + a3;
        goto LABEL_31;
      case -1:
        if ( a2 == *(_DWORD *)(a1 + 144) )
          *(_DWORD *)(a1 + 288) = a3;
        v13 = 4;
        goto LABEL_60;
      case 0:
        if ( a2 == *(_DWORD *)(a1 + 144) )
          *(_DWORD *)(a1 + 288) = v10;
        v13 = 4;
        goto LABEL_60;
      case 6:
      case 9:
        if ( sub_649010(v12, a2, a3, v10) )
          goto LABEL_59;
        v13 = 1;
        goto LABEL_60;
      case 7:
LABEL_31:
        if ( v12[2] == v12[3] && !(unsigned __int8)sub_649210(v12) )
        {
          v13 = 1;
          goto LABEL_60;
        }
        *(_BYTE *)v12[3]++ = 10;
        goto LABEL_59;
      case 10:
        v7 = (*(int (__cdecl **)(int, int))(a2 + 44))(a2, a3);
        if ( v7 >= 0 )
        {
          v7 = XmlUtf8Encode(v7, v5);
          if ( v7 )
          {
            for ( i = 0; ; ++i )
            {
              if ( i >= v7 )
                goto LABEL_59;
              if ( v12[2] == v12[3] && !(unsigned __int8)sub_649210(v12) )
                break;
              *(_BYTE *)v12[3]++ = v5[i];
            }
            v13 = 1;
          }
          else
          {
            if ( a2 == *(_DWORD *)(a1 + 144) )
              *(_DWORD *)(a1 + 288) = a3;
            v13 = 14;
          }
        }
        else
        {
          if ( a2 == *(_DWORD *)(a1 + 144) )
            *(_DWORD *)(a1 + 288) = a3;
          v13 = 14;
        }
        goto LABEL_60;
      case 28:
        if ( !*(_BYTE *)(a1 + 488) && a2 == *(_DWORD *)(a1 + 144) )
        {
          *(_DWORD *)(a1 + 288) = a3;
          v13 = 10;
          goto LABEL_60;
        }
        v8 = sub_6491A0(a1 + 416, a2, *(_DWORD *)(a2 + 68) + a3, v10 - *(_DWORD *)(a2 + 68));
        if ( !v8 )
        {
          v13 = 1;
          goto LABEL_60;
        }
        v9 = sub_648950(a1, v15 + 132, v8, 0);
        *(_DWORD *)(a1 + 428) = *(_DWORD *)(a1 + 432);
        if ( !v9 )
        {
          v15[128] = v15[130];
          goto LABEL_60;
        }
        if ( !*(_BYTE *)(v9 + 32) )
        {
          if ( *(_DWORD *)(v9 + 16) )
          {
            if ( *(_DWORD *)(a1 + 112) )
            {
              v15[131] = 0;
              *(_BYTE *)(v9 + 32) = 1;
              if ( !(*(int (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(a1 + 112))(
                      *(_DWORD *)(a1 + 116),
                      0,
                      *(_DWORD *)(v9 + 20),
                      *(_DWORD *)(v9 + 16),
                      *(_DWORD *)(v9 + 24)) )
              {
                *(_BYTE *)(v9 + 32) = 0;
                v13 = 21;
                goto LABEL_60;
              }
              *(_BYTE *)(v9 + 32) = 0;
              if ( !v15[131] )
                v15[128] = v15[130];
            }
            else
            {
              v15[128] = v15[130];
            }
          }
          else
          {
            *(_BYTE *)(v9 + 32) = 1;
            v13 = sub_646E80(a1, *(_DWORD *)(a1 + 228), *(_DWORD *)(v9 + 4), *(_DWORD *)(v9 + 8) + *(_DWORD *)(v9 + 4));
            *(_BYTE *)(v9 + 32) = 0;
            if ( v13 )
              goto LABEL_60;
          }
LABEL_59:
          a3 = v10;
          continue;
        }
        if ( a2 == *(_DWORD *)(a1 + 144) )
          *(_DWORD *)(a1 + 288) = a3;
        v13 = 12;
LABEL_60:
        *(_DWORD *)(a1 + 276) = v14;
        return v13;
      default:
        if ( a2 == *(_DWORD *)(a1 + 144) )
          *(_DWORD *)(a1 + 288) = a3;
        v13 = 23;
        goto LABEL_60;
    }
  }
}
