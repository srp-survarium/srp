_WORD **__cdecl sub_533B40(int a1, char **a2, unsigned __int8 *a3, _WORD **a4, _WORD *a5)
{
  _WORD **result; // eax
  char v6; // [esp+0h] [ebp-10h]
  unsigned int v7; // [esp+4h] [ebp-Ch]
  char *v8; // [esp+8h] [ebp-8h]
  _WORD *v9; // [esp+Ch] [ebp-4h]

  v9 = *a4;
  v8 = *a2;
  while ( v8 != (char *)a3 && v9 != a5 )
  {
    v6 = *(_BYTE *)(a1 + (unsigned __int8)*v8 + 76);
    switch ( v6 )
    {
      case 5:
        *v9++ = v8[1] & 0x3F | ((*v8 & 0x1F) << 6);
        v8 += 2;
        break;
      case 6:
        *v9++ = v8[2] & 0x3F | ((v8[1] & 0x3F) << 6) | ((*v8 & 0xF) << 12);
        v8 += 3;
        break;
      case 7:
        if ( v9 + 1 == a5 )
          goto LABEL_12;
        v7 = (v8[3] & 0x3F | ((v8[2] & 0x3F) << 6) | ((v8[1] & 0x3F) << 12) | ((*v8 & 7) << 18))
           - (_DWORD)&_sbh_sizeHeaderList;
        *v9 = (v7 >> 10) | 0xD800;
        v9[1] = v7 & 0x3FF | 0xDC00;
        v9 += 2;
        v8 += 4;
        break;
      default:
        *v9++ = *v8++;
        break;
    }
  }
LABEL_12:
  *a2 = v8;
  result = a4;
  *a4 = v9;
  return result;
}
