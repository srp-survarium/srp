unsigned int *__cdecl png_do_pack(unsigned int *a1, _BYTE *a2, int a3)
{
  unsigned int *result; // eax
  unsigned int v4; // [esp+0h] [ebp-58h]
  int v5; // [esp+Ch] [ebp-4Ch]
  unsigned int v6; // [esp+10h] [ebp-48h]
  _BYTE *v7; // [esp+14h] [ebp-44h]
  _BYTE *v8; // [esp+18h] [ebp-40h]
  unsigned int k; // [esp+1Ch] [ebp-3Ch]
  int v10; // [esp+20h] [ebp-38h]
  int v11; // [esp+28h] [ebp-30h]
  unsigned int v12; // [esp+2Ch] [ebp-2Ch]
  _BYTE *v13; // [esp+30h] [ebp-28h]
  _BYTE *v14; // [esp+34h] [ebp-24h]
  unsigned int j; // [esp+38h] [ebp-20h]
  int v16; // [esp+3Ch] [ebp-1Ch]
  unsigned int v17; // [esp+40h] [ebp-18h]
  _BYTE *v18; // [esp+44h] [ebp-14h]
  int v19; // [esp+48h] [ebp-10h]
  _BYTE *v20; // [esp+4Ch] [ebp-Ch]
  unsigned int i; // [esp+50h] [ebp-8h]
  char v22; // [esp+54h] [ebp-4h]

  result = a1;
  if ( *((_BYTE *)a1 + 9) == 8 )
  {
    result = (unsigned int *)*((unsigned __int8 *)a1 + 10);
    if ( result == (unsigned int *)1 )
    {
      switch ( a3 )
      {
        case 1:
          v17 = *a1;
          v20 = a2;
          v18 = a2;
          v19 = 128;
          v22 = 0;
          for ( i = 0; i < v17; ++i )
          {
            if ( *v20 )
              v22 |= v19;
            ++v20;
            if ( v19 <= 1 )
            {
              v19 = 128;
              *v18++ = v22;
              v22 = 0;
            }
            else
            {
              v19 >>= 1;
            }
          }
          if ( v19 != 128 )
            *v18 = v22;
          break;
        case 2:
          v12 = *a1;
          v14 = a2;
          v13 = a2;
          v11 = 6;
          v16 = 0;
          for ( j = 0; j < v12; ++j )
          {
            v16 |= (*v14 & 3) << v11;
            if ( v11 )
            {
              v11 -= 2;
            }
            else
            {
              v11 = 6;
              *v13++ = v16;
              v16 = 0;
            }
            ++v14;
          }
          if ( v11 != 6 )
            *v13 = v16;
          break;
        case 4:
          v6 = *a1;
          v8 = a2;
          v7 = a2;
          v5 = 4;
          v10 = 0;
          for ( k = 0; k < v6; ++k )
          {
            v10 |= (*v8 & 0xF) << v5;
            if ( v5 )
            {
              v5 -= 4;
            }
            else
            {
              v5 = 4;
              *v7++ = v10;
              v10 = 0;
            }
            ++v8;
          }
          if ( v5 != 4 )
            *v7 = v10;
          break;
      }
      *((_BYTE *)a1 + 9) = a3;
      *((_BYTE *)a1 + 11) = a3 * *((_BYTE *)a1 + 10);
      if ( *((unsigned __int8 *)a1 + 11) < 8u )
        v4 = (*a1 * *((unsigned __int8 *)a1 + 11) + 7) >> 3;
      else
        v4 = *a1 * (*((unsigned __int8 *)a1 + 11) >> 3);
      result = a1;
      a1[1] = v4;
    }
  }
  return result;
}
