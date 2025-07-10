void __fastcall vostok::render::constants_handler<2>::fill_changes_buffer(
        vostok::render::constants_handler<0> *this,
        unsigned int *a2,
        ID3D11Buffer **buffer,
        unsigned int *out_num_constants)
{
  unsigned int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // esi

  v4 = a2[2];
  v5 = *a2;
  v6 = a2[1];
  if ( v4 )
    v7 = (*(_DWORD *)(v4 + 20) - *(_DWORD *)(v4 + 16)) >> 2;
  else
    v7 = 0;
  for ( *out_num_constants = v7; v5 < v6; ++v5 )
  {
    if ( v5 >= v7 )
      buffer[v5] = 0;
    else
      buffer[v5] = *(ID3D11Buffer **)(*(_DWORD *)(*(_DWORD *)(a2[2] + 16) + 4 * v5) + 96);
  }
}
