unsigned int __userpurge vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::chunk_position@<eax>(
        vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader> *this@<ecx>,
        int a2@<edi>,
        unsigned int chunk_id)
{
  _DWORD *v3; // edx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // esi
  _DWORD *v8; // eax
  int *v9; // ecx
  unsigned int result; // eax
  int v11; // esi
  int v12; // eax
  const stlp_std::pair<unsigned int,unsigned int> *v13; // eax
  int v14; // ecx
  int v15; // edx
  const stlp_std::pair<unsigned int,unsigned int> *v16; // esi
  const stlp_std::pair<unsigned int,unsigned int> *v17; // eax
  const stlp_std::random_access_iterator_tag *v18; // [esp+0h] [ebp-8h]

  if ( a2 )
    v3 = (_DWORD *)(a2 - 2);
  else
    v3 = 0;
  if ( a2 )
    v4 = a2 - 2;
  else
    v4 = 0;
  if ( !*(_DWORD *)(v4 + 20) )
    goto LABEL_16;
  v5 = a2 ? a2 - 2 : 0;
  if ( *(_DWORD *)(v5 + 20) >= v3[3] )
    goto LABEL_16;
  v6 = a2 ? a2 - 2 : 0;
  v7 = v3[1];
  v8 = (_DWORD *)(*(_DWORD *)(v6 + 20) + v7 + 4);
  v3[2] = v8;
  v9 = (_DWORD *)((char *)v8 + (*v8 & 0x3FFFFFFF) + 4);
  v3[2] = v9;
  result = (unsigned int)v9 - v7;
  v11 = *v9;
  v3[2] = v9 + 1;
  if ( v11 != chunk_id )
  {
LABEL_16:
    if ( a2 )
      v12 = a2 - 2;
    else
      v12 = 0;
    v13 = *(const stlp_std::pair<unsigned int,unsigned int> **)(v12 + 16);
    if ( a2 )
    {
      v14 = a2 - 2;
      v15 = a2 - 2;
    }
    else
    {
      v14 = 0;
      v15 = 0;
    }
    v16 = (const stlp_std::pair<unsigned int,unsigned int> *)(*(_DWORD *)(v14 + 16) + 8 * *(_DWORD *)(v15 + 24));
    v17 = stlp_std::priv::__find_if<stlp_std::pair<unsigned int,unsigned int> const *,vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::predicate>(
            v13,
            v16,
            (vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::predicate)chunk_id,
            v18);
    if ( v17 == v16 )
      return -1;
    result = v17->second;
  }
  if ( a2 )
    *(_DWORD *)(a2 - 2 + 20) = result;
  else
    MEMORY[0x14] = result;
  return result;
}
