void __thiscall vostok::render::fog_box_geometry::fog_box_geometry(
        vostok::render::fog_box_geometry *this,
        vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *a2)
{
  vostok::render::untyped_buffer *v2; // eax
  const vostok::render::untyped_buffer *v3; // eax
  vostok::render::resource_manager *v4; // ecx
  const vostok::render::untyped_buffer *v5; // edi
  vostok::render::res_geometry *v6; // eax
  bool v7; // zf
  vostok::render::untyped_buffer *v8; // esi
  vostok::render::resource_manager *v9; // [esp-18h] [ebp-44h]
  vostok::render::hw_buffer_pool *v10; // [esp+0h] [ebp-2Ch]
  D3D11_INPUT_ELEMENT_DESC decl_size; // [esp+Ch] [ebp-20h] BYREF
  vostok::render::untyped_buffer *ib; // [esp+28h] [ebp-4h]

  v9 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  a2->m_object = 0;
  vostok::render::resource_manager::create_buffer(
    0x60u,
    v9,
    (void *)0xC,
    (vostok::render::enum_buffer_type)du_box_vertices,
    0,
    0,
    0);
  ib = 0;
  if ( v2 )
  {
    ++v2->m_reference_count;
    ib = v2;
  }
  vostok::render::resource_manager::create_buffer(
    0x48u,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)2,
    (vostok::render::enum_buffer_type)du_box_faces,
    1,
    0,
    0);
  v5 = 0;
  if ( v3 )
  {
    ++v3->m_reference_count;
    v5 = v3;
  }
  decl_size.SemanticName = "POSITION";
  decl_size.SemanticIndex = 0;
  decl_size.Format = DXGI_FORMAT_R32G32B32_FLOAT;
  memset(&decl_size.InputSlot, 0, 16);
  v6 = vostok::render::resource_manager::create_geometry(
         v4,
         (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
         &decl_size,
         1u,
         (vostok::render::untyped_buffer *)0xC,
         ib,
         (int)v5);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    a2,
    v6);
  if ( v5 )
  {
    v7 = v5->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(v5, v10);
  }
  v8 = ib;
  if ( ib )
  {
    v7 = ib->m_reference_count-- == 1;
    if ( v7 )
      vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(v8, v10);
  }
}
