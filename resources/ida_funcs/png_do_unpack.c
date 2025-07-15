unsigned int *__cdecl png_do_unpack(unsigned int *a1, int a2)
{
  unsigned int *result; // eax
  char v3; // [esp+0h] [ebp-30h]
  int v4; // [esp+4h] [ebp-2Ch]
  _BYTE *v5; // [esp+8h] [ebp-28h]
  unsigned __int8 *v6; // [esp+Ch] [ebp-24h]
  int v7; // [esp+10h] [ebp-20h]
  _BYTE *v8; // [esp+14h] [ebp-1Ch]
  unsigned __int8 *v9; // [esp+18h] [ebp-18h]
  int v10; // [esp+1Ch] [ebp-14h]
  _BYTE *v11; // [esp+20h] [ebp-10h]
  unsigned __int8 *v12; // [esp+24h] [ebp-Ch]
  unsigned int v13; // [esp+28h] [ebp-8h]
  unsigned int i; // [esp+2Ch] [ebp-4h]
  unsigned int j; // [esp+2Ch] [ebp-4h]
  unsigned int k; // [esp+2Ch] [ebp-4h]

  result = a1;
  if ( *((unsigned __int8 *)a1 + 9) < 8u )
  {
    v13 = *a1;
    v3 = *((_BYTE *)a1 + 9);
    switch ( v3 )
    {
      case 1:
        v12 = (unsigned __int8 *)(a2 + ((v13 - 1) >> 3));
        v11 = (_BYTE *)(a2 + v13 - 1);
        v10 = 7 - (((_BYTE)v13 + 7) & 7);
        for ( i = 0; i < v13; ++i )
        {
          *v11 = ((int)*v12 >> v10) & 1;
          if ( v10 == 7 )
          {
            v10 = 0;
            --v12;
          }
          else
          {
            ++v10;
          }
          --v11;
        }
        break;
      case 2:
        v9 = (unsigned __int8 *)(a2 + ((v13 - 1) >> 2));
        v8 = (_BYTE *)(a2 + v13 - 1);
        v7 = 2 * (3 - (((_BYTE)v13 + 3) & 3));
        for ( j = 0; j < v13; ++j )
        {
          *v8 = ((int)*v9 >> v7) & 3;
          if ( v7 == 6 )
          {
            v7 = 0;
            --v9;
          }
          else
          {
            v7 += 2;
          }
          --v8;
        }
        break;
      case 4:
        v6 = (unsigned __int8 *)(a2 + ((v13 - 1) >> 1));
        v5 = (_BYTE *)(a2 + v13 - 1);
        v4 = 4 * (1 - (((_BYTE)v13 + 1) & 1));
        for ( k = 0; k < v13; ++k )
        {
          *v5 = ((int)*v6 >> v4) & 0xF;
          if ( v4 == 4 )
          {
            v4 = 0;
            --v6;
          }
          else
          {
            v4 = 4;
          }
          --v5;
        }
        break;
    }
    *((_BYTE *)a1 + 9) = 8;
    *((_BYTE *)a1 + 11) = 8 * *((_BYTE *)a1 + 10);
    result = a1;
    a1[1] = v13 * *((unsigned __int8 *)a1 + 10);
  }
  return result;
}
