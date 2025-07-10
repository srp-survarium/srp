int __cdecl sub_5335E0(int a1, char *a2, char *a3)
{
  int v3; // edx
  int v4; // ecx
  int result; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  char *v14; // [esp+14h] [ebp+Ch]
  char *v15; // [esp+18h] [ebp+10h]

  while ( 2 )
  {
    switch ( *(_BYTE *)(a1 + (unsigned __int8)*a2 + 76) )
    {
      case 5:
        goto LABEL_6;
      case 6:
        goto LABEL_4;
      case 7:
        v3 = *a3;
        v4 = *a2;
        ++a3;
        ++a2;
        if ( v4 != v3 )
          return 0;
LABEL_4:
        v6 = *a3;
        v7 = *a2;
        ++a3;
        ++a2;
        if ( v7 != v6 )
          return 0;
LABEL_6:
        v8 = *a3;
        v9 = *a2;
        v15 = a3 + 1;
        v14 = a2 + 1;
        if ( v9 != v8 )
          return 0;
        v10 = *v15;
        v11 = *v14;
        a3 = v15 + 1;
        a2 = v14 + 1;
        if ( v11 == v10 )
          continue;
        return 0;
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1A:
      case 0x1B:
      case 0x1D:
        v12 = *a2;
        v13 = *a3;
        ++a2;
        ++a3;
        if ( v13 == v12 )
          continue;
        return 0;
      default:
        if ( *a2 == *a3 )
          return 1;
        switch ( *(_BYTE *)(a1 + (unsigned __int8)*a3 + 76) )
        {
          case 5:
          case 6:
          case 7:
          case 0x16:
          case 0x17:
          case 0x18:
          case 0x19:
          case 0x1A:
          case 0x1B:
          case 0x1D:
            result = 0;
            break;
          default:
            result = 1;
            break;
        }
        return result;
    }
  }
}
