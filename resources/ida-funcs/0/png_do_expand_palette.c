unsigned int *__cdecl png_do_expand_palette(unsigned int *a1, int a2, int a3, int a4, int a5)
{
  unsigned int *result; // eax
  char v6; // [esp+0h] [ebp-1Ch]
  int v7; // [esp+4h] [ebp-18h]
  int v8; // [esp+4h] [ebp-18h]
  int v9; // [esp+4h] [ebp-18h]
  unsigned int v10; // [esp+8h] [ebp-14h]
  bool *v11; // [esp+Ch] [ebp-10h]
  _BYTE *v12; // [esp+Ch] [ebp-10h]
  _BYTE *v13; // [esp+Ch] [ebp-10h]
  _BYTE *v14; // [esp+Ch] [ebp-10h]
  _BYTE *v15; // [esp+Ch] [ebp-10h]
  _BYTE *v16; // [esp+Ch] [ebp-10h]
  _BYTE *v17; // [esp+Ch] [ebp-10h]
  unsigned __int8 *v18; // [esp+10h] [ebp-Ch]
  unsigned __int8 *v19; // [esp+10h] [ebp-Ch]
  unsigned __int8 *v20; // [esp+10h] [ebp-Ch]
  unsigned __int8 *v21; // [esp+10h] [ebp-Ch]
  unsigned __int8 *v22; // [esp+10h] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp-8h]
  unsigned int j; // [esp+14h] [ebp-8h]
  unsigned int k; // [esp+14h] [ebp-8h]
  unsigned int n; // [esp+14h] [ebp-8h]
  unsigned int m; // [esp+14h] [ebp-8h]

  v10 = *a1;
  result = (unsigned int *)*((unsigned __int8 *)a1 + 8);
  if ( result == (unsigned int *)3 )
  {
    if ( *((unsigned __int8 *)a1 + 9) < 8u )
    {
      v6 = *((_BYTE *)a1 + 9);
      switch ( v6 )
      {
        case 1:
          v18 = (unsigned __int8 *)(a2 + ((v10 - 1) >> 3));
          v11 = (bool *)(a2 + v10 - 1);
          v7 = 7 - (((_BYTE)v10 + 7) & 7);
          for ( i = 0; i < v10; ++i )
          {
            *v11 = (((int)*v18 >> v7) & 1) != 0;
            if ( v7 == 7 )
            {
              v7 = 0;
              --v18;
            }
            else
            {
              ++v7;
            }
            --v11;
          }
          break;
        case 2:
          v19 = (unsigned __int8 *)(a2 + ((v10 - 1) >> 2));
          v12 = (_BYTE *)(a2 + v10 - 1);
          v8 = 2 * (3 - (((_BYTE)v10 + 3) & 3));
          for ( j = 0; j < v10; ++j )
          {
            *v12 = ((int)*v19 >> v8) & 3;
            if ( v8 == 6 )
            {
              v8 = 0;
              --v19;
            }
            else
            {
              v8 += 2;
            }
            --v12;
          }
          break;
        case 4:
          v20 = (unsigned __int8 *)(a2 + ((v10 - 1) >> 1));
          v13 = (_BYTE *)(a2 + v10 - 1);
          v9 = 4 * (*a1 & 1);
          for ( k = 0; k < v10; ++k )
          {
            *v13 = ((int)*v20 >> v9) & 0xF;
            if ( v9 == 4 )
            {
              v9 = 0;
              --v20;
            }
            else
            {
              v9 += 4;
            }
            --v13;
          }
          break;
      }
      *((_BYTE *)a1 + 9) = 8;
      *((_BYTE *)a1 + 11) = 8;
      a1[1] = v10;
    }
    result = a1;
    if ( *((_BYTE *)a1 + 9) == 8 )
    {
      if ( a5 <= 0 )
      {
        v22 = (unsigned __int8 *)(a2 + v10 - 1);
        v16 = (_BYTE *)(a2 + 3 * v10 - 1);
        for ( m = 0; m < v10; ++m )
        {
          *v16 = *(_BYTE *)(a3 + 3 * *v22 + 2);
          v17 = v16 - 1;
          *v17-- = *(_BYTE *)(a3 + 3 * *v22 + 1);
          *v17 = *(_BYTE *)(a3 + 3 * *v22);
          v16 = v17 - 1;
          --v22;
        }
        *((_BYTE *)a1 + 9) = 8;
        *((_BYTE *)a1 + 11) = 24;
        result = a1;
        a1[1] = 3 * v10;
        *((_BYTE *)a1 + 8) = 2;
        *((_BYTE *)a1 + 10) = 3;
      }
      else
      {
        v21 = (unsigned __int8 *)(a2 + v10 - 1);
        v14 = (_BYTE *)(a2 + 4 * v10 - 1);
        for ( n = 0; n < v10; ++n )
        {
          if ( *v21 < a5 )
            *v14 = *(_BYTE *)(a4 + *v21);
          else
            *v14 = -1;
          v15 = v14 - 1;
          *v15-- = *(_BYTE *)(a3 + 3 * *v21 + 2);
          *v15-- = *(_BYTE *)(a3 + 3 * *v21 + 1);
          *v15 = *(_BYTE *)(a3 + 3 * *v21);
          v14 = v15 - 1;
          --v21;
        }
        *((_BYTE *)a1 + 9) = 8;
        *((_BYTE *)a1 + 11) = 32;
        result = a1;
        a1[1] = 4 * v10;
        *((_BYTE *)a1 + 8) = 6;
        *((_BYTE *)a1 + 10) = 4;
      }
    }
  }
  return result;
}
