void __userpurge vostok::render::batched_geometry<vostok::render::lpv_vertex>::batched_geometry<vostok::render::lpv_vertex>(
        vostok::render::batched_geometry<vostok::render::lpv_vertex> *this@<ecx>,
        int a2@<esi>,
        const D3D11_INPUT_ELEMENT_DESC *layout,
        const unsigned int num_elements,
        unsigned int in_batched_geometry_max_vertices_count)
{
  vostok::render::resource_manager *v5; // eax
  vostok::render::res_declaration *declaration; // eax
  vostok::render::res_declaration *v7; // ecx
  const vostok::render::res_declaration *v8; // eax
  stlp_std::priv::_Impl_vector<vostok::render::lpv_vertex,vostok::render::std_allocator<vostok::render::lpv_vertex> > *v10; // ecx
  __int64 v11; // [esp+Ch] [ebp-Ch]
  int v12; // [esp+14h] [ebp-4h]

  *(_DWORD *)a2 = &vostok::render::batched_geometry<vostok::render::lpv_vertex>::`vftable';
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  `vector constructor iterator'(
    (char *)(a2 + 16),
    0xCu,
    8,
    (void *(__thiscall *)(void *))vostok::render::vector<vostok::render::lpv_render_surface>::vector<vostok::render::lpv_render_surface>);
  v5 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  *(_DWORD *)(a2 + 112) = 0;
  *(_DWORD *)(a2 + 116) = &_sbh_sizeHeaderList;
  *(_DWORD *)(a2 + 152) = 0;
  *(_DWORD *)(a2 + 156) = 0;
  *(_DWORD *)(a2 + 160) = 0;
  *(_DWORD *)(a2 + 164) = 0;
  *(_DWORD *)(a2 + 168) = 0;
  *(_DWORD *)(a2 + 172) = 0;
  v12 = 0;
  v11 = 0;
  *(_QWORD *)(a2 + 176) = 0;
  *(_QWORD *)(a2 + 188) = 0;
  *(_DWORD *)(a2 + 184) = 0;
  *(_DWORD *)(a2 + 196) = 0;
  *(_DWORD *)(a2 + 200) = 0;
  declaration = vostok::render::resource_manager::create_declaration(v5, lpv_layout, (unsigned int)layout);
  v7 = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    v7 = declaration;
  }
  v8 = *(const vostok::render::res_declaration **)(a2 + 112);
  *(_DWORD *)(a2 + 112) = v7;
  if ( v8 )
  {
    if ( v8->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v8);
  }
  stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short>>::reserve(
    *(stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > **)(a2 + 116),
    a2 + 164,
    *(_DWORD *)(a2 + 116));
  stlp_std::priv::_Impl_vector<vostok::render::lpv_vertex,vostok::render::std_allocator<vostok::render::lpv_vertex>>::reserve(
    v10,
    *(_DWORD *)(a2 + 116));
}
