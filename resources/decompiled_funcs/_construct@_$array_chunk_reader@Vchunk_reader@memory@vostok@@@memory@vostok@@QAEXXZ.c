void __thiscall vostok::memory::array_chunk_reader<vostok::memory::chunk_reader>::construct(
        vostok::memory::array_chunk_reader<vostok::memory::chunk_reader> *this)
{
  vostok::memory::array_chunk_reader<vostok::memory::chunk_reader> *v1; // eax
  vostok::memory::array_chunk_reader<vostok::memory::chunk_reader> *v2; // edx
  int *v3; // eax
  int v4; // esi

  if ( this )
    v1 = this - 1;
  else
    v1 = 0;
  *(_DWORD *)&v1[20] = 0;
  if ( this )
    v2 = this - 1;
  else
    v2 = 0;
  v3 = *(int **)&v2[8];
  v4 = *v3;
  *(_DWORD *)&v2[8] = v3 + 1;
  if ( this )
    *(_DWORD *)&this[15] = (char *)v3 + v4;
  else
    MEMORY[0x10] = (char *)v3 + v4;
}
