int __userpurge vostok::memory::chunk_reader::chunk_size@<eax>(
        vostok::memory::chunk_reader *this@<ecx>,
        int a2@<esi>,
        vostok::memory::chunk_reader::chunk_type *chunk_id,
        vostok::memory::chunk_reader::chunk_type *type)
{
  int v4; // eax
  unsigned int v5; // eax
  unsigned int *v6; // ecx
  unsigned int v7; // eax

  v4 = *(_DWORD *)(a2 + 28);
  if ( v4 )
  {
    if ( v4 == 1 )
      v5 = vostok::memory::array_chunk_reader<vostok::memory::chunk_reader>::chunk_position(
             (vostok::memory::array_chunk_reader<vostok::memory::chunk_reader> *)this,
             a2 + 1,
             (unsigned int)this);
    else
      v5 = vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::chunk_position(
             (vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader> *)this,
             a2 + 2,
             (unsigned int)this);
  }
  else
  {
    v5 = vostok::memory::sequential_chunk_reader<vostok::memory::chunk_reader>::chunk_position(
           (vostok::memory::sequential_chunk_reader<vostok::memory::chunk_reader> *)a2,
           (unsigned int)this);
  }
  *(_DWORD *)(a2 + 8) = v5 + *(_DWORD *)(a2 + 4);
  *(_DWORD *)(a2 + 8) += 4;
  v6 = *(unsigned int **)(a2 + 8);
  v7 = *v6;
  *(_DWORD *)(a2 + 8) = v6 + 1;
  *chunk_id = v7 >> 30;
  return v7 & 0x3FFFFFFF;
}
