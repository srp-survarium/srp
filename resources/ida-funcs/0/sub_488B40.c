_WORD *__cdecl sub_488B40(int a1, int a2, int a3)
{
  int v3; // ecx
  int v4; // esi
  int v5; // ebx
  int v6; // eax
  unsigned __int8 *v7; // ecx
  _DWORD *v8; // edi
  int v9; // ebp
  int v10; // edx
  int v11; // ebx
  _WORD *result; // eax
  __int16 v13; // si
  int v14; // [esp+10h] [ebp-18Ch]
  int v15; // [esp+14h] [ebp-188h]
  _BYTE v16[128]; // [esp+18h] [ebp-184h] BYREF
  _BYTE v17[256]; // [esp+98h] [ebp-104h] BYREF
  int v18; // [esp+1A4h] [ebp+8h]
  int v19; // [esp+1A8h] [ebp+Ch]

  v4 = v3 >> 3;
  v19 = a3 >> 2;
  v18 = a2 >> 2;
  v5 = 32 * (v3 >> 3) + 2;
  v15 = *(_DWORD *)(*(_DWORD *)(a1 + 440) + 24);
  v6 = sub_4887F0(a1, v5, 32 * v18 + 4, 32 * v19 + 4, (int)v17);
  sub_4889C0(a1, 32 * v18 + 4, v5, 32 * v19 + 4, v6, (int)v17, v16);
  v7 = v16;
  v14 = 2 * (4 * v19 + (v4 << 8));
  v8 = (_DWORD *)(v15 + 16 * v18);
  v9 = 4;
  do
  {
    v10 = v14;
    v11 = 8;
    do
    {
      result = (_WORD *)(v10 + *v8);
      *result = *v7 + 1;
      result[1] = v7[1] + 1;
      result[2] = v7[2] + 1;
      v13 = v7[3] + 1;
      v7 += 4;
      v10 += 64;
      --v11;
      result[3] = v13;
    }
    while ( v11 );
    ++v8;
    --v9;
  }
  while ( v9 );
  return result;
}
