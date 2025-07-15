int __cdecl sub_6468B0(_DWORD *a1, int a2, char a3, int a4, int a5, _DWORD *a6)
{
  bool v7; // [esp+0h] [ebp-4Ch]
  bool v8; // [esp+4h] [ebp-48h]
  int v10; // [esp+Ch] [ebp-40h]
  int v11; // [esp+10h] [ebp-3Ch]
  int v12; // [esp+14h] [ebp-38h]
  int v13; // [esp+1Ch] [ebp-30h]
  int v14; // [esp+20h] [ebp-2Ch]
  char v15; // [esp+27h] [ebp-25h]
  int v16; // [esp+28h] [ebp-24h]
  int v17; // [esp+2Ch] [ebp-20h]
  bool v18; // [esp+33h] [ebp-19h]
  _BYTE v19[4]; // [esp+34h] [ebp-18h] BYREF
  int i; // [esp+38h] [ebp-14h]
  int v21; // [esp+3Ch] [ebp-10h]
  int v22; // [esp+40h] [ebp-Ch] BYREF
  int v23; // [esp+44h] [ebp-8h]
  int v24; // [esp+48h] [ebp-4h]

  v24 = a1[89];
  while ( 2 )
  {
    v23 = (*(int (__cdecl **)(int, int, int, int *))(a2 + 16))(a2, a4, a5, &v22);
    switch ( v23 )
    {
      case -4:
        return 0;
      case -3:
        v22 = *(_DWORD *)(a2 + 68) + a4;
        goto LABEL_37;
      case -1:
        if ( a2 == a1[36] )
          a1[72] = a4;
        return 4;
      case 0:
        if ( a2 == a1[36] )
          a1[72] = v22;
        return 4;
      case 6:
        if ( sub_649010(a6, a2, a4, v22) )
          goto LABEL_97;
        return 1;
      case 7:
      case 39:
LABEL_37:
        if ( !a3 && (a6[3] == a6[4] || *(_BYTE *)(a6[3] - 1) == 32) )
          goto LABEL_97;
        if ( a6[3] != a6[2] || (unsigned __int8)sub_649210(a6) )
        {
          *(_BYTE *)a6[3]++ = 32;
          v11 = 1;
        }
        else
        {
          v11 = 0;
        }
        if ( v11 )
          goto LABEL_97;
        return 1;
      case 9:
        v15 = (*(int (__cdecl **)(int, int, int))(a2 + 48))(a2, *(_DWORD *)(a2 + 68) + a4, v22 - *(_DWORD *)(a2 + 68));
        if ( v15 )
        {
          if ( a6[3] != a6[2] || (unsigned __int8)sub_649210(a6) )
          {
            *(_BYTE *)a6[3]++ = v15;
            v10 = 1;
          }
          else
          {
            v10 = 0;
          }
          if ( !v10 )
            return 1;
        }
        else
        {
          v16 = sub_6491A0(a1 + 110, a2, *(_DWORD *)(a2 + 68) + a4, v22 - *(_DWORD *)(a2 + 68));
          if ( !v16 )
            return 1;
          v17 = sub_648950(a1, v24, v16, 0);
          a1[113] = a1[114];
          if ( a6 == (_DWORD *)(v24 + 80) )
          {
            v8 = 0;
            if ( a1[68] )
            {
              if ( *(_BYTE *)(v24 + 130) ? a1[75] == 0 : *(_BYTE *)(v24 + 129) == 0 )
                v8 = 1;
            }
            v18 = v8;
          }
          else
          {
            v7 = !*(_BYTE *)(v24 + 129) || *(_BYTE *)(v24 + 130);
            v18 = v7;
          }
          if ( v18 )
          {
            if ( !v17 )
              return 11;
            if ( !*(_BYTE *)(v17 + 34) )
              return 24;
          }
          else if ( !v17 )
          {
            goto LABEL_97;
          }
          if ( *(_BYTE *)(v17 + 32) )
          {
            if ( a2 == a1[36] )
              a1[72] = a4;
            return 12;
          }
          if ( *(_DWORD *)(v17 + 28) )
          {
            if ( a2 == a1[36] )
              a1[72] = a4;
            return 15;
          }
          if ( !*(_DWORD *)(v17 + 4) )
          {
            if ( a2 == a1[36] )
              a1[72] = a4;
            return 16;
          }
          v14 = *(_DWORD *)(v17 + 8) + *(_DWORD *)(v17 + 4);
          *(_BYTE *)(v17 + 32) = 1;
          v13 = sub_6468B0(a1, a1[57], a3, *(_DWORD *)(v17 + 4), v14, a6);
          *(_BYTE *)(v17 + 32) = 0;
          if ( v13 )
            return v13;
        }
        goto LABEL_97;
      case 10:
        v21 = (*(int (__cdecl **)(int, int))(a2 + 44))(a2, a4);
        if ( v21 < 0 )
        {
          if ( a2 == a1[36] )
            a1[72] = a4;
          return 14;
        }
        if ( !a3 && v21 == 32 && (a6[3] == a6[4] || *(_BYTE *)(a6[3] - 1) == 32) )
        {
LABEL_97:
          a4 = v22;
          continue;
        }
        v21 = XmlUtf8Encode(v21, v19);
        if ( v21 )
        {
          for ( i = 0; ; ++i )
          {
            if ( i >= v21 )
              goto LABEL_97;
            if ( a6[3] != a6[2] || (unsigned __int8)sub_649210(a6) )
            {
              *(_BYTE *)a6[3]++ = v19[i];
              v12 = 1;
            }
            else
            {
              v12 = 0;
            }
            if ( !v12 )
              break;
          }
          return 1;
        }
        else
        {
          if ( a2 == a1[36] )
            a1[72] = a4;
          return 14;
        }
      default:
        if ( a2 == a1[36] )
          a1[72] = a4;
        return 23;
    }
  }
}
