int __cdecl png_do_read_intrapixel(_BYTE *a1, _BYTE *a2)
{
  int result; // eax
  int v3; // [esp+0h] [ebp-2Ch]
  __int16 v4; // [esp+8h] [ebp-24h]
  int v5; // [esp+10h] [ebp-1Ch]
  unsigned __int8 *v6; // [esp+14h] [ebp-18h]
  unsigned int v7; // [esp+18h] [ebp-14h]
  _BYTE *v8; // [esp+1Ch] [ebp-10h]
  unsigned int v9; // [esp+20h] [ebp-Ch]
  unsigned int v10; // [esp+24h] [ebp-8h]
  int v11; // [esp+28h] [ebp-4h]
  int v12; // [esp+28h] [ebp-4h]

  result = (int)a1;
  if ( (a1[8] & 2) != 0 )
  {
    v10 = *(_DWORD *)a1;
    if ( a1[9] == 8 )
    {
      result = (int)a1;
      if ( a1[8] == 2 )
      {
        v11 = 3;
      }
      else
      {
        result = (unsigned __int8)a1[8];
        if ( result != 6 )
          return result;
        v11 = 4;
      }
      v9 = 0;
      v8 = a2;
      while ( v9 < v10 )
      {
        *v8 += v8[1];
        v8[2] += v8[1];
        ++v9;
        result = (int)&v8[v11];
        v8 += v11;
      }
    }
    else
    {
      result = (unsigned __int8)a1[9];
      if ( result != 16 )
        return result;
      if ( a1[8] == 2 )
      {
        v12 = 6;
      }
      else
      {
        result = (int)a1;
        if ( a1[8] != 6 )
          return result;
        v12 = 8;
      }
      v7 = 0;
      v6 = a2;
      while ( v7 < v10 )
      {
        v5 = v6[1] | (*v6 << 8);
        v3 = v6[3] | (v6[2] << 8);
        v4 = (unsigned __int16)&_sbh_sizeHeaderList + (v6[5] | (v6[4] << 8)) + v3;
        *v6 = (unsigned __int16)((unsigned __int16)&_sbh_sizeHeaderList + v5 + v3) >> 8;
        v6[1] = (unsigned __int8)&_sbh_sizeHeaderList + v5 + v3;
        v6[4] = HIBYTE(v4);
        v6[5] = v4;
        result = ++v7;
        v6 += v12;
      }
    }
  }
  return result;
}
