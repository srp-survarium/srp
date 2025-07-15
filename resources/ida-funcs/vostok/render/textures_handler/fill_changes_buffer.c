void __userpurge vostok::render::textures_handler<1>::fill_changes_buffer(
        vostok::render::textures_handler<0> *this@<ecx>,
        _DWORD *a2@<edi>,
        ID3D11ShaderResourceView **buffer,
        vostok::render::res_texture *out_num_textures)
{
  int v4; // ecx
  int v5; // esi
  int i; // ebx
  ID3D11ShaderResourceView *m_sh_res_view; // eax
  int v9; // [esp+Ch] [ebp-4h]

  v4 = a2[1];
  v5 = 0;
  v9 = 0;
  if ( *a2 )
    v5 = (*(_DWORD *)(*a2 + 8) - *(_DWORD *)(*a2 + 4)) >> 2;
  out_num_textures->__vftable = (vostok::render::res_texture_vtbl *)v5;
  for ( i = v4; i < v5; ++i )
  {
    if ( *(_DWORD *)(*(_DWORD *)(*a2 + 4) + 4 * i)
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      m_sh_res_view = *(ID3D11ShaderResourceView **)(*(_DWORD *)(*(_DWORD *)(*a2 + 4) + 4 * i) + 448);
      if ( !m_sh_res_view )
      {
        v9 |= 1u;
        m_sh_res_view = vostok::render::resource_manager::get_default_texture(
                          (vostok::render::resource_manager *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
                          (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                          (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&out_num_textures)->m_object->m_sh_res_view;
      }
      buffer[i] = m_sh_res_view;
      if ( (v9 & 1) != 0 )
      {
        v9 &= ~1u;
        if ( out_num_textures )
        {
          if ( out_num_textures->m_reference_count-- == 1 )
            vostok::render::resource_manager::release(
              (vostok::render::resource_manager *)buffer,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              out_num_textures);
        }
      }
    }
    else
    {
      buffer[i] = 0;
    }
  }
}
