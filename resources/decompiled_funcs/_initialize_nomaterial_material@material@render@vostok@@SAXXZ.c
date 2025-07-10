void __cdecl vostok::render::material::initialize_nomaterial_material()
{
  unsigned int i; // esi
  int *v1; // eax
  vostok::render::material_effects *v2; // ecx
  int v3; // eax
  vostok::render::effect_options_descriptor *v4; // eax
  int v5; // ecx
  const void **p_destroyer; // eax
  vostok::render::effect_options_descriptor *v7; // eax
  const void **v8; // eax
  vostok::render::effect_manager *m_conflicted_action_to_bind; // edx
  vostok::render::material_effects *v10; // eax
  vostok::render::effect_options_descriptor additional_parameters; // [esp+10h] [ebp-41Ch] BYREF
  unsigned __int8 data[1024]; // [esp+28h] [ebp-404h] BYREF

  for ( i = 0; i < 0xF; ++i )
  {
    v1 = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
           0x390u);
    if ( v1 )
      vostok::render::material_effects::material_effects(v2, (int)v1);
    else
      v3 = 0;
    s_nomaterial_material_effects[i] = (vostok::render::material_effects *)v3;
    *(_DWORD *)(v3 + 788) = i;
    additional_parameters.data = &data[24];
    additional_parameters.type = 3;
    additional_parameters.bytes = 0;
    additional_parameters.count = 0;
    additional_parameters.id = 0;
    additional_parameters.destroyer = 0;
    additional_parameters.memory_size = 1024;
    v4 = vostok::render::effect_options_descriptor::operator[](
           (vostok::render::effect_options_descriptor *)3,
           (int)&additional_parameters,
           (const char *)&key);
    v5 = 4;
    v4->data = (unsigned __int8 *)i;
    v4->count = 4;
    if ( (`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::`local static guard' |= 1u;
      LOWORD(v5) = vostok::render::static_type::type_id_counter + 1;
      vostok::render::static_type::type_id_counter = v5;
      LOWORD(`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::current_id) = v5;
    }
    v4->type = (unsigned __int16)`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::current_id;
    p_destroyer = &v4->destroyer;
    if ( p_destroyer )
      *p_destroyer = &vostok::render::destroy_data_helper<enum vostok::render::enum_vertex_input_type const>::`vftable';
    v7 = vostok::render::effect_options_descriptor::operator[](
           (vostok::render::effect_options_descriptor *)v5,
           (int)&additional_parameters,
           (const char *)&stru_960A14);
    v7->data = (unsigned __int8 *)1;
    v7->count = 4;
    if ( (`vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::`local static guard' & 1) == 0 )
    {
      `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::`local static guard' |= 1u;
      `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::current_id = ++vostok::render::static_type::type_id_counter;
    }
    v7->type = `vostok::render::static_type::get_type_id<enum D3D11_CULL_MODE>'::`2'::current_id;
    v8 = &v7->destroyer;
    if ( v8 )
      *v8 = &vostok::render::destroy_data_helper<enum D3D11_CULL_MODE const>::`vftable';
    vostok::render::effect_manager::create_effect<vostok::render::effect_gbuffer_nomaterial_materials>(
      (vostok::render::effect_options_descriptor *)s_nomaterial_material_effects[i]->m_effects,
      &additional_parameters,
      (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind);
    m_conflicted_action_to_bind = (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind;
    s_nomaterial_material_effects[i]->stage_enable[0] = 1;
    vostok::render::effect_manager::create_effect<vostok::render::depth_accumulate_material_effect>(
      (vostok::render::effect_options_descriptor *)&s_nomaterial_material_effects[i]->m_effects[28],
      &additional_parameters,
      m_conflicted_action_to_bind);
    v10 = s_nomaterial_material_effects[i];
    v10->stage_enable[28] = 1;
  }
}
