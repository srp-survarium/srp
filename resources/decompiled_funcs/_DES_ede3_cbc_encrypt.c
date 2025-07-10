int __cdecl DES_ede3_cbc_encrypt(int *a1, int a2, int a3, _DWORD *a4, _DWORD *a5, _DWORD *a6, int *a7, int a8)
{
  int v8; // esi
  unsigned int v11; // ebp
  int result; // eax
  int v13; // ebx
  int v14; // ebx
  int v15; // ecx
  int v16; // edx
  unsigned int v17; // ebp
  int v18; // ebx
  int v19; // edx
  int v20; // ebx
  int v21; // ecx
  int v22; // edx
  int *v23; // [esp-10h] [ebp-30h]
  _DWORD *v24; // [esp-Ch] [ebp-2Ch]
  _DWORD *v25; // [esp-8h] [ebp-28h]
  _DWORD *v26; // [esp-4h] [ebp-24h]
  int v27; // [esp+0h] [ebp-20h] BYREF
  int v28; // [esp+4h] [ebp-1Ch]
  int v29; // [esp+8h] [ebp-18h]
  int v30; // [esp+Ch] [ebp-14h]

  v8 = *a7;
  v30 = a7[1];
  v29 = v8;
  v28 = v30;
  v27 = v8;
  v26 = a6;
  v25 = a5;
  v24 = a4;
  v23 = &v27;
  if ( a8 )
  {
    v11 = a3 & 0xFFFFFFF8;
    result = v27;
    v13 = v28;
    if ( (a3 & 0xFFFFFFF8) != 0 )
    {
      do
      {
        v14 = a1[1] ^ v13;
        v27 = *a1 ^ result;
        v28 = v14;
        DES_encrypt3(v23, v24, v25, v26);
        result = v27;
        v13 = v28;
        *(_DWORD *)a2 = v27;
        *(_DWORD *)(a2 + 4) = v13;
        a1 += 2;
        a2 += 8;
        v11 -= 8;
      }
      while ( v11 );
    }
    v15 = 0;
    v16 = 0;
    switch ( a3 & 7 )
    {
      case 0:
        goto $L043ej1;
      case 1:
        goto $L042ej2;
      case 2:
        BYTE1(v15) = *((_BYTE *)a1 + 2);
        v15 <<= 8;
$L042ej2:
        BYTE1(v15) = *((_BYTE *)a1 + 1);
$L043ej1:
        LOBYTE(v15) = *(_BYTE *)a1;
        goto $L040ejend;
      case 3:
        goto $L039ej4;
      case 4:
        goto $L038ej5;
      case 5:
        goto $L037ej6;
      case 6:
        BYTE1(v16) = *((_BYTE *)a1 + 6);
        v16 <<= 8;
$L037ej6:
        BYTE1(v16) = *((_BYTE *)a1 + 5);
$L038ej5:
        LOBYTE(v16) = *((_BYTE *)a1 + 4);
$L039ej4:
        v15 = *a1;
$L040ejend:
        v27 = v15 ^ result;
        v28 = v16 ^ v13;
        DES_encrypt3(v23, v24, v25, v26);
        result = v27;
        v13 = v28;
        *(_DWORD *)a2 = v27;
        *(_DWORD *)(a2 + 4) = v13;
        break;
      default:
        break;
    }
  }
  else
  {
    v17 = a3 & 0xFFFFFFF8;
    result = v29;
    v13 = v30;
    if ( (a3 & 0xFFFFFFF8) != 0 )
    {
      do
      {
        v18 = a1[1];
        v27 = *a1;
        v28 = v18;
        DES_decrypt3(v23, v24, v25, v26);
        v19 = v28 ^ v30;
        result = *a1;
        v13 = a1[1];
        *(_DWORD *)a2 = v27 ^ v29;
        *(_DWORD *)(a2 + 4) = v19;
        v29 = result;
        v30 = v13;
        a1 += 2;
        a2 += 8;
        v17 -= 8;
      }
      while ( v17 );
    }
    if ( (a3 & 7) != 0 )
    {
      v20 = a1[1];
      v27 = *a1;
      v28 = v20;
      DES_decrypt3(v23, v24, v25, v26);
      v21 = v27 ^ v29;
      result = *a1;
      v13 = a1[1];
      v22 = __ROR4__(v28 ^ v30, 16);
      *(_BYTE *)(a2 + 6) = v22;
      *(_WORD *)(a2 + 4) = HIWORD(v22);
      *(_DWORD *)a2 = v21;
    }
  }
  *a7 = result;
  a7[1] = v13;
  return result;
}
