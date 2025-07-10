unsigned int __userpurge vostok::memory::array_chunk_reader<vostok::memory::chunk_reader>::chunk_position@<eax>(
        vostok::memory::array_chunk_reader<vostok::memory::chunk_reader> *this@<ecx>,
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
  int v12; // ecx
  int v13; // eax

  if ( a2 )
    v3 = (_DWORD *)(a2 - 1);
  else
    v3 = 0;
  if ( a2 )
    v4 = a2 - 1;
  else
    v4 = 0;
  if ( !*(_DWORD *)(v4 + 20) )
    goto LABEL_16;
  v5 = a2 ? a2 - 1 : 0;
  if ( *(_DWORD *)(v5 + 20) >= v3[3] )
    goto LABEL_16;
  v6 = a2 ? a2 - 1 : 0;
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
      v12 = a2 - 1;
    else
      v12 = 0;
    if ( v3[1] + v3[3] <= chunk_id + *(_DWORD *)(v12 + 16) )
      return -1;
    if ( a2 )
      v13 = a2 - 1;
    else
      v13 = 0;
    result = *(unsigned __int8 *)(*(_DWORD *)(v13 + 16) + chunk_id);
  }
  if ( a2 )
    *(_DWORD *)(a2 - 1 + 20) = result;
  else
    MEMORY[0x14] = result;
  return result;
}
