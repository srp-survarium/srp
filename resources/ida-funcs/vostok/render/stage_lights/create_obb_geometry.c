void __thiscall vostok::render::stage_lights::create_obb_geometry(vostok::render::stage_lights *this, int a2)
{
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // eax
  void *v3; // esp
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v4; // eax
  vostok::render::res_geometry *v5; // eax
  vostok::render::resource_manager *v6; // [esp-50h] [ebp-7Ch]
  int v7; // [esp-4Ch] [ebp-78h]
  unsigned __int8 v8[88]; // [esp-48h] [ebp-74h] BYREF
  D3D11_INPUT_ELEMENT_DESC decl_size; // [esp+10h] [ebp-1Ch] BYREF

  vostok::render::resource_manager::create_buffer(
    0x60u,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)0xC,
    (vostok::render::enum_buffer_type)vostok::geometry_utils::cube_solid::vertices,
    0,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v2,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 2196),
    0);
  v3 = alloca(72);
  stlp_std::priv::__copy_trivial(
    (unsigned __int8 *)vostok::geometry_utils::cube_solid::faces,
    (unsigned __int8 *)vostok::geometry_utils::rectangle_solid::vertices,
    v8);
  vostok::render::resource_manager::create_buffer(
    0x48u,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)2,
    (vostok::render::enum_buffer_type)v8,
    1,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v4,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 2200),
    0);
  v7 = *(_DWORD *)(a2 + 2200);
  v6 = *(vostok::render::resource_manager **)(a2 + 2196);
  decl_size.SemanticName = "POSITION";
  decl_size.SemanticIndex = 0;
  decl_size.Format = DXGI_FORMAT_R32G32B32_FLOAT;
  memset(&decl_size.InputSlot, 0, 16);
  v5 = vostok::render::resource_manager::create_geometry(
         v6,
         (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
         &decl_size,
         1u,
         (vostok::render::untyped_buffer *)0xC,
         (vostok::render::untyped_buffer *)v6,
         v7);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 2204),
    v5);
}
