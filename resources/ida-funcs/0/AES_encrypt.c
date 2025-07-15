void __cdecl AES_encrypt(__m64 *a1, __m64 *a2, __m64 *a3)
{
  void *v3; // esp
  int v4; // ebx
  char *v5; // ebp
  unsigned __int64 m64_u64; // mm0
  __m64 v7; // mm4
  int v8; // ebx
  int v9; // ecx
  int v10; // edx
  _DWORD v11[9]; // [esp+0h] [ebp-34h] BYREF
  int v12; // [esp+24h] [ebp-10h] BYREF

  v3 = alloca(((char *)v11 - ((char *)&a3[-16].m64_u64 + 1)) & 0x3C0);
  v11[8] = &v12;
  v11[0] = 8148015;
  v4 = ((_WORD)v3 + 764 - (unsigned __int16)_LAES_Te) & 0x300;
  v5 = (char *)_LAES_Te + v4 + (_DWORD)&loc_7C5CAD - 8148013;
  if ( _bittest((const signed __int32 *)&OPENSSL_ia32cap_P, 0x19u) )
  {
    m64_u64 = a1->m64_u64;
    v7 = a1[1];
    _sse_AES_encrypt_compact((int)v5, a3, (__m64)a1->m64_u64, v7);
    a2->m64_u64 = m64_u64;
    a2[1].m64_u64 = (unsigned __int64)v7;
    _m_empty();
  }
  else
  {
    v11[7] = (char *)_LAES_Te + v4 + (_DWORD)&loc_7C5CAD - 8148013;
    v8 = a1->m64_i32[1];
    a2->m64_i32[0] = _x86_AES_encrypt_compact(
                       a1->m64_i32[0],
                       a1[1].m64_i32[1],
                       a1[1].m64_i32[0],
                       v8,
                       (int)v5,
                       a3,
                       v11[1],
                       v11[2],
                       v11[3],
                       v11[4],
                       v11[5],
                       v11[6],
                       (int)v5);
    a2->m64_i32[1] = v8;
    a2[1].m64_i32[0] = v9;
    a2[1].m64_i32[1] = v10;
  }
}
