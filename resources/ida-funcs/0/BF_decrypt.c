int __cdecl BF_decrypt(int a1, int a2)
{
  int v2; // ecx
  int v3; // esi
  int v4; // edi
  int v5; // ecx
  int v6; // esi
  int v7; // edi
  int v8; // esi
  int v9; // edi
  int v10; // esi
  int v11; // edi
  int v12; // esi
  int v13; // edi
  int v14; // esi
  int v15; // edi
  int v16; // esi
  int v17; // edi
  int v18; // esi
  int result; // eax
  int v20; // edi
  int v21; // esi

  v2 = (unsigned __int8)((unsigned __int16)(*(_WORD *)(a2 + 68) ^ *(_WORD *)a1) >> 8);
  v3 = (*(_DWORD *)(a2 + 4 * (unsigned __int8)(*(_BYTE *)(a2 + 68) ^ *(_BYTE *)a1) + 3144)
      + (*(_DWORD *)(a2 + 4 * v2 + 2120)
       ^ (*(_DWORD *)(a2 + 4 * ((unsigned int)(*(_DWORD *)(a2 + 68) ^ *(_DWORD *)a1) >> 24) + 72)
        + *(_DWORD *)(a2 + 4 * (unsigned __int8)((unsigned int)(*(_DWORD *)(a2 + 68) ^ *(_DWORD *)a1) >> 16) + 1096))))
     ^ *(_DWORD *)(a2 + 64)
     ^ *(_DWORD *)(a1 + 4);
  v4 = (*(_DWORD *)(a2
                  + 4
                  * (unsigned __int8)((*(_BYTE *)(a2 + 4 * (unsigned __int8)(*(_BYTE *)(a2 + 68) ^ *(_BYTE *)a1) + 3144)
                                     + (*(_BYTE *)(a2 + 4 * v2 + 2120)
                                      ^ (*(_BYTE *)(a2
                                                  + 4 * ((unsigned int)(*(_DWORD *)(a2 + 68) ^ *(_DWORD *)a1) >> 24)
                                                  + 72)
                                       + *(_BYTE *)(a2
                                                  + 4
                                                  * (unsigned __int8)((unsigned int)(*(_DWORD *)(a2 + 68) ^ *(_DWORD *)a1) >> 16)
                                                  + 1096))))
                                    ^ *(_BYTE *)(a2 + 64)
                                    ^ *(_BYTE *)(a1 + 4))
                  + 3144)
      + (*(_DWORD *)(a2
                   + 4
                   * (unsigned __int8)((unsigned __int16)((*(_WORD *)(a2
                                                                    + 4
                                                                    * (unsigned __int8)(*(_BYTE *)(a2 + 68)
                                                                                      ^ *(_BYTE *)a1)
                                                                    + 3144)
                                                         + (*(_WORD *)(a2 + 4 * v2 + 2120)
                                                          ^ (*(_WORD *)(a2
                                                                      + 4
                                                                      * ((unsigned int)(*(_DWORD *)(a2 + 68)
                                                                                      ^ *(_DWORD *)a1) >> 24)
                                                                      + 72)
                                                           + *(_WORD *)(a2
                                                                      + 4
                                                                      * (unsigned __int8)((unsigned int)(*(_DWORD *)(a2 + 68) ^ *(_DWORD *)a1) >> 16)
                                                                      + 1096))))
                                                        ^ *(_WORD *)(a2 + 64)
                                                        ^ *(_WORD *)(a1 + 4)) >> 8)
                   + 2120)
       ^ (*(_DWORD *)(a2 + 4 * HIBYTE(v3) + 72) + *(_DWORD *)(a2 + 4 * BYTE2(v3) + 1096))))
     ^ *(_DWORD *)(a2 + 60)
     ^ *(_DWORD *)(a2 + 68)
     ^ *(_DWORD *)a1;
  v5 = (unsigned __int8)((unsigned __int16)((*(_WORD *)(a2
                                                      + 4
                                                      * (unsigned __int8)((*(_BYTE *)(a2
                                                                                    + 4
                                                                                    * (unsigned __int8)(*(_BYTE *)(a2 + 68) ^ *(_BYTE *)a1)
                                                                                    + 3144)
                                                                         + (*(_BYTE *)(a2 + 4 * v2 + 2120)
                                                                          ^ (*(_BYTE *)(a2
                                                                                      + 4
                                                                                      * ((unsigned int)(*(_DWORD *)(a2 + 68) ^ *(_DWORD *)a1) >> 24)
                                                                                      + 72)
                                                                           + *(_BYTE *)(a2
                                                                                      + 4
                                                                                      * (unsigned __int8)((unsigned int)(*(_DWORD *)(a2 + 68) ^ *(_DWORD *)a1) >> 16)
                                                                                      + 1096))))
                                                                        ^ *(_BYTE *)(a2 + 64)
                                                                        ^ *(_BYTE *)(a1 + 4))
                                                      + 3144)
                                           + (*(_WORD *)(a2
                                                       + 4
                                                       * (unsigned __int8)((unsigned __int16)((*(_WORD *)(a2 + 4 * (unsigned __int8)(*(_BYTE *)(a2 + 68) ^ *(_BYTE *)a1) + 3144)
                                                                                             + (*(_WORD *)(a2 + 4 * v2 + 2120)
                                                                                              ^ (*(_WORD *)(a2 + 4 * ((unsigned int)(*(_DWORD *)(a2 + 68) ^ *(_DWORD *)a1) >> 24) + 72)
                                                                                               + *(_WORD *)(a2 + 4 * (unsigned __int8)((unsigned int)(*(_DWORD *)(a2 + 68) ^ *(_DWORD *)a1) >> 16) + 1096))))
                                                                                            ^ *(_WORD *)(a2 + 64)
                                                                                            ^ *(_WORD *)(a1 + 4)) >> 8)
                                                       + 2120)
                                            ^ (*(_WORD *)(a2 + 4 * HIBYTE(v3) + 72)
                                             + *(_WORD *)(a2 + 4 * BYTE2(v3) + 1096))))
                                          ^ *(_WORD *)(a2 + 60)
                                          ^ *(_WORD *)(a2 + 68)
                                          ^ *(_WORD *)a1) >> 8);
  v6 = (*(_DWORD *)(a2 + 4 * (unsigned __int8)v4 + 3144)
      + (*(_DWORD *)(a2 + 4 * v5 + 2120)
       ^ (*(_DWORD *)(a2 + 4 * HIBYTE(v4) + 72) + *(_DWORD *)(a2 + 4 * BYTE2(v4) + 1096))))
     ^ *(_DWORD *)(a2 + 56)
     ^ v3;
  LOBYTE(v5) = BYTE1(v6);
  v7 = (*(_DWORD *)(a2 + 4 * (unsigned __int8)v6 + 3144)
      + (*(_DWORD *)(a2 + 4 * v5 + 2120)
       ^ (*(_DWORD *)(a2 + 4 * HIBYTE(v6) + 72) + *(_DWORD *)(a2 + 4 * BYTE2(v6) + 1096))))
     ^ *(_DWORD *)(a2 + 52)
     ^ v4;
  LOBYTE(v5) = BYTE1(v7);
  v8 = (*(_DWORD *)(a2 + 4 * (unsigned __int8)v7 + 3144)
      + (*(_DWORD *)(a2 + 4 * v5 + 2120)
       ^ (*(_DWORD *)(a2 + 4 * HIBYTE(v7) + 72) + *(_DWORD *)(a2 + 4 * BYTE2(v7) + 1096))))
     ^ *(_DWORD *)(a2 + 48)
     ^ v6;
  LOBYTE(v5) = BYTE1(v8);
  v9 = (*(_DWORD *)(a2 + 4 * (unsigned __int8)v8 + 3144)
      + (*(_DWORD *)(a2 + 4 * v5 + 2120)
       ^ (*(_DWORD *)(a2 + 4 * HIBYTE(v8) + 72) + *(_DWORD *)(a2 + 4 * BYTE2(v8) + 1096))))
     ^ *(_DWORD *)(a2 + 44)
     ^ v7;
  LOBYTE(v5) = BYTE1(v9);
  v10 = (*(_DWORD *)(a2 + 4 * (unsigned __int8)v9 + 3144)
       + (*(_DWORD *)(a2 + 4 * v5 + 2120)
        ^ (*(_DWORD *)(a2 + 4 * HIBYTE(v9) + 72) + *(_DWORD *)(a2 + 4 * BYTE2(v9) + 1096))))
      ^ *(_DWORD *)(a2 + 40)
      ^ v8;
  LOBYTE(v5) = BYTE1(v10);
  v11 = (*(_DWORD *)(a2 + 4 * (unsigned __int8)v10 + 3144)
       + (*(_DWORD *)(a2 + 4 * v5 + 2120)
        ^ (*(_DWORD *)(a2 + 4 * HIBYTE(v10) + 72) + *(_DWORD *)(a2 + 4 * BYTE2(v10) + 1096))))
      ^ *(_DWORD *)(a2 + 36)
      ^ v9;
  LOBYTE(v5) = BYTE1(v11);
  v12 = (*(_DWORD *)(a2 + 4 * (unsigned __int8)v11 + 3144)
       + (*(_DWORD *)(a2 + 4 * v5 + 2120)
        ^ (*(_DWORD *)(a2 + 4 * HIBYTE(v11) + 72) + *(_DWORD *)(a2 + 4 * BYTE2(v11) + 1096))))
      ^ *(_DWORD *)(a2 + 32)
      ^ v10;
  LOBYTE(v5) = BYTE1(v12);
  v13 = (*(_DWORD *)(a2 + 4 * (unsigned __int8)v12 + 3144)
       + (*(_DWORD *)(a2 + 4 * v5 + 2120)
        ^ (*(_DWORD *)(a2 + 4 * HIBYTE(v12) + 72) + *(_DWORD *)(a2 + 4 * BYTE2(v12) + 1096))))
      ^ *(_DWORD *)(a2 + 28)
      ^ v11;
  LOBYTE(v5) = BYTE1(v13);
  v14 = (*(_DWORD *)(a2 + 4 * (unsigned __int8)v13 + 3144)
       + (*(_DWORD *)(a2 + 4 * v5 + 2120)
        ^ (*(_DWORD *)(a2 + 4 * HIBYTE(v13) + 72) + *(_DWORD *)(a2 + 4 * BYTE2(v13) + 1096))))
      ^ *(_DWORD *)(a2 + 24)
      ^ v12;
  LOBYTE(v5) = BYTE1(v14);
  v15 = (*(_DWORD *)(a2 + 4 * (unsigned __int8)v14 + 3144)
       + (*(_DWORD *)(a2 + 4 * v5 + 2120)
        ^ (*(_DWORD *)(a2 + 4 * HIBYTE(v14) + 72) + *(_DWORD *)(a2 + 4 * BYTE2(v14) + 1096))))
      ^ *(_DWORD *)(a2 + 20)
      ^ v13;
  LOBYTE(v5) = BYTE1(v15);
  v16 = (*(_DWORD *)(a2 + 4 * (unsigned __int8)v15 + 3144)
       + (*(_DWORD *)(a2 + 4 * v5 + 2120)
        ^ (*(_DWORD *)(a2 + 4 * HIBYTE(v15) + 72) + *(_DWORD *)(a2 + 4 * BYTE2(v15) + 1096))))
      ^ *(_DWORD *)(a2 + 16)
      ^ v14;
  LOBYTE(v5) = BYTE1(v16);
  v17 = (*(_DWORD *)(a2 + 4 * (unsigned __int8)v16 + 3144)
       + (*(_DWORD *)(a2 + 4 * v5 + 2120)
        ^ (*(_DWORD *)(a2 + 4 * HIBYTE(v16) + 72) + *(_DWORD *)(a2 + 4 * BYTE2(v16) + 1096))))
      ^ *(_DWORD *)(a2 + 12)
      ^ v15;
  LOBYTE(v5) = BYTE1(v17);
  v18 = (*(_DWORD *)(a2 + 4 * (unsigned __int8)v17 + 3144)
       + (*(_DWORD *)(a2 + 4 * v5 + 2120)
        ^ (*(_DWORD *)(a2 + 4 * HIBYTE(v17) + 72) + *(_DWORD *)(a2 + 4 * BYTE2(v17) + 1096))))
      ^ *(_DWORD *)(a2 + 8)
      ^ v16;
  LOBYTE(v5) = BYTE1(v18);
  result = a1;
  v20 = (*(_DWORD *)(a2 + 4 * (unsigned __int8)v18 + 3144)
       + (*(_DWORD *)(a2 + 4 * v5 + 2120)
        ^ (*(_DWORD *)(a2 + 4 * HIBYTE(v18) + 72) + *(_DWORD *)(a2 + 4 * BYTE2(v18) + 1096))))
      ^ *(_DWORD *)(a2 + 4)
      ^ v17;
  v21 = *(_DWORD *)a2 ^ v18;
  *(_DWORD *)(a1 + 4) = v20;
  *(_DWORD *)a1 = v21;
  return result;
}
