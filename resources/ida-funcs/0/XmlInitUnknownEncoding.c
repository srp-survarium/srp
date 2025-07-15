_DWORD *__cdecl XmlInitUnknownEncoding(_DWORD *a1, int a2, int a3, int a4)
{
  __int16 v5; // [esp+0h] [ebp-10h]
  int v6; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]
  int j; // [esp+Ch] [ebp-4h]
  int k; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 368; ++i )
    *((_BYTE *)a1 + i) = *((_BYTE *)off_88B138 + i);
  for ( j = 0; j < 128; ++j )
  {
    if ( byte_88B184[j] != 28 && byte_88B184[j] && *(_DWORD *)(a2 + 4 * j) != j )
      return 0;
  }
  for ( k = 0; k < 256; ++k )
  {
    v6 = *(_DWORD *)(a2 + 4 * k);
    if ( v6 == -1 )
    {
      *((_BYTE *)a1 + k + 76) = 1;
      *((_WORD *)a1 + k + 188) = -1;
      LOBYTE(a1[k + 222]) = 1;
      BYTE1(a1[k + 222]) = 0;
    }
    else if ( v6 >= 0 )
    {
      if ( v6 >= 128 )
      {
        if ( sub_53FD00(v6) >= 0 )
        {
          if ( v6 > 0xFFFF )
            return 0;
          if ( (dword_88A300[8 * (unsigned __int8)byte_88A800[v6 >> 8] + ((int)(unsigned __int8)v6 >> 5)]
              & (1 << (v6 & 0x1F))) != 0 )
          {
            *((_BYTE *)a1 + k + 76) = 22;
          }
          else if ( (dword_88A300[8 * (unsigned __int8)byte_88A900[v6 >> 8] + ((int)(unsigned __int8)v6 >> 5)]
                   & (1 << (v6 & 0x1F))) != 0 )
          {
            *((_BYTE *)a1 + k + 76) = 26;
          }
          else
          {
            *((_BYTE *)a1 + k + 76) = 28;
          }
          LOBYTE(a1[k + 222]) = XmlUtf8Encode(v6, (_BYTE *)&a1[k + 222] + 1);
          *((_WORD *)a1 + k + 188) = v6;
        }
        else
        {
          *((_BYTE *)a1 + k + 76) = 0;
          *((_WORD *)a1 + k + 188) = -1;
          LOBYTE(a1[k + 222]) = 1;
          BYTE1(a1[k + 222]) = 0;
        }
      }
      else
      {
        if ( byte_88B184[v6] != 28 && byte_88B184[v6] && v6 != k )
          return 0;
        *((_BYTE *)a1 + k + 76) = byte_88B184[v6];
        LOBYTE(a1[k + 222]) = 1;
        BYTE1(a1[k + 222]) = v6;
        if ( v6 )
          v5 = v6;
        else
          v5 = -1;
        *((_WORD *)a1 + k + 188) = v5;
      }
    }
    else
    {
      if ( v6 < -4 )
        return 0;
      *((_BYTE *)a1 + k + 76) = 5 - (v6 + 2);
      LOBYTE(a1[k + 222]) = 0;
      *((_WORD *)a1 + k + 188) = 0;
    }
  }
  a1[93] = a4;
  a1[92] = a3;
  if ( a3 )
  {
    a1[83] = sub_540250;
    a1[84] = sub_540250;
    a1[85] = sub_540250;
    a1[86] = sub_5402D0;
    a1[87] = sub_5402D0;
    a1[88] = sub_5402D0;
    a1[89] = sub_540350;
    a1[90] = sub_540350;
    a1[91] = sub_540350;
  }
  a1[15] = sub_5403B0;
  a1[16] = sub_5404C0;
  return a1;
}
