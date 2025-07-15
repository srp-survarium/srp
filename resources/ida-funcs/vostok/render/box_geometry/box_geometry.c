void __usercall vostok::render::box_geometry::box_geometry(vostok::render::box_geometry *this@<ecx>, int a2@<eax>)
{
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v3; // eax
  void *v4; // esp
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v5; // eax
  vostok::render::resource_manager *v6; // ecx
  vostok::render::res_declaration *v7; // eax
  unsigned __int8 v8[48]; // [esp-48h] [ebp-70h] BYREF
  vostok::render::resource_manager *v9; // [esp-18h] [ebp-40h]
  int v10; // [esp-14h] [ebp-3Ch]
  const float *v11; // [esp-10h] [ebp-38h]
  BOOL v12; // [esp-Ch] [ebp-34h]
  bool v13; // [esp-8h] [ebp-30h]
  bool v14; // [esp-4h] [ebp-2Ch]
  D3D11_INPUT_ELEMENT_DESC count; // [esp+Ch] [ebp-1Ch] BYREF

  v14 = 0;
  v13 = 0;
  v12 = 0;
  v11 = vostok::geometry_utils::cube_solid::vertices;
  v10 = 12;
  v9 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 12;
  vostok::render::resource_manager::create_buffer(
    0x60u,
    v9,
    (void *)v10,
    (vostok::render::enum_buffer_type)v11,
    v12,
    v13,
    v14);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v3,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 4),
    (vostok::render::hw_buffer_pool *)a2);
  v4 = alloca(72);
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
    v5,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 8),
    (vostok::render::hw_buffer_pool *)a2);
  count.SemanticName = "POSITION";
  count.SemanticIndex = 0;
  count.Format = DXGI_FORMAT_R32G32B32_FLOAT;
  memset(&count.InputSlot, 0, 16);
  v7 = vostok::render::resource_manager::create_declaration(
         v6,
         (const D3D11_INPUT_ELEMENT_DESC *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
         &count,
         1u);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2,
    v7);
}
