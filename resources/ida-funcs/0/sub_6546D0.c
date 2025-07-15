int __cdecl sub_6546D0(int a1, int a2, int a3, unsigned __int8 **a4)
{
  int v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+10h] [ebp-4h]
  unsigned __int8 *v8; // [esp+20h] [ebp+Ch]
  unsigned __int8 *v9; // [esp+24h] [ebp+10h]

  v8 = (unsigned __int8 *)(a2 + 2);
  v9 = (unsigned __int8 *)(a3 - 2);
  while ( v8 != v9 )
  {
    if ( v8[1] )
      v7 = sub_64FDE0(v8[1], *v8);
    else
      v7 = *(unsigned __int8 *)(a1 + *v8 + 76);
    switch ( v7 )
    {
      case 9:
      case 10:
      case 13:
      case 14:
      case 15:
      case 16:
      case 17:
      case 18:
      case 19:
      case 23:
      case 24:
      case 25:
      case 27:
      case 30:
      case 31:
      case 32:
      case 33:
      case 34:
      case 35:
        goto LABEL_2;
      case 21:
        if ( v8[1] || *v8 != 9 )
          goto LABEL_2;
        *a4 = v8;
        return 0;
      case 22:
      case 26:
        if ( v8[1] )
          v6 = -1;
        else
          v6 = (char)*v8;
        if ( (v6 & 0xFFFFFF80) != 0 )
          goto LABEL_16;
        goto LABEL_2;
      default:
LABEL_16:
        if ( v8[1] )
          v5 = -1;
        else
          v5 = (char)*v8;
        if ( v5 != 36 && v5 != 64 )
        {
          *a4 = v8;
          return 0;
        }
LABEL_2:
        v8 += 2;
        break;
    }
  }
  return 1;
}
