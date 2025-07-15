void __fastcall vostok::memory::array_chunk_reader<vostok::memory::chunk_reader>::construct(
        vostok::memory::array_chunk_reader<vostok::memory::chunk_reader> *this,
        int a2)
{
  int v2; // eax
  int v3; // ecx
  int *v4; // eax
  int v5; // ecx
  int v6; // [esp+0h] [ebp-4h]

  if ( a2 )
    v2 = a2 - 1;
  else
    v2 = 0;
  *(_DWORD *)(v2 + 20) = 0;
  if ( a2 )
    v3 = a2 - 1;
  else
    v3 = 0;
  v4 = *(int **)(v3 + 8);
  v6 = *v4;
  *(_DWORD *)(v3 + 8) = v4 + 1;
  if ( a2 )
    v5 = a2 - 1;
  else
    v5 = 0;
  *(_DWORD *)(v5 + 16) = (char *)v4 + v6;
}
