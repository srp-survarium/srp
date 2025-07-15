void __cdecl vostok::render::query_material_per_vertex_type(const vostok::fs_new::virtual_path_string *material_name)
{
  vostok::memory::doug_lea_allocator *v1; // ecx
  survarium::pure_game_effect_emitter_base *v2; // ecx
  vostok::render::enum_vertex_input_type v3; // ebx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  vostok::variant<32> *v5; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v6; // [esp-8h] [ebp-184h] BYREF
  BOOL v7; // [esp-4h] [ebp-180h]
  const char *v8; // [esp+0h] [ebp-17Ch]
  const char *v9; // [esp+4h] [ebp-178h]
  unsigned int v10; // [esp+8h] [ebp-174h]
  vostok::buffer_string v11[22]; // [esp+10h] [ebp-16Ch] BYREF
  vostok::variant<32> v12; // [esp+120h] [ebp-5Ch] BYREF
  int v13; // [esp+150h] [ebp-2Ch] BYREF
  boost::detail::function::function_buffer in_buffer; // [esp+158h] [ebp-24h] BYREF
  vostok::render::material_effects_instance_cook_data *value; // [esp+170h] [ebp-Ch] BYREF
  unsigned int i; // [esp+174h] [ebp-8h]

  for ( i = 0; i < 0xF; ++i )
  {
    v12.m_helper = 0;
    v12.m_type_id = 0;
    value = (vostok::render::material_effects_instance_cook_data *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                     v1,
                                                                     (int)vostok::render::g_allocator,
                                                                     0x10u,
                                                                     (char *)uri,
                                                                     v8,
                                                                     v9,
                                                                     v10);
    if ( value )
    {
      if ( i < 0xF )
      {
        v2 = (survarium::pure_game_effect_emitter_base *)i;
        v3 = 1 << i;
      }
      else
      {
        v3 = unknown_vertex_input_type;
      }
      v7 = 1;
      v6.m_object = v2;
      vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
        &v6,
        0);
      vostok::render::material_effects_instance_cook_data::material_effects_instance_cook_data(
        v3,
        value,
        v6,
        v7,
        (vostok::render::enum_cull_mode)v8);
    }
    vostok::variant<32>::set<vostok::render::material_effects_instance_cook_data *>(
      (vostok::variant<32> *)v2,
      (int)&v12,
      &value);
    _InterlockedExchangeAdd(&s_pending_materials_count, 1u);
    v13 = 0;
    if ( `boost::function1<void,vostok::resources::queries_result &>::assign_to<void (__cdecl *)(vostok::resources::queries_result &)>'::`2'::stored_vtable )
      `boost::function1<void,vostok::resources::queries_result &>::assign_to<void (__cdecl *)(vostok::resources::queries_result &)>'::`2'::stored_vtable(
        &in_buffer,
        &in_buffer,
        destroy_functor_tag);
    if ( vostok::render::on_single_material_loaded )
    {
      in_buffer.obj_ptr = vostok::render::on_single_material_loaded;
      v13 = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<void (__cdecl *)(vostok::resources::queries_result &)>'::`2'::stored_vtable
          + 1;
    }
    else
    {
      v13 = 0;
    }
    vostok::fixed_string<260>::fixed_string<260>(
      (vostok::fixed_string<260> *)vostok::render::on_single_material_loaded,
      v11,
      material_name->m_string.m_begin);
    vostok::resources::query_resource(
      v11[0].m_begin,
      (vostok::variant<32> *)0xF,
      vostok::render::g_allocator,
      &v12,
      0,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, &v13);
    vostok::variant<32>::destroy_previous_variable_if_needed(v5, (int)&v12);
  }
}
