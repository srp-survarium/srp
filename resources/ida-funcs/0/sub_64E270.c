int __cdecl sub_64E270(int a1, int a2, int a3, _DWORD *a4)
{
  _BYTE *v5; // [esp+14h] [ebp+Ch]
  _BYTE *v6; // [esp+18h] [ebp+10h]

  v5 = (_BYTE *)(a2 + 1);
  v6 = (_BYTE *)(a3 - 1);
  while ( v5 != v6 )
  {
    switch ( *(_BYTE *)(a1 + (unsigned __int8)*v5 + 76) )
    {
      case 9:
      case 0xA:
      case 0xD:
      case 0xE:
      case 0xF:
      case 0x10:
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1B:
      case 0x1E:
      case 0x1F:
      case 0x20:
      case 0x21:
      case 0x22:
      case 0x23:
        goto LABEL_2;
      case 0x15:
        if ( *v5 != 9 )
          goto LABEL_2;
        *a4 = v5;
        return 0;
      case 0x16:
      case 0x1A:
        if ( ((char)*v5 & 0xFFFFFF80) != 0 )
          goto LABEL_9;
        goto LABEL_2;
      default:
LABEL_9:
        if ( *v5 != 36 && *v5 != 64 )
        {
          *a4 = v5;
          return 0;
        }
LABEL_2:
        ++v5;
        break;
    }
  }
  return 1;
}
