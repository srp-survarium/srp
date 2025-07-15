void __fastcall vostok::render::textures_handler<1>::fill_changes_buffer(
        vostok::render::textures_handler<0> *this,
        _DWORD *a2,
        ID3D11ShaderResourceView **buffer,
        int *out_num_textures)
{
  int v4; // eax
  int v5; // edi
  int v6; // esi
  int v7; // ecx
  bool v8; // zf
  int v9; // ecx

  v4 = a2[1];
  v5 = a2[2];
  if ( *a2 )
    v6 = (*(_DWORD *)(*a2 + 8) - *(_DWORD *)(*a2 + 4)) >> 2;
  else
    v6 = 0;
  for ( *out_num_textures = v6; v4 < v5; ++v4 )
  {
    if ( v4 >= v6
      || (v7 = *(_DWORD *)(*a2 + 4), v8 = *(_DWORD *)(v7 + 4 * v4) == 0, v9 = v7 + 4 * v4, v8)
      || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      buffer[v4] = 0;
    }
    else
    {
      buffer[v4] = *(ID3D11ShaderResourceView **)(*(_DWORD *)v9 + 428);
    }
  }
}
