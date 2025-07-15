void __thiscall vostok::render::stage_lights::create_pyramid_geometry(vostok::render::stage_lights *this, int a2)
{
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // eax
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v3; // eax
  vostok::render::res_geometry *v4; // eax
  vostok::render::resource_manager *v5; // [esp-8h] [ebp-94h]
  int v6; // [esp-4h] [ebp-90h]
  _DWORD data[15]; // [esp+10h] [ebp-7Ch] BYREF
  _WORD v8[18]; // [esp+4Ch] [ebp-40h] BYREF
  D3D11_INPUT_ELEMENT_DESC decl_size; // [esp+70h] [ebp-1Ch] BYREF

  v8[0] = 0;
  v8[1] = 1;
  v8[2] = 2;
  v8[3] = 0;
  v8[4] = 2;
  v8[5] = 4;
  v8[6] = 0;
  v8[7] = 4;
  v8[8] = 3;
  v8[9] = 0;
  v8[10] = 3;
  v8[11] = 1;
  v8[12] = 1;
  v8[13] = 3;
  v8[15] = 2;
  v8[17] = 4;
  memset(data, 0, 12);
  *(float *)&data[3] = FLOAT_N1_0;
  *(float *)&data[4] = FLOAT_N1_0;
  *(float *)&data[5] = s_bm_current_air_resistance;
  *(float *)&data[6] = FLOAT_N1_0;
  *(float *)&data[7] = s_bm_current_air_resistance;
  *(float *)&data[8] = s_bm_current_air_resistance;
  *(float *)&data[9] = s_bm_current_air_resistance;
  *(float *)&data[10] = FLOAT_N1_0;
  *(float *)&data[11] = s_bm_current_air_resistance;
  *(float *)&data[12] = s_bm_current_air_resistance;
  *(float *)&data[13] = s_bm_current_air_resistance;
  *(float *)&data[14] = s_bm_current_air_resistance;
  v8[14] = 2;
  v8[16] = 3;
  vostok::render::resource_manager::create_buffer(
    0x3Cu,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)0xC,
    (vostok::render::enum_buffer_type)data,
    0,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v2,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 2184),
    0);
  vostok::render::resource_manager::create_buffer(
    0x24u,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)2,
    (vostok::render::enum_buffer_type)v8,
    1,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v3,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 2188),
    0);
  v6 = *(_DWORD *)(a2 + 2188);
  v5 = *(vostok::render::resource_manager **)(a2 + 2184);
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
    (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 2192),
    v4);
}
