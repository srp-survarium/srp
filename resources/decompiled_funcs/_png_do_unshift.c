int __cdecl png_do_unshift(int a1, _BYTE *a2, unsigned __int8 *a3)
{
  int result; // eax
  int v4; // [esp+4h] [ebp-64h]
  int v5; // [esp+8h] [ebp-60h]
  unsigned __int8 *v6; // [esp+Ch] [ebp-5Ch]
  unsigned int v7; // [esp+10h] [ebp-58h]
  int v8; // [esp+14h] [ebp-54h]
  int v9; // [esp+18h] [ebp-50h]
  _BYTE *v10; // [esp+1Ch] [ebp-4Ch]
  unsigned int v11; // [esp+20h] [ebp-48h]
  char v12; // [esp+28h] [ebp-40h]
  char v13; // [esp+2Ch] [ebp-3Ch]
  _BYTE *v14; // [esp+30h] [ebp-38h]
  unsigned int v15; // [esp+34h] [ebp-34h]
  _BYTE *v16; // [esp+3Ch] [ebp-2Ch]
  unsigned int v17; // [esp+40h] [ebp-28h]
  int i; // [esp+44h] [ebp-24h]
  int v19; // [esp+48h] [ebp-20h]
  _DWORD v20[4]; // [esp+4Ch] [ebp-1Ch]
  int v21; // [esp+5Ch] [ebp-Ch]
  int v22; // [esp+60h] [ebp-8h]
  int v23; // [esp+64h] [ebp-4h]

  result = a1;
  v23 = *(unsigned __int8 *)(a1 + 8);
  if ( v23 != 3 )
  {
    v22 = 0;
    v21 = *(unsigned __int8 *)(a1 + 9);
    if ( (v23 & 2) != 0 )
    {
      v20[v22++] = v21 - *a3;
      v20[v22++] = v21 - a3[1];
      v20[v22] = v21 - a3[2];
    }
    else
    {
      v20[v22] = v21 - a3[3];
    }
    ++v22;
    if ( (v23 & 4) != 0 )
      v20[v22++] = v21 - a3[4];
    v19 = 0;
    for ( i = 0; ; ++i )
    {
      result = i;
      if ( i >= v22 )
        break;
      if ( (int)v20[i] > 0 && v20[i] < v21 )
        v19 = 1;
      else
        v20[i] = 0;
    }
    if ( v19 )
    {
      result = v21 - 2;
      switch ( v21 )
      {
        case 2:
          v16 = a2;
          v17 = (unsigned int)&a2[*(_DWORD *)(a1 + 4)];
          while ( 1 )
          {
            result = (int)v16;
            if ( (unsigned int)v16 >= v17 )
              break;
            *v16 = ((int)(unsigned __int8)*v16 >> 1) & 0x55;
            ++v16;
          }
          break;
        case 4:
          v14 = a2;
          v15 = (unsigned int)&a2[*(_DWORD *)(a1 + 4)];
          v12 = v20[0];
          result = (15 >> SLOBYTE(v20[0])) | (16 * (15 >> SLOBYTE(v20[0])));
          v13 = result;
          while ( (unsigned int)v14 < v15 )
          {
            *v14 = v13 & ((int)(unsigned __int8)*v14 >> v12);
            result = (int)++v14;
          }
          break;
        case 8:
          v10 = a2;
          result = (int)&a2[*(_DWORD *)(a1 + 4)];
          v11 = result;
          v9 = 0;
          while ( (unsigned int)v10 < v11 )
          {
            v8 = (int)(unsigned __int8)*v10 >> v20[v9++];
            if ( v9 >= v22 )
              v9 = 0;
            *v10 = v8;
            result = (int)++v10;
          }
          break;
        case 16:
          v6 = a2;
          result = (int)&a2[*(_DWORD *)(a1 + 4)];
          v7 = result;
          v5 = 0;
          while ( (unsigned int)v6 < v7 )
          {
            v4 = (v6[1] + (*v6 << 8)) >> v20[v5++];
            if ( v5 >= v22 )
              v5 = 0;
            *v6 = BYTE1(v4);
            result = (int)(v6 + 1);
            v6[1] = v4;
            v6 += 2;
          }
          break;
        default:
          return result;
      }
    }
  }
  return result;
}
