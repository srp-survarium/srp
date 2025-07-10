void __fastcall vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::construct(
        vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader> *this,
        int a2)
{
  int v2; // eax
  int v3; // eax
  int *v4; // ecx
  int v5; // edi
  int v6; // esi
  int *v7; // ecx
  int v8; // esi

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
  v5 = *v4;
  *(_DWORD *)(v3 + 8) = v4 + 1;
  if ( a2 )
    v6 = a2 - 2;
  else
    v6 = 0;
  *(_DWORD *)(v6 + 16) = (char *)v4 + v5;
  v7 = *(int **)(v3 + 8);
  v8 = *v7;
  *(_DWORD *)(v3 + 8) = v7 + 1;
  if ( a2 )
    *(_DWORD *)(a2 + 22) = v8;
  else
    MEMORY[0x18] = v8;
}
