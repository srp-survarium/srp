int __cdecl sub_37BD00(int a1, int a2, int a3, int a4, int a5, int a6, _BYTE *a7)
{
  int result; // eax
  int v8; // ebx
  _DWORD *v9; // esi
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  int v13; // esi
  int v14; // ebp
  _BYTE *v15; // edx
  int v16; // esi
  int v17; // ebp
  int v18; // edi
  int *v19; // ecx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  bool v24; // sf
  int v25; // [esp+4h] [ebp-21Ch]
  int v26; // [esp+8h] [ebp-218h]
  int v27; // [esp+Ch] [ebp-214h]
  int i; // [esp+10h] [ebp-210h]
  int v29; // [esp+14h] [ebp-20Ch]
  int v30; // [esp+18h] [ebp-208h]
  int v31; // [esp+1Ch] [ebp-204h]
  _DWORD v32[128]; // [esp+20h] [ebp-200h] BYREF

  memset32(v32, 0x7FFFFFFF, 0x80u);
  result = 0;
  for ( i = 0; i < a5; ++i )
  {
    v8 = *(unsigned __int8 *)(result + a6);
    v9 = *(_DWORD **)(a1 + 116);
    v10 = a2 - *(unsigned __int8 *)(v8 + *v9);
    v11 = 3 * (a3 - *(unsigned __int8 *)(v9[1] + v8));
    v12 = a4 - *(unsigned __int8 *)(v9[2] + v8);
    v13 = v11 * v11 + v12 * v12;
    v10 *= 2;
    v14 = 3 * v11 + 18;
    v15 = a7;
    v16 = v10 * v10 + v13;
    v17 = 8 * v14;
    v18 = 16 * (v12 + 4);
    v31 = v17;
    v19 = v32;
    v25 = 32 * (v10 + 8);
    v26 = 3;
    while ( 1 )
    {
      v20 = v16;
      v29 = v16;
      v27 = v17;
      v30 = 7;
      do
      {
        if ( v20 < *v19 )
        {
          *v19 = v20;
          *v15 = v8;
        }
        v21 = v18 + v20;
        if ( v21 < v19[1] )
        {
          v19[1] = v21;
          v15[1] = v8;
        }
        v22 = v18 + 128 + v21;
        if ( v22 < v19[2] )
        {
          v19[2] = v22;
          v15[2] = v8;
        }
        v23 = v18 + 256 + v22;
        if ( v23 < v19[3] )
        {
          v19[3] = v23;
          v15[3] = v8;
        }
        v20 = v27 + v29;
        v19 += 4;
        v15 += 4;
        v24 = --v30 < 0;
        v29 += v27;
        v27 += 288;
      }
      while ( !v24 );
      v16 += v25;
      v24 = --v26 < 0;
      v25 += 512;
      if ( v24 )
        break;
      v17 = v31;
    }
    result = i + 1;
  }
  return result;
}
