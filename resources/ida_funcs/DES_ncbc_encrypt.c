int __cdecl DES_ncbc_encrypt(int *a1, int a2, int a3, _DWORD *a4, int *a5, int a6)
{
  int v6; // esi
  unsigned int v9; // ebp
  int result; // eax
  int v11; // ebx
  int v12; // ebx
  int v13; // ecx
  int v14; // edx
  unsigned int v15; // ebp
  int v16; // ebx
  int v17; // edx
  int v18; // ebx
  int v19; // ecx
  int v20; // edx
  int *v21; // [esp-Ch] [ebp-2Ch]
  _DWORD *v22; // [esp-8h] [ebp-28h]
  int v23; // [esp-4h] [ebp-24h]
  int v24; // [esp+0h] [ebp-20h] BYREF
  int v25; // [esp+4h] [ebp-1Ch]
  int v26; // [esp+8h] [ebp-18h]
  int v27; // [esp+Ch] [ebp-14h]

  v6 = *a5;
  v27 = a5[1];
  v26 = v6;
  v25 = v27;
  v24 = v6;
  v23 = a6;
  v22 = a4;
  v21 = &v24;
  if ( a6 )
  {
    v9 = a3 & 0xFFFFFFF8;
    result = v24;
    v11 = v25;
    if ( (a3 & 0xFFFFFFF8) != 0 )
    {
      do
      {
        v12 = a1[1] ^ v11;
        v24 = *a1 ^ result;
        v25 = v12;
        DES_encrypt1(v21, v22, v23);
        result = v24;
        v11 = v25;
        *(_DWORD *)a2 = v24;
        *(_DWORD *)(a2 + 4) = v11;
        a1 += 2;
        a2 += 8;
        v9 -= 8;
      }
      while ( v9 );
    }
    v13 = 0;
    v14 = 0;
    switch ( a3 & 7 )
    {
      case 0:
        goto $L019ej1;
      case 1:
        goto $L018ej2;
      case 2:
        BYTE1(v13) = *((_BYTE *)a1 + 2);
        v13 <<= 8;
$L018ej2:
        BYTE1(v13) = *((_BYTE *)a1 + 1);
$L019ej1:
        LOBYTE(v13) = *(_BYTE *)a1;
        goto $L016ejend;
      case 3:
        goto $L015ej4;
      case 4:
        goto $L014ej5;
      case 5:
        goto $L013ej6;
      case 6:
        BYTE1(v14) = *((_BYTE *)a1 + 6);
        v14 <<= 8;
$L013ej6:
        BYTE1(v14) = *((_BYTE *)a1 + 5);
$L014ej5:
        LOBYTE(v14) = *((_BYTE *)a1 + 4);
$L015ej4:
        v13 = *a1;
$L016ejend:
        v24 = v13 ^ result;
        v25 = v14 ^ v11;
        DES_encrypt1(v21, v22, v23);
        result = v24;
        v11 = v25;
        *(_DWORD *)a2 = v24;
        *(_DWORD *)(a2 + 4) = v11;
        break;
      default:
        break;
    }
  }
  else
  {
    v15 = a3 & 0xFFFFFFF8;
    result = v26;
    v11 = v27;
    if ( (a3 & 0xFFFFFFF8) != 0 )
    {
      do
      {
        v16 = a1[1];
        v24 = *a1;
        v25 = v16;
        DES_encrypt1(v21, v22, v23);
        v17 = v25 ^ v27;
        result = *a1;
        v11 = a1[1];
        *(_DWORD *)a2 = v24 ^ v26;
        *(_DWORD *)(a2 + 4) = v17;
        v26 = result;
        v27 = v11;
        a1 += 2;
        a2 += 8;
        v15 -= 8;
      }
      while ( v15 );
    }
    if ( (a3 & 7) != 0 )
    {
      v18 = a1[1];
      v24 = *a1;
      v25 = v18;
      DES_encrypt1(v21, v22, v23);
      v19 = v24 ^ v26;
      result = *a1;
      v11 = a1[1];
      v20 = __ROR4__(v25 ^ v27, 16);
      *(_BYTE *)(a2 + 6) = v20;
      *(_WORD *)(a2 + 4) = HIWORD(v20);
      *(_DWORD *)a2 = v19;
    }
  }
  *a5 = result;
  a5[1] = v11;
  return result;
}
