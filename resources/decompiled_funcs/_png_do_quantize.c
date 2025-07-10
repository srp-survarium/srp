unsigned int __cdecl png_do_quantize(unsigned int a1, unsigned __int8 *a2, int a3, int a4)
{
  unsigned int result; // eax
  int v5; // [esp+0h] [ebp-38h]
  int v6; // [esp+4h] [ebp-34h]
  int v7; // [esp+8h] [ebp-30h]
  int v8; // [esp+Ch] [ebp-2Ch]
  int v9; // [esp+10h] [ebp-28h]
  int v10; // [esp+18h] [ebp-20h]
  int v11; // [esp+1Ch] [ebp-1Ch]
  int v12; // [esp+20h] [ebp-18h]
  unsigned int v13; // [esp+28h] [ebp-10h]
  unsigned __int8 *v14; // [esp+2Ch] [ebp-Ch]
  unsigned __int8 *v15; // [esp+2Ch] [ebp-Ch]
  unsigned __int8 *v16; // [esp+30h] [ebp-8h]
  unsigned __int8 *v17; // [esp+30h] [ebp-8h]
  unsigned __int8 *v18; // [esp+30h] [ebp-8h]
  unsigned __int8 *v19; // [esp+30h] [ebp-8h]
  unsigned __int8 *v20; // [esp+30h] [ebp-8h]
  unsigned int i; // [esp+34h] [ebp-4h]
  unsigned int j; // [esp+34h] [ebp-4h]
  unsigned int k; // [esp+34h] [ebp-4h]

  v13 = *(_DWORD *)a1;
  result = *(unsigned __int8 *)(a1 + 9);
  if ( result == 8 )
  {
    if ( *(_BYTE *)(a1 + 8) == 2 && a3 )
    {
      v16 = a2;
      v14 = a2;
      for ( i = 0; i < v13; ++i )
      {
        v10 = *v16;
        v17 = v16 + 1;
        v11 = *v17++;
        v12 = *v17;
        v16 = v17 + 1;
        *v14++ = *(_BYTE *)(((v12 >> 3) & 0x1F | (32 * ((v11 >> 3) & 0x1F)) | (((v10 >> 3) & 0x1F) << 10)) + a3);
      }
      *(_BYTE *)(a1 + 8) = 3;
      *(_BYTE *)(a1 + 10) = 1;
      *(_BYTE *)(a1 + 11) = *(_BYTE *)(a1 + 9);
      if ( *(unsigned __int8 *)(a1 + 11) < 8u )
      {
        result = (v13 * *(unsigned __int8 *)(a1 + 11) + 7) >> 3;
        v6 = result;
      }
      else
      {
        result = a1;
        v6 = v13 * (*(unsigned __int8 *)(a1 + 11) >> 3);
      }
      *(_DWORD *)(a1 + 4) = v6;
    }
    else if ( *(_BYTE *)(a1 + 8) == 6 && a3 )
    {
      v18 = a2;
      v15 = a2;
      for ( j = 0; j < v13; ++j )
      {
        v7 = *v18;
        v19 = v18 + 1;
        v8 = *v19++;
        v9 = *v19;
        v18 = v19 + 2;
        *v15++ = *(_BYTE *)(((v9 >> 3) & 0x1F | (32 * ((v8 >> 3) & 0x1F)) | (((v7 >> 3) & 0x1F) << 10)) + a3);
      }
      *(_BYTE *)(a1 + 8) = 3;
      *(_BYTE *)(a1 + 10) = 1;
      *(_BYTE *)(a1 + 11) = *(_BYTE *)(a1 + 9);
      if ( *(unsigned __int8 *)(a1 + 11) < 8u )
      {
        result = (v13 * *(unsigned __int8 *)(a1 + 11) + 7) >> 3;
        v5 = result;
      }
      else
      {
        result = a1;
        v5 = v13 * (*(unsigned __int8 *)(a1 + 11) >> 3);
      }
      *(_DWORD *)(a1 + 4) = v5;
    }
    else
    {
      result = a1;
      if ( *(_BYTE *)(a1 + 8) == 3 && a4 )
      {
        v20 = a2;
        for ( k = 0; k < v13; ++k )
        {
          *v20 = *(_BYTE *)(a4 + *v20);
          result = k + 1;
          ++v20;
        }
      }
    }
  }
  return result;
}
