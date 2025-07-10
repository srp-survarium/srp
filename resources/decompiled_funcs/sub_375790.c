int __cdecl sub_375790(int a1, int a2)
{
  _DWORD *v2; // edi
  int v3; // ebp
  int v4; // eax
  int v5; // ecx
  int result; // eax
  int v7; // ebx
  int v8; // esi
  _DWORD *v9; // ebp
  int v10; // ecx
  unsigned int v11; // eax
  int v12; // ebx
  int v13; // edi
  unsigned int v14; // ebp
  int v15; // [esp+8h] [ebp-20h]
  int v16; // [esp+Ch] [ebp-1Ch]
  int v17; // [esp+10h] [ebp-18h]
  int v18; // [esp+14h] [ebp-14h]
  _DWORD *v19; // [esp+18h] [ebp-10h]
  unsigned int v20; // [esp+1Ch] [ebp-Ch]
  int v21; // [esp+20h] [ebp-8h]
  void (__cdecl *v22)(int, int, int, int, int); // [esp+24h] [ebp-4h]

  v2 = (_DWORD *)a1;
  v3 = *(_DWORD *)(a1 + 408);
  v20 = *(_DWORD *)(a1 + 288) - 1;
  while ( 1 )
  {
    v4 = *(_DWORD *)(a1 + 124);
    v5 = *(_DWORD *)(a1 + 132);
    if ( v4 >= v5 && (v4 != v5 || *(_DWORD *)(a1 + 128) > *(_DWORD *)(a1 + 136)) )
      break;
    result = (**(int (__cdecl ***)(int))(a1 + 416))(a1);
    if ( !result )
      return result;
  }
  v7 = 0;
  v8 = *(_DWORD *)(a1 + 196);
  v18 = 0;
  if ( *(int *)(a1 + 36) > 0 )
  {
    v9 = (_DWORD *)(v3 + 72);
    v19 = v9;
    do
    {
      if ( *(_BYTE *)(v8 + 52) )
      {
        v21 = (*(int (__cdecl **)(_DWORD *, _DWORD, int, _DWORD, _DWORD))(v2[1] + 32))(
                v2,
                *v9,
                *(_DWORD *)(v8 + 12) * v2[34],
                *(_DWORD *)(v8 + 12),
                0);
        if ( v2[34] >= v20 )
        {
          v15 = *(_DWORD *)(v8 + 32) % *(_DWORD *)(v8 + 12);
          if ( !v15 )
            v15 = *(_DWORD *)(v8 + 12);
        }
        else
        {
          v15 = *(_DWORD *)(v8 + 12);
        }
        v16 = *(_DWORD *)(a2 + 4 * v7);
        v10 = 0;
        v22 = *(void (__cdecl **)(int, int, int, int, int))(v2[107] + 4 * v7 + 4);
        v17 = 0;
        if ( v15 > 0 )
        {
          v11 = *(_DWORD *)(v8 + 28);
          do
          {
            v12 = *(_DWORD *)(v21 + 4 * v10);
            v13 = 0;
            v14 = 0;
            if ( v11 )
            {
              do
              {
                v22(a1, v8, v12, v16, v13);
                v11 = *(_DWORD *)(v8 + 28);
                v13 += *(_DWORD *)(v8 + 36);
                ++v14;
                v12 += 128;
              }
              while ( v14 < v11 );
              v10 = v17;
            }
            ++v10;
            v16 += 4 * *(_DWORD *)(v8 + 40);
            v17 = v10;
          }
          while ( v10 < v15 );
          v7 = v18;
          v2 = (_DWORD *)a1;
        }
      }
      ++v7;
      v9 = v19 + 1;
      v8 += 88;
      v18 = v7;
      ++v19;
    }
    while ( v7 < v2[9] );
  }
  return 4 - (++v2[34] < v2[72]);
}
