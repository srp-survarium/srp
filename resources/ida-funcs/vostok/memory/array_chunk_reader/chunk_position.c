unsigned int __thiscall vostok::memory::array_chunk_reader<vostok::memory::chunk_reader>::chunk_position(
        vostok::memory::array_chunk_reader<vostok::memory::chunk_reader> *this,
        unsigned int chunk_id,
        int a3)
{
  unsigned int v3; // edx
  _DWORD *v4; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // ebx
  _DWORD *v9; // eax
  int *v10; // edx
  int v11; // esi
  unsigned int result; // eax
  unsigned int v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // eax
  int v16; // [esp+0h] [ebp-4h]

  v3 = chunk_id;
  if ( chunk_id )
    v4 = (_DWORD *)(chunk_id - 1);
  else
    v4 = 0;
  if ( chunk_id )
    v5 = chunk_id - 1;
  else
    v5 = 0;
  if ( !*(_DWORD *)(v5 + 20) || (!chunk_id ? (v6 = 0) : (v6 = chunk_id - 1), *(_DWORD *)(v6 + 20) >= v4[3]) )
  {
    v11 = a3;
LABEL_20:
    if ( v3 )
      v14 = v3 - 1;
    else
      v14 = 0;
    if ( v4[1] + v4[3] <= (unsigned int)(v11 + *(_DWORD *)(v14 + 16)) )
      return -1;
    if ( v3 )
      v15 = v3 - 1;
    else
      v15 = 0;
    result = *(unsigned __int8 *)(*(_DWORD *)(v15 + 16) + v11);
    if ( v3 )
    {
      v13 = v3 - 1;
      goto LABEL_31;
    }
LABEL_30:
    v13 = 0;
    goto LABEL_31;
  }
  if ( chunk_id )
    v7 = chunk_id - 1;
  else
    v7 = 0;
  v8 = v4[1];
  v9 = (_DWORD *)(*(_DWORD *)(v7 + 20) + v8 + 4);
  v4[2] = v9;
  v10 = (_DWORD *)((char *)v9 + (*v9 & 0x3FFFFFFF) + 4);
  v4[2] = v10;
  v16 = *v10;
  v11 = a3;
  result = (unsigned int)v10 - v8;
  v4[2] = v10 + 1;
  if ( v16 != a3 )
  {
    v3 = chunk_id;
    goto LABEL_20;
  }
  if ( !chunk_id )
    goto LABEL_30;
  v13 = chunk_id - 1;
LABEL_31:
  *(_DWORD *)(v13 + 20) = result;
  return result;
}
