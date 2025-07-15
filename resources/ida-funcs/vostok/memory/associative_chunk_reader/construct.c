void __fastcall vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::construct(
        vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader> *this,
        int a2)
{
  int v2; // eax
  int v3; // eax
  int *v4; // ecx
  int v5; // esi
  int *v6; // esi
  int v7; // eax
  int v8; // [esp+0h] [ebp-4h]
  int v9; // [esp+0h] [ebp-4h]

  if ( a2 )
    v2 = a2 - 2;
  else
    v2 = 0;
  *(_DWORD *)(v2 + 20) = 0;
  if ( a2 )
    v3 = a2 - 2;
  else
    v3 = 0;
  v4 = *(int **)(v3 + 8);
  v8 = *v4;
  *(_DWORD *)(v3 + 8) = v4 + 1;
  if ( a2 )
    v5 = a2 - 2;
  else
    v5 = 0;
  *(_DWORD *)(v5 + 16) = (char *)v4 + v8;
  v6 = *(int **)(v3 + 8);
  v9 = *v6;
  *(_DWORD *)(v3 + 8) = v6 + 1;
  if ( a2 )
    v7 = a2 - 2;
  else
    v7 = 0;
  *(_DWORD *)(v7 + 24) = v9;
}
