int __cdecl AES_decrypt(__m64 *a1, __m64 *a2, __m64 *a3)
{
  void *v3; // esp
  int v4; // ebx
  char *v5; // ebp
  __m64 m64_u64; // mm0
  __m64 v7; // mm4
  int result; // eax
  int v9; // ebx
  int v10; // ecx
  int v11; // edx
  _DWORD v12[9]; // [esp+0h] [ebp-34h] BYREF
  int v13; // [esp+24h] [ebp-10h] BYREF

  v3 = alloca(((char *)v12 - ((char *)&a3[-16].m64_u64 + 1)) & 0x3C0);
  v12[8] = &v13;
  v12[0] = 8153711;
  v4 = ((_WORD)v3 + 764 - (unsigned __int16)_LAES_Td) & 0x300;
  v5 = (char *)_LAES_Td + v4 + (_DWORD)&loc_7C72EF - 8153711;
  if ( _bittest((const signed __int32 *)&OPENSSL_ia32cap_P, 0x19u) )
  {
    m64_u64 = (__m64)a1->m64_u64;
    v7 = a1[1];
    result = _sse_AES_decrypt_compact((int)v5, a3, (__m64)a1->m64_u64, v7);
    a2->m64_u64 = (unsigned __int64)m64_u64;
    a2[1].m64_u64 = (unsigned __int64)v7;
    _m_empty();
  }
  else
  {
    v12[7] = (char *)_LAES_Td + v4 + (_DWORD)&loc_7C72EF - 8153711;
    v9 = a1->m64_i32[1];
    result = _x86_AES_decrypt_compact(
               a1->m64_i32[0],
               a1[1].m64_i32[1],
               a1[1].m64_i32[0],
               v9,
               (int)v5,
               a3,
               v12[1],
               v12[2],
               v12[3],
               v12[4],
               v12[5],
               v12[6],
               (int)v5);
    a2->m64_i32[0] = result;
    a2->m64_i32[1] = v9;
    a2[1].m64_i32[0] = v10;
    a2[1].m64_i32[1] = v11;
  }
  return result;
}
