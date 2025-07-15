void __thiscall vostok::render::renderer_context_targets::new_rt(
        vostok::render::renderer_context_targets *this,
        vostok::render::enum_render_target_index index,
        vostok::render::enum_render_target_index in_format,
        const vostok::math::uint2 in_size,
        unsigned int usage,
        DXGI_FORMAT enabled)
{
  char *v6; // eax
  int v7; // ebx
  vostok::buffer_string *v8; // ecx
  vostok::render::resource_manager *v9; // ecx
  stlp_std::priv::_Rb_tree_node_base *render_target; // eax
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v11; // esi
  vostok::render::res_texture *y; // esi
  vostok::render::resource_manager *v13; // ecx
  bool v14; // zf
  vostok::render::res_texture *v15; // eax
  unsigned int format_block_size; // eax
  unsigned int v17; // [esp+0h] [ebp-10h]
  char indexa; // [esp+1Ch] [ebp+Ch]

  v6 = (char *)vostok::render::rt_index_to_name(in_format);
  v7 = index + 160 * in_format;
  v8 = *(vostok::buffer_string **)v7;
  if ( *(char **)v7 != v6 )
  {
    *(_DWORD *)(v7 + 4) = v8;
    LOBYTE(v8->m_begin) = 0;
    vostok::buffer_string::operator+=((vostok::buffer_string *)v7, v6);
  }
  vostok::fs_new::path_string_impl::assignf(
    (_DWORD *)(v7 + 76),
    v8,
    (vostok::buffer_string *)"%s_%d",
    *(const char **)v7,
    *(_DWORD *)(index + 11688));
  render_target = vostok::render::resource_manager::create_render_target(
                    v9,
                    (const char **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                    (_BYTE *)(v7 + 88),
                    usage,
                    enabled,
                    (char *)in_size.x,
                    (DXGI_FORMAT)in_size.y,
                    0,
                    0,
                    0,
                    v17);
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(v7 + 152),
    (vostok::render::render_target *)render_target);
  v11 = *(const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(v7 + 152);
  if ( v11
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    indexa = 1;
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_size.elements[1],
      v11 + 7);
    y = (vostok::render::res_texture *)in_size.y;
  }
  else
  {
    y = 0;
    indexa = 2;
    in_size.y = 0;
  }
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_size.elements[1],
    (vostok::render::res_texture *)(v7 + 156));
  if ( (indexa & 2) != 0 )
  {
    indexa &= ~2u;
    if ( y )
    {
      v14 = y->m_reference_count-- == 1;
      if ( v14 )
        vostok::render::resource_manager::release(
          v13,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          y);
    }
  }
  if ( (indexa & 1) != 0 )
  {
    v15 = (vostok::render::res_texture *)in_size.y;
    if ( in_size.y )
    {
      v14 = (*(_DWORD *)(in_size.y + 4))-- == 1;
      if ( v14 )
        vostok::render::resource_manager::release(
          v13,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v15);
    }
  }
  format_block_size = vostok::render::get_format_block_size(in_size.x);
  *(_DWORD *)(index + 11692) += enabled * usage * format_block_size;
}
