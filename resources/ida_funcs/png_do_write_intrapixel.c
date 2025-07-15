int __cdecl png_do_write_intrapixel(_BYTE *a1, _BYTE *a2)
{
  int result; // eax
  __int16 v3; // [esp+8h] [ebp-24h]
  __int16 v4; // [esp+Ch] [ebp-20h]
  _BYTE *v5; // [esp+14h] [ebp-18h]
  unsigned int v6; // [esp+18h] [ebp-14h]
  _BYTE *v7; // [esp+1Ch] [ebp-10h]
  unsigned int v8; // [esp+20h] [ebp-Ch]
  unsigned int v9; // [esp+24h] [ebp-8h]
  int v10; // [esp+28h] [ebp-4h]
  int v11; // [esp+28h] [ebp-4h]

  result = (int)a1;
  if ( (a1[8] & 2) != 0 )
  {
    v9 = *(_DWORD *)a1;
    if ( a1[9] == 8 )
    {
      result = (int)a1;
      if ( a1[8] == 2 )
      {
        v10 = 3;
      }
      else
      {
        result = (unsigned __int8)a1[8];
        if ( result != 6 )
          return result;
        v10 = 4;
      }
      v8 = 0;
      v7 = a2;
      while ( v8 < v9 )
      {
        *v7 -= v7[1];
        v7[2] -= v7[1];
        ++v8;
        result = (int)&v7[v10];
        v7 += v10;
      }
    }
    else
    {
      result = (unsigned __int8)a1[9];
      if ( result != 16 )
        return result;
      if ( a1[8] == 2 )
      {
        v11 = 6;
      }
      else
      {
        result = (int)a1;
        if ( a1[8] != 6 )
          return result;
        v11 = 8;
      }
      v6 = 0;
      v5 = a2;
      while ( v6 < v9 )
      {
        v4 = _byteswap_ushort(*(_WORD *)v5) - _byteswap_ushort(*((_WORD *)v5 + 1));
        v3 = _byteswap_ushort(*((_WORD *)v5 + 2)) - _byteswap_ushort(*((_WORD *)v5 + 1));
        *v5 = HIBYTE(v4);
        v5[1] = v4;
        v5[4] = HIBYTE(v3);
        v5[5] = v3;
        result = ++v6;
        v5 += v11;
      }
    }
  }
  return result;
}
