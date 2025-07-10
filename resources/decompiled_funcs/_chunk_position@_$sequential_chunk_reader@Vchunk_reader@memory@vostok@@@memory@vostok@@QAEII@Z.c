unsigned int __thiscall vostok::memory::sequential_chunk_reader<vostok::memory::chunk_reader>::chunk_position(
        vostok::memory::sequential_chunk_reader<vostok::memory::chunk_reader> *this,
        unsigned int chunk_id)
{
  unsigned int v2; // eax
  int *v3; // eax
  int v4; // edx
  unsigned int result; // eax
  int v6; // ebp
  int *v7; // edx
  int v8; // edi
  int *v9; // edx
  int v10; // esi
  _DWORD *v11; // edx
  int v12; // esi

  v2 = *(_DWORD *)&this[20];
  if ( v2 )
  {
    if ( v2 < *(_DWORD *)&this[12] )
    {
      v3 = (int *)(*(_DWORD *)&this[4] + v2);
      *(_DWORD *)&this[8] = v3;
      v4 = *v3;
      *(_DWORD *)&this[8] = v3 + 1;
      if ( v4 == chunk_id )
        return *(_DWORD *)&this[20];
    }
  }
  v6 = *(_DWORD *)&this[4];
  for ( *(_DWORD *)&this[8] = v6; ; *(_DWORD *)&this[8] = (char *)v11 + v12 )
  {
    v7 = *(int **)&this[8];
    result = (unsigned int)v7 - v6;
    if ( (unsigned int)v7 - v6 >= *(_DWORD *)&this[12] )
      break;
    v8 = *v7;
    v9 = v7 + 1;
    *(_DWORD *)&this[8] = v9;
    v10 = *v9;
    v11 = v9 + 1;
    v12 = v10 & 0x3FFFFFFF;
    *(_DWORD *)&this[8] = v11;
    if ( v8 == chunk_id )
    {
      *(_DWORD *)&this[20] = (char *)v11 + v12 - v6;
      return result;
    }
  }
  return -1;
}
