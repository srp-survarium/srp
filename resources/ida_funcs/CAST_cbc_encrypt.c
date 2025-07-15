unsigned __int32 __cdecl CAST_cbc_encrypt(int *a1, int a2, int a3, _DWORD *a4, unsigned __int32 *a5, int a6)
{
  unsigned int v6; // esi
  unsigned int v9; // ebp
  unsigned __int32 result; // eax
  unsigned __int32 v11; // ebx
  unsigned __int32 v12; // ebx
  int v13; // ecx
  int v14; // edx
  unsigned int v15; // ebp
  unsigned __int32 v16; // ebx
  unsigned __int32 v17; // edx
  unsigned __int32 v18; // ebx
  unsigned __int32 v19; // ecx
  int v20; // edx
  unsigned int *v21; // [esp-8h] [ebp-28h]
  _DWORD *v22; // [esp-4h] [ebp-24h]
  unsigned int v23; // [esp+0h] [ebp-20h] BYREF
  unsigned int v24; // [esp+4h] [ebp-1Ch]
  unsigned int v25; // [esp+8h] [ebp-18h]
  unsigned int v26; // [esp+Ch] [ebp-14h]

  v6 = *a5;
  v26 = a5[1];
  v25 = v6;
  v24 = v26;
  v23 = v6;
  v22 = a4;
  v21 = &v23;
  if ( a6 )
  {
    v9 = a3 & 0xFFFFFFF8;
    result = v23;
    v11 = v24;
    if ( (a3 & 0xFFFFFFF8) != 0 )
    {
      do
      {
        v12 = _byteswap_ulong(a1[1] ^ v11);
        v23 = _byteswap_ulong(*a1 ^ result);
        v24 = v12;
        CAST_encrypt(v21, v22);
        result = _byteswap_ulong(v23);
        v11 = _byteswap_ulong(v24);
        *(_DWORD *)a2 = result;
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
        goto $L015ej1;
      case 1:
        goto $L014ej2;
      case 2:
        BYTE1(v13) = *((_BYTE *)a1 + 2);
        v13 <<= 8;
$L014ej2:
        BYTE1(v13) = *((_BYTE *)a1 + 1);
$L015ej1:
        LOBYTE(v13) = *(_BYTE *)a1;
        goto $L012ejend;
      case 3:
        goto $L011ej4;
      case 4:
        goto $L010ej5;
      case 5:
        goto $L009ej6;
      case 6:
        BYTE1(v14) = *((_BYTE *)a1 + 6);
        v14 <<= 8;
$L009ej6:
        BYTE1(v14) = *((_BYTE *)a1 + 5);
$L010ej5:
        LOBYTE(v14) = *((_BYTE *)a1 + 4);
$L011ej4:
        v13 = *a1;
$L012ejend:
        v23 = _byteswap_ulong(v13 ^ result);
        v24 = _byteswap_ulong(v14 ^ v11);
        CAST_encrypt(v21, v22);
        result = _byteswap_ulong(v23);
        v11 = _byteswap_ulong(v24);
        *(_DWORD *)a2 = result;
        *(_DWORD *)(a2 + 4) = v11;
        break;
      default:
        break;
    }
  }
  else
  {
    v15 = a3 & 0xFFFFFFF8;
    result = v25;
    v11 = v26;
    if ( (a3 & 0xFFFFFFF8) != 0 )
    {
      do
      {
        v16 = _byteswap_ulong(a1[1]);
        v23 = _byteswap_ulong(*a1);
        v24 = v16;
        CAST_decrypt(v21, v22);
        v17 = _byteswap_ulong(v24) ^ v26;
        result = *a1;
        v11 = a1[1];
        *(_DWORD *)a2 = _byteswap_ulong(v23) ^ v25;
        *(_DWORD *)(a2 + 4) = v17;
        v25 = result;
        v26 = v11;
        a1 += 2;
        a2 += 8;
        v15 -= 8;
      }
      while ( v15 );
    }
    if ( (a3 & 7) != 0 )
    {
      v18 = _byteswap_ulong(a1[1]);
      v23 = _byteswap_ulong(*a1);
      v24 = v18;
      CAST_decrypt(v21, v22);
      v19 = _byteswap_ulong(v23) ^ v25;
      result = *a1;
      v11 = a1[1];
      v20 = __ROR4__(_byteswap_ulong(v24) ^ v26, 16);
      *(_BYTE *)(a2 + 6) = v20;
      *(_WORD *)(a2 + 4) = HIWORD(v20);
      *(_DWORD *)a2 = v19;
    }
  }
  *a5 = result;
  a5[1] = v11;
  return result;
}
