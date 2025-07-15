void __userpurge vostok::render::renderer_context_targets::new_lt(
        vostok::render::renderer_context_targets *this@<ecx>,
        vostok::render::enum_render_target_index index,
        unsigned int in_format,
        const vostok::math::uint2 in_size)
{
  char *v4; // eax
  int v5; // ecx
  int v6; // edi
  vostok::buffer_string *v7; // ecx
  vostok::render::resource_manager *v8; // ecx
  vostok::render::res_texture *texture2d; // eax

  v4 = (char *)vostok::render::rt_index_to_name((vostok::render::enum_render_target_index)this);
  v6 = 160 * v5 + index;
  v7 = *(vostok::buffer_string **)v6;
  if ( *(char **)v6 != v4 )
  {
    *(_DWORD *)(v6 + 4) = v7;
    LOBYTE(v7->m_begin) = 0;
    vostok::buffer_string::operator+=((vostok::buffer_string *)v6, v4);
  }
  vostok::fs_new::path_string_impl::assignf(
    (_DWORD *)(v6 + 76),
    v7,
    (vostok::buffer_string *)"%s_%d",
    *(const char **)v6,
    *(_DWORD *)(index + 11688));
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(v6 + 152),
    0);
  texture2d = vostok::render::resource_manager::create_texture2d(
                v8,
                (const char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                (char *)(v6 + 88),
                in_format,
                (const D3D11_SUBRESOURCE_DATA *)in_size.x,
                0,
                DXGI_FORMAT_R32G32B32A32_FLOAT,
                D3D11_USAGE_STAGING,
                1u,
                0);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    texture2d,
    (vostok::render::res_texture *)(v6 + 156));
  *(_DWORD *)(index + 11692) += in_size.x * in_format * vostok::render::get_format_block_size(2);
}
