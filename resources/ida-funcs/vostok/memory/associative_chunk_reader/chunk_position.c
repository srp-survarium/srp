unsigned int __thiscall vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::chunk_position(
        vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader> *this,
        unsigned int chunk_id,
        vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::predicate __pred)
{
  unsigned int v3; // esi
  _DWORD *v4; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // ebx
  _DWORD *v9; // eax
  int *v10; // edx
  unsigned int result; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  const stlp_std::pair<unsigned int,unsigned int> *v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // ecx
  const stlp_std::pair<unsigned int,unsigned int> *v17; // edi
  const stlp_std::pair<unsigned int,unsigned int> *v18; // eax
  int v19; // [esp+8h] [ebp-4h]

  v3 = chunk_id;
  if ( chunk_id )
    v4 = (_DWORD *)(chunk_id - 2);
  else
    v4 = 0;
  if ( chunk_id )
    v5 = chunk_id - 2;
  else
    v5 = 0;
  if ( !*(_DWORD *)(v5 + 20) || (!chunk_id ? (v6 = 0) : (v6 = chunk_id - 2), *(_DWORD *)(v6 + 20) >= v4[3]) )
  {
LABEL_19:
    if ( v3 )
      v13 = v3 - 2;
    else
      v13 = 0;
    v14 = *(const stlp_std::pair<unsigned int,unsigned int> **)(v13 + 16);
    if ( v3 )
      v15 = v3 - 2;
    else
      v15 = 0;
    if ( v3 )
      v16 = v3 - 2;
    else
      v16 = 0;
    v17 = (const stlp_std::pair<unsigned int,unsigned int> *)(*(_DWORD *)(v15 + 16) + 8 * *(_DWORD *)(v16 + 24));
    v18 = stlp_std::find_if<stlp_std::pair<unsigned int,unsigned int> const *,vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::predicate>(
            v14,
            v17,
            __pred);
    if ( v18 == v17 )
      return -1;
    result = v18->second;
    if ( v3 )
    {
      v12 = v3 - 2;
      goto LABEL_33;
    }
LABEL_32:
    v12 = 0;
    goto LABEL_33;
  }
  if ( chunk_id )
    v7 = chunk_id - 2;
  else
    v7 = 0;
  v8 = v4[1];
  v9 = (_DWORD *)(*(_DWORD *)(v7 + 20) + v8 + 4);
  v4[2] = v9;
  v10 = (_DWORD *)((char *)v9 + (*v9 & 0x3FFFFFFF) + 4);
  v4[2] = v10;
  v19 = *v10;
  v4[2] = v10 + 1;
  result = (unsigned int)v10 - v8;
  if ( v19 != __pred.m_chunk_id )
  {
    v3 = chunk_id;
    goto LABEL_19;
  }
  if ( !chunk_id )
    goto LABEL_32;
  v12 = chunk_id - 2;
LABEL_33:
  *(_DWORD *)(v12 + 20) = result;
  return result;
}
