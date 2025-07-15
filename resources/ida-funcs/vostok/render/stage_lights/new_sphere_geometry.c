void __thiscall vostok::render::stage_lights::new_sphere_geometry(vostok::render::stage_lights *this, int a2)
{
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // eax
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v3; // eax
  vostok::render::res_geometry *v4; // eax
  vostok::render::resource_manager *v5; // [esp-8h] [ebp-34h]
  int v6; // [esp-4h] [ebp-30h]
  D3D11_INPUT_ELEMENT_DESC decl_size; // [esp+10h] [ebp-1Ch] BYREF

  vostok::render::resource_manager::create_buffer(
    0x450u,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)0xC,
    (vostok::render::enum_buffer_type)du_sphere_vertices,
    0,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v2,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 2172),
    0);
  vostok::render::resource_manager::create_buffer(
    0x438u,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)2,
    (vostok::render::enum_buffer_type)du_sphere_faces,
    1,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v3,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 2176),
    0);
  v6 = *(_DWORD *)(a2 + 2176);
  v5 = *(vostok::render::resource_manager **)(a2 + 2172);
  decl_size.SemanticName = "POSITION";
  decl_size.SemanticIndex = 0;
  decl_size.Format = DXGI_FORMAT_R32G32B32_FLOAT;
  memset(&decl_size.InputSlot, 0, 16);
  v4 = vostok::render::resource_manager::create_geometry(
         v5,
         (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
         &decl_size,
         1u,
         (vostok::render::untyped_buffer *)0xC,
         (vostok::render::untyped_buffer *)v5,
         v6);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 2180),
    v4);
}
