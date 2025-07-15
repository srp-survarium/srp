unsigned int __thiscall vostok::memory::sequential_chunk_reader<vostok::memory::chunk_reader>::chunk_position(
        vostok::memory::sequential_chunk_reader<vostok::memory::chunk_reader> *this,
        unsigned int chunk_id)
{
  unsigned int v2; // eax
  int *v4; // eax
  unsigned int result; // eax
  int v6; // eax
  int *v7; // edx
  _DWORD *v8; // edx
  int v9; // esi
  char *v10; // edx
  int v11; // [esp+Ch] [ebp-8h]
  int v12; // [esp+10h] [ebp-4h]
  int v13; // [esp+1Ch] [ebp+8h]
  unsigned int v14; // [esp+1Ch] [ebp+8h]

  v2 = *(_DWORD *)&this[20];
  if ( v2 )
  {
    if ( v2 < *(_DWORD *)&this[12] )
    {
      v4 = (int *)(*(_DWORD *)&this[4] + v2);
      *(_DWORD *)&this[8] = v4;
      v13 = *v4;
      *(_DWORD *)&this[8] = v4 + 1;
      if ( v13 == chunk_id )
        return *(_DWORD *)&this[20];
    }
  }
  v6 = *(_DWORD *)&this[4];
  for ( *(_DWORD *)&this[8] = v6; ; *(_DWORD *)&this[8] = (char *)v8 + v9 )
  {
    v14 = *(_DWORD *)&this[8] - v6;
    if ( v14 >= *(_DWORD *)&this[12] )
      break;
    v7 = (int *)(*(_DWORD *)&this[8] + 4);
    v11 = **(_DWORD **)&this[8];
    *(_DWORD *)&this[8] = v7;
    v12 = *v7;
    v8 = v7 + 1;
    v9 = v12 & 0x3FFFFFFF;
    *(_DWORD *)&this[8] = v8;
    if ( v11 == chunk_id )
    {
      v10 = (char *)v8 - v6;
      result = v14;
      *(_DWORD *)&this[20] = &v10[v9];
      return result;
    }
  }
  return -1;
}
